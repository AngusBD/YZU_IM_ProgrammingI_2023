#include<iostream>
#include<string>
#include<algorithm>//std::reverse
// #include<cstdlib>//std::atoi

using namespace std;

//a022 palindrome
void Q1(){
    string str1 = "abcba";
    // string str1 = "ab123ba";

    string str_r = str1;
    reverse(str_r.begin(), str_r.end());
    if(str1 == str_r){
        cout << "Yes";
    }
    else{
        cout << "No";
    }

}

//Valid ISBN
void Q2(){
    string isbn1 = "0-670-82162-0";
    int total = 0;
    for(int i = 0, multiplier = 1; i < isbn1.length()-2; i++){
        if(isdigit(isbn1[i])){
            total += (isbn1[i] - '0') * multiplier++;
        }
    }
    if(total % 11 == (isbn1.back() - '0')){
        cout << "Valid";
    }
    else{
        isbn1[isbn1.length() - 1] = (total % 11) + '0';
        cout << isbn1;
    }
}

int main(void){
    Q2();
}