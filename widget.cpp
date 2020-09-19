#include "widget.h"
#include "ui_widget.h"
#include "DialogInsert.h"
#include <QMessageBox>
#include "Simulation.h"
#include "simulateopc.h"

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);
    cpu = 0;
    connect(addwid, SIGNAL(save()), this, SLOT(add()));
}

Widget::~Widget()
{
    delete ui;
}

void Widget::add() {
    LinkedL LinkL;
    LinkL.name = newProcess->name;
    LinkL.cpu = newProcess->cpu;
    LinkL.priority = newProcess->priority;
    LinkL.time_arrived = newProcess->time_arrived;
    LinkL.waiting_time = 0;
    LinkL.success_time = 0;
    LinkL.status = "Ready";
    cpu += newProcess->cpu;
    InsertP(list, LinkL);
}

void Widget::on_AddProcess_clicked()
{
    addwid->show();
    addwid->setProcess(newProcess);
}

void Widget::on_simulation_clicked()
{
    simulateForm *simuform = new simulateForm;
    simuform->setList(list);
    simuform->setProperties(cpu, 5);
    simuform->show();
}

void Widget::on_printPbtn_clicked()
{
    Simulate *simu = new Simulate;
    simu->setList(list);
    simu->show();
    simu->setShow(false);
    simu->showData();
}
void Widget::on_show_clicked(){

}
void Widget::on_pushButton_clicked(){

}
