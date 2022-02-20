#include <iostream>
using namespace std;

struct node
{
    int data;
    node *next;
};

class Stack
{
private:
    node *top;

public:
    Stack() : top(NULL) {}
    ~Stack() {}

private:
    node *createNode(int value)
    {
        node *newNode = new node;
        newNode->data = value;
        newNode->next = NULL;
        return newNode;
    }

public:
    void push(int value)
    {
        if (top == NULL)
        {
            top = createNode(value);
            return;
        }

        node *newTop = createNode(value);
        newTop->next = top;
        top = newTop;
    }

    void pop()
    {
        if (top == NULL)
        {
            cout << "The stack is empty" << endl;
            return;
        }

        node *toPop = top;
        top = top->next;
        cout << "The popped value is: " << toPop->data << endl;
        delete toPop;
        toPop = NULL;
    }

    node *getTop()
    {
        return top;
    }

    bool compareTops(node *top1, node *top2)
    {
        if (top1->data == top2->data)
            return true;

        return false;
    }

    void display()
    {
        node *iter = top;
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
    Stack stack;
    stack.push(1);
    stack.push(2);

    stack.display();

    stack.pop();
    stack.pop();

    stack.display();

    stack.push(3);

    stack.display();

    return 0;
}