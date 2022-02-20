#include <iostream>
#ifndef EDGE_H
#define EDGE_H

class Edge
{
    char data;
    Edge *next;

public:
    Edge() : data(' '), next(NULL) {}

    void setData(char key) { this->data = key; }
    void setNext(Edge *nextEdge) { this->next = nextEdge; }

    char getData() { return data; }
    Edge *getNext() { return next; }
};
#endif
