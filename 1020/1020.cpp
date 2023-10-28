#include <cstdlib>
#include <ctime>
#include <iostream>
#include <string>

using namespace std;

void q1(void);
void q2(void);
void q3(void);

int main(void) {
    q1();
    q2();
    q3();
    return 0;
}

void q1(void) {
    int ary[5];

    cout << "Please enter 5 integers: " << endl;

    for (int i = 0; i < 5; i++) {
        cin >> ary[i];
    }

    for (int i = 0; i < 5; i++) {
        if (i == 0) {
            cout << ary[i] << " ";
        } else {
            cout << ary[i] - ary[i - 1] << " ";
        }
    }

    cout << endl;
    return;
}

void q2(void) {
    char letter[26];
    int num[26], check[] = {1, 9, 8, 7, 6, 5, 4, 3, 2, 1, 1}, ans;
    string input;

    // initialize the letter and the number
    for (int i = 'A'; i <= 'Z'; i++) {
        letter[i - 65] = i;
    }

    for (int i = 0, j = 10; i < 26; i++) {
        switch (letter[i]) {
            case 'I':
                num[i] = 34;
                break;
            case 'O':
                num[i] = 35;
                break;
            case 'W':
                num[i] = 32;
                break;
            case 'Z':
                num[i] = 33;
                break;
            default:
                num[i] = j;
                j++;
                break;
        }
    }

    // get the ID no.
    cout << "Please enter ID number: ";
    getline(cin, input);

    // calculate the input to make sure it is valid
    // the ascii of A is 65
    ans = (num[input[0] - 65]) / 10 * check[0] +
          (num[input[0] - 65]) % 10 * check[1];

    for (int i = 1; i < input.length(); i++) {
        // the ascii of 0 is 48
        ans += (input[i] - 48) * check[i + 1];
    }

    // print the answer
    if (ans % 10 == 0) {
        cout << "Valid ";
        if (input[1] == '1') {
            cout << "Man" << endl;
        } else {
            cout << "Woman" << endl;
        }
    } else {
        cout << "Invalid" << endl;
    }

    return;
}

void q3(void) {
    char letter[26];
    int num[26], check[] = {1, 9, 8, 7, 6, 5, 4, 3, 2, 1, 1}, ans;

    // initialize the letter
    for (int i = 'A'; i <= 'Z'; i++) {
        letter[i - 65] = i;
    }

    // initialize the number
    for (int i = 0, j = 10; i < 26; i++) {
        switch (letter[i]) {
            case 'I':
                num[i] = 34;
                break;
            case 'O':
                num[i] = 35;
                break;
            case 'W':
                num[i] = 32;
                break;
            case 'Z':
                num[i] = 33;
                break;
            default:
                num[i] = j;
                j++;
                break;
        }
    }

    // set the random seed
    srand(time(NULL));

    // loop until the valid ID was generated
    for (;;) {
        string input = "";

        // generate a random number between 0 and 25. This will be use as a index of the "letter" array.
        input += letter[rand() % (25 - 0 + 1)];

        // store number 0 ~ 9 as character in the "num_char" array.
        char num_char[10];
        for (int i = '0'; i <= '9'; i++) {
            // the ascii of 0 is 48
            num_char[i - 48] = i;
        }
        // generate a random number between 1 and 2. This will be use as a index of the "num_char" array.
        // this will be used to identify the ID is a male or female
        input += num_char[rand() % (2 - 1 + 1) + 1];

        // generate the remaining 8 numbers randomly
        for (int i = 0; i < 8; i++) {
            input += num_char[rand() % (9 - 0 + 1)];
        }

        // calculate the input to make sure it is valid
        // the ascii of A is 65
        ans = (num[input[0] - 65]) / 10 * check[0] +
              (num[input[0] - 65]) % 10 * check[1];

        for (int i = 1; i < input.length(); i++) {
            // the ascii of 0 is 48
            ans += (input[i] - 48) * check[i + 1];
        }

        // print the answer
        if (ans % 10 == 0) {
            cout << input << endl;
            if (input[1] == '1') {
                cout << "Man" << endl;
            } else {
                cout << "Woman" << endl;
            }
            break;
        }
    }

    return;
}