//
// Created by Nawaraj Shahi on 4/10/20.
/*
Write	a	program	that	asks the	user	to	enter	an	amount	of	money	in	the	format	of	dollars	and	
remaining	cents.	The	program	should	calculate	and	print	the	minimum	number	of	coins	
(quarters,	dimes,	nickels	and	pennies)	that	are	equivalent	to	the	given	amount.
*/


#include <iostream>
using namespace std;

const int dollar_to_quarter = 4;
const int quarterValue_inPennies = 25;
const int dimeValue_inPennies = 10;
const int nicklesValue_inPennies = 5;

int main()
{
    int dollar, penny, quarters_equivalent, dimes_equivalent, nickles_equivalent, penny_value, remainder_value;

    cout << "Please enter your amount in the format of dollars and cents separated by a space:" << endl;
    cin >> dollar >> penny;

    quarters_equivalent = (dollar * dollar_to_quarter) + (penny/quarterValue_inPennies);
    remainder_value = penny % quarterValue_inPennies;

    dimes_equivalent = remainder_value / dimeValue_inPennies;
    remainder_value = remainder_value % dimeValue_inPennies;

    nickles_equivalent = remainder_value / nicklesValue_inPennies;
    remainder_value = remainder_value % nicklesValue_inPennies;

    penny_value = remainder_value; //remaining pennies

    cout << dollar << " and " << penny << " cents are:" << endl;
    cout << quarters_equivalent << " quarters, " << dimes_equivalent << " dimes, ";
    cout << nickles_equivalent << " nickles and " << penny_value << " pennies" << endl;

    return 0;

}
