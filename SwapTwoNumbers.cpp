/*
Author: Getem Ratan
Date: 12-02-2020
Description: Program to swap two numbers without third variable
Example: a = 12 b = 24 -----> a = 24 b = 12
*/

#include <iostream>

using namespace std;

class A{
    public:
        void SwapNumbers(int &num_one, int &num_two){
            num_one = num_one * num_two;
            num_two = num_one / num_two;
            num_one = num_one / num_two;
        }
};

int main(){
    A a;

    int inputone;
    int inputtwo;

    cout << "Enter the two numbers that want to swap: ";
    cout << "Number One: ";
    cin >> inputone;
    cout << "Number Two: ";
    cin >> inputtwo;

    a.SwapNumbers(inputone, inputtwo);
    cout << "Results are: " << "Number One: " << inputone << " Number Two: " << inputtwo;
}
