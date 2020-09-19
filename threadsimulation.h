#ifndef THREADSIMULATION_H
#define THREADSIMULATION_H

#include <QObject>
#include <QThread>
#include "Node.h"

class ThreadSimulation : public QObject
{
    Q_OBJECT
public:
    Node *list;
    explicit ThreadSimulation(QObject *parent = nullptr);
    ~ThreadSimulation();
    void setList(Node *&);
protected:
    void run();
signals:

};

#endif // THREADSIMULATION_H
