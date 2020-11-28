//
// Created by Nawaraj Shahi on 4/20/20.
/*
Write	a	program	that	does	the	following:
• Ask	user	to	input	three	Real numbers	a,	b	and	c.	They	represent	the	parameters	of	a	
quadratic	equation.
You should identify and see if the given equation has the following: 
    1. Infinite number of solutions
    2. No solution
    3. No real solution
    4. One real solution
    5. Two real solutions

If there are 1 or 2 real solutions, also print the solutions. 

*/

#include <iostream>
#include <cmath>
using namespace std;

int main()
{
    int a, b, c;
    double denominator=0, discriminant=0;
    double val1, val2, val;

    cout << "Please enter value of a: ";
    cin >> a;

    cout <<" Please enter value of b: ";
    cin >> b;

    cout << "Please enter value of c: ";
    cin >> c;

    discriminant = (b * b) - (4 * a * c);
    denominator = 2.0 * a;

    if ((a==0) && (b ==0) && (c==0)){
        cout << "This equation has infinite number of solutions." << endl;

    } else if ((a ==0) && (b !=0) && (c !=0)){
        cout << "This equation has one real solution, x = " << (int)(-1*c)/b << endl;
    } else if (discriminant >0){
        if ((a ==0) && (b !=0) && (c ==0)){
            cout << "This equation has one solution, x = 0" << endl;
        }else {
            val1 = ((-1 * b) + sqrt(discriminant)) / denominator;
            val2 = ((-1 * b) - sqrt(discriminant)) / denominator;
            cout << "This equation has two solutions, x = " << val1 << " and x = " << val2 << endl;
        }
    } else if (discriminant ==0){
        val = (-1*b)/denominator;
        cout << "This equation has one real solution, x = " << val << endl;

    } else if (discriminant <0){
        cout << "This equation has no real solutions" << endl;
    }
    return  0;
}
