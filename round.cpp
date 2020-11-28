//
// Created by Nawaraj Shahi on 4/20/20.
/*
Write	a	program	that	asks	the	user	to	enter	a	Real	number,	then	it	asks	the	user	to	enter	the
method	by	which	they	want	to	round	that	number	(floor,	ceiling	or	to	the	nearest	integer).	
The	program	will	then	print	the	rounded	result.
*/

#include <iostream>
using namespace std;

int main() {
    const int FLOOR_ROUND = 1;
    const int CEILING_ROUND = 2;
    const int ROUND = 3;

    double real_num, rounded_VAL, whole_POS, whole_NEG;
    int choice;

    cout << "Please enter a Real number: ";
    cin >> real_num;

    rounded_VAL = real_num;

    /*
     * Two lines of code below obtain the difference of user entered number and its integer value
     * which will be used to formulate if a number is a whole number for CEILING_ROUND and FLOOR ROUND.
     *
     * As for the ROUND method, these two codes will determine the value after the decimal fro the user
     * entered real number
     */

    whole_POS = real_num - (int)real_num;
    whole_NEG = (-1*real_num) - (int)(-1*real_num);

    cout << "Choose your rounding method: " << endl;
    cout << "1. Floor round" << endl;
    cout << "2. Ceiling round" << endl;
    cout << "3. Round to the nearest whole number" << endl;
    cin >> choice;

    switch (choice) {
        case FLOOR_ROUND:
            if (real_num < 0) { //checks to see if user entered number <0
                if (whole_NEG ==0){ //checks to see if user entered an integer
                    cout << rounded_VAL;
                } else {
                    rounded_VAL -=1;
                    cout << (int)rounded_VAL << endl;
                }

            } else if (real_num >=0){
                cout << (int)rounded_VAL << endl;
                //whether or not user entered number >=0 is a whole or a fraction
                //output will be the integer value of that number

            }
            break;
        case CEILING_ROUND:
            if ((real_num >=0)) {   //this checks if user entered number >= 0
                if (whole_POS ==0){ //checks to see if user entered a integer number
                    cout << (int) rounded_VAL << endl;
                }else {
                    rounded_VAL += 1;
                    cout << (int) rounded_VAL << endl;
                }


            } else if ((real_num <0)){
                cout << (int)rounded_VAL << endl;
                //whether or not user entered number <0 is an integer or fraction
                //output will be rounded to the ceiling integer value

            }
            break;
        case ROUND:
            if (real_num >=0){ //checks to see if user entered real number >=0
                if (whole_POS >= 0.5){  //checks to see if value after decimal is >= 0.5
                    rounded_VAL +=1;
                    cout << (int)rounded_VAL << endl;
                }else{
                    cout << (int)rounded_VAL << endl;
                    //whether or not user entered value >=0, is an integer
                    //or a fraction with decimal value <0.5
                    //output will be rounded to the floor value
                }
            }else if (real_num <0){
                if (whole_NEG >= 0.5){
                    rounded_VAL -=1;
                    cout << (int)rounded_VAL << endl;
                }else{
                    cout << (int)rounded_VAL << endl;
                }
            }

            break;
    }
    return 0;
}