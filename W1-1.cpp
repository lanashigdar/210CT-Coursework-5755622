#include <iostream>
#include <stdlib.h> //for rand and srand
#include <time.h> // for time

using namespace std;

void randomShuffle(int arr[],int length);

void W1_1()
{
    int numbers[] = {5,3,8,6,1,9,2,7};                  //array of numbers
    int length = sizeof(numbers) / sizeof(numbers[0]);  //stating length

    randomShuffle(numbers,length);                      //call function
}

void randomShuffle(int arr[],int length)
{
    srand(time(NULL));                  //seeds so array is different, seeds compared to
                                        // current time on pc
    for ( int i = 0; i < length; i++)   //if number < length, add one
    {
        int n = i+rand() % (length-i);  //n is length
        int temp = arr[i];              //swapping i with position of n
        arr[i] = arr[n];
        arr[n] = temp;
    }                                   //continues until there is nothing beyond current length
                                        //therefore, the entire array has been shuffled
    for (int i = 0; i < length; i++)
    {
        cout << arr[i];                 //printing new array
    }
}
