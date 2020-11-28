//
// Created by Nawaraj Shahi on 4/26/20.
/*
Write two versions of a program that reads a sequence of positive integers from the user,
calculates their geometric mean, and print the geometric mean. 
*/

#include <iostream>
#include <cmath>

using namespace std;

int main()
{
    int user_INPUT, counter, sequence, total_VAL = 1;
    long double geometric_MEAN;

    /*Section a: First reads the length of the sequence and obtains that many sequences from the user
    * to determine geometric sequence
    */
    cout << "Section a"<< endl;

    cout << "Please enter the length of the sequence:";
    cin >> user_INPUT;
    if (user_INPUT <2){
        cout << "Length of sequence has to be more than 2, please try again!";
    }else{
        cout << "Please enter your sequence: " << endl;
        for (counter = 1; counter <= user_INPUT; counter++){
            cin >> sequence;
            total_VAL *=sequence;
        }
        geometric_MEAN = pow(total_VAL, 1.0/user_INPUT);
        cout << "The geometric mean is: " << geometric_MEAN << endl;
    }

    //Section b: Keeps reading the numbers until -1 is entered and determines geometric mean.
    cout << "Section b" << endl;

    int counter2, sequence2, total_VAL2 = 1;
    long double geometric_MEAN2=0;

    cout << "Please enter a non-empty sequence of positive integers, each one in a separate line. End your\n"
            "sequence by typing -1:" << endl;
    sequence2 = 1
    while(sequence2 !=-1){
        cin >> sequence2;
        if (sequence2 !=-1){
            counter2 +=1;
            total_VAL2 *=sequence2;
        }
    }
    geometric_MEAN2 = pow(total_VAL2, 1/(double )counter2);

    cout << "The geometric mean is: " << geometric_MEAN2 << endl;

    return 0;
}
