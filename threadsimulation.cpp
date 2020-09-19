#include "threadsimulation.h"
#include "Simulation.h"

ThreadSimulation::ThreadSimulation(QObject *parent) : QObject(parent)
{

}
ThreadSimulation::~ThreadSimulation(){

}
void ThreadSimulation::run(){
}
void ThreadSimulation::setList(Node *&_List){
    list =_List;
}
