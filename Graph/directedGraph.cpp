#include <iostream>
#include <queue>
#include "vertex.h"
using namespace std;

class DirectedGraph
{
private:
    Vertex *vertices; //array of vertices from vertex.h
    int size;
    int count;

public:
    DirectedGraph(int s = 0) //Default constructor
    {
        size = s;
        count = 0;
        vertices = new Vertex[size];
    }

    DirectedGraph(int s, char v[]) //parametirzed constructor
    {
        size = s;
        count = 0;
        vertices = new Vertex[size];
        for (int i = 0; i < size; i++)
        {
            vertices[i].setData(v[i]);
            count++;
        }
    }

    ~DirectedGraph() { delete[] vertices; } //destructor

    void addVertex(char key)
    {
        if (count < size)
        {
            vertices[count].setData(key); //add a new vertex to the array, and increment the count
            count++;
            return;
        }
    }

    void addEdgeFrom(char vertexKey, char edgeData) //add edge to vertex "vertexKey", of value "edgeData"
    {
        Vertex *keyVertex = vertices;

        char iter;
        int i = 0;

        while (iter != vertexKey && i < count) //loop until you find the key vertex
        {
            iter = vertices[i].getData();
            keyVertex = vertices + i;
            i++;
        }

        keyVertex->addEdge(edgeData); //add edge to the key vertex
    }

    void display()
    {
        if (count == 0)
            return;

        for (int i = 0; i < count; i++)
            vertices[i].display(); //display the edges of each vertex by looping throug them
    }

    //bfs utility function
    int getNextVertexIndex(char key)
    {
        for (int i = 0; i < count; i++)
        {
            if (vertices[i].getData() == key)
                return i;
        }
        return -1;
    }

    void bfs(int startIndex) //takes in the index of the vertex to start the bfs from
    {
        if (startIndex >= count || startIndex < 0)
            return;

        queue<char> q;
        char visited[count];

        for (int i = 0; i < count; i++)
            visited[i] = ' '; //intially no visited vertices

        q.push(vertices[startIndex].getData()); //push the first vertex to the queue

        int i = 0;              //i used to index the visited array
        visited[i] = q.front(); //mark the front element as visited
        i++;

        int currIndex = startIndex; //currIndex used to index the vertices array

        while (!q.empty())
        {
            vertices[currIndex].pushEdgesToQ(q, visited, i); //push all the adjacent vertices of current vertex to the queue
            q.pop();                                         //and pop the current vertex

            if (q.empty() && i < count) //if a vertex has no adjacent vertices
            {                           //and not all the vertices are visited
                for (int j = 0; j < count; j++)
                {
                    //check which vertex hasn't been visited
                    bool visit = contains(visited, vertices[j].getData());

                    if (!visit)
                    {
                        currIndex = j;
                        visited[i] = vertices[j].getData(); //mark the unvisited vertex as visited
                        q.push(visited[i]);                 //and push it into the queue
                        i++;
                        break;
                    }
                }
            }

            else //else get the next adjacent vertex's index to find their edges
            {
                currIndex = getNextVertexIndex(q.front());
                if (currIndex == -1)
                    break;
            }
        }

        //print the visited array to get the bfs
        cout << "\nBfs: ";
        for (int j = 0; j < count; j++)
            cout << visited[j] << " ";
    }
};

int main()
{
    char vertices[5] = {'A', 'B', 'C', 'D', 'E'};
    DirectedGraph *g = new DirectedGraph(5, vertices);

    g->addEdgeFrom('A', 'C');
    g->addEdgeFrom('A', 'B');
    g->addEdgeFrom('B', 'D');
    g->addEdgeFrom('B', 'A');
    g->addEdgeFrom('C', 'A');
    g->addEdgeFrom('C', 'D');
    g->display();

    g->bfs(0);

    delete g;

    return 0;
}