/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.15.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralWidget;
    QPushButton *TransparentBtn;
    QLabel *title;
    QPushButton *exit;
    QLineEdit *EdPid;
    QLabel *PID;
    QLineEdit *EdLevel;
    QLabel *Level;
    QLineEdit *EdProcessName;
    QLabel *ProcessName;
    QLabel *label;
    QPushButton *min;
    QPushButton *target;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(383, 420);
        MainWindow->setStyleSheet(QString::fromUtf8("background-color:rgb(163, 179, 245);"));
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QString::fromUtf8("centralWidget"));
        TransparentBtn = new QPushButton(centralWidget);
        TransparentBtn->setObjectName(QString::fromUtf8("TransparentBtn"));
        TransparentBtn->setGeometry(QRect(10, 360, 361, 31));
        QFont font;
        font.setFamily(QString::fromUtf8("\345\276\256\350\275\257\351\233\205\351\273\221"));
        font.setPointSize(13);
        font.setBold(true);
        TransparentBtn->setFont(font);
        TransparentBtn->setStyleSheet(QString::fromUtf8("QPushButton#TransparentBtn\n"
"{\n"
"background-color:rgb(255, 255, 255);\n"
"border:2px solid #5F92B2;\n"
"border-radius:5px;\n"
"color:rgb(0, 0, 0)\n"
"}\n"
"QPushButton#TransparentBtn:hover\n"
"{\n"
"background-color:rgb(0,130,150);\n"
"border:2px solid #5F92B2;\n"
"border-radius:5px;\n"
"color:white;\n"
"}\n"
"QPushButton#TransparentBtn:hover:pressed\n"
"{\n"
"background-color:rgb(85,170,255); \n"
"border:2px solid #3C80B1;\n"
"border-radius:5px;\n"
"color:white;\n"
"}\n"
""));
        title = new QLabel(centralWidget);
        title->setObjectName(QString::fromUtf8("title"));
        title->setGeometry(QRect(1, 1, 381, 41));
        QFont font1;
        font1.setFamily(QString::fromUtf8("\345\276\256\350\275\257\351\233\205\351\273\221"));
        font1.setPointSize(10);
        font1.setBold(true);
        title->setFont(font1);
        title->setTabletTracking(false);
        title->setAutoFillBackground(false);
        title->setStyleSheet(QString::fromUtf8("border:2px solid #FFFFFF;\n"
"color: rgb(255, 255, 255);"));
        title->setTextFormat(Qt::AutoText);
        exit = new QPushButton(centralWidget);
        exit->setObjectName(QString::fromUtf8("exit"));
        exit->setGeometry(QRect(340, 6, 30, 30));
        exit->setStyleSheet(QString::fromUtf8("\n"
"QPushButton#exit\n"
"{\n"
"border-image: url(:/res/timg.png);\n"
"border:1px solid #5F92B2;\n"
"border-radius:5px;\n"
"color:white\n"
"}\n"
"QPushButton#exit:hover\n"
"{\n"
"border-image: url(:/res/red.png);\n"
"color: rgb(170, 0, 0);\n"
"border:1px solid #5F92B2;\n"
"border-radius:5px;\n"
"color:white;\n"
"}\n"
"QPushButton#exit:hover:pressed\n"
"{\n"
"border-image: url(:/res/timg.png);\n"
"border:1px solid #3C80B1;\n"
"border-radius:5px;\n"
"color:white;\n"
"}\n"
""));
        EdPid = new QLineEdit(centralWidget);
        EdPid->setObjectName(QString::fromUtf8("EdPid"));
        EdPid->setGeometry(QRect(50, 60, 101, 31));
        EdPid->setFont(font);
        EdPid->setStyleSheet(QString::fromUtf8("border:2px solid #FFFFFF;\n"
"color: rgb(255, 255, 255);"));
        PID = new QLabel(centralWidget);
        PID->setObjectName(QString::fromUtf8("PID"));
        PID->setGeometry(QRect(10, 50, 41, 49));
        QFont font2;
        font2.setFamily(QString::fromUtf8("\345\276\256\350\275\257\351\233\205\351\273\221"));
        font2.setPointSize(11);
        font2.setBold(true);
        PID->setFont(font2);
        PID->setStyleSheet(QString::fromUtf8("color: rgb(255, 255, 255);background-color: rgba(0,0,0,0.0);"));
        PID->setIndent(0);
        EdLevel = new QLineEdit(centralWidget);
        EdLevel->setObjectName(QString::fromUtf8("EdLevel"));
        EdLevel->setGeometry(QRect(260, 60, 101, 31));
        EdLevel->setFont(font);
        EdLevel->setStyleSheet(QString::fromUtf8("border:2px solid #FFFFFF;\n"
"color: rgb(255, 255, 255);"));
        Level = new QLabel(centralWidget);
        Level->setObjectName(QString::fromUtf8("Level"));
        Level->setGeometry(QRect(210, 50, 51, 49));
        Level->setFont(font2);
        Level->setStyleSheet(QString::fromUtf8("color: rgb(255, 255, 255);background-color: rgba(0,0,0,0.0);"));
        EdProcessName = new QLineEdit(centralWidget);
        EdProcessName->setObjectName(QString::fromUtf8("EdProcessName"));
        EdProcessName->setGeometry(QRect(10, 140, 361, 31));
        EdProcessName->setFont(font);
        EdProcessName->setStyleSheet(QString::fromUtf8("border:2px solid #FFFFFF;\n"
"color: rgb(255, 255, 255);"));
        ProcessName = new QLabel(centralWidget);
        ProcessName->setObjectName(QString::fromUtf8("ProcessName"));
        ProcessName->setGeometry(QRect(10, 100, 111, 49));
        ProcessName->setFont(font2);
        ProcessName->setStyleSheet(QString::fromUtf8("color: rgb(255, 255, 255);"));
        label = new QLabel(centralWidget);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(40, 180, 311, 21));
        QFont font3;
        font3.setFamily(QString::fromUtf8("\345\276\256\350\275\257\351\233\205\351\273\221"));
        font3.setPointSize(12);
        font3.setBold(true);
        label->setFont(font3);
        min = new QPushButton(centralWidget);
        min->setObjectName(QString::fromUtf8("min"));
        min->setGeometry(QRect(310, 6, 30, 30));
        min->setStyleSheet(QString::fromUtf8("\n"
"QPushButton#min\n"
"{\n"
"border-image: url(:/res/touch-none.png);\n"
"border:1px solid #5F92B2;\n"
"border-radius:5px;\n"
"color:white\n"
"}\n"
"QPushButton#min:hover\n"
"{\n"
"border-image: url(:/res/touch-pass.png);\n"
"color: rgb(170, 0, 0);\n"
"border:1px solid #5F92B2;\n"
"border-radius:5px;\n"
"color:white;\n"
"}\n"
"QPushButton#min:hover:pressed\n"
"{\n"
"border-image:url(:/res/touch-pass.png);\n"
"border:1px solid #3C80B1;\n"
"border-radius:5px;\n"
"color:white;\n"
"}\n"
""));
        min->setIconSize(QSize(22, 22));
        target = new QPushButton(centralWidget);
        target->setObjectName(QString::fromUtf8("target"));
        target->setGeometry(QRect(120, 210, 130, 125));
        target->setStyleSheet(QString::fromUtf8("QPushButton#target\n"
"{\n"
"border-image: url(:/res/target.png);\n"
"border:1px solid #5F92B2;\n"
"border-radius:5px;\n"
"color:white\n"
"}"));
        target->setIconSize(QSize(22, 22));
        MainWindow->setCentralWidget(centralWidget);
        TransparentBtn->raise();
        title->raise();
        EdPid->raise();
        PID->raise();
        Level->raise();
        EdLevel->raise();
        exit->raise();
        ProcessName->raise();
        EdProcessName->raise();
        label->raise();
        min->raise();
        target->raise();
        statusBar = new QStatusBar(MainWindow);
        statusBar->setObjectName(QString::fromUtf8("statusBar"));
        MainWindow->setStatusBar(statusBar);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "TransparentBox", nullptr));
        TransparentBtn->setText(QCoreApplication::translate("MainWindow", "Transparent", nullptr));
        title->setText(QCoreApplication::translate("MainWindow", "TransparentBox By\357\274\232xm93cc", nullptr));
        exit->setText(QCoreApplication::translate("MainWindow", "X", nullptr));
        PID->setText(QCoreApplication::translate("MainWindow", "PID", nullptr));
        EdLevel->setInputMask(QString());
        Level->setText(QCoreApplication::translate("MainWindow", "Level", nullptr));
        ProcessName->setText(QCoreApplication::translate("MainWindow", "ProcessName", nullptr));
        label->setText(QCoreApplication::translate("MainWindow", "PID Level greater than  ProcessName ", nullptr));
        min->setText(QString());
        target->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
