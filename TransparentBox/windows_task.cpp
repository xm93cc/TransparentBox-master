#include "windows_task.h"

WindowsTask::WindowsTask()
{
    _cur_wnd = GetForegroundWindow();
    installMouseEvent();
}

static HHOOK g_hook = nullptr;

void WindowsTask::run()
{
     while(1)
     {
         if (is_stop) {
             break;
         }
        POINT m_mouse;
        GetCursorPos(&m_mouse);
        HWND wnd =  WindowFromPoint(m_mouse);
        int textLen = GetWindowTextLengthW(wnd);
        LPWSTR str =  new wchar_t[textLen + 1];
        GetWindowTextW(wnd,str,textLen + 1);
        std::wstring cur_win_title = L"MainWindow";
        if(cur_win_title.find(str) != std::wstring::npos ){
            continue;
        }
        RECT rect;
        GetWindowRect(wnd,&rect);
        std::shared_ptr<RectInfo> info = std::make_shared<RectInfo>();
        info->top = static_cast<int32_t>(rect.top);
        info->bottom = static_cast<int32_t>(rect.bottom);
        info->left = static_cast<int32_t>(rect.left);
        info->right = static_cast<int32_t>(rect.right);
        _cur_catch_wnd = wnd;
        _lock_free_queue.produce(info);
        emit catch_window(); // send signal to ui level
        Sleep(1000);
     }
}

/**
 * @brief           处理鼠标事件的回调函数
 *                  DOC: https://learn.microsoft.com/zh-cn/previous-versions/windows/desktop/legacy/ms644986(v=vs.85)
 * @param nCode     挂钩过程用于确定如何处理消息的代码。如果nCode小于零，则挂钩过程必须将消息传递给 CallNextHookEx 函数而不进行进一步处理，并且应返回CallNextHookEx返回的值
 * @param wParam    信号类型：WM_LBUTTONDOWN、WM_LBUTTONUP、WM_MOUSEMOVE、WM_MOUSEWHEEL、WM_MOUSEHWHEEL、WM_RBUTTONDOWN 或WM_RBUTTONUP（鼠标中键点击和拓展按还没找到怎么弄）。
 * @param lParam    MSLLHOOKSTRUCT结构体指针
 * @return
 */
LRESULT CALLBACK LowLevelMouseProc(int nCode, WPARAM wParam, LPARAM lParam)
{
     switch (wParam)
     {
     case WM_LBUTTONUP:     // 鼠标左键抬起
        emit WindowsTask::getInstance()->modify_mouse();
        WindowsTask::getInstance()->is_stop = true;
        qDebug() << "left btn up" << "\n";
        break;
     default:
        break;
     }

     return CallNextHookEx(nullptr, nCode, wParam, lParam);   // 注意这一行一定不能少，否则会出大问题
}

bool WindowsTask::installMouseEvent()
{
     if(g_hook) return true;     // 避免重复安装
     /**
     * WH_KEYBOARD_LL 为全局键盘钩子, WH_MOUSE_LL 为全局鼠标钩子
     * DOC: https://learn.microsoft.com/zh-cn/windows/win32/api/winuser/nf-winuser-setwindowshookexw
     */
     g_hook = SetWindowsHookExW(WH_MOUSE_LL, LowLevelMouseProc, GetModuleHandleW(nullptr), 0);
     return g_hook;
}


/**
 * @brief   卸载全局鼠标事件监听器
 * @return
 */
bool WindowsTask::removeMouseEvent()
{
     if(!g_hook) return true;   // 避免重复卸载
     bool ret = UnhookWindowsHookEx(g_hook);
     if(ret)
     {
        g_hook = nullptr;
        return true;
     }
     return false;
}

void WindowsTask::stop()
{
     this->is_stop = true;
     this->removeMouseEvent();//程序结束卸载鼠标钩子
}
