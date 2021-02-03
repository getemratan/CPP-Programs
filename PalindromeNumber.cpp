#include <iostream>

using namespace std;

class A{
    public:

    bool IsPalindrome(int num){
        int result = 0;

        int number = num;
        while(num != 0){
            int r = (num % 10);

            result = (result * 10) + r;

            num /= 10;
        }

        if(number == result){
            return true;
        }
        else{
            return false;
        }
    }
};

int main(){
    A a;

    int _num;

    cout << "Enter the number that you want to check for palindrome: ";
    cin >> _num;

    a.IsPalindrome(_num) ? cout << "Is a palindrome number" : cout << "Is not a palindrome number!!";

}
