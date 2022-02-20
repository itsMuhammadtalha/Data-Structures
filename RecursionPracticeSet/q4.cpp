#include <iostream>
using namespace std;

bool isPalindrome(string str, int count = 0)
{
    if (str == "")
        return false;

    if (count == str.length() / 2)
        return true;

    if (str[count] == str[str.length() - count - 1])
        return isPalindrome(str, count + 1);

    return false;
}

int main()
{
    string str = "abracadabraarbadacarba";

    bool returnValue = isPalindrome(str);

    if (returnValue == true)
        cout << "True" << endl;
    if (returnValue == false)
        cout << "False" << endl;

    return 0;
}