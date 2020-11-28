//
// Created by Nawaraj Shahi on 5/12/20.
/*
Write a program that reads from the user a positive integer (>=2)
And prints all it's divisors
*/

#include <iostream>
#include <cmath>
using namespace  std;

void printDivisors(int num);
int main()
{
    int num;
    cout <<"Please enter a positive integer >= 2: ";
    cin >> num;

    printDivisors(num);

    return 0;

}

void printDivisors(int num)
{
    int sqrt_NUM, counter, divisor;
    sqrt_NUM = sqrt(num);

    //prints all divisors that are in lower half of the range
    for(counter = 1; counter <= sqrt_NUM; counter +=1){
        if (num % counter ==0){
            divisor = counter;
            cout << divisor << " ";
        }
    }

    //prints all divisors that are in upper half of the range
    for (counter = sqrt_NUM-1; counter >0; counter -=1){
        if (num % counter ==0){
            divisor = num/counter;
            cout << divisor << " ";
        }
    }
    cout << endl;
}
