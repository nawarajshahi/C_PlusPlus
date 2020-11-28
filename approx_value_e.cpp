//
// Created by Nawaraj Shahi on 5/11/20.


#include <iostream>
using namespace std;

double eApprox (int n);
int main() {
    cout.precision(30);
    for (int n = 1; n <= 15; n++) {
        cout<<"n = "<<n<<'\t'<<eApprox(n)<<endl;
    }
    return 0;
}

double eApprox(int n){
    double  e, factorial;
    int counter;

    e = 1.0;
    factorial = 1;
    for (counter = 1; counter <= n + 1; counter +=1){
        factorial *=counter;
        e += 1/factorial;
    }
    return e;
}