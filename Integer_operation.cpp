//
// Created by Nawaraj Shahi on 4/10/20.
/*
Write	a	program	that	reads	from	the	user	two positive	integers,	and	prints	the	result	of	
when	we add,	subtract	multiply,	divide,	div	and	mod	them.
*/


#include <iostream>
using namespace std;

int main()
{
    int value1, value2;
    cout << "Please enter two positive integers, separated by a space:" << endl;
    cin>> value1 >> value2;

    cout << value1 << " + " << value2 << " = " << value1 + value2 << endl;
    cout << value1 << " - " << value2 << " = " << value1 - value2 << endl;
    cout << value1 << " * " << value2 << " = " << value1 * value2 << endl;
    cout << value1 << " / " << value2 << " = " << (double)value1 / value2 << endl;
    cout << value1 << " div " << value2 << " = " << value1 / value2 << endl;
    cout << value1 << " mod " << value2 << " = " << value1 % value2 << endl;

    return 0;
}
