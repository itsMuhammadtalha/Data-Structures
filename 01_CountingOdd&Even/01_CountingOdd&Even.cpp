#include <iostream>
using namespace std;

void numCount(char *ch, int size)
{
    int leftCount = 0;
    int rightCount = 0;

    for (int i = 0; i < size; i++)
    {
        int j = i;
        if (*(ch + i) == '.')
        {
            j++;
            for (j; *(ch + j) != '\0'; j++)
            {
                rightCount++;
            }
            break;
        }
        else if (*(ch + i) != '.')
        {
            leftCount++;
        }
    }

    cout << "left Count = " << leftCount << endl;
    cout << "right Count = " << rightCount << endl
         << endl;
}

void checkOddEven(char *ch, int size)
{
    int leftOddCount = 0;
    int leftEvenCount = 0;
    int rightOddCount = 0;
    int rightEvenCount = 0;
    int j;

    for (int i = 0; i < size; i++)
    {
        j = i;
        if (*(ch + i) == '.')
        {
            j++;
            for (j; *(ch + j) != '\0'; j++)
            {
                if (*(ch + j) % 2 == 0)
                    rightEvenCount++;

                else
                    rightOddCount++;
            }
            break;
        }
        else
        {
            if (*(ch + i) % 2 == 0)
                leftEvenCount++;

            else
                leftOddCount++;
        }
    }

    cout << "Left Even Count = " << leftEvenCount << endl;
    cout << "Left Odd Count = " << leftOddCount << endl
         << endl;
    cout << "Right Even Count = " << rightEvenCount << endl;
    cout << "Right Odd Count = " << rightOddCount << endl;
}
int main()
{
    char *ch = "1232333.3422324234";
    int size = 0;

    //storing size of array in variable
    for (int i = 0; *(ch + i) != '\0'; i++)
        size++;

    numCount(ch, size);
    checkOddEven(ch, size);

    return 0;
}