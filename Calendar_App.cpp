//
// Created by Nawaraj Shahi on 5/18/20.
//

#include <iostream>
using namespace  std;

int printMonthCalender(int numOfDays, int startingDay);

bool isLeapYear (int year);

void printYearCalender(int year, int startingDay);

int main()
{
    int startingDay, year;
    cout << "Please enter a year in an integer format that represents a year (e.g. 2016): ";
    cin >> year;

    cout << "Please enter starting day of a week in a number 1-7 format that represents the day \n"
            "in the week of 1/1 in that year (1 for Monday, 2 for Tuesday, 3 for Wednesday, etc.): ";
    cin >> startingDay;

    printYearCalender( year, startingDay);
    isLeapYear(year);

    return 0;
}

int printMonthCalender(int numOfDays, int startingDay)
{
    int dayOfWeek, numTabs, counter, date;
    dayOfWeek = startingDay;
    numTabs = startingDay-1;

    cout << "Mon\tTue\tWed\tThr\tFri\tSat\tSun" << endl;
    for (counter = 1; counter <=numTabs; counter +=1)
        cout << "\t";
    for (date = 1; date <= numOfDays; date +=1){
        cout << date << "\t";       //prints date of the day
        dayOfWeek +=1;   //increments the day of the week

        if (dayOfWeek >7){
            dayOfWeek = 1;
            cout << endl;
        }

    }
    cout << endl;   //this end line ensures that next month will start on new line
    return dayOfWeek;
}
bool isLeapYear (int year){
    bool leapYear;
    if (((year % 4 == 0) && (year % 100 != 0)) || ((year % 100 == 0)  && (year % 400 == 0) && (year % 4 == 0))){
        leapYear = true;
    }
    return leapYear;
}

void printYearCalender(int year, int startingDay) {
    int lastDayOfMonth, currMonth, numOfDays;
    const int monthsInYear = 12;
    for (currMonth = 1; currMonth <= monthsInYear; currMonth += 1) {
        if (currMonth == 2) {
            if (isLeapYear(year)) {
                numOfDays = 29;
            } else
                numOfDays = 28;
        } else if ((currMonth == 1) || (currMonth == 3) || (currMonth == 5) || (currMonth == 7)
                    || (currMonth == 8) || (currMonth == 10) || (currMonth == 12)) {
            numOfDays = 31;
        } else
            numOfDays = 30;
        switch (currMonth) {
            case 1:
                cout << "January";
                break;
            case 2:
                cout << "February";
                break;
            case 3:
                cout << "March";
                break;
            case 4:
                cout << "April";
                break;
            case 5:
                cout << "May";
                break;
            case 6:
                cout << "June";
                break;
            case 7:
                cout << "July";
                break;
            case 8:
                cout << "August";
                break;
            case 9:
                cout << "September";
                break;
            case 10:
                cout << "October";
                break;
            case 11:
                cout << "November";
                break;
            case 12:
                cout << "December";
                break;

        }
        cout << "\t" << year << endl;
        if (currMonth == 1){
            lastDayOfMonth = printMonthCalender(numOfDays, startingDay);
        } else
            lastDayOfMonth = printMonthCalender(numOfDays, lastDayOfMonth);
        cout << endl;
    }
}