#include <iostream>
using namespace std;

struct node
{
    int data;
    node *next;
};

class QueueLinkedList
{
private:
    node *front;
    node *rear;
    int totalLength;
    int currLength;

    node *createNode(int value)
    {
        node *newNode = new node;
        newNode->data = value;
        newNode->next = NULL;
        return newNode;
    }

public:
    QueueLinkedList()
    {
        front = rear = NULL;
        totalLength = 10;
        currLength = 0;
    }
    ~QueueLinkedList()
    {
        node *iter = front;
        rear = NULL;
        while (iter != NULL)
        {
            iter = front->next;
            delete front;
            front = iter;
        }
    }

    void enqueue(int value)
    {
        if (currLength == totalLength)
        {
            cout << "Overflow" << endl;
            return;
        }

        if (rear == NULL)
        {
            rear = createNode(value);
            front = rear;
            currLength++;
            return;
        }

        node *eqNode = createNode(value);
        rear->next = eqNode;
        rear = eqNode;
        currLength++;
    }

    void dequeue()
    {
        if (rear == NULL)
        {
            cout << "Underflow" << endl;
            return;
        }

        node *dqNode = front;
        front = front->next;

        if (dqNode == rear)
            rear = front;

        delete dqNode;
        dqNode = NULL;

        currLength--;
    }

    int peek()
    {
        if (front == NULL)
            return -1;

        return front->data;
    }

    void display()
    {
        if (front == NULL)
            return;

        node *iter = front;

        while (iter != NULL)
        {
            cout << iter->data << " ";
            iter = iter->next;
        }

        cout << endl;
    }
};

int main()
{
    QueueLinkedList Q;

    for (int i = 1; i < 10; i++)
        Q.enqueue(i);

    Q.display();

    for (int i = 0; i < 5; i++)
        Q.dequeue();

    Q.display();

    return 0;
}