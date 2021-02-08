/*
Author: Getem Ratan
Date: 08-02-2020
Description: Program to get the sum of a given number
Example: 23 = 2+3 = 5 
*/

#include <iostream>

using namespace std;

class A{
    public:
        int AddTheDigits(int num){
            int sum = 0;

            while(num != 0){
                sum += (num % 10);

                num /= 10;
            }

            return sum;
        }
};

int main(){
    A a;

    int number;

    cout << "Enter the number to get the sum: ";
    cin >> number;


    cout << "The sum is: " << a.AddTheDigits(number);
}
