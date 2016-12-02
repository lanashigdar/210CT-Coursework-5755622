#include <iostream>
#include <string>

using namespace std;

string removeVowel(string word);

void W3_3()
{
    string word;

    cout << "Enter a word ";
    cin >> word;
    cout << "Word without vowels is " << removeVowel(word);

}

string removeVowel(string word)
{
    int length = word.length();
    char isVowel = word[0];     //chars in string

    if (length == 0)
    {
        return word;
    }

    else {

        if (isVowel == 'a'|| isVowel == 'e' || isVowel == 'i' || isVowel == 'o' || isVowel == 'u' || isVowel == 'A' || isVowel == 'E' || isVowel == 'I' || isVowel == 'O' || isVowel == 'U')
        {
            return removeVowel(word.substr(1));     //remove vowel then do function from next position
        }
        else
        {
            return word[0] + removeVowel(word.substr(1));   //return non-vowel to string
        }
    }
}
