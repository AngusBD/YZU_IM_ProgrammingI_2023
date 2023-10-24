#include<iostream>
#include<cstdlib>
#include<ctime>

using namespace std;

bool is_prime(int);
string to_binary(int);

void Exercise_6_1(){
    int num;
    for(int i = 0; i < 6; i++){
        num = rand();
        cout << num % 50 << " ";
    }
}

void Exercise_6_2(){
    for(int i = 0; i < 9; i++){
        for(int j = 0; j < i + 1; j++){
            cout << "*";
        }
        cout << endl;
    }

    cout << endl;
    
    for(int i = 0; i < 9; i++){
        for(int j = 0; j < 9 - i -1; j++){
            cout << " ";
        }
        for(int j = 0; j < i + 1; j++){
            cout << "*";
        }
        cout << endl;
    }
    
    cout << endl;
    
    for(int i = 0; i < 9; i++){
        for(int j = 0; j < 9 - i; j++){
            cout << "*";
        }
        cout << endl;
    }

    cout << endl;
    
    for(int i = 0; i < 9; i++){
        for(int j = 0; j < i; j++){
            cout << " ";
        }
        for(int j = 0; j < 9 - i; j++){
            cout << "*";
        }
        cout << endl;
    }

}

void Exercise_6_3(){
    int num1, num2;
    cin >> num1 >> num2;
    for(int i = num1; i <= num2; i++){
        if(is_prime(i)){
            cout << i << " ";
        }
    }
}

bool is_prime(int n){
    if (n == 0 || n == 1) {
        return false;
    }
    for (int i = 2; i <= n/2; i++) {
        if (n % i == 0) {
            return false;
        }
    }
    return true;
}

void Exercise_6_4(){
    int n;
    cin >> n;
    cout << to_binary(n);
}

string to_binary(int n){
    string bin;
    for(; n != 0;){
        bin = (n % 2 == 0 ? "0" : "1") + bin;
        n /= 2;
    }
    return bin;
}

int main(void){
    srand(time(NULL));
    cout << endl;
    Exercise_6_4();
    cout << "\n\n";
    return 0;
}