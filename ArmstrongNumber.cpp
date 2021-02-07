#include <iostream>
#include <cmath>

using namespace std;

class A{
    public:
            bool CheckIfArmstrong(int num){
                int count = 0;
                int n = num;

                while(n != 0){
                    n /= 10;
                    count++;
                }

                int sum = 0;
                int p = num;
                for(int i = 0;i < count;i++){
                    sum += pow((p % 10), count);
                    p /= 10;
                }

                if(sum == num){
                    return true;
                }
                else{
                    return false;
                }
            }
};

int main(){
    A a;

    int number;
    cout << "Enter your number to check if Armstrong or not: ";
    cin >> number;

    (a.CheckIfArmstrong(number)) ? cout << "Yes, It is Armstrong." : cout << "No, It is not Armstrong.";
}
