/*
Author: Getem Ratan
Date: xx-xx-2020
Description:
Example:
*/

#include <iostream>

using namespace std;

class A{
    public:
       int * DataEntry(int row, int column){

           int arr[row][column];

           for(int i = 0;i < row;i++){
               for(int j = 0;i < column;i++){
                   cin >> arr[i][j];
               }
           }

           return arr;
       }
};

int main(){
    A a;

    int m, n, r, s;

    cout << "Enter the number of rows and column for first matrix: ";
    cin >> m;
    cin >> n;

    cout << "Enter the number of rows and column for second matrix: ";
    cin >> r;
    cin >> s;

    if(n != r)
        cout <<  "Matrix multiplication can't proceed because number of columns of first matrix is not equal to numbers rows for the second matrix!!";

    cout << "Enter the elements for the first matrix " << "R: " << m << " C: " << n;

    int *p;

    p = a.DataEntry(m,n);



    cout << "Enter the elements for the second matrix " << "R: " << r << " C: " << s;
}
