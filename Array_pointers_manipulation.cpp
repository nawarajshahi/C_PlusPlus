//
// Created by Nawaraj Shahi on 6/4/20.
//

#include <iostream>
using namespace std;

void printArr(int arr[], int arrSize);
int* getPosNums1(int* arr, int arrSize, int& outPosArrSize);    //implementation 3(a)
void getPosNums2(int* arr, int arrSize, int*& outPosArr, int& outPosArrSize);  //implementation 3(b)
int* getPosNums3(int* arr, int arrSize, int* outPosArrSizePtr); // implementation 3(c)
void getPosNums4(int* arr, int arrSize, int** outPosArrPtr, int* outPosArrSizePtr);

int main()
{
    const int arrSize = 6;
    int arr[arrSize] =  {1, -1, -2, 5, -3, 7};
    int arr2[arrSize] = {3, -1, -3, 0, 6, 4};
    int arr3[arrSize] = {4, -1, -3, -2, 6, 4};
    int arr4[arrSize] = {-4, -1, -3, 1, 2, 9};


//    implementation 3(a)
    int outPosArrSize1;

    int *outPosArr1 = getPosNums1(arr, arrSize, outPosArrSize1);
    printArr(outPosArr1, outPosArrSize1);

    delete [] outPosArr1;
    outPosArr1 = NULL;
    cout << endl;

    //===========================================================
    //implementation 3(b)
    int outPosArrSize2;
    int *outPosArr2{NULL};

    getPosNums2(arr2, arrSize, outPosArr2, outPosArrSize2);
    printArr(outPosArr2, outPosArrSize2);

    delete [] outPosArr2;
    outPosArr2 = NULL;
    cout << endl;

    //===========================================================
    //implementation 3(c)
    int outPosArrSize3;
    int *outPosArrSizePtr3{NULL};
    outPosArrSizePtr3 = &outPosArrSize3;

    int *outPosArr3 = getPosNums3(arr3, arrSize, outPosArrSizePtr3);
    printArr(outPosArr3, *outPosArrSizePtr3);

    delete [] outPosArr3;
    outPosArr3 = NULL;
    cout << endl;


    //===========================================================
    //implementation 3(d)
    int outPosArrSize4{0};
    int *outPosArrSizePtr4{NULL};
    outPosArrSizePtr4 = &outPosArrSize4;

    int *outPosArrPtr4{NULL};

    getPosNums4(arr4, arrSize, &outPosArrPtr4, outPosArrSizePtr4);
    printArr(outPosArrPtr4, outPosArrSize4);

    delete [] outPosArrPtr4;
    outPosArrPtr4 = NULL;


    return 0;
}

//prints the array
void printArr(int arr[], int arrSize){
    int index;
    cout << "[";
    for(index = 0; index < arrSize; index +=1){
        if(index != (arrSize-1))
            cout <<arr[index] << ", ";
        else
            cout << arr[index];
    }
    cout << "]";
}


//implementation 3(a)
int* getPosNums1(int* arr, int arrSize, int& outPosArrSize){
    int *newArr{NULL}, index, newSize;
    newArr = new int[arrSize];

    newSize = 0;
    for (index = 0; index < arrSize; index +=1){
        if(arr[index]>0){
            newArr[newSize] = arr[index];
            newSize +=1;
        }
    }
    outPosArrSize = newSize;
    return newArr;
}


//implementation 3(b)
void getPosNums2(int* arr, int arrSize, int*& outPosArr, int& outPosArrSize)
{
   int index, newSize = 0;
   int *newArr{NULL};
   newArr = new int[arrSize];

   for (index = 0; index < arrSize; index +=1){
       if (arr[index] >0){
           newArr[newSize] = arr[index];
           newSize +=1;
       }
   }
   outPosArr = newArr;
   outPosArrSize = newSize;
}


//implementation 3(c)
int* getPosNums3(int* arr, int arrSize, int* outPosArrSizePtr)
{
    int index, newSize;

    int *newArr{NULL};
    newArr = new int[arrSize];

    newSize = 0;

    for (index = 0; index < arrSize; index +=1){
        if (arr[index] >0){
            newArr[newSize] = arr[index];
            newSize +=1;
        }
    }
    *outPosArrSizePtr = newSize;
    return newArr;
}


//implementation 3(d)
void getPosNums4(int* arr, int arrSize, int** outPosArrPtr, int* outPosArrSizePtr)
{
    int index, newSize;
    int *newArr{NULL};
    newArr = new int[arrSize];

    newSize = 0;
    for (index = 0; index < arrSize; index +=1){
        if (arr[index] >0){
            newArr[newSize] = arr[index];
            newSize +=1;
        }
    }
    *outPosArrSizePtr = newSize;
    *outPosArrPtr = newArr;
}

