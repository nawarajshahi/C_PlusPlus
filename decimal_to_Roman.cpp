//
// Created by Nawaraj Shahi on 4/25/20.
/*
In this question we will use a simplified version of the Roman Numerals System to represent
positive integers.
The digits in this system are I, V, X, L, C, D and M. Each digit corresponds to a decimal value, as
showed in the following table:
    Roman digit   I V  X L   C   D   M
    Decimal value 1 5 10 50 100 500 1000
*/

#include <iostream>
#include <string>
using namespace std;

int main()
{
    int user_INPUT, lessThan_FIVE = 0, fifth_VAL = 0, tenth_VAL=0;
    int fiftieth_VAL=0, hundredth_VAL=0, fiveHundredth_VAL=0, thousandth_VAL=0;
    string to_ROMAN = "";

    /*all the variables above except user_INPUT are initialized because uninitialized variable
     * later will affect COUNTER value in determining length of the roman numerals sequence
     */

    int original_INPUT;
    int COUNTER;

    cout << "Enter decimal number: ";
    cin >> user_INPUT;

    original_INPUT = user_INPUT; //Assigns user's entered value for it to be reused at the end of the program

    while (user_INPUT > 0)  //checks if user's value is >0
    {
        if (user_INPUT >= 1000){
            thousandth_VAL = user_INPUT/1000;   //checks # of 1000's in user's value
            user_INPUT %=1000;                  //Removes # of 1000's from user's value
        } else if (user_INPUT >=500){
            fiveHundredth_VAL = user_INPUT/500; //checks # of 500's in user's value
            user_INPUT %= 500;                  //Removes # of 500's from user's value
        } else if (user_INPUT >=100){
            hundredth_VAL = user_INPUT/100;     //Checks # of 100's in user's value
            user_INPUT %=100;                   //Removes # of 100's from user's value
        } else if (user_INPUT >=50){
            fiftieth_VAL = user_INPUT/50;          //Checks # of 50's in user's value
            user_INPUT %=50;                    //Removes # of 50's from user's value
        } else if (user_INPUT >=10){
            tenth_VAL = user_INPUT/10;          //Checks # of 10's in user's value
            user_INPUT %=10;                    //Removes # of 10's from user's value
        } else if (user_INPUT >=5){
            fifth_VAL = user_INPUT/5;           //Checks # of 5's in user's value
            user_INPUT %=5;                     //Removes # of 5's from user's value
        } else{
            lessThan_FIVE = user_INPUT;         // Assigns remainder of value that is <5 to the variable
            user_INPUT = 0;                     //Resets the user's value to 0 for loop termination
        }
    }
    /*The following counter variable determines the length of sequence that has to be displayed for the final roman
     * numerals equivalent value
     */
    COUNTER = thousandth_VAL + fiveHundredth_VAL + hundredth_VAL + fiftieth_VAL + tenth_VAL + fifth_VAL + lessThan_FIVE;

    while (COUNTER >0){
        if (thousandth_VAL > 0){
            to_ROMAN +="M";
            thousandth_VAL--;
        } else if (fiveHundredth_VAL >0){
            to_ROMAN +="D";
            fiveHundredth_VAL--;
        } else if (hundredth_VAL>0){
            to_ROMAN +="C";
            hundredth_VAL--;
        } else if (fiftieth_VAL >0){
            to_ROMAN +="L";
            fiftieth_VAL--;
        } else if (tenth_VAL >0){
            to_ROMAN +="X";
            tenth_VAL--;
        } else if (fifth_VAL >0){
            to_ROMAN +="V";
            fifth_VAL--;
        } else if (lessThan_FIVE >0){
            to_ROMAN +="I";
            lessThan_FIVE--;
        }
        COUNTER--;
    }
    cout << original_INPUT << " is " << to_ROMAN << endl;
    return 0;
}
