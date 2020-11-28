//
// Created by Nawaraj Shahi on 6/14/20.
//

#include <iostream>
using namespace std;

int minInArray1(int arr[], int arrSize);
int minInArray2(int arr[], int low, int high);
void printArr(int arr[], int arrSize);
int minVal(int val1, int val2);

int main()
{
    const int arrSize = 10;
    int arr1[arrSize] = {12, 0, 1, 5, -1, 15, -9, -11, 4, 19};
    int arr2[arrSize] = {-22, 0, -11, 4, -1, 15, -9, -15, 4, 19};

    int res1, res2, res3, res4;

    res1 = minInArray1(arr2, arrSize);
    res2 = minInArray2(arr2, 0, 10);

    cout << "\n";
    printArr(arr2, arrSize);
    cout << "\nMinimum value is with implementation A: "<< res1 << endl;
    cout << "Minimum value is with implementation B: " << res2 << endl;

    cout << "\n============================================" << endl;
    cout << "\n";
    printArr(arr2+2, 4);
    res4 = minInArray1(arr2 +2, 4);
    res3 = minInArray2(arr2, 2, 5);

    cout << "\nMinimum value is with implementation A: "<< res4 << endl;
    cout << "Minimum value is with implementation B: " << res3 << endl;


}

//Implementation 3(a)
int minInArray1(int arr[], int arrSize)
{
    int minValInArr;
    if (arrSize ==0)
        return arr[0];
    else{
        //uses minVal function that is defined separately to calculate
        // minimum value between arr[n-1] and arr[n-2]
        return (minVal(arr[arrSize-1], minInArray1(arr, arrSize-1)));
    }
}

//Implementation 3(b)
int minInArray2(int arr[], int low, int high)
{
    int minValInArr;
    if(low == high) //since low and high represent indices of Arr
        return arr[low];
    else{
        minValInArr = minInArray2(arr, low +1, high);   //since low <= high
        if(arr[low]< minValInArr )
            minValInArr = arr[low]; //update minValinArray
    }
    return minValInArr;
}

//Just printing Array for better understanding of which array
//they're working with
void printArr(int arr[], int arrSize)
{
    int index;
    cout << "[";
    for (index = 0; index < arrSize; index +=1){
        if (index != arrSize-1)
            cout << arr[index] << ", ";
        else
            cout << arr[index] << "]";
    }
}

//FYI, I defined minVal function to return minimum value among two integers
int minVal(int val1, int val2)
{
    if (val1 <=val2)
        return val1;
    else
        return val2;
}