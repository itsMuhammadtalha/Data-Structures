#include <iostream>
using namespace std;

struct Node
{
    int data;
    Node *next;
    Node *prev;
};

class List
{
private:
    Node *head;
    Node *current;

public:
    List() : head(NULL), current(NULL) {}
    ~List()
    {
        current = head;
        while (current != NULL)
        {
            current = head->next;
            delete head;
            head = current;
        }
        cout << "The list has now been deleted" << endl;
    }

    void insertAfter(int count, int key, int value)
    {
        if (head == NULL)
        {
            head = new Node;
            head->data = value;
            head->next = NULL;
            head->prev = NULL;
        }

        else
        {
            Node *temp = NULL;
            current = head;
            int myCount = 0;

            while (current != NULL)
            {
                if (key == current->data)
                {
                    myCount++;
                    if (myCount == count)
                    {
                        temp = new Node;
                        temp->data = value;
                        temp->next = current->next;
                        temp->prev = current;
                        current->next = temp;

                        if (temp->next != NULL)
                            temp->next->prev = temp;

                        return;
                    }
                }

                current = current->next;
            }

            cout << "The key wasn't found" << endl;
        }
    }

    void addHeadNode(int value)
    {
        if (head == NULL)
        {
            head = new Node;
            head->data = value;
            head->next = NULL;
            head->prev = NULL;
        }

        else
        {
            current = NULL;
            current = new Node;
            current->data = value;
            current->prev = NULL;
            current->next = head;
            head->prev = current;
            head = current;
        }
    }

    void removeNode(int count, int key)
    {
        if (head == NULL)
            cout << "List is empty" << endl;

        else
        {
            current = head;
            int myCount = 0;

            while (current != NULL)
            {
                if (current->data == key)
                {
                    myCount++;
                    if (myCount == count)
                    {
                        if (current->prev != NULL)
                            current->prev->next = current->next;

                        if (current->next != NULL)
                            current->next->prev = current->prev;

                        if (current->prev == NULL)
                            head = NULL;

                        delete current;
                        current = NULL;
                        return;
                    }
                }

                current = current->next;
            }

            cout << "Key wasn't found" << endl;
        }
    }

    void Display()
    {
        if (head == NULL)
            cout << "The list is empty" << endl;

        else
        {
            current = head;
            while (current != NULL)
            {
                cout << current->data << " ";
                current = current->next;
            }
            cout << endl;
        }
    }
};

int main()
{
    List list;
    list.addHeadNode(4);
    list.Display();
    list.removeNode(1, 4);
    list.Display();
    list.addHeadNode(4);
    list.Display();

    return 0;
}
