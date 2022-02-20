#include <iostream>
#include <cmath>
using namespace std;

struct Node
{
    int data;
    Node *next;
};

class List
{
public:
    Node *head;
    Node *current;

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
    }

    /*void insertAfter(int count, int key, int value)
    {
        if (head == NULL)
        {
            head = new Node;
            head->data = value;
            head->next = NULL;
        }

        else
        {
            Node *temp = NULL;
            current = head;
            int myCount = 0;
            while (current != NULL)
            {
                if (current->data == key)
                {
                    myCount++;
                    if (myCount == count)
                    {
                        temp = new Node;
                        temp->data = value;
                        temp->next = current->next;
                        current->next = temp;
                        return;
                    }
                }

                current = current->next;
            }
            cout << "Key wasn't found" << endl;
        }
    }

    void addHeadNode(int value)
    {
        if (head == NULL)
        {
            head = new Node;
            head->data = value;
            head->next = NULL;
        }

        else
        {
            current = NULL;
            current = new Node;
            current->data = value;
            current->next = head;
            head = current;
        }
    }

    void removeNode(int key)
    {
        if (head == NULL)
            cout << "List is empty" << endl;

        else
        {
            current = head;
            Node *temp = NULL;

            while (current != NULL)
            {
                if (current->data == key)
                {
                    temp->next = current->next;
                    delete current;
                    current = NULL;
                    return;
                }

                temp = current;
                current = current->next;
            }

            cout << "The key wasn't found" << endl;
        }
    }*/

    void addNode(int value)
    {
        if (head == NULL)
        {
            head = new Node;
            head->data = value;
            head->next = NULL;
            return;
        }

        current = head;

        while (current->next != NULL)
            current = current->next;

        Node *temp = new Node;
        temp->data = value;
        temp->next = current->next;
        current->next = temp;
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
        }
        cout << endl;
    }
};

List *addLists(Node *head1, Node *head2)
{

    if (head1 == NULL || head2 == NULL)
    {
        cout << "Empty list found" << endl;
        return NULL;
    }

    Node *current1 = NULL;
    Node *current2 = NULL;

    int list1Size = 0;
    int list2Size = 0;

    current1 = head1;
    current2 = head2;

    //storing the size of lists
    while (current1 != NULL || current2 != NULL)
    {
        if (current1 != NULL)
        {
            list1Size++;
            current1 = current1->next;
        }

        if (current2 != NULL)
        {
            list2Size++;
            current2 = current2->next;
        }
    }

    int *arr1 = new int[list1Size];
    int *arr2 = new int[list2Size];

    current1 = head1;
    current2 = head2;
    int i = 0;
    int j = 0;

    //storing lists data in arrays
    while (current1 != NULL || current2 != NULL)
    {
        if (current1 != NULL)
        {
            *(arr1 + i) = current1->data;
            i++;
            current1 = current1->next;
        }
        if (current2 != NULL)
        {
            *(arr2 + j) = current2->data;
            j++;
            current2 = current2->next;
        }
    }

    int firstListNumber = 0;
    int secondListNumber = 0;

    //converting arrays to respective integers
    for (int i = 0; i < list1Size; i++)
    {
        *(arr1 + i) = *(arr1 + i) * pow(10, list1Size - i - 1) + 0.5;
        firstListNumber += *(arr1 + i);
    }

    for (int i = 0; i < list2Size; i++)
    {
        *(arr2 + i) = *(arr2 + i) * pow(10, list2Size - i - 1) + 0.5;
        secondListNumber += *(arr2 + i);
    }

    int result = 0;
    //adding integers to result
    result = firstListNumber + secondListNumber;

    //storing the result in a new array
    int *arr3 = new int[list1Size + list2Size];
    int k = 0;
    while (result != 0)
    {
        *(arr3 + k) = result % 10;
        result /= 10;
        k++;
    }
    *(arr3 + k) = -1;

    //adding nodes to the new list with the new array data
    List *newList = new List;
    while (k > 0)
    {
        newList->addNode(*(arr3 + k - 1));
        k--;
    }

    delete[] arr1;
    delete[] arr2;
    delete[] arr3;
    return newList;
}

int main()
{
    List *list1 = new List;
    List *list2 = new List;
    List *list3 = new List;
    list1->addNode(9);
    list1->addNode(9);
    list1->addNode(9);
    list1->addNode(9);

    list2->addNode(9);
    list2->addNode(9);
    // list2->addNode(9);

    cout << "Inputs:" << endl;
    list1->Display();
    list2->Display();

    list3 = addLists(list1->head, list2->head);

    cout << "Output = ";
    list3->Display();

    delete list1;
    delete list2;
    delete list3;

    return 0;
}