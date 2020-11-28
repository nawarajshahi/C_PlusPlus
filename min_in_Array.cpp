//
// Created by Nawaraj Shahi on 5/22/20.
//

#include <iostream>
using namespace std;

const int MAX_ARR_SIZE = 20;
int minInArray(int arr[], int arrSize);
void readArray(int arr[], int arrSize);
void printMinIndices(int arr[], int arrSize, int minVal);


int main()
{
    int numsArr[MAX_ARR_SIZE];
    int minVal;

    readArray(numsArr, MAX_ARR_SIZE);
    minVal = minInArray(numsArr, MAX_ARR_SIZE);
    printMinIndices(numsArr, MAX_ARR_SIZE, minVal);

    return 0;
}

void readArray(int arr[], int arrSize)
{
    int index;
    cout << "Please enter 20 integers separated by a space: " << endl;
    for (index = 0;  index < arrSize; index +=1) {
        cin >> arr[index];
    }

}

int minInArray(int arr[], int arrSize)
{
    int minVal = arr[0], index;
    for (index = 0; index < arrSize; index +=1){
        if (arr[index] < minVal){
            minVal = arr[index];
        }
    }
    cout<< endl;
    return minVal;

}

void printMinIndices(int arr[], int arrSize, int minVal)
{
    int index;
    cout << "The minimum value is " << minVal;
    cout << ", and it is located in the following indices: ";
    for (index = 0; index < arrSize; index +=1){
        if (minVal == arr[index]){
            cout << index << " ";
        }
    }
    cout << endl;

}