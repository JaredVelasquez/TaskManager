#ifndef ADDWIDGET_H
#define ADDWIDGET_H

#include <QWidget>
#include "Node.h"

namespace Ui {
class addWidget;
}

class addWidget : public QWidget
{
    Q_OBJECT

public:

    LinkedL *newProcess;
    explicit addWidget(QWidget *parent = nullptr);
    void setProcess(LinkedL *&);
    ~addWidget();
signals :
    void save();
private slots:
    void on_pushButton_clicked();

private:
    Ui::addWidget *ui;
};

#endif // ADDWIDGET_H
