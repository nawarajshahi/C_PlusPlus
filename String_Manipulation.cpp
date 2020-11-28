//
// Created by Nawaraj Shahi on 6/3/20.
/*
Write a program that will read in a line of text and output the number of words in the line and
the number of occurrences of each letter. 
*/

#include <iostream>
#include <string>
#include <cctype>

using namespace std;

string lowerString(string userInput);
int numLettersAndWords( string userInput, int numLettersArr[]);
void printNumLetters(int lettersArr[], int arrSize);

const int numsOfAlphabets = 26;

int main()
{
    string userInput, lowerUserInput;

    int wordsCount;
    int lettersArray[numsOfAlphabets] = {0};

    cout << "Please enter a line of text: " << endl;
    getline(cin, userInput);

    lowerUserInput = lowerString(userInput); //converts the line of text to all lowercase

    wordsCount = numLettersAndWords(lowerUserInput, lettersArray);
    cout << wordsCount << " \twords" << endl;

    printNumLetters(lettersArray, numsOfAlphabets);

    return 0;
}

string lowerString(string userInput)
{
    int index;
    string lowerLetters;
    for (index = 0; index < userInput.length(); index ++){
        lowerLetters += tolower(userInput[index]);
    }
    return lowerLetters;
}

int numLettersAndWords( string userInput, int numLettersArr[])
{
    int numWords = 1, index;

    for (index = 0; index < userInput.length(); index +=1){
        if ((userInput[index] != ' ') && (userInput[index] >= 'a') && (userInput[index] <= 'z')){
            numLettersArr[userInput[index] - 'a']++;
        }else if (userInput[index] == ' '){
            numWords +=1;
        }
    }
    return numWords;
}

void printNumLetters(int lettersArr[], int arrSize)
{
    int index;
    for (index = 0; index < arrSize; index +=1){
        if(lettersArr[index] !=0){
            cout << lettersArr[index] << "\t" << char(index + 'a') << endl;
        }
    }
}