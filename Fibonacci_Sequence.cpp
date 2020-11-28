//
// Created by Nawaraj Shahi on 5/8/20.
/*
Write a program that prompts the user to enter a positive integer num, and then
prints the num’s elements in the Fibonacci sequence.
*/

#include <iostream>
using namespace std;

double fib(int n);

int main()
{
    int num;
    double Fibonacci;
    cout << "Please enter a positive integer: ";
    cin >> num;

    Fibonacci = fib(num);
    cout << Fibonacci << endl;

    return 0;
}

double fib(int n){
    int seq_counter;
    double nth_sequence, final_sequence;
    double first_sequence, second_sequence;

    if (n<=2){
        nth_sequence = 1;
    } else{
        first_sequence = 1;
        second_sequence = 1;
        for(seq_counter = 3; seq_counter <=n; seq_counter++){
            nth_sequence = first_sequence + second_sequence;
            first_sequence = second_sequence;
            second_sequence = nth_sequence;
        }
    }
    final_sequence = nth_sequence;
    return final_sequence;
}