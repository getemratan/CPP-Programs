/*
Author: Getem Ratan
Date: 10-02-2020
Description: Program to print the reverse of a given number
Example: 345 => 543
*/

#include <iostream>

using namespace std;

class A{
    public:

       int ReverseTheNum(int num){
           int sum = 0;
           int temp = 0;

           while(num != 0){
                temp = (num % 10);

                sum = (sum * 10) + temp;

                num /= 10;
           }

           return sum;
       }
};

int main(){
    A a;

    int number;

    cout << "Enter the number that you want the reverse for: ";
    cin >> number;

    cout << "The reverse of the given number is: " << a.ReverseTheNum(number);
}
