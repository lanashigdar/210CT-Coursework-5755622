#include <iostream>
#include <string>

using namespace std;

string reverseString(string sentence, int starting, int ending)
{
    int i = starting;               //start of string
    int j = ending;                 //end of string
    char temp;

    while (i <= j)
    {
        temp = sentence[i];         //swap positioning of characters from start to end
        sentence[i] = sentence[j];  //to get a reversed string
        sentence[j] = temp;
        i++;
        j--;
    }
    return sentence;
};

string reverseSentence(string sentence)
{
    int length = sentence.length();
    int starting = 0;                    //starts at position 0
    int ending;

    for (int i = 0; i <= length; i++)   //increment to given length
    {
        if(sentence[i] == ' ' || sentence[i] == '\0') //if blank space or at end of string
        {
            ending = i-1;
            sentence = reverseString(sentence, starting, ending);
            starting = i+1;
        }
    }
    sentence = reverseString(sentence, 0, length-1);
    return sentence;
};

void W3_1()
{
    string sentence = "my name is Lana";
    cout << reverseSentence(sentence);

}
