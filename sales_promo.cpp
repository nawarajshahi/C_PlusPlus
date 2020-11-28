//
// Created by Nawaraj Shahi on 4/20/20.
/*
Write	a	program	that	computes	how	much	a	customer	has	to	pay	after	purchasing	two	
items.	The	price	is	calculated	according	to	the	following	rules:
    • Buy	one	get	one	half	off	promotion:	the	lower	price	item	is	half	price.
    • If	the	customer	is	club	card	member,	additional	10%	off.
    • Tax	is	added.
Inputs	to	the	program	include:
    • Two	items’	prices
    • Have	club	card	or	not	(User	enters	‘Y’	or	‘y’	for	“yes”;	‘N’	or	‘n’	for	“no”)
    • Tax	rate	(User	enters	the	percentage	as	a	number;	for	example	they	enter	8.25	if	the	tax	
rate	is	8.25%)
Program	displays:
    • Base	price	- the	price	before	the	discounts	and	taxes	
    • Price	after	discounts	- the	price	after	the	buy	one	get	one	half	off	promotion	and	the	
    member’s	discount,	if	applicable	
    • Total	price	– the	amount	of	money	the	customer	has	to	pay	(after	tax).
*/

#include <iostream>
using namespace std;
const double clubCard_DISCOUNT = 0.1; // converting 10% into numerical value

int main()
{
    double item1, item2, tax_RATE;
    double base_PRICE = 0, priceAfter_DISCOUNT=0, total_PRICE=0;
    char card_VALIDITY;

    cout << "Enter price of first item: ";
    cin >> item1;

    cout << "Enter price of second item: ";
    cin >> item2;

    cout << "Does customer have a club card? (Y/N): ";
    cin >> card_VALIDITY;

    cout << "Enter tax rate, e.g. 5.5 for 5.5% tax: ";
    cin >> tax_RATE;


    if (item1 > item2)
        priceAfter_DISCOUNT = item1 + (0.5 * item2);
    else if (item1 == item2)
        priceAfter_DISCOUNT = item1 + (0.5 * item2); // if price is equal for both items, one of them will be half off
    else
        priceAfter_DISCOUNT = item2 + (0.5 * item1);

    tax_RATE = tax_RATE/100;
    base_PRICE = item1 + item2;

    cout.setf(ios::fixed);
    cout.setf(ios::showpoint);

    if (card_VALIDITY == 'Y' || card_VALIDITY == 'y')
    {
        priceAfter_DISCOUNT -= (clubCard_DISCOUNT * priceAfter_DISCOUNT);
        total_PRICE = priceAfter_DISCOUNT + (priceAfter_DISCOUNT * tax_RATE);

        cout << "Base price: " << base_PRICE << endl;
        cout << "Price after discounts: " << priceAfter_DISCOUNT << endl;

        cout.precision(5);
        cout << "Total price: " << total_PRICE << endl;

    }
    else
    {
        total_PRICE = priceAfter_DISCOUNT + (priceAfter_DISCOUNT * tax_RATE);

        cout << "Base price: " << base_PRICE << endl;
        cout << "Price after discounts: " << priceAfter_DISCOUNT << endl;

        cout.precision(5);
        cout << "Total price: " << total_PRICE << endl;

    }
    return 0;
}
