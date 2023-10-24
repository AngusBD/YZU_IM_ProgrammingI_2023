#include<iostream>
#include<cstdlib>
using namespace std;

void Q1(){
    int n = rand() % (10 - 1 + 1) + 1;  // rand() % (max - min + 1) + min
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= i; j++) {
            cout << i * j << "\t";
        }
        cout << endl;
    }
}

void Q2(){
    int price, money, n[] = {1000, 500, 100, 50, 10, 5, 1};
    for (;;) {
        cout << "Please enter the price and money: ";
        cin >> price >> money;
        if (price == -1 && money == -1) {
            cout << "exit..." << endl;
            break;
        } else if (price < 0 || money < 0) {
            cout << "Price or Money must be a positive integer!" << endl;
        } else {
            if (money < price) {
                cout << "Not enough money! You still need " << price - money << " dollars to pay." << endl;
            } else if (money - price == 0) {
                cout << "No change!" << endl;
            } else {
                int change = money - price;
                for (int i = 0; i < sizeof(n) / 4; i++) {
                    if (change >= n[i]) {
                        cout << n[i] << " * " << change / n[i] << endl;
                        change %= n[i];
                    }
                }
            }
        }
    }
}

void Q3(){
    int a, f;
    cin >> a >> f;
    for(int freauency = 0; freauency < f; freauency++){
        for(int height = 0; height < 2*a; height++){
            int x = a - abs(a - height);
            for(int k = abs(a - height); k < a; k++){
                cout << x;
            }
            cout << endl;
        }
    }
}

int main(void){
    srand(time(NULL));
    // Q1();
    Q2();
    // Q3();
}