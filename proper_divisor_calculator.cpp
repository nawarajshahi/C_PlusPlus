//
// Created by Nawaraj Shahi on 5/18/20.
//
#include <iostream>
#include <cmath>

using namespace  std;

void analyzeDividors(int num, int& outCountDivs, int& outSumDivs);
bool isPerfect(int num);

int main()
{
    int num, counter;
    int curr_COUNT, curr_SUM, isAmicable_COUNT, isAmicable_SUM;

    cout << "Please enter a integer >=2: ";
    cin >> num;


    for (counter = 2; counter <=num; counter +=1){
        if (isPerfect(counter)){
            cout << counter << " is perfect." << endl;
        }

        analyzeDividors(counter, curr_COUNT, curr_SUM);
        analyzeDividors(curr_SUM, isAmicable_COUNT, isAmicable_SUM );

        if( counter == isAmicable_SUM && curr_SUM > counter){
            //In the above condition: curr_sum > counter removes duplication of values from
            //printing twice in the range from 2 to user entered integer
            cout << counter << " and " << curr_SUM << " are Amicable." << endl;
        }

    }

    return 0;
}

void analyzeDividors(int num, int& outCountDivs, int& outSumDivs){
    int sqrt_val, div_COUNT, div_SUM, counter, divisor;
    sqrt_val = sqrt(num);
    div_COUNT = 0;
    div_SUM = 0;
    for (counter = 1; counter <=sqrt_val; counter+=1){
        if(num %counter == 0){
            divisor = counter;
            div_COUNT +=1;
            div_SUM +=divisor;
        }

    }

    for (counter = sqrt_val; counter >1; counter -=1){
        if (num % counter ==0){
            divisor = num/counter;
            div_COUNT +=1;
            div_SUM +=divisor;
        }
    }
    outCountDivs = div_COUNT;
    outSumDivs = div_SUM;
}

bool isPerfect(int num){
    int num_COUNT, num_SUM;
    analyzeDividors(num, num_COUNT, num_SUM);
    return (num_SUM==num);
}