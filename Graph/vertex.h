#include <iostream>
#include <queue>
#include "edge.h"
using namespace std;

#ifndef VERTEX_H
#define VERTEX_H

//utility function
bool contains(char arr[], char key)
{
    int i = 0;
    while (arr[i] != ' ')
    {
        if (arr[i] == key)
            return true;
        i++;
    }
    return false;
}

class Vertex
{
    char data;
    Edge *edges;

    Edge *createEdge(char key)
    {
        Edge *newEdge = new Edge;
        newEdge->setData(key);
        return newEdge;
    }

public:
    Vertex() : data(' '), edges(NULL) {}
    ~Vertex()
    {
        Edge *iter = edges;
        Edge *iterNext;
        while (iter)
        {
            iterNext = iter->getNext();
            delete iter;
            iter = iterNext;
        }
        edges = NULL;
    }
    void setData(char key) { this->data = key; }
    char getData() { return data; }
    Edge *getEdge() { return edges; }
    Edge *getLastEdge()
    {
        if (!edges)
            return NULL;

        Edge *iter = edges;
        while (iter->getNext() != NULL)
            iter = iter->getNext();
        return iter;
    }

    void addEdge(char key)
    {
        if (!edges)
        {
            edges = createEdge(key);
            return;
        }

        Edge *append = createEdge(key);
        Edge *lastEdge = getLastEdge();
        lastEdge->setNext(append);
    }

    void display()
    {
        if (edges)
        {
            cout << this->data << "->";
            Edge *iter = this->edges;
            while (iter)
            {
                cout << iter->getData() << " ";
                iter = iter->getNext();
            }
        }
        else
            cout << this->data;
        cout << endl;
    }

    void pushEdgesToQ(queue<char> &q, char visited[], int &i)
    {
        Edge *iter = this->edges;
        while (iter)
        {
            if (!contains(visited, iter->getData())) //find the unvisited vertices among the adjacent
            {
                q.push(iter->getData());      //push them into the queue
                visited[i] = iter->getData(); //mark them as visited
                i++;
            }

            iter = iter->getNext();
        }
    }
};
#endif