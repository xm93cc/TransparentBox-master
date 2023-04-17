/********************************************************************************
** Form generated from reading UI file 'subform.ui'
**
** Created by: Qt User Interface Compiler version 5.15.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SUBFORM_H
#define UI_SUBFORM_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_SubForm
{
public:

    void setupUi(QWidget *SubForm)
    {
        if (SubForm->objectName().isEmpty())
            SubForm->setObjectName(QString::fromUtf8("SubForm"));
        SubForm->resize(655, 435);
        SubForm->setMinimumSize(QSize(100, 100));
        SubForm->setBaseSize(QSize(100, 100));

        retranslateUi(SubForm);

        QMetaObject::connectSlotsByName(SubForm);
    } // setupUi

    void retranslateUi(QWidget *SubForm)
    {
        SubForm->setWindowTitle(QCoreApplication::translate("SubForm", "Form", nullptr));
    } // retranslateUi

};

namespace Ui {
    class SubForm: public Ui_SubForm {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SUBFORM_H
