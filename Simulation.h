#ifndef SIMULATE_H
#define SIMULATE_H

#include <QWidget>
#include "Node.h"
#include <QTimer>

namespace Ui {
class Simulate;
}

class Simulate : public QWidget
{
    Q_OBJECT

public:
    explicit Simulate(QWidget *parent = nullptr);
    ~Simulate();
    Node *list;
    Node *aux;
    bool showStart, creatRow;
    void setShow(bool);
    int cpu, quantum;
    void PrintH(int, LinkedL);
    void setList(Node *&);
    void setProperties(int , int);
    void showData();
    void PrintRes(int, LinkedL);
    void PrintThread();
     int position = 0;
      Node *actual;
    int cont;
    int realtime = 0;
private slots:

    void ThreadS();
    void on_START_clicked();

private:
    Ui::Simulate *ui;
    QTimer *hilo1, *hilo2;
    enum {
        NAME, PRIORITY, CPU, TIME_ARRIVED, STATUS, WAITING, BLOQN
    };
};

#endif // SIMULATE_H
