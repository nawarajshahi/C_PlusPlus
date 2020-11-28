//
// Created by Nawaraj Shahi on 6/4/20.
//

#include <iostream>
using namespace  std;

void oddsKeepEvensFlip(int arr[], int arrSize);

int main()
{
    int arr[8] = {7, 4, 3, 6, 5, 8, 1, 2};
    const int arrSize = 8;

    oddsKeepEvensFlip(arr, arrSize);

    return 0;

}

void oddsKeepEvensFlip(int arr[], int arrSize)
{
    int index, oddsIndex, evensIndex;
    oddsIndex = 0, evensIndex = arrSize-1;

    int newArr[arrSize];

    for (index = 0; index < arrSize; index+=1){
        if(arr[index] % 2 ==0){
            newArr[evensIndex] = arr[index];
            evensIndex -=1;
        } else{
            newArr[oddsIndex] = arr[index];
            oddsIndex +=1;
        }
    }

    for (index = 0; index < arrSize; index +=1){
        cout << newArr[index] << "\t";
    }
}

