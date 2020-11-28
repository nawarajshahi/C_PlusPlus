//
// Created by Nawaraj Shahi on 4/10/20.
/*
Write	a	program	that	asks the	user	to	enter	a	number	of	quarters,	dimes,	nickels and	
pennies and	then	outputs	the	monetary	value	of	the	coins	in	the	format	of	dollars	and	
remaining	cents.	
*/


#include <iostream>
using namespace std;

const int quarterValue_inCents = 25;
const int dollarValue_inCents = 100;
const int dimeValue_inCents = 10;
const int nicklesValue_inCents = 5;

int main()
{
    int quarter, dimes, nickles, cents, final_dollar_value, remaining_cents, total_cents;

    cout << "Please enter number of coins:" << endl;

    cout << "# of quarters: ";
    cin >> quarter;

    cout << "# of dimes: ";
    cin >> dimes;

    cout << "# of nickles: ";
    cin >> nickles;

    cout << "# of pennies: ";
    cin >> cents;

    total_cents = (quarter * quarterValue_inCents) + (dimes * dimeValue_inCents) + (nickles * nicklesValue_inCents) + cents;

    final_dollar_value = total_cents / dollarValue_inCents;
    remaining_cents = total_cents % dollarValue_inCents;


    cout << "The total is " << final_dollar_value << " dollars and " << remaining_cents << " cents" << endl;

    return 0;

}
