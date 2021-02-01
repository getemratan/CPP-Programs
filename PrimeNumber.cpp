#include<iostream>

using namespace std;

class A{
    public:

    bool IsPrimeNumber(int num){

        if(num <= 2)
            return true;
        else if((num % 2) == 0){
            return false;
        }

        for(int i = 3;i < num; i += 2){
            if((num % i) == 0){
                return false;
            }
        }
        return true;
    }
};


int main(){
    A a;

    int number;
    cout << "Enter a number to check if prime or not: ";
    cin >>  number;

    if(a.IsPrimeNumber(number)){
        cout << "Is a Prime Number!!" << endl;
    }
    else{
        cout << "Is not a Prime Number!!" << endl;
    }
}
