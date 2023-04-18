//! Question : Convert the number to words, ex-> 123 o/p-> one two three
#include <iostream>
using namespace std;

class convert
{

public:
    void extdigit(int);
    void num_to_word(int);
    int reverse(int digit);
};

int convert ::reverse(int digit)
{
    int c = 1, rem, rev;

    while (digit != 0)
    {
        rem = digit % 10;
        rev = rev * 10 + rem;
        c *= 10;
        digit = digit / 10;
    }
    return rev;
}

void convert ::extdigit(int num)
{
    int rem;

    while (num != 0)
    {
        rem = num % 10;
        num_to_word(rem);
        num = num / 10;
    }
}

void convert ::num_to_word(int r)
{
    if (r == 1)
    {
        cout << " one";
    }
    if (r == 2)
    {
        cout << " two";
    }
    if (r == 3)
    {
        cout << " three";
    }
    if (r == 4)
    {
        cout << " four";
    }
    if (r == 5)
    {
        cout << " five";
    }
    if (r == 6)
    {
        cout << " six";
    }
    if (r == 7)
    {
        cout << " seven";
    }
    if (r == 8)
    {
        cout << " eight";
    }
    if (r == 9)
    {
        cout << " nine";
    }
}

int main()
{
    int value;
    convert obj;
    cout << "Enter the number to be converted to words:\n";
    cin >> value;
    value = obj.reverse(value); //*value reverse is must else printing will be from R to L
    obj.extdigit(value);
    return 0;
}