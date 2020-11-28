//
// Created by Nawaraj Shahi on 6/13/20.
//
#include <iostream>
#include <cmath>
using namespace std;

int sumOfSquares(int arr[], int arrSize);
bool isSorted(int arr[], int arrSize);
void printArr(int arr[], int arrSize);    //added printArr functionality to print entire Array as well

int main()
{
    bool check;
    int sum;
    const int arrSize = 6;
    int arr[arrSize] = {-3, -3, -1, 1, -12, 13};
    int arr2[arrSize] = {-4, -3, -1, 1, 12, 13};

    //Part A implementation
    sum = sumOfSquares(arr, arrSize);
    cout << "Sum is: " << sum << endl;

    //Part B implementation
    check = isSorted(arr, arrSize);

    if (check == true) {
        printArr(arr, arrSize);
        cout << " => is sorted!" << endl;
    }
    else{
        printArr(arr, arrSize);
        cout << " => is not sorted!" << endl;
    }

}


int sumOfSquares(int arr[], int arrSize)
{
  if (arrSize ==0)  //exits the program
      return 0;
  else
      return (pow(arr[arrSize-1], 2) + sumOfSquares(arr, arrSize-1));
}



bool isSorted(int arr[], int arrSize)
{
    if (arrSize ==1)   //array with 1 element is always sorted
        return true;
    else{
        return ((arr[arrSize-1] >= arr[arrSize-2]) && isSorted(arr, arrSize-1));
    }
}
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
