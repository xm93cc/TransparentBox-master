#ifndef SUBFORM_H
#define SUBFORM_H

#include <QWidget>

namespace Ui {
class SubForm;
}

class SubForm : public QWidget
{
    Q_OBJECT

public:
    explicit SubForm(QWidget *parent = nullptr);
    ~SubForm();
    void SubForm::paintEvent(QPaintEvent *);


private:
    Ui::SubForm *ui;
};

#endif // SUBFORM_H
