#include <iostream>
using namespace std;

class List
{
private:
    int *arr;
    int *current;
    int *end;
    int size;

public:
    List(int s = 0)
    {
        size = s;
        arr = new int[size];
        for (int i = 0; i < size; i++)
        {
            *(arr + i) = 0;
        }
        current = arr; //set to start
        end = arr + (size - 1);
    }

    ~List()
    {
        delete[] arr;
    }

    //moving current pointer location
    void start()
    {
        current = arr;
    }

    void tail()
    {
        current = end;
    }

    void next()
    {
        if (current == end)
            cout << "Error: End of the list" << endl;

        else
            current++;
    }

    void back()
    {
        if (current == arr)
            cout << "Error: Beginning of the list" << endl;
        else
            current--;
    }

    //operations on list
    void add(int num);
    void remove();
    bool find(int num);
    int get();
    void update(int num);
    void length();

    //ASSIGNMENT
    void mostFrequentElementsInSubArray(int left, int right, int frequency);

    //displaying list
    void display();
};

//operations on list
void List::add(int num)
{
    int *temp = NULL;
    temp = end;

    while (temp != current)
    {
        *temp = *(temp - 1);
        temp--;
    }

    *current = num;
    if (current != end)
        current++;
}

void List::remove()
{
    int *temp = NULL;
    temp = current + 1;

    while (true)
    {
        if (temp == end)
        {
            *(temp - 1) = *temp;
            *temp = 0;
            break;
        }
        *(temp - 1) = *temp;
        temp++;
    }
}

bool List::find(int num)
{
    int *temp = NULL;
    temp = arr;

    while (true)
    {
        if (*temp == num)
            return true;

        if (temp == end)
            return false;

        temp++;
    }

    return false;
}

int List::get()
{
    return *current;
}

void List::update(int num)
{
    *current = num;
    if (current != end)
        current++;
}

void List::length()
{
    int lengthCount = 0;

    for (int i = 0; i < size; i++)
    {
        if (*(arr + i) != 0)
            lengthCount++;
    }

    cout << "Number of items in list (length) = " << lengthCount << endl;
    cout << "Size of the list = " << size << endl;
    cout << "Remaining slots in the list = " << size - lengthCount << endl;
}

//ASSIGNMENT
void List::mostFrequentElementsInSubArray(int left, int right, int frequency)
{
    bool condition = (0 <= left && left <= right && right < size) && (2 * frequency >= right - (left + 1));

    if (!condition)
    {
        cout << "The condition wasn't met, returning." << endl;
        return;
    }

    int *tempArr = new int[size];
    int temp;

    //COPYING ELEMENTS OF LIST TO A TEMP ARRAY
    for (int i = left; i <= right; i++)
        *(tempArr + i) = *(arr + i);

    //ASCENDING SORTING OF TEMP ARRAY
    for (int i = left; i <= right; i++)
    {
        for (int j = i + 1; j <= right; j++)
        {
            if (*(tempArr + i) > *(tempArr + j))
            {
                temp = *(tempArr + i);
                *(tempArr + i) = *(tempArr + j);
                *(tempArr + j) = temp;
            }
        }
    }

    int currCount = 1;
    int j = 0;

    cout << "The most frequent elements in sub array are: ";

    for (int i = left; i <= right; i++)
    {
        j = i + 1;
        while ((*(tempArr + i) == *(tempArr + j)) && j <= right)
        {
            i++;
            j++;
            currCount++;
        }
        if (currCount >= frequency)
            cout << *(tempArr + i) << " ";

        currCount = 1;
    }

    cout << endl;
    delete[] tempArr;
}

//displaying the list
void List::display()
{
    for (int i = 0; i < size; i++)
        cout << *(arr + i) << " ";

    cout << endl;
}

int main()
{
    List *L = new List(8);

    L->add(2);
    L->add(2);
    L->add(3);
    L->add(3);
    L->add(3);
    L->add(4);
    L->add(5);
    L->add(6);

    L->display();
    L->mostFrequentElementsInSubArray(0, 3, 1);

    delete L;

    return 0;
}
