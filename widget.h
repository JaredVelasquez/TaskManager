#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include "Node.h"
#include "DialogInsert.h"
#include <QString>
#include "DialogInsert.h"

QT_BEGIN_NAMESPACE
namespace Ui { class Widget; }
QT_END_NAMESPACE

class Widget : public QWidget
{
    Q_OBJECT

public:
    LinkedL *newProcess = new LinkedL;
    addWidget *addwid = new addWidget;
    Node *list = nullptr;
    int cpu;
    Widget(QWidget *parent = nullptr);
    ~Widget();
public slots:
    void add();
private slots:
    void on_AddProcess_clicked();
    void on_show_clicked();

    void on_pushButton_clicked();

    void on_simulation_clicked();

    void on_printPbtn_clicked();

private:
    Ui::Widget *ui;
};
#endif // WIDGET_H
