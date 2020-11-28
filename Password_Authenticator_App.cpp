//
// Created by Nawaraj Shahi on 5/23/20.
/*
 Traditional password entry schemes are susceptible to "shoulder surfing" in which an attacker
watches an unsuspecting user enter their password or PIN number and uses it later to gain
access to the account. One way to combat this problem is with a randomized challengeresponse system. In these systems the user enters different information every time, based on a
secret in response to a randomly generated challenge.
Consider the following scheme, in which the password consists of a five-digit PIN number (00000
to 99999). Each digit is assigned a random number that is 1, 2, or 3. The user enters the random
numbers that correspond to their PIN instead of their actual PIN numbers.

For example, consider an actual PIN number of 12345. To authenticate the user would be
presented with a screen such as:
    PIN: 0 1 2 3 4 5 6 7 8 9
    NUM: 3 2 3 1 1 3 2 2 1 3
The user would enter 23113 instead of 12345. This doesn’t divulge the password even if an
attacker intercepts the entry because 23113 could correspond to other PIN numbers, such as
69440 or 70439.
The next time the user logs in, a different sequence of random numbers would be generated,
such as:
    PIN: 0 1 2 3 4 5 6 7 8 9
    NUM: 1 1 2 3 1 2 2 3 3 3
    
Write a program to simulate the authentication process. Store an actual 5-digit PIN number in
your program (make one up, and store it as a constant). The program should use an array to
assign random numbers to the digits from 0 to 9. Output the random digits to the screen, input
the response from the user, and output whether or not the user’s response correctly matches
the PIN number.
 */

#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

const int maxSize = 10;
const int maxPinLength = 5;

void readRandArray(int arr[], int arrSize);
void printInfo(int arr1[], int arr2[], int arrSize);
void strToIntArray(int arr[], string str, int pinLength);
int charToDigit(char digit);
bool isCorrectPin(int userInputArr[], int actualPinArr[], int randMap[], int pinLength);

int main()
{
    const int OriginalPin = 61195;
    string userInput;
    bool isCorrect;
    int mainPin = OriginalPin;
    int pin[maxSize] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
    int randMap[maxSize];

    cout << "Please enter your PIN according to the following mapping:" << endl;
    readRandArray(randMap, maxSize);

    printInfo(pin, randMap, maxSize);

    cin >> userInput;

    int userInputArr[maxPinLength];
    int actualPinArr[maxPinLength];

    strToIntArray(userInputArr, userInput, maxPinLength);
    strToIntArray(actualPinArr, to_string(mainPin), maxPinLength);

    isCorrect = isCorrectPin(userInputArr, actualPinArr, randMap, maxPinLength);

    if (isCorrect)
        cout << "Your PIN is correct" << endl;
    else
        cout << "Your PIN is not correct" << endl;

}
void readRandArray(int arr[], int arrSize)
{
    srand(time(0));
    const int highestRand = 3;
    int randDig;
    for (int i = 0; i <arrSize; i+=1){
        randDig = (rand()%highestRand) +1;
        arr[i] = randDig;
    }
}
void printInfo(int arr1[], int arr2[], int arrSize)
{
    string pin, num;
    for (int i = 0; i < arrSize; i +=1){
        pin +=to_string(arr1[i])+ "\t";
        num +=to_string(arr2[i]) + "\t";
    }
    cout << "PIN: \t" << pin << endl;
    cout << "NUM: \t" << num << endl;
}
void strToIntArray(int arr[], string str, int pinLength)
{
    int index;
    for (index = 0; index < pinLength; index +=1){
        arr[index]= charToDigit(str[index]);
    }
}
int charToDigit(char digit)
{
    return digit - '0';
}
bool isCorrectPin(int userInputArr[], int actualPinArr[], int randMap[], int pinLength)
{
    int index;
    for (index = 0; index < pinLength; index +=1){
        if (randMap[actualPinArr[index]]!=userInputArr[index])
            return false;
    }
    return true;
}