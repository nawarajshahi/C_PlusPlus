//
// Created by Nawaraj Shahi on 5/23/20.
/*
Write a program that reads in a line of text and outputs the line with all the digits in all integer
numbers replaced with 'x'. 
*/

#include <iostream>
#include <string>
using namespace std;

void redactUserInput (string &userInput);
bool isWordInt (string currWord);
void redactNum(string &currWord);

int main()
{
    string userInput;

    cout << "Please enter a line of text:" << endl;
    getline(cin, userInput);

    redactUserInput(userInput);

    cout << userInput << endl;

    return 0;
}

void redactUserInput(string &userInput)
{
    int index=0;
    string currWord, redactedLine;

    for(index = 0; index < userInput.length(); index +=1)
    {
        //accumulate each characters until space is encountered
        if(userInput[index] != ' ')
            currWord += userInput[index];

        if ((userInput[index] == ' ') || (index == userInput.length()-1)){
            //code above checks for space to separate word

            //code below determines if the word has all numbers or combination of integers and letters
            if(isWordInt(currWord)){
                //if word has all integers then it will call the redact function
                //in order to redact these integers
                redactNum(currWord);
            }

            //once word is determined for redaction eligibility, redactedLine then
            // concatenates the word to it
            redactedLine +=currWord;
            currWord = "";          //resets the currentWord

            /*Space placement needs to be identified once each word is concatenated to the
             * redactLine. Also, spaces cannot be provided when index reaches the length
             * of the given line of text
            */

            if (index < userInput.length()-1)
                redactedLine += " ";
        }
    }
    userInput = redactedLine;
}

void redactNum(string &currWord)
{
    int index;
    string redacted;
    for (index = 0; index < currWord.length(); index +=1){
        redacted += 'x';
    }
    currWord = redacted;
}

bool isWordInt (string currWord)
{
    int index;
    for (index = 0; index < currWord.length(); index +=1){
        if((currWord[index] < '0') || (currWord[index] >'9'))
            return false;
    }
    return true;
}