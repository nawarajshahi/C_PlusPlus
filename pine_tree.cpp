//
// Created by Nawaraj Shahi on 5/11/20.
/*
Write	a	program	that,	prints	a	‘pine	tree’	consisting	of	triangles	of	increasing	sizes,	filled	
with	a	character	(eg.	‘*’	or	’+’	or	‘$’	etc).	
*/

#include <iostream>
using namespace std;


void printShiftedTriangle(int n, int shift, char symbol);
void printPineTree(int n, char symbol);

int main()
{
    int num_TRIANGLES;
    char symbol;

    cout << "Please enter the number of triangles desired: ";
    cin >> num_TRIANGLES;

    cout << "Please enter a symbol that you want your triangle to be filled with: ";
    cin >> symbol;

    printPineTree(num_TRIANGLES, symbol);

    return 0;

}

void printShiftedTriangle(int n, int shift, char symbol)
{
    int num_SPACES, line_COUNT, char_COUNT, curr_SPACE, curr_CHAR;

    for (line_COUNT = 1, num_SPACES = shift + (n-1), char_COUNT = 1;
         line_COUNT <= n;
         line_COUNT+=1, num_SPACES-=1, char_COUNT +=2){

        for(curr_SPACE = 1; curr_SPACE <= num_SPACES; curr_SPACE+=1){
            cout << " ";
        }

        for(curr_CHAR= 0; curr_CHAR < char_COUNT; curr_CHAR++){
            cout << symbol;
        }
        cout << endl;
    }

}

void printPineTree(int n, char symbol)
{
    int num_TRIANGLES, shift, line_COUNT;

    line_COUNT = 2;     //sets minimum of 2 lines triangle
    for(num_TRIANGLES = 1, shift = n-1;
        num_TRIANGLES <=n;
        num_TRIANGLES+=1, shift-=1){

        printShiftedTriangle(line_COUNT, shift, symbol);
        line_COUNT +=1;
    }
}
