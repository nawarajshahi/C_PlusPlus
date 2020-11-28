//
// Created by Nawaraj Shahi on 6/19/20.
//
#include <iostream>

using namespace std;

int minJumpItCost(int costColArr[], int costColArrSize);

int main()
{
    int costColArr[9] = {0, 1, 1, 1, 5, 6, 8, 9, 9}; //output should be 21
    int minCost;

    minCost = minJumpItCost(costColArr, 9);
    cout << "Minimum cost of Jump It game is: " << minCost << endl;

    return 0;
}

int minJumpItCost(int costColArr[], int costColArrSize)
{
    int jumpCOST, moveCost;

    //base case can be for size <=3:
    // if costArr size is 3 or less then just last value can be returned
    if ((costColArrSize <= 3)) {
        return costColArr[costColArrSize - 1];
    }
    else{
        //determine move or jump cost first
        jumpCOST = costColArr[1] + costColArr[3]; //determines jump to the next cost
        moveCost = costColArr[2] + costColArr[3]; //determines move to the next cost

        //determine whether move cost is higher or the jump cost
        if (jumpCOST < moveCost)
            //if the jump to the next cost is higher than jump it
            return costColArr[1] + minJumpItCost(costColArr + 1, costColArrSize - 1);

        else
            //otherwise, move to the next cost is going to be cheaper, so move to next cost
            return costColArr[2] + minJumpItCost(costColArr + 2, costColArrSize - 2);
    }
}

