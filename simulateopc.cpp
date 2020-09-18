#include "simulateopc.h"
#include "ui_simulateform.h"
#include "Node.h"

simulateForm::simulateForm(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::simulateForm)
{
    ui->setupUi(this);
}

simulateForm::~simulateForm()
{
    delete ui;
}

void simulateForm::setList(Node *&_list){
    list = _list;
}

void simulateForm::setProperties(int _cpu, int _quantum) {
    cpu = _cpu;
    quantum = _quantum;
    ui->QUANTUM->setValue(quantum);
}

void simulateForm::on_pushButton_clicked()
{
    Priority(list);
    Fifo(list);
    simulate->setList(list);
    simulate->setProperties(cpu,quantum);
    simulate->show();
    simulate->setShow(true);
    simulate->showData();
}

void simulateForm::on_pushButton_2_clicked()
{
    CPU(list);
    simulate->setList(list);
    simulate->setProperties(cpu,quantum);
    simulate->show();
    simulate->setShow(true);
    simulate->showData();
}

void simulateForm::on_pushButton_3_clicked()
{
    Priority(list);
    MIX(list);
    simulate->setList(list);
    simulate->setProperties(cpu,quantum);
    simulate->show();
    simulate->setShow(true);
    simulate->showData();
}

void simulateForm::on_QUANTUM_valueChanged(int arg1)
{
    quantum = arg1;
}
