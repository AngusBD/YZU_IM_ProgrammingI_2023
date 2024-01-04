#include <ctime>
#include <iomanip>
#include <iostream>
#include <string>

#define SIZE 10

using namespace std;

void q1(void);
bool password(string);

void q2(void);

void q3(void);
template <typename T>
void func(T[]);
template <typename T>
void bubbleSort(T[]);
template <typename T>
int binarySearch(T[], T);

int main(void) {
    q1();
    q2();
    q3();

    return 0;
}

void q1(void) {
    string input = "";
    cout << "Please input a password: ";
    getline(cin, input);
    if (password(input)) {
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

void q2(void) {
    int idx = 0;
    string input = "", actions = "";

    cout << "Please enter a sentence: ";
    getline(cin, input);
    cout << "Please enter series of action: ";
    getline(cin, actions);

    for (int i = 0; i < actions.length(); i++) {
        switch (actions[i]) {
            case '0':
                idx = 0;
                break;
            case '$':
                idx = input.length();
                break;
            case 'x':
                if (idx != input.length()) {
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
                cout << "Unknown action '" << actions[i]
                     << "', ignored and skip to next action." << endl;
        }
    }

    cout << "The final output is: " << input << endl;

    return;
}

void q3(void) {
    srand((unsigned)time(NULL));

    int intAry[SIZE];
    func(intAry);

    float douAry[SIZE];
    func(douAry);

    string strAry[SIZE];
    func(strAry);

    return;
}

template <typename T>
void func(T ary[]) {
    if (is_same<T, int>::value) {
        cout << "Original int array: " << endl;
        for (int i = 0; i < SIZE; i++) {
            // rand() % (b - a + 1) + a
            ary[i] = rand() % (100 - 1 + 1) + 1;
            cout << ary[i] << " ";
        }
    } else if (is_same<T, float>::value) {
        cout << "Original float array: " << endl;
        cout << fixed << setprecision(1);
        for (int i = 0; i < SIZE; i++) {
            ary[i] = (rand() % (100 - 1 + 1) + 1) * 0.3;
            cout << ary[i] << " ";
        }
    } else if (is_same<T, string>::value) {
        cout << "Please enter " << SIZE << " strings: " << endl;
        for (int i = 0; i < SIZE; i++) {
            cin >> ary[i];
        }
        cout << "Original string array: " << endl;
        for (int i = 0; i < SIZE; i++) {
            cout << ary[i] << " ";
        }
    }
    cout << endl;

    bubbleSort(ary);

    cout << "After bubble sort: " << endl;
    for (int i = 0; i < SIZE; i++) {
        cout << ary[i] << " ";
    }
    cout << endl;

    T tgt;
    cout << "Please enter an element to search: ";
    cin >> tgt;
    int idx = binarySearch(ary, tgt);
    if (idx == -1) {
        cout << tgt << " does not exist in the array" << endl;
    } else {
        cout << tgt << " is at index " << idx << endl;
    }
    cout << endl;

    return;
}

template <typename T>
void bubbleSort(T data[]) {
    T temp;
    for (int i = 0; i < SIZE - 1; i++) {
        for (int j = 0; j < SIZE - i - 1; j++) {
            if (data[j] > data[j + 1]) {
                temp = data[j + 1];
                data[j + 1] = data[j];
                data[j] = temp;
            }
        }
    }
    return;
}

template <typename T>
int binarySearch(T data[], T tgt) {
    int l = 0, h = SIZE - 1, m;
    for (m = (l + h) / 2; l <= h; m = (l + h) / 2) {
        if (data[m] == tgt) {
            return m;
        } else if (data[m] < tgt) {
            l = m + 1;
        } else {
            h = m - 1;
        }
    }
    return -1;
}