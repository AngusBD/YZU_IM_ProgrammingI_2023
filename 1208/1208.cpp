#include <iostream>
#include <string>

using namespace std;

void q1(void);

void q2(void);
string decToHex(int);

void q3(void);

int main(void) {
    // q1();
    // q2();
    // q3();
    return 0;
}

void q1(void) {
    string input = "" ;
    cout << "Input: ";
    getline(cin, input);
    cout << "Output: "; 
    for (int i = 0; i < input.length(); i++) {
        cout << char(input[i] - 7);
    }
    cout << endl;
    return;
}

void q2(void) {
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

void q3(void) {
    int idx = 0;
    string input = "", actions = "";

    cout << "Please enter a sentence: ";
    getline(cin, input);
    cout << "Please enter series of action: ";
    getline(cin, actions);
    
    for(int i = 0; i < actions.length(); i++) {
        switch (actions[i]) {
            case '0':
                idx = 0;
                break;
            case '$':
                idx = input.length();
                break;
            case 'x':
                if (idx != input.length()){
                    input.replace(idx, 1, "");
                }
                break;
            case 's':
                if (idx != input.length() && idx != input.length() - 1) {
                    input[idx] ^= input[idx + 1];
                    input[idx + 1] ^= input[idx];
                    input[idx] ^= input[idx + 1];
                }
                break;
            case 'i':
                input.insert(idx++, 1, actions[i++ + 1]);
                break;
            case 'u':
                if (isalpha(input[idx])) {
                    input[idx] = toupper(input[idx]);
                }
                idx++;
                break;
            case '+':
                idx++;
                break;
            case '-':
                idx--;
                break;
            default:
                cout << "Unknown action '" << actions[i] << "', ignored and skip to next action." << endl;
        }
    }

    cout << "The final output is: " << input << endl;

    return;
}