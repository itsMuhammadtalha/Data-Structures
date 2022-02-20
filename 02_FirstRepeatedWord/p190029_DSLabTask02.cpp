#include <iostream>
using namespace std;

string getRepeated(string arr[])
{
    string result;
    int j = 0;
    for (int i = 0; *(arr + i) != "\0"; i++)
    {
        result = *(arr + i);
        j = i + 1;

        for (j; *(arr + j) != "\0"; j++)
        {
            if (result == *(arr + j))
            {
                return result;
            }
        }

        j = 0;
    }
    return "No words were repeated";
}

int main()
{
    string arr[13] = {"He", "is", "in", "Peshawar", "Ali", "came", "to",
                      "Peshawar", "yesterday", "She", "is", "in", "Islamabad"};

    cout << getRepeated(arr) << endl;

    return 0;
}