//
// Created by Nawaraj Shahi on 4/30/20.
/*
Write	a	program	that	asks	the user	to	input	a	positive	integer	n,	and	print	all	of	the	numbers	
from	1	to	n that	have	more	even	digits	than	odd	digits.
*/
#include <iostream>
using namespace std;

int main()
{
    int evensCount, oddsCount, user_input, counter, newNum, digit;
    cout << "This program accepts a positive integer and \n"
            " and prints all the numbers from 1 to input number \n"
            " that have more even digits than odd digits" << endl;

    cout << "Please input a positive integer: ";
    cin >> user_input;

    for(counter = 1; counter <=user_input; counter++){
        //initialize evensCount and oddsCount so that it resets every
        //time a new number is checked for conditions mentioned below
        evensCount = 0;
        oddsCount = 0;

        //copy counter
        newNum = counter;

        //check if the copied number is >0
        while (newNum >0){
            //check each digit of the number
            digit = newNum %10;

            //check if the digit(s) of the number is odd or even and increment accordingly
            if (digit %2 ==0){
                evensCount +=1;
            } else{
                oddsCount +=1;
            }
            //reduce the copied number
            newNum /=10;
        }

        //print the number if it has more even digits than odd digits
        if (evensCount > oddsCount)
            cout << counter << endl;
    }
    return 0;
}

