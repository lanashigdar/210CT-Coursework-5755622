#include <iostream>

void longAsc(int sequence[], int seqLength);

using namespace std;

void W5_1()
{
    int sequence[] = {1,3,8,9,2,5,3,4,6};
    int seqLength = sizeof(sequence) / sizeof(sequence[0]);

    longAsc(sequence, seqLength);

}

void longAsc(int sequence[], int seqLength)
{
    int startIndex = 0;
    int endIndex;
    int length = 0;
    int maxLength = 0;

    for (int i = 0; i < seqLength; i++)         //i stop for length of sequence
    {
        for (int j = i+1; j < seqLength; j++)     //start from i for remainder of sequence
        {
            if (sequence[j] > sequence[j-1])    //if current value > previous value
            {
                length = length + 1;            //increments length
            }
            else
            {
                break;
            }
        }
        if (length > maxLength)
        {
            startIndex = i;                 //current position
            endIndex = i + length;          //count length to find end
            maxLength = length;

        }
        length = 0;                         //reset for next iteration
    }
    for (int i = startIndex; i <= endIndex; i++) //print from start of subsequence to end of subsequence
    {
        cout << sequence[i];
    }

}
