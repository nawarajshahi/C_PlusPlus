//
// Created by Nawaraj Shahi on 4/25/20.
/*
Write	two versions of	a	program	that	reads	a	positive	integer	n,	and	prints	the	first	n even	
numbers.	
    a) In	the	first,	use	a	while loop.	
    b) In	the	second,	use	a	for loop.	
*/

#include <iostream>
using namespace std;

int main()
{
    int counter = 1, evenNumber = 2, n;

    cout << "Please enter a positive integer: ";
    cin >> n;

    cout << "Section a " << endl;

    // Using while loop
    while (counter <= n)
    {
        cout << counter * evenNumber << endl;
        counter ++;
    }

    cout << "Section b" << endl;

    // Using For Loop
    for (counter = 1; counter <= n; counter ++ )
    {
        cout << counter * evenNumber << endl;
    }
}