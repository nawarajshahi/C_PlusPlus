//
// Created by Nawaraj Shahi on 6/6/20.
//

#include <iostream>
using namespace  std;

int* findMissing(int arr[], int n, int& resArrSize);
void printArr(const int const missingNumArr[], const int missingNumArrSize);

int main()
{
    const int arrSize = 6;
    int arr1[arrSize] = {0, 1, 1, 3, 4, 6};

    const int arrSize2 = 4;
    int arr2[arrSize2] = {0, 1, 1, 1};

    int *missingArr, missingArrSize;

    //TESTING FOR 1ST ARRAY
    cout << "\nIntegers in given array are:\n";
    printArr(arr1, arrSize);

    missingArr = findMissing(arr1, arrSize, missingArrSize);

    cout << "\nMissing integer(s) in given array are: \n";
    printArr(missingArr, missingArrSize);

    delete [] missingArr;
    missingArr = NULL;

    cout << endl;

    //TESTING FOR 2ND ARRAY
    cout << "\nIntegers in given array are:\n";
    printArr(arr2, arrSize2);

    missingArr = findMissing(arr2, arrSize2, missingArrSize);

    cout << "\nMissing integer(s) in given array are: \n";
    printArr(missingArr, missingArrSize);

    delete [] missingArr;
    missingArr = NULL;

    cout << endl;
    return 0;

}


int* findMissing(int arr[], int n, int& resArrSize)
{
    int missingArrSize = 0;
    int missingArrPhysicalSize = 1;
    int index;
    int *outMissingArr{NULL};
    int *tempArr{NULL};
    outMissingArr = new int[1];

    string arrIntoString;

    for (index = 0; index < n; index +=1){
        arrIntoString +=to_string(arr[index]);
    }

    for (index = 0; index < n+1; index +=1){
       if (arrIntoString.find(to_string(index)) == string::npos ){
           if (missingArrSize == missingArrPhysicalSize){
               tempArr = new int[2 * missingArrPhysicalSize];
               for (int i = 0; i < missingArrSize; i +=1){
                   tempArr[i] = outMissingArr[i];
               }
               delete [] outMissingArr;
               outMissingArr = tempArr;
               missingArrPhysicalSize *=2;
           }
           outMissingArr[missingArrSize] = index;
           missingArrSize +=1;
       }
    }
    resArrSize = missingArrSize;
    return outMissingArr;
}

void printArr(const int const missingNumArr[], const int missingNumArrSize)
{
    int index;
    cout << "[";
    for (index = 0; index < missingNumArrSize; index+=1){
        if(index != missingNumArrSize-1){
            cout << missingNumArr[index] << ", ";
        }else{
            cout << missingNumArr[index];
        }
    }
    cout << "]";
}