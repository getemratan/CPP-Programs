#include <iostream>

using namespace std;

class A{
    public:

    int GetFactorial(int num){
        int result = num;

        for(int i = num; i > 1; i--){
            result *= (i - 1);
        }

        return result;
    }
};

int main(){
    A a;

    int n;

    cout << "Enter the number for which you want the factorial: ";
    cin >> n;

    cout << "Factorial of the given number is: " << a.GetFactorial(n);
}
