#ifndef NODEPROCESS_H
#define NODEPROCESS_H

#include <string>
#include <iostream>
#include <cstdlib>
#include <bits/stdc++.h>
#include <QString>

using namespace std;

struct LinkedL {
    QString name;
    QString status;
    int priority;
    int cpu;
    int time_arrived;
    int waiting_time;
    int success_time;
    int bloqnumber;

};

struct Node {
    LinkedL data;
    struct Node *next;
};

void InsertP(Node *&,const LinkedL&);
void sort(Node *&);
void swap(Node *, Node *);
void Priority(Node *&);
void CPU(Node *&);
void MIX(Node *&);
void Fifo(Node *&);

#endif // NODEPROCESS_H
