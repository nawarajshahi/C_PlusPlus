//
// Created by Nawaraj Shahi on 4/10/20.
/*
Suppose	John	and	Bill	worked	for	some	time	and	we	want	to	calculate	the	total	time	both	of	
them	worked.	Write	a	program	that	reads number	of	days,	hours, minutes	each	of	them	
worked,	and	prints	the	total	time	both	of	them	worked	together	as	days,	hours,	minutes.
*/


#include <iostream>
using namespace std;

const int totalMinutesInHour = 60;
const int totalHoursInDay = 24;

int main()
{

    int daysOfJohn, hoursOfJohn, minutesOfJohn;
    int daysOfBill, hoursOfBill, minutesOfBill;

    int totalDays, totalHours, totalMinutes, carryOverdays, carryOverHours;

    //Codes below reads days, hours and minutes worked for John
    cout << "Please enter the number of days John has worked: ";
    cin>> daysOfJohn;

    cout << "Please enter the number of hours John has worked: ";
    cin >> hoursOfJohn;

    cout << "Please enter the number of minutes John has worked: ";
    cin >> minutesOfJohn;

    //Codes below reads days, hours and minutes worked for Bill
    cout << "\nPlease enter the number of days Bill has worked: ";
    cin >> daysOfBill;

    cout << "Please enter the number of hours Bill has worked: ";
    cin >> hoursOfBill;

    cout <<"Please enter the number of minutes Bill has worked: ";
    cin>> minutesOfBill;

    //Section below does calculations for days, hours and minutes for both Bill and John
    totalMinutes = minutesOfBill + minutesOfJohn;
    carryOverHours =totalMinutes/totalMinutesInHour;
    totalMinutes = totalMinutes % totalMinutesInHour;

    totalHours = hoursOfBill + hoursOfJohn + carryOverHours;
    carryOverdays = totalHours/totalHoursInDay;
    totalHours = totalHours % totalHoursInDay;

    totalDays = daysOfBill + daysOfJohn + carryOverdays;

    //Section below will give the output of total days, hours and minutes for both Bill and John
    cout << "\nTotal time for both of them worked together is: " << totalDays << " days, ";
    cout << totalHours << " hours and " << totalMinutes << " minutes." << endl;

    return 0;
}
