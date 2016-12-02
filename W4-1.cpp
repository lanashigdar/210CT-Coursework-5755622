#include <iostream>

using namespace std;

bool binarySearch (int aList[], int low, int high, int starting, int ending); //declaring function

void W4_1()
{
    int l;          //declaring user inputs
    int low;
    int high;
    int starting;
    int ending;

    cout << "input the length of the list ";
    cin >> l;                               //input integer of list length

    int aList[l];                           //declaring the list with length

    cout << "input sorted list integers ";  //inputting individual integers for length
    for (int i = 0; i < l; i++){            //starting at 0, amount less than the length
    cin >> aList[i];
    }

    cout << "input lowest interval value ";
    cin >> low;                             //low interval value

    cout << "input highest interval value ";
    cin >> high;                            //high interval value

    cout << "input starting position ";
    cin >> starting;                        //starting position

    cout << "input ending position ";
    cin >> ending;                          //ending position

    bool output = binarySearch(aList, low, high, starting, ending); //run function for results


    cout << output;     //printing result to screen
}

bool binarySearch (int aList[], int low, int high, int starting, int ending)
{
    if (starting > ending)
    {
        return false;               //fail condition
    }
    else {
    int midPosition = (starting + ending) / 2;  //finding middle of array

    int middle = aList[midPosition];            //storing variable

    if (middle >= low && middle <= high)
    {
        return true;                            //success condition
    }
    else if (middle < low)
    {
        binarySearch (aList, low, high, midPosition+1, ending);
        /*if true, ignores integers in the list below the low interval and
        midPosition moves up from middle value*/
    }
    else if (middle > high)
    {
        binarySearch (aList, low, high, starting, midPosition-1);
        /*if true, ignores integers in the list above the high interval and
        midPosition moves down from middle value*/
    }
}
}

