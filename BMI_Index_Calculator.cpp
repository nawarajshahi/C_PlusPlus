//
// Created by Nawaraj Shahi on 4/20/20.
/*
Write	a	program	that	prompts	for	weight	(in	pounds)	and	height	(in	inches)	of	a	person,	and	
prints	the	weight	status	of	that	person.
*/

#include <iostream>
using namespace std;

int main()
{
    double lbTo_KG = 0.453592, inchTO_METERS = 0.0254;
    double weight, height, BMI_INDEX;
    cout << "Please enter weight (in pounds): ";
    cin >> weight;

    cout << "Please enter height (in inches): ";
    cin >> height;

    weight = weight * lbTo_KG;
    height = (height*height) * (inchTO_METERS * inchTO_METERS);

    BMI_INDEX = weight/height;

    if (BMI_INDEX < 18.5){
        cout << "The weight status is: Underweight " << endl;
    } else if ((BMI_INDEX >= 18.5) && (BMI_INDEX <25)){
        cout << "The weight status is: Normal" << endl;
    } else if ((BMI_INDEX >= 25) && (BMI_INDEX <30)){
        cout << "The weight status is: Overweight" << endl;
    } else if ((BMI_INDEX >= 30)){
        cout << "The weight status is: Obese" << endl;
    } else{
        cout << "Invalid entry---please try again" << endl;
    }

    return 0;
}



