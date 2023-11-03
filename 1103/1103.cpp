#include<iostream>
#include<cmath>
#include<iomanip>

using namespace std;

void NumberRectangle(int n){
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            for(int k = 0; n/2 -k > 0; k++){
                if(abs(i - n/2) == n/2 -k|| abs(j - n/2) == n/2 -k){
                    cout << setw(3) << n - 2*k;
                    break;
                }
            }
            
            if(i == n/2 && j == n/2){
                cout << setw(3) << 1;
            }
            // if(abs(i - n/2) == n/2 || abs(j - n/2) == n/2){
            //     cout << n;
            // }
            // else if(abs(i - n/2) == n/2 -1 || abs(j - n/2) == n/2 -1){
            //     cout << n-2;
            // }
            // else if(abs(i - n/2) == n/2 -2 || abs(j - n/2) == n/2 -2){
            //     cout << n-4;
            // }
            // else if(abs(i - n/2) == n/2 -3 || abs(j - n/2) == n/2 -3){
            //     cout << n-6;
            // }
            // else{
            //     cout << 1;
            // }
        }
        cout << endl;
    }
}

void Q1(void){
    for(int i = 3; i < 100; i+=2){
        NumberRectangle(i);
        cout << endl;
    }
}

void Q2(void){
    int m1[2][2], m2[2][2], ans[3][3] = {0};
    cout << "Please enter the first matrix: " << endl;
    for (int i = 0; i < 2; i++) {
        for (int j = 0; j < 2; j++){
           cin >> m1[i][j];
        }
    }
    cout << "Please enter the second matrix: " << endl;
    for (int i = 0; i < 2; i++){
        for (int j = 0; j < 2; j++) {
            cin >> m2[i][j];
        }
    }
    cout << "The first matrix is " << endl;
    for (int i = 0; i < 2; i++){
        for (int j = 0; j < 2; j++){
            cout << m1[i][j] << " ";
        }
        cout << endl;
    }
    cout << "The second matrix is " << endl;
    for (int i = 0; i < 2; i++){
        for (int j = 0; j < 2; j++){
            cout << m2[i][j] << " ";
        }
        cout << endl;
    }
    
    
    cout << "The answer is: " << endl;
    for (int i = 0; i < 2; i++) {
        for (int j = 0; j < 2; j++){
            for (int k = 0; k < 2; k++){
                ans[i][j] += m1[i][k] * m2[k][j];
            }
        }
    }
    for (int i = 0; i < 2; i++){
        for (int j = 0; j < 2; j++){
            cout << ans[i][j] << " ";
        }
        cout << endl;
    }
}

int main(void){
    cout << endl;
    Q1();
    NumberRectangle(9);
    Q2();

    return 0;
}