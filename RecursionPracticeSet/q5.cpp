#include <iostream>
using namespace std;

string reverse(string &str, int c)
{
    if (c >= str.length())
        return "";

    return str = reverse(str, c + 1) + str[c];
}

int main()
{
    string str = "Hello World";

    //second parameter for designated location to reverse from
    //only the reversed part will be stored in the string
    reverse(str, 0);

    cout << str << endl;

    return 0;
}