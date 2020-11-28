//
// Created by Nawaraj Shahi on 4/20/20.
/*
Write	a	program	that	computes	the	cost	of	a	long-distance	call.	The	cost	of	 the	call	is	
determined	according	to	the	following	rate	schedule:	
    • Any	call	started	between	8:00	A.M.	and	6:00	P.M.,	Monday	through	Friday,	is	billed	at	a	
        rate	of	$0.40	per	minute.
    • Any	call	starting	before	8:00	A.M.	or	after	6:00	P.M.,	Monday	through	Friday,	is	charged	
        at	a	rate	of	$0.25	per	minute.	
    • Any	call	started	on	a	Saturday	or	Sunday	is	charged	at	a	rate	of	$0.15	per	minute.	
        The	input	will	consist	of	the	day	of	the	week, the	time	the	call	started,	and	the	length	of	the	
        call	in	minutes.	
The	output	will	be	the	cost	of	the	call.	

Notes:
1. The	time	is	to	be	input	in	24-hour	notation,	so	the	time	1:30	P.M.	is	input	as	 13:30	
2. The	day	of	the	week	will	be	read	as	one	of	the	following	two	character	string:	Mo		Tu		
    We		Th		Fr		Sa		Su
3. The	number	of	minutes	will	be	input	as	a	positive	integer.	
*/

#include <iostream>
#include <string>
using namespace std;

int main()
{
    int hh, mm, call_MINS;
    string day;
    char colon;

    const double rate_WEEKEND = 0.15, rate_BEFORE_8am_AFTER_6PM = 0.25;
    const double rate_AFTER_8am_BEFORE_6pm = 0.40;

    double cost_WEEKEND = 0;
    double cost_BEFORE_8am_AFTER_6pm = 0;
    double cost_AFTER_8am_BEFORE_6pm = 0;

    cout << "Please enter the day of the week in the following format: ";
    cout << "Mo Tu, We Th Fr Sa Su : ";
    cin >> day;

    cout << "Please enter the time the call started on 24 hour format (hh : mm) ";
    cin >> hh >> colon >> mm;

    cout << "Please enter the length of the call in minutes: ";
    cin >> call_MINS;

    if ((day == "Sa") || (day == "Su")){
        cost_WEEKEND = call_MINS * rate_WEEKEND;
        cout << "Cost of the call is: $" << cost_WEEKEND << endl;

    }else if ((day == "Mo") || (day == "Tu") || (day == "We")
              || (day == "Th") || (day == "Fr"))
    {
        if ((hh < 8) || ((mm != 00) && (hh >= 18))){    //checks if time is >18:00 OR < 8am
            cost_BEFORE_8am_AFTER_6pm = call_MINS * rate_BEFORE_8am_AFTER_6PM;
            cout << "Cost of the call is: $" << cost_BEFORE_8am_AFTER_6pm;

        } else{
            cost_AFTER_8am_BEFORE_6pm = call_MINS * rate_AFTER_8am_BEFORE_6pm;
            cout << "Cost of the call is: $" << cost_AFTER_8am_BEFORE_6pm;
        }

    }
    return 0;
}


