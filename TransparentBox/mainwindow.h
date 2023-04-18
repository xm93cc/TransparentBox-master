#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include "windows_task.h"
#include <windows.h>
#include <dwmapi.h>
#include <QMainWindow>
#include <stdlib.h>
#include <QMouseEvent>
#include <QWidget>
#include <windowsx.h>
#include <QStandardItemModel>
#include <QFileDialog>
#include <shellapi.h>
#include <QMessageBox>
#include <QStringListModel>
#include <QStandardItemModel>
#include <QModelIndex>
#include <stdio.h>
#include <windows.h>
#include <tlhelp32.h>
#include <QMenu>
#include <QSystemTrayIcon>
#include "catchwindow.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

protected:
protected:
    bool nativeEvent(const QByteArray &eventType, void *message, long *result);
    void mousePressEvent(QMouseEvent *e);
    void mouseMoveEvent(QMouseEvent *e);

public:
    explicit MainWindow(QWidget *parent = nullptr);
    void resize_window();
    void modify_mouse_icon();
    ~MainWindow();

signals:
    void clickIndex();


private slots:

    void on_exit_clicked();

    void on_TransparentBtn_clicked();

    void on_min_clicked();

    void onActivated(QSystemTrayIcon::ActivationReason action);

    void createSystemTray();

    void on_target_pressed();

private:
    Ui::MainWindow *ui;
    int boundaryWidth;
    QPoint clickPos;
    QStandardItemModel *processList;
    QString begin="cmd /c tasklist |findstr ";
    QString end="  > ./1.ini";
    QStringListModel *Model;
    QStandardItemModel *ItemModel;
    QStringList strListl;
    QMenu* m_pTrayMennu;            //系统托盘右键菜单项
    QSystemTrayIcon* m_pSystemTray; //系统托盘图标
    //右键菜单栏选项
    QAction* m_pActionShow;
    QAction* m_pActionQuit;
    bool m_isShowSystemTray=false;
    WindowsTask* m_catch_window_task;
    CatchWindow* m_draw_catch_window;
};

#endif // MAINWINDOW_H
