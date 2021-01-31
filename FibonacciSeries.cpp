#include<iostream>
using namespace std;

void UsingRecursion(int x, int y, int num){
    int a = x;
    int b = y;
    int c;

    if(num != 0){
        c = a + b;
        cout << c << " ";

        a = b;
        b = c;

        num -= 1;

        UsingRecursion(a, b, num);
    }
}

void WithoutRecursion(int num){
    int a = 0;
    int b = 1;
    int c;

    for(int i = 0;i < num;i++){
        c = a + b;
        cout << c << " ";

        a = b;
        b = c;
    }
}

int main(){
    int num;
    int firstnum = 0;
    int secondnum = 1;
    int choice;

    cout << "Enter a number to get fibonacci series: ";
    cin >> num;

    cout << "Press 1 for Recursion Fibonacci and 2 for Without Recursion Fibonacci: ";
    cin >> choice;

    cout << firstnum << " " << secondnum << " ";
    num -= 2;
    if(choice == 1){
        UsingRecursion(firstnum, secondnum, num);
    }
    else if(choice == 2){
        WithoutRecursion(num);
    }
    else{
        cout << "Wrong Choice!\n";
    }
}
