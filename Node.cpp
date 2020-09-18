#include "Node.h"

void InsertP(Node *&List, const LinkedL &newProcess) {
    Node* newNode = new Node;
    newNode->data= newProcess;
    Node *aux1 = List;

    if(List == aux1)
        List = newNode;

    newNode->next = aux1;
}

void swap(Node *node1, Node *node2) {
    LinkedL temp = node1->data;
    node1->data = node2 -> data;
    node2->data = temp;
}

void Priority(Node *&List) {
    int swapped;
    Node *left;
    Node *right = NULL;

    do {
        swapped = 0;
        left = List;
        while (left->next != right) {
            if (left->data.priority > left->next->data.priority) {
                swap(left, left->next);
                swapped = 1;
            }
            left = left->next;
        }
        right = left;
    } while (swapped);
}


void Fifo(Node *&List) {
    int swapped;
    Node *left;
    Node *right = NULL;

    do {
        swapped = 0;
        left = List;
        while (left->next != right) {
            if (left->data.time_arrived > left->next->data.time_arrived && left->data.priority == left->next->data.priority) {
                swap(left, left->next);
                swapped = 1;
            }
            left = left->next;
        }
        right = left;
    } while (swapped);
}

void CPU(Node *&List) {
    int swapped;
    Node *left;
    Node *right = NULL;

    do {
        swapped = 0;
        left = List;
        while (left->next != right) {
            if (left->data.cpu > left->next->data.cpu) {
                swap(left, left->next);
                swapped = 1;
            }
            left = left->next;
        }
        right = left;
    } while (swapped);
}


void MIX(Node *&List){
    int swapped;
    Node *left;
    Node *right = NULL;

    do {
        swapped = 0;
        left = List;
        while (left->next != right) {
            if (left->data.cpu > left->next->data.cpu && left->data.priority == left->next->data.priority) {
                swap(left, left->next);
                swapped = 1;
            }
            left = left->next;
        }
        right = left;
    } while (swapped);
}
