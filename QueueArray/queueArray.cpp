#include <iostream>
using namespace std;

class QueueArray
{
private:
    int *que;
    int *rear;
    int *front;
    int size;
    int currLength;

public:
    QueueArray(int length = 0)
    {
        size = length;
        que = new int[size];
        currLength = 0;
        rear = NULL;
        front = NULL;
    }
    ~QueueArray() { delete[] que; }

    void enqueue(int value)
    {
        if (currLength == size)
        {
            cout << "Overflow" << endl;
            return;
        }

        if (rear == NULL)
        {
            rear = que;
            *rear = value;
            front = rear;
            currLength++;
            return;
        }

        if (rear == (que + size - 1))
            rear = que;
        else
            rear++;
        *rear = value;
        currLength++;
    }

    void dequeue()
    {
        if (currLength == 0)
        {
            cout << "Underflow" << endl;
            return;
        }

        if (front == rear)
        {
            front = NULL;
            rear = NULL;
            currLength--;
            return;
        }

        if (front == que + (size - 1))
            front = que;
        else
            front++;
        currLength--;
    }

    int
    peek()
    {
        if (currLength == 0)
            return -1;

        return *front;
    }

    void display()
    {
        if (currLength == 0)
            return;

        int *iter = front;

        while (iter != rear)
        {
            cout << *iter << " ";
            if (iter == que + (size - 1))
                iter = que;
            else
                iter++;
        }

        cout << *iter << " ";
        cout << endl;
    }
};

int main()
{
    QueueArray Q(5);

    Q.enqueue(1);
    Q.enqueue(2);
    Q.enqueue(3);
    Q.enqueue(4);
    Q.enqueue(5);

    Q.display();

    Q.dequeue();
    Q.dequeue();
    Q.dequeue();

    Q.display();

    return 0;
}