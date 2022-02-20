#include <iostream>
using namespace std;

class ArrayStack
{
private:
    int *arr;
    int size;
    int dataCount;

public:
    ArrayStack(int s = 0)
    {
        size = s;
        arr = new int[size];

        for (int i = 0; i < size; i++)
            *(arr + i) = -1;

        dataCount = 0;
    }

    ~ArrayStack() { delete[] arr; }

    bool isEmpty()
    {
        if (dataCount)
            return false;

        return true;
    }

    bool isFull()
    {
        if (dataCount == size)
            return true;

        return false;
    }

    void push(int value)
    {
        if (isFull())
        {
            cout << "Stack overflows" << endl;
            return;
        }

        *(arr + dataCount) = value;
        dataCount++;
    }

    void pop()
    {
        if (isEmpty())
        {
            cout << "Stack underflows" << endl;
            return;
        }

        dataCount--;
        *(arr + dataCount) = -1;
    }

    int getTop()
    {
        return *(arr + dataCount);
    }

    void display()
    {
        for (int i = 0; i < size; i++)
            cout << *(arr + i) << " ";

        cout << endl;
    }
};

int main()
{
    ArrayStack stack(5);
    stack.display();

    stack.push(1);
    stack.push(2);
    stack.push(3);
    stack.push(4);
    stack.push(5);

    stack.display();

    stack.push(6);

    stack.pop();
    stack.pop();
    stack.pop();
    stack.pop();
    stack.pop();

    stack.display();

    stack.pop();

    stack.push(1);
    stack.push(2);

    stack.display();

    return 0;
}