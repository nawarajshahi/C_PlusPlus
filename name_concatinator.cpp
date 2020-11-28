//
// Created by Nawaraj Shahi on 5/24/20.
/*
Write a program that reads a person’s name in the following format:
first name, then middle name or initial, and then last name.
The program then outputs the name in the following format:
Last_Name, First_Name Middle_Initial.

For example, the input
Mary Average User
should produce the output:
User, Mary A. 
*/

#include <iostream>
#include <string>

using namespace std;

void readName(string &firstName, string &middleName, string &lastName );
void printName(string firstName, string middleName, string lastName);

int main()
{
    string firstName, middleName, lastName;

    readName(firstName, middleName, lastName);
    printName(firstName, middleName, lastName);

    return 0;
}
void readName(string &firstName, string &middleName, string &lastName )
{
    cout << "Please enter your first, middle, and last name separated by a space: ";
    cin >> firstName >> middleName >> lastName;
}

void printName(string firstName, string middleName, string lastName)
{
    string middleInitial;

    middleInitial = middleName[0];
    cout << lastName << ", " << firstName << " " << middleInitial << "." << endl;

}