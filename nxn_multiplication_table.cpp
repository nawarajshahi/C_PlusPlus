//
// Created by Nawaraj Shahi on 5/1/20.
/*
Write a program that reads a positive integer n from the user and prints out a nxn
multiplication table. The columns should be spaced by a tab.
*/

#include <iostream>
#include <string>
using namespace  std;

int  main()
{
    int num, outerCounter, innerCounter, multiply;

    //obtain positive integer n from the user

    cout << "Please enter a positive integer: " << endl;
    cin >> num;

    //display multiplication table n x n
    innerCounter = 0;
    outerCounter = 0;
    for(outerCounter = 1; outerCounter <= num; outerCounter +=1){
        for(innerCounter = 1; innerCounter <=num; innerCounter +=1){
           multiply = innerCounter * outerCounter;
           cout << multiply << "\t";
        }
        cout << endl;
    }
    return 0;
}
