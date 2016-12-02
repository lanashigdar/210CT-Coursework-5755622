#include <iostream>
#include <cmath>

using namespace std;

int highestPerfectSquare(int parameter);    //declaring function

void W2_1()
{
    int parameter;

    cout << "enter positive integer " << endl;
    cin >> parameter;
    cout << "The highest perfect square is " << highestPerfectSquare(parameter) << endl;

}

int highestPerfectSquare(int parameter)
{
    int squareRoot = sqrt(parameter);                   //square rooting parameter
    int equalInt = floor(squareRoot);                   //floor dividing square root of parameter to get whole number
    int highestPerfectSquare = (equalInt * equalInt);   //equal whole ints multiplied by itself to get the
                                                        //highest perfect square
    return highestPerfectSquare;                        //return int to main

}
