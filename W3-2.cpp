#include <iostream>

using namespace std;

bool primeCheck(int n, int divisor);

void W3_2()
{
    int n;              //integer to check if prime
    int divisor = 2;    //begins at 2, will increment

    cout << "Enter number: ";
    cin >> n;

    cout << boolalpha << "The number is:  " << primeCheck(n, divisor);

}

bool primeCheck(int n, int divisor)
{
    if (n <= 1)
    {
        cout << "Invalid number. ";
        return false;               //fail condition if n is invalid
    }

    int remainder = n % divisor;    //to return an int that is not a floating number

    if (divisor == n)
    {
        return true;                //n is a prime number
    }
    else if (remainder == 0)
    {
        return false;               //n is not a prime number
    }
    else
    {
        primeCheck(n,divisor+1);    //indenting the divisor by 1 every run time, then run function again
    }
}
