// 12-13-2023 1121 Programming(I) TA class

#include <cstdlib>
#include <ctime>
#include <iomanip>
#include <iostream>
#include <string>

#define SIZE 10

using namespace std;

template <typename T>
void func(T[]);
template <typename T>
void bubbleSort(T[]);
template <typename T>
int binarySearch(T[], T);

int main(void) {
    srand((unsigned)time(NULL));

    int intAry[SIZE];
    func(intAry);

    float douAry[SIZE];
    func(douAry);

    string strAry[SIZE];
    func(strAry);

    return 0;
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