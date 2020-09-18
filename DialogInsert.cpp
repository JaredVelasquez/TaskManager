#include "DialogInsert.h"
#include "ui_addwidget.h"
#include "Node.h"
#include <QString>
#include <QMessageBox>

addWidget::addWidget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::addWidget)
{
    ui->setupUi(this);
}

addWidget::~addWidget()
{
    delete ui;
}

void addWidget::setProcess(LinkedL *&process) {
    newProcess = process;
}

void addWidget::on_pushButton_clicked()
{
    addWidget di;
    newProcess->name = ui->Name->text();
    newProcess->cpu = QString::number(ui->CPU->value()).toInt();
    newProcess->priority = QString::number(ui->Priority->value()).toInt();
    newProcess->time_arrived = QString::number(ui->time_arrived->value()).toInt();
    newProcess->waiting_time = 0;
    newProcess->success_time = 0;
    newProcess->status = "Ready";
    ui->CPU->clear();
    ui->Name->clear();
    ui->Priority->clear();
    ui->time_arrived->clear();
    emit save();
}
