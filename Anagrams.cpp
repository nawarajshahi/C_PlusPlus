//
// Created by Nawaraj Shahi on 6/4/20.
/*
Write a program that determines if two strings are anagrams. The program should not be case
sensitive and should disregard any punctuation or spaces. 

Two strings are anagrams if the letters can be rearranged to form each other. For example,
“Eleven plus two” is an anagram of “Twelve plus one”. Each string contains one ‘v’, three ‘e’s,
two ‘l’s, etc.
*/

#include <iostream>
#include <cctype>
#include <string>

using namespace std;

const int lettersInAlphabets = 26;

void lowerString(string &userInput);
void numLetters(string input1, string  input2, int lettersArr1[], int lettersArr2[]);
bool isAnagram(int lettersArr1[], int lettersArr2[], int totalAlphabets);

int main()
{
    string input1, input2;
    string lowerInput1, lowerInput2;
    int lettersInInput1Arr[lettersInAlphabets] = {0}, lettersInInput2Arr[lettersInAlphabets]={0};

    cout << "PLease enter the first sentence: " << endl;
    getline(cin, input1);
    lowerInput1 = input1;

    cout << "Please enter the second sentence: " << endl;
    getline(cin, input2);
    lowerInput2 = input2;

    lowerString(lowerInput1);
    lowerString(lowerInput2);

    numLetters(input1, input2, lettersInInput1Arr, lettersInInput2Arr);

    if (isAnagram(lettersInInput1Arr, lettersInInput2Arr, lettersInAlphabets)) {
        cout << input1 << " AND " << input2;
        cout << " are anagrams" << endl;
    }else {
        cout << input1 << " AND " << input2;
        cout << " are not anagrams" << endl;
    }
}

void lowerString(string &userInput)
{
    int index;
    string lowerLetters;
    for (index = 0; index < userInput.length(); index ++){
        lowerLetters += tolower(userInput[index]);
    }
    userInput = lowerLetters;
}

void numLetters(string input1, string  input2, int lettersArr1[], int lettersArr2[])
{
    int index;
    for (index = 0; index < input1.length(); index +=1){
        if ((input1[index] >= 'a') && (input1[index] <= 'z')){
            lettersArr1[input1[index]-'a']++;
        }
    }

    for (index = 0; index < input2.length(); index +=1){
        if ((input2[index] >= 'a') && (input2[index] <= 'z')){
            lettersArr2[input2[index] - 'a']++;
        }
    }
}

bool isAnagram(int lettersArr1[], int lettersArr2[], int totalAlphabets){
  int index;
  for (index = 0; index < totalAlphabets; index +=1){
      if (lettersArr1[index] != lettersArr2[index])
          return false;
      else
          index ++;
  }
  return true;

}