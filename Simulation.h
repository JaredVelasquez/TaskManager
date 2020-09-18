#ifndef SIMULATE_H
#define SIMULATE_H

#include <QWidget>
#include "Node.h"

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
    bool showStart, creatRow;
    void setShow(bool);
    int cpu, quantum;
    void ThreadS();
    void PrintH(int, LinkedL);
    void setList(Node *&);
    void setProperties(int , int);
    void showData();
private slots:
    void on_START_clicked();

private:
    Ui::Simulate *ui;

    enum {
        NAME, PRIORITY, CPU, TIME_ARRIVED, STATUS, WAITING, BLOQN
    };
};

#endif // SIMULATE_H
