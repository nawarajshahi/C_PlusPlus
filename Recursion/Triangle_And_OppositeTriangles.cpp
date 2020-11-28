//
// Created by Nawaraj Shahi on 6/12/20.
//

#include <iostream>
using namespace std;

void printTriangle(int n);
void printOpositeTriangles(int n);
void printRuler(int n);

int main()
{
    printTriangle(4);
    cout << endl;

    printOpositeTriangles(4);
    cout << endl;
    printRuler(5);



    return 0;
}

void printTriangle(int n)
{
    string star = "*";
    int counter;
    if (n==1){
        cout << star << endl;
    }else{
        printTriangle(n-1);
        for (counter = 1; counter < n; counter +=1){
            star += "*";
        }
        cout << star << endl;
    }
}

void printOpositeTriangles(int n)
{
    string upperHalfTriangle = "*";
    string bottomHalfTriangle = "*";
    int upperCounter, bottomCounter;
    if(n ==1){
        cout << upperHalfTriangle << endl;
        cout << bottomHalfTriangle << endl;

    }else{
        for (upperCounter = 1; upperCounter < n; upperCounter +=1){
            upperHalfTriangle +="*";
        }
        cout << upperHalfTriangle << endl;

        printOpositeTriangles(n-1);

        for (bottomCounter = 1; bottomCounter < n; bottomCounter +=1){
            bottomHalfTriangle +="*";
        }
        cout << bottomHalfTriangle << endl;
    }
}

void printRuler(int n) {
    int counter;
    char ruler = '-';
    if (n==1)
        cout<< ruler << endl;
    else{
        printRuler(n - 1);
        for (counter = 0; counter < n; counter+=1)
            cout<<ruler;
        cout<<endl;
    }
    if (n > 1)
        printRuler(n - 1);
}