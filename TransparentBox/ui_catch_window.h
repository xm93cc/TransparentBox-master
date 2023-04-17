/********************************************************************************
** Form generated from reading UI file 'catch_window.ui'
**
** Created by: Qt User Interface Compiler version 5.15.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CATCH_WINDOW_H
#define UI_CATCH_WINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_CatchWindow
{
public:

    void setupUi(QWidget *CatchWindow)
    {
        if (CatchWindow->objectName().isEmpty())
            CatchWindow->setObjectName(QString::fromUtf8("CatchWindow"));
        CatchWindow->resize(400, 300);

        retranslateUi(CatchWindow);

        QMetaObject::connectSlotsByName(CatchWindow);
    } // setupUi

    void retranslateUi(QWidget *CatchWindow)
    {
        CatchWindow->setWindowTitle(QCoreApplication::translate("CatchWindow", "Form", nullptr));
    } // retranslateUi

};

namespace Ui {
    class CatchWindow: public Ui_CatchWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CATCH_WINDOW_H
