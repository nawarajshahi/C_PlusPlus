//
// Created by Nawaraj Shahi on 6/6/20.
//

#include <iostream>
#include <vector>
using namespace std;

//PART A IMPLEMENTATION WITHOUT USING VECTOR
int *getInputArr(int &arrSize);
int *searchArr(int numArr[], int numArrSize, int &searchArrSize, int &numToSearch);
void printArr(const int const searchArr[], const int searchArrSize, const int numToSearch);
int main1();


//PART B IMPLEMENTATION USING VECTOR
vector<int> getInput();
vector<int> numSearchVec(vector<int> numVec, int &numToFind);
void printVec(vector<int>numToFindVec, const int numToFind);
int main2();


int main()
{
    cout << "\n*********** Part A **********" << endl;
    main1();

    cout << endl;

    cout << "\n*********** Part B **********" << endl;
    main2();
}

int main1()
{
    int numArrSize, findNumArrSize, numToSearch;
    int *numArr{NULL};
    int *findNumArr{NULL};

    numArr = getInputArr(numArrSize);
    findNumArr = searchArr(numArr, numArrSize, findNumArrSize, numToSearch);
    printArr(findNumArr, findNumArrSize, numToSearch);

    delete [] numArr;
    numArr=NULL;

    delete [] findNumArr;
    findNumArr = NULL;

}

int *getInputArr(int &arrSize)
{
    int *numArr{NULL};
    int userNum;
    int numArrSize =0, numArrPhysicalSize =1;

    numArr = new int[1];
    bool seenNegOne = false;

    int *tempNumArr{NULL};

    cout << "\nPlease enter a sequence of positive integers, each in a separate line.\n"
            "End you input by typing -1." << endl;

    while (seenNegOne == false){
        cin >> userNum;
        if (userNum != -1){
            if(numArrSize == numArrPhysicalSize){
                tempNumArr = new int[2*numArrPhysicalSize];
                for (int i = 0; i < numArrSize; i+=1){
                    tempNumArr[i] = numArr[i];
                }
                delete [] numArr;
                numArr = tempNumArr;
                numArrPhysicalSize *=2;
            }
            numArr[numArrSize] = userNum;
            numArrSize +=1;
        } else
            seenNegOne = true;

    }
    arrSize = numArrSize;
    return numArr;
}

int *searchArr( int numArr[], int numArrSize, int &searchArrSize, int &numToSearch)
{
    int numToFind;
    int *foundNumArr{NULL};

    cout << "Please enter a number you want to search." << endl;
    cin >> numToFind;

    //because occurance of numToFind can always be upto size of numArr
    foundNumArr = new int[numArrSize];
    int findNumArrSize = 0;

    for (int i = 0; i < numArrSize; i+=1){
        if(numToFind == numArr[i]){
            foundNumArr[findNumArrSize] = i+1;
            findNumArrSize+=1;
        }
    }
    numToSearch = numToFind;
    searchArrSize = findNumArrSize;
    return foundNumArr;
}

void printArr(const int const searchArr[], const int searchArrSize, const int numToSearch)
{

    cout << numToSearch << " shows in lines ";
    for (int i = 0; i < searchArrSize; i+=1){
        if (i != searchArrSize-1){
            cout << searchArr[i] << ", ";
        } else
            cout << searchArr[i]<< ".";
    }
}


//PART B WITH VECTOR IMPLEMENTATION
int main2()
{
    vector<int> numVec;
    vector<int>numToFindVec;
    int numToFind;
    numVec = getInput();
    numToFindVec = numSearchVec(numVec, numToFind);
    printVec(numToFindVec, numToFind);
}

vector<int> getInput()
{
    int userNum;
    vector<int> numVec;
    cout << "\nPlease enter a sequence of positive integers, each in a separate line.\n"
            "End you input by typing -1." << endl;
    do{
        cin >> userNum;
        numVec.push_back(userNum);
    }while (userNum !=-1);

    return numVec;
}

vector<int> numSearchVec(vector<int>numVec, int &numToFind)
{
    vector<int>numToFindVec;
    int numToSearch, index;

    cout << "Please enter a number you want to search." << endl;
    cin >> numToSearch;

    for (index = 0; index < numVec.size(); index +=1){
        if(numToSearch == numVec[index])
            numToFindVec.push_back(index+1);
    }
    numToFind = numToSearch;
    return numToFindVec;
}

void printVec(vector<int>numToFindVec, const int numToFind)
{
    int index;

    cout <<numToFind << " shows in lines ";
    for (index = 0; index < numToFindVec.size(); index+=1){
        if(index !=numToFindVec.size()-1){
            cout << numToFindVec[index] << ", ";
        } else
            cout << numToFindVec[index] << ".";
    }
}

