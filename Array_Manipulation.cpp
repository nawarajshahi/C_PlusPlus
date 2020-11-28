//
// Created by Nawaraj Shahi on 5/23/20.
//

#include <iostream>
using namespace std;

void reverseArray(int arr[], int arrSize);
void removeOdd(int arr[], int& arrSize);
void splitParity(int arr[], int arrSize);

void printArray(int arr[], int arrSize);

int main()
{

    int arr1[10] = {9, 2, 14, 12, -3};
    int arr1Size = 5;

    int arr2[10] = {21, 12, 6, 7, 14};
    int arr2Size = 5;

    int arr3[10] = {3, 6, 4, 1, 12};
    int arr3Size = 5;

    reverseArray(arr1, arr1Size);
    printArray(arr1, arr1Size);

    removeOdd(arr2, arr2Size);
    printArray(arr2, arr2Size);

    splitParity(arr3, arr3Size);
    printArray(arr3, arr3Size);

    return 0;

}
void printArray(int arr[], int arrSize){
    int i;
    for (i = 0; i < arrSize; i++) {
        cout<<arr[i]<<' ';
    }
    cout<<endl;
}
void reverseArray(int arr[], int arrSize)
{
    int firstIndex, lastIndex;
    for (firstIndex = 0, lastIndex = arrSize-1;
        firstIndex < arrSize/2;
        firstIndex +=1, lastIndex -=1){

       int temp = arr[firstIndex];
       arr[firstIndex] = arr[lastIndex];
       arr[lastIndex] = temp;
    }

}
void removeOdd(int arr[], int& arrSize)
{
    int index, newIndex=0;
    int temp;
    int new_len =0;

    for (index = 0; index < arrSize; index +=1){
        if (arr[index]%2 ==0){
            temp = arr[index];
            arr[newIndex] = temp;
            new_len +=1;
            newIndex +=1;
        }
    }
    arrSize = new_len;
}

void splitParity(int arr[], int arrSize) {
    int index, tempVal, setOddIndex;
    setOddIndex = 0;
    for (index = 0; index < arrSize; index +=1) {
        //code below swaps values only if odd value is encountered in the
        //array of integers
        if (arr[index] % 2 != 0) {      //determines if the digit encountered is even or odd
            tempVal = arr[setOddIndex];
            arr[setOddIndex] = arr[index];
            arr[index] = tempVal;
            setOddIndex += 1;
        }
    }
}