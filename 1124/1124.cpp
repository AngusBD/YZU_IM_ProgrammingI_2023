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
        if(total % 11 == 10){
            isbn1[isbn1.length() - 1] = 'X';
        }
        else{
            isbn1[isbn1.length() - 1] = (total % 11) + '0';
        }
        cout << isbn1;
    }
}


void Q3(){
    string str_pwd = "";
    cout << "Please input the string: ";
    getline(cin, str_pwd);
    cout << "The actual password is: ";
    for(int i = 1; i < str_pwd.length(); i++) {
        cout << abs(str_pwd[i] - str_pwd[i-1]);
    }
    cout << endl;
}

void Q4(){
    string input = "", index = "";
    cout << "Please input the string: ";
    getline(cin,input);
    cout << "Plese input the index: ";
    getline(cin,index);

    // bubble sort index and input which both are string simultaneously
    for(int i = 0; i < index.length(); i++)
    {
        for(int j = 0; j < index.length() - 1; j++)
        {
            if(index[j] > index[j+1])
            {
                index[j] ^= index[j+1];
                index[j+1] ^= index[j];
                index[j] ^= index[j+1];
                
                input[j] ^= input[j+1];
                input[j+1] ^= input[j];
                input[j] ^= input[j+1];
            }
        }
    }
    cout << input << endl;
}

int main(void){
    Q1();
    Q2();
    Q3();
    Q4();
}