#include "mainwindow.h"
#include "ui_mainwindow.h"
#include<QDebug>
#include<QRegExpValidator>
#include<vector>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    this->setWindowIcon(QIcon(":/../res/home-ico.ico"));
   // setWindowOpacity(0.8);
    this->setWindowFlags(Qt::FramelessWindowHint);
    boundaryWidth=4;                                    //设置触发resize的宽度
    this->setMinimumSize(383,420);                        //设置最小尺寸
    this->setMaximumSize(383,420);

    m_catch_window_task = WindowsTask::getInstance();
    connect(m_catch_window_task, &WindowsTask::catch_window, this ,&MainWindow::resize_window);
    connect(m_catch_window_task, &WindowsTask::modify_mouse, this ,&MainWindow::modify_mouse_icon);
    m_draw_catch_window = new CatchWindow();



    QLineEdit *edPid=ui->EdPid;
    QRegExp regx("[1-9][0-9][0-9][0-9][0-9]$");
    QValidator *validator = new QRegExpValidator(regx, edPid );
    edPid->setValidator( validator );
    edPid->setPlaceholderText("1~65536");


    QLineEdit *edLevel=ui->EdLevel;
    QRegExp regxl("[1-9][0-9][0-9]$");
    QValidator *validatoredLevel = new QRegExpValidator(regxl, edPid );
    edLevel->setValidator( validatoredLevel );
    edLevel->setPlaceholderText("1~255");

    this->setWindowFlags(Qt::ToolTip);
    createSystemTray();


}

MainWindow::~MainWindow()
{
    delete ui;
}
typedef struct WindowInfo_t
{
    HWND  hwnd1;
    char WindowText[255];
    char ClassName[255];
    DWORD dwProcessId;
    DWORD dwThreadId;
}WindowInfo;

typedef WindowInfo* PWindowInfo;
typedef WindowInfo* LPWindowInfo;

DWORD EnumWindowInfo(WindowInfo WInfo[]);
HWND m_hwndFind[255];
int m_num = 0;



BOOL CALLBACK EnumCallback(HWND hwnd, LPARAM /*lParam*/,int t)
{
    DWORD bAlpha = 0;
    GetLayeredWindowAttributes(hwnd, 0L, (BYTE*)&bAlpha, NULL);   // 获得当前窗口的透明度（255为不透明）
    SetWindowLong(hwnd, GWL_EXSTYLE, WS_EX_LAYERED);               // 给窗口增加透明属性
    SetLayeredWindowAttributes(hwnd, 0L, (BYTE)t, LWA_ALPHA);
    //DwmEnableBlurBehindWindow(getwin, &pd);
    //EnumChildWindows(hwnd, EnumCallback, lParam);                // 遍历窗口的子窗口

    return TRUE;
}

typedef struct
{
    HWND hwndWindow; // 窗口句柄
    DWORD dwProcessID; // 进程ID
}EnumWindowsArg;

BOOL CALLBACK EnumWindowsProc(HWND hWnd, LPARAM /*lParam*/)
{
    //判断窗口是否可见
    if (::GetWindowLong(hWnd, GWL_STYLE) & WS_VISIBLE)
    {
        m_hwndFind[m_num] = hWnd;
        m_num++;
    }

    return true;
}

BOOL CALLBACK EnumWindowsProcs(HWND hwnd, LPARAM lParam)
{
    EnumWindowsArg* pArg = (EnumWindowsArg*)lParam;
    DWORD dwProcessID = 0;
    // 通过窗口句柄取得进程ID
    ::GetWindowThreadProcessId(hwnd, &dwProcessID);
    if (dwProcessID == pArg->dwProcessID)
    {
        pArg->hwndWindow = hwnd;
        return FALSE;
    }
    return TRUE;
}


HWND GetWindowHwndByPID(DWORD dwProcessID)
{
    HWND hwndRet = NULL;
    EnumWindowsArg ewa;
    ewa.dwProcessID = dwProcessID;
    ewa.hwndWindow = NULL;
    EnumWindows(EnumWindowsProc, (LPARAM)&ewa);
    if (ewa.hwndWindow)
    {
        hwndRet = ewa.hwndWindow;
    }
    return hwndRet;
}
bool GetHwndByPid(DWORD ProcessId, std::vector<HWND> &out)
{

    bool bRet = false;
    WindowInfo WinInfo1[255];
    DWORD enum_window = EnumWindowInfo(WinInfo1);
    for (int i = 0; i < static_cast<int>(enum_window); i++)
    {
        if (WinInfo1[i].dwProcessId == ProcessId)
        {
            bRet = true;
            out.push_back(WinInfo1[i].hwnd1);

//            if (NULL == ::GetWindowLong(WinInfo1[i].hwnd1, GWL_HWNDPARENT)) //枚举父窗口的句柄
        }
    }

    return bRet;
}

DWORD EnumWindowInfo(WindowInfo WInfo[])
{
    WindowInfo Winpro;
    m_num = 0;
    ::EnumWindows(EnumWindowsProc, NULL);

    int i;
    for (i = 0; i < m_num; i++)
    {
        Winpro.hwnd1 = m_hwndFind[i];

        ::GetWindowText(m_hwndFind[i], (LPWSTR)Winpro.WindowText, 128);
        ::GetClassName(m_hwndFind[i], (LPWSTR)Winpro.ClassName, MAX_PATH - 1);

        Winpro.dwThreadId = ::GetWindowThreadProcessId(m_hwndFind[i], &Winpro.dwProcessId);
        WInfo[i] = Winpro;
    }

    return i;
}



void MainWindow::mousePressEvent(QMouseEvent *e)
{
    if(e->button()==Qt::LeftButton && m_catch_window_task->is_stop)
        clickPos=e->pos();
}
void MainWindow::mouseMoveEvent(QMouseEvent *e)
{
    if(e->buttons()&Qt::LeftButton && m_catch_window_task->is_stop)
        move(e->pos()+pos()-clickPos);
}

bool MainWindow::nativeEvent(const QByteArray &/*eventType*/, void *message, long *result)
{
    MSG* msg = (MSG*)message;
    if(m_catch_window_task->is_stop)
        return false;
    switch(msg->message)
    {
    case WM_NCHITTEST:
        int xPos = GET_X_LPARAM(msg->lParam) - this->frameGeometry().x();
        int yPos = GET_Y_LPARAM(msg->lParam) - this->frameGeometry().y();
        if(xPos < boundaryWidth && yPos<boundaryWidth)                    //左上角
            *result = HTTOPLEFT;
        else if(xPos>=width()-boundaryWidth&&yPos<boundaryWidth)          //右上角
            *result = HTTOPRIGHT;
        else if(xPos<boundaryWidth&&yPos>=height()-boundaryWidth)         //左下角
            *result = HTBOTTOMLEFT;
        else if(xPos>=width()-boundaryWidth&&yPos>=height()-boundaryWidth)//右下角
            *result = HTBOTTOMRIGHT;
        else if(xPos < boundaryWidth)                                     //左边
            *result =  HTLEFT;
        else if(xPos>=width()-boundaryWidth)                              //右边
            *result = HTRIGHT;
        else if(yPos<boundaryWidth)                                       //上边
            *result = HTTOP;
        else if(yPos>=height()-boundaryWidth)                             //下边
            *result = HTBOTTOM;
        else              //其他部分不做处理，返回false，留给其他事件处理器处理
            return false;
        return true;
    }
    return false;         //此处返回false，留给其他事件处理器处理
}

void transparentAppByPid(int pid,int t)
{

   std::vector<HWND> hwnd_v;
   GetHwndByPid(pid,hwnd_v);
   if (hwnd_v.empty())
   {
        return;
   }
   EnumCallback(hwnd_v.front(), 0L,t);

}

void MainWindow::on_exit_clicked()
{
    m_catch_window_task->stop();
    exit(1);
}


void MainWindow::on_TransparentBtn_clicked()
{
    QString edPid=ui->EdPid->text();
    QString edLevel=ui->EdLevel->text();
    QString processName=ui->EdProcessName->text();
    int level=0;
    int pid=0;
    if(edLevel.length()>0)
        level=edLevel.toInt();
    if(level<=0)
        level=50;
    else if(level>255)
        level=255;

    if(edPid.length()>1)
    {
        pid=edPid.toInt();
        transparentAppByPid(pid,level);
        return;
    }
    if(processName.length()<2)
    {
        QMessageBox::warning(this,tr("警告"),tr("<p><span style='color: #FFFFFF;'>pid和processName必填一项</span></p>"),QMessageBox::Yes);

        return;
    }
    QString strcmmd=begin+processName+end;
    qDebug()<<strcmmd.toUtf8()<<'\n';
    WinExec(strcmmd.toUtf8(), SW_HIDE);
    Sleep(500);
    QString fileName = "./1.ini";
    QFile file(fileName);
    file.open(QIODevice::ReadOnly | QIODevice::Text);
    QByteArray t = file.readAll();
    if(t.length()<10)
    {
        QMessageBox::information(this,tr("提示"),tr("<p><span style='color: #FFFFFF;'>没有找到进程</span></p>"),QMessageBox::Yes);
        return;
    }
    QString contest=QString(t);
    file.close();
    QStringList splitList= contest.split('\n');
    QList<QString>::Iterator it = splitList.begin(),itend = splitList.end();
    int i=0;
    for (;it != itend; it++,i++){
        if(it->length()>5)
        {
            QStringList list=it->split("                ");
            QList<QString>::Iterator its = list.begin(),itsend = list.end();
            int j=0;
            for (;its != itsend; its++,j++){
                if(j==1)
                {
                    QString pidc=its->toUtf8().trimmed();
                    QStringList newPid=pidc.split(' ');
                    //qDebug()<<newPid.begin()->toUtf8()<<endl;
                    int pid=newPid.begin()->toInt();
                    qDebug() << pid << '\n';
                    transparentAppByPid(pid,level);
                }

            }

        }

    }

}


void MainWindow::on_min_clicked()
{
    this->hide();
}

void MainWindow::createSystemTray()
{
    if(m_isShowSystemTray){
        return;
    }
    m_isShowSystemTray=true;
    m_pTrayMennu = new QMenu(this);
    m_pSystemTray = new QSystemTrayIcon(this);
    m_pTrayMennu->setStyleSheet("QMenu{\n"
                                "  background:rgba(255,255,255,1);"
                                "  border:none;"
                                "}"
                                "QMenu::item{"
                                "  padding:11px 32px;"
                                "  color:rgba(51,51,51,1);"
                                "  font-size:12px;"
                                "}"
                                "QMenu::item:hover{"
                                "  background-color:#409CE1;"
                                "}"
                                "QMenu::item:selected{"
                                "  background-color:#409CE1;"
                                "}");
    //创建菜单项
    m_pActionShow = new QAction(tr("Show pet"), this);
    m_pActionQuit = new QAction(tr("Exit"), this);

    //添加菜单项
    m_pTrayMennu->addAction(m_pActionShow);
    m_pTrayMennu->addSeparator();
    m_pTrayMennu->addAction(m_pActionQuit);

    //为系统托盘设置菜单为m_pTrayMennu
    m_pSystemTray->setContextMenu(m_pTrayMennu);
    m_pSystemTray->setIcon(QIcon(":/res/home-ico.ico"));
    connect(m_pActionShow,&QAction::triggered,m_pTrayMennu,[=](){
        this->showNormal();
    });


    connect(m_pActionQuit,&QAction::triggered,m_pTrayMennu,[=](){
        m_catch_window_task->stop();
        exit(0);
    });
    connect(m_pSystemTray,SIGNAL(activated(QSystemTrayIcon::ActivationReason)),this,SLOT(onActivated(QSystemTrayIcon::ActivationReason)));
    m_pSystemTray->show();
}




void MainWindow::onActivated(QSystemTrayIcon::ActivationReason action){
    qDebug()<<action;
       if(action==QSystemTrayIcon::ActivationReason::Unknown){
           qDebug()<<"未知点击";
       }
       else if(action==QSystemTrayIcon::ActivationReason::Context || action==QSystemTrayIcon::ActivationReason::Trigger){
           qDebug()<<"鼠标单击";
       }
       else if(action==QSystemTrayIcon::ActivationReason::DoubleClick){
           this->showNormal();
       }
       else if(action==QSystemTrayIcon::ActivationReason::MiddleClick){
           qDebug()<<"鼠标中间单击";
       }else{
           return;
       }
}

void MainWindow::on_target_pressed()
{
    QIcon icon(":/res/target.png");
    this->setCursor(QCursor(icon.pixmap(icon.actualSize(QSize(64, 64)))));
    if(!m_catch_window_task->isRunning()){
        this->m_draw_catch_window->show();
        m_catch_window_task->is_stop = false;
        m_catch_window_task->start();
    }
}

void MainWindow::modify_mouse_icon()
{
    QString edLevel=ui->EdLevel->text();
    int level=0;
    if(edLevel.length()>0)
        level=edLevel.toInt();
    if(level<=0)
        level=50;
    else if(level>255)
        level=255;
    QCursor q;
    this->setCursor(q);
    this->m_draw_catch_window->hide();
    EnumCallback(m_catch_window_task->_cur_catch_wnd, 0L,level);
}

void MainWindow::resize_window()
{
    std::shared_ptr<RectInfo> info;
    if (m_catch_window_task->_lock_free_queue.consume(&info)) {
        m_draw_catch_window->resize((info->right - info->left) - 20, (info->bottom - info->top) - 15);
        m_draw_catch_window->move(info->left + 10,info->top + 5);
        m_draw_catch_window->show();
    }
}
