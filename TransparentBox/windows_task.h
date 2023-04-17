#ifndef WINDOWSTASK_H
#define WINDOWSTASK_H
#include <QObject>
#include<QThread>
#include<windows.h>
#include<qdebug.h>
#include<iostream>
#include"lock_free_queue.h"
#include"rect_info.h"
#include<memory>
#include<string>
class WindowsTask : public QThread
{
    Q_OBJECT
public:
    static WindowsTask* getInstance()
    {
        static WindowsTask mouseEvent;
        return &mouseEvent;
    }

    Safe::LockFreeQueue<std::shared_ptr<RectInfo>> _lock_free_queue;
    WindowsTask();
    static bool installMouseEvent();      // 安装全局鼠标事件监听器
    static bool removeMouseEvent();       // 卸载全局鼠标事件监听器
    void stop();


protected:
    void run();
private:
    HWND _cur_wnd;

signals:
    void catch_window();
    void modify_mouse();
public:
    bool is_stop = false;
    HWND _cur_catch_wnd;
};

#endif // WINDOWSTASK_H
