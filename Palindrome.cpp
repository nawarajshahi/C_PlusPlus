//
// Created by Nawaraj Shahi on 5/23/20.
//

#include <iostream>
#include <cctype>
using namespace  std;
bool isPalindrome(string str);
string lowerCaseWord(string str);
void reversed( string & str);

int main()
{
    string userInputWord;

    cout << "Please enter a word: ";
    cin >> userInputWord;

    if(isPalindrome(userInputWord)){
        cout << userInputWord << " is a palindrome" << endl;
    } else
        cout << userInputWord << " is not a palindrome" << endl;
}

bool isPalindrome(string str)
{
    string lowerWord, reverse;

    lowerWord = lowerCaseWord(str);
    reverse = lowerWord;

    reversed(reverse); //reverses the word that has all lowercase characters

    return (lowerWord == reverse);

}
string lowerCaseWord(string str)
{
    string lower;
    int index;
    for (index = 0; index < str.length(); index +=1){
        lower+= tolower(str[index]);
    }
    return lower;
}

void reversed( string & str){
    string reversed;
    int index, newIndex;
    string temp;

    for (index = str.length()-1, newIndex = 0; index >=0; index -=1, newIndex +=1){
        reversed +=str[index];
    }
    str = reversed;
}