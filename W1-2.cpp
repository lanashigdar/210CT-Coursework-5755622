#include <iostream>

using namespace std;

void W1_2()
{

    int zeroCount = 0;
    int number;

    cout << "input a number " << endl;
    cin >> number;

    if (number < 0){
        cout << "number is invalid " << endl;                  //fail condition

    }

    if (number == 5){
        cout << 1;                   //adds to count
    }

    for (int i = 5; number / i >= 1; i = i * 5){   //divides by factors of 5, also extra factors
        zeroCount = zeroCount + number / i;        //created by powers of 5 e.g 25
    }                                              //then adds number to zero counter

    cout << "the number of trailing zeros is: " << zeroCount;

}
