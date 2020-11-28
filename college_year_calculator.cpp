//
// Created by Nawaraj Shahi on 4/18/20.
/*
Write	a	program	that:
    • Asks	the	user	for	their	name.
    • Asks	the	user	to	input	their	graduation	year.
    • Asks	the	user	to	input	the	current	year.
Assume	the	student	is	in	a	four-year	undergraduate	program.	Display	the	current	status	the	
student	is	in.	Possible	status	include:	not	in	college	yet,	freshman,	sophomore,	junior,	senior,	
graduated.	

Note:	If	graduation	year	equals	to	current	year,	status	is	‘Graduated’;	if	graduation	year	is	
four	years	after	current	year,	status	is	‘Freshman’,	etc.
*/


#include <iostream>
#include <string>
using namespace std;

int main()
{
    string name;
    int current_YEAR, graduation_YEAR, difference;

    cout << "Please enter your name: ";
    cin >> name;

    cout << "Please enter your graduation year: ";
    cin >> graduation_YEAR;

    cout << "Please enter current year: ";
    cin >> current_YEAR;

    difference = graduation_YEAR - current_YEAR;

    if (difference == 4)
        cout << name << ", you are a freshman";
    else if (difference == 3)
        cout << name << ", you are a sophomore";
    else if (difference == 2)
        cout << name << ", you are a junior";

    else if (difference == 1)
        cout << name << ", you are a senior";
    else if (difference == 0)
        cout << name << ", you are graduated";
    else
        cout << name << ", you are not in college yet";
    return  0;
}