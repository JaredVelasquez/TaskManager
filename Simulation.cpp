#include "Simulation.h"
#include "ui_simulate.h"
#include <QString>
#include <QMessageBox>
#include <QThread>
Simulate::Simulate(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Simulate)
{
    ui->setupUi(this);
    setWindowTitle("Nodes");
    QStringList titles;
    titles << "Name" << "Priority" << "Time Burst" << "Arrival Time" << "State" << "Waiting Time" << "Bloq#";
    ui->tableWidget->setColumnCount(7);
    ui->tableWidget->setHorizontalHeaderLabels(titles);
}

Simulate::~Simulate()
{
    delete ui;
}

void Simulate::setList(Node *&_list) {
    list = _list;
}

void Simulate::setShow(bool _show) {
    showStart = _show;
    if(showStart == false)
        ui->START->hide();
}
void Simulate::setProperties(int _cpu, int _quantum) {
    cpu = _cpu;
    quantum = _quantum;
}

void Simulate::PrintH(int position, LinkedL Linkl) {
    if(creatRow == true)
        ui->tableWidget->insertRow(ui->tableWidget->rowCount());
    ui->tableWidget->setItem(position,NAME, new QTableWidgetItem(Linkl.name));
    ui->tableWidget->setItem(position,PRIORITY, new QTableWidgetItem(QString::number(Linkl.priority)));
    ui->tableWidget->setItem(position,CPU, new QTableWidgetItem(QString::number(Linkl.cpu)));
    ui->tableWidget->setItem(position,TIME_ARRIVED, new QTableWidgetItem(QString::number(Linkl.time_arrived)));
    ui->tableWidget->setItem(position,STATUS, new QTableWidgetItem(Linkl.status));
    ui->tableWidget->setItem(position,WAITING, new QTableWidgetItem(QString::number(Linkl.waiting_time)));
    ui->tableWidget->setItem(position,BLOQN, new QTableWidgetItem(QString::number(Linkl.bloqnumber)));
}

void Simulate::showData() {
    int row = 0;
    Node *aux;
    aux = list;
    creatRow = true;
    while(aux != nullptr){
        PrintH(row, aux->data);
        aux = aux->next;
        row = row + 1;
    }
}



void Simulate::ThreadS() {
    int realtime = 0, bloqlist = 0,totalcpu = cpu;
    bool finish = false;
    int position = 0, quantumaux=quantum;
    Node *actual;
    actual = list;

    do{
        while(actual != NULL){

        if( actual->data.status != "Succes")
        {
                actual->data.status = "Ready";
                PrintH(position, actual->data);
                while(quantum > 0 && actual->data.cpu > 0){
                    if (actual->data.cpu > 0){
                        actual->data.cpu -= 1;
                        quantum --;
                        PrintH(position, actual->data);
                    }
                }
                realtime += quantumaux - quantum;
                totalcpu = totalcpu - (quantumaux - quantum);
                quantum = quantumaux;

            if(actual->data.cpu <= 0){
                actual->data.status = "Succes";
                PrintH(position, actual->data);
            }
            else if(actual->data.cpu > 0){
                actual->data.status = "Bloq";
                if(actual->data.bloqnumber == 0){
                    actual->data.bloqnumber = bloqlist+1;
                    bloqlist += 1;
                }
                PrintH(position, actual->data);
            }
            actual->data.waiting_time = realtime - actual->data.time_arrived;
            PrintH(position, actual->data);
            actual = actual->next;
        }
            if(totalcpu <= 0){
                finish = true;
                actual = NULL;
            }
            position ++;
        }


        if(actual== NULL && totalcpu > 0){
            actual = list;
            position = 0;
        }
    }while(finish != true);

}

void Simulate::on_START_clicked()
{
    ThreadS();
}
