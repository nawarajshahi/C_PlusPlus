//
// Created by Nawaraj Shahi on 4/25/20.
/*
Write a program that reads from the user a positive integer (in a decimal representation), and
prints its binary (base 2) representation.
*/

#include <iostream>
using namespace std;

int main() {
    int dec_number, decimal_counter, decimal_val, original_Dec_Val;
    int multiplier = 1, binary_val = 0, binary_counter, remainder;
    cout << "Please enter a decimal number: ";
    cin >> dec_number;

    original_Dec_Val = dec_number;
    decimal_val = dec_number;
    decimal_counter = 0;

    while (dec_number >=1) {
        dec_number /= 2;
        decimal_counter += 1;
    }

    int inner_counter;
    for (binary_counter = 0; binary_counter < decimal_counter; binary_counter++){
        remainder = decimal_val % 2;    //finds the remainder from the decimal-value

        /*Following for loop determines whether the remainder falls in
         * 1's, 10's, 100's 1000's, and so on...
         */
        for (inner_counter = 0; inner_counter < binary_counter; inner_counter++){
            multiplier *=10;
        }
        binary_val +=remainder * multiplier;
        multiplier = 1;  //resets the value of multiplier for next remainder digit's placement in the binary number
        decimal_val /=2; //reduces the value of original decimal value

    }

    cout << "The binary representation of " << original_Dec_Val << " is: " << binary_val << endl;

    return 0;
}