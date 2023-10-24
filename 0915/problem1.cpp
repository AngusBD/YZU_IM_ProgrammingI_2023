#include<iostream>

using namespace std;

int main(void){
    float num1, num2;
    cout << "Enter two floating point numbers." << endl;
    
    cin >> num1 >> num2;

    cout << num1 + num2 << endl;
    cout << (num1 + num2) / 2;

    //Variable solution
    // float total;
    // total = num1 + num2;
    // cout << total;
    // cout << total / 2;
    return 0;
}