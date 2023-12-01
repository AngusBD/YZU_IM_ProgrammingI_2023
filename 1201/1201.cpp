#include <iostream>
#include <string>
#include <cmath>

using namespace std;

void q1(void);
string reverse(string);

void q2(void);
bool password(string);

void q3(void);
string decToHex(int);

void q4(void);
int hexToDec(string);


int main(void) {
    // q1();
    // q2();
    // q3();
    for(;;) {
    q4();
    }
    
    return 0;
}

void q1(void) {
    string input = "";
    cout << "Please input a sentence: ";
    getline(cin, input);
    cout << "The reverse of the sentence is: " << reverse(input) << endl;
    return;
}

string reverse(string sentence) {
    string reverse = "";
    for (int i = sentence.length() - 1; i >= 0; i--) {
        reverse += sentence[i];
    }
    return reverse;
}

void q2(void) {
    string input = "";
    cout << "Please input a password: ";
    getline(cin, input);
    if(password(input)) {
        cout << "valid" << endl;
    } else {
        cout << "invalid" << endl;
    }
    return;
}

bool password(string pwd) {
    int digit_count = 0;
    // check if the password len is less len 8
    if (pwd.length() < 8) {
        return false;
    }
    // check if the password only contains alphabets and numbers
    for (int i = 0; i < pwd.length(); i++) {
        if (!isalnum(pwd[i])) {
            return false;
        }
        if (isdigit(pwd[i])) {
            digit_count += 1;
        }
    }
    // check if the password contains at least two numbers
    if (digit_count < 2) {
        return false;
    }
    // if pass all the checks, means the pwd is valid, return true
    return true;
}

void q3(void) {
    int num;
    cout << "Please enter a positive decimal integer: ";
    cin >> num;
    cout << "The hexadecimal of " << num << " is " << decToHex(num) << endl;
    return;
}

string decToHex(int dec) {
    string hex = "";
    for (;dec > 0;) {
        int remainder = dec % 16;
        char digit;
        if (remainder >= 10) {
            digit = 'A' + remainder - 10;
        } else {
            digit = '0' + remainder;
        }
        dec /= 16;
        hex = digit + hex;
    }
    return hex;
}

void q4(void) {
    string num = "";
    cout << "Please enter an hexadecimal number: ";
    getline(cin, num);
    cout << "The decimal number of " << num << " is " << hexToDec(num) << endl;
    return;
}

int hexToDec(string hex) {
    int dec = 0;
    char digit;
    for (int i = 0; i < hex.length(); i++) {
        hex[i] = toupper(hex[i]);
        if ('0' <= hex[i] && hex[i] <= '9') {
            digit = hex[i] - '0';
        } else if ('A' <= hex[i] && hex[i] <= 'F') {
            digit = hex[i] - 'A' + 10;
        }
        
        dec += digit * pow(16, hex.length() -1 - i);
    }

    return dec;
}