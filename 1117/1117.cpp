#include<iostream>
#include<string>
#include<cmath>

using namespace std;

void display(const char*, int);
void square(int *);

void Q1(){
    // string str = "Hello, World.";
    const char *ptr = "Hello, World.";
    display(ptr, 3);
}

void display(const char *ptr, int n){
    // string newStr = ptr;
    // cout << newStr.substr(n, newStr.length());
    ptr += n;
    cout << ptr;
}

void Q2(){
    int a[5] = {1,2,3,4,5};
    square(a);
    for(auto &i : a){
        cout << i << " ";
    }
}

void square(int *arr){
    for(int i = 0; i < 5; i++){
        *(arr+i) = pow(*(arr+i), 2);
    }
}

void Q3(){
    string str;
    for(int i = 32; i < 126; i++){
        char temp = i;
        str += temp;
    }
    char *ptr = &str[0];
    cout << ptr << endl;
    for(int i = 0; i < str.length(); i++){
        if(*(ptr+i) >= 'a' && *(ptr + i) <= 'z'){
            *(ptr + i) = *(ptr + i) + ('A' - 'a');
        }
    }
    cout << ptr << endl;
}

int main(){
    // Q1();
    // Q2();
    Q3();
}