#include<iostream>
#include<cstdlib>
#include<iomanip>
using namespace std;

#define SIZE 100

void Q1(void){
    int numbers[SIZE];

    for(int i = 0; i < SIZE; i++){
        numbers[i] = rand() % 31;
    }

    for(auto &i : numbers){
        cout << i << " ";
    }

    //bubble sort
    for(int i = 0; i < SIZE-1; i++){
        for(int j = 0; j < SIZE - i - 1; j++){
            if(numbers[j] > numbers[j+1]){
                int temp = numbers[j];
                numbers[j] = numbers[j+1];
                numbers[j+1] = temp;
            }
        }
    }

    //sum all element
    int sum = 0;
    for(auto &i : numbers){
        sum += i;
    }

    //find Median
    double median = 0;
    if(SIZE % 2 == 0){
        median = (numbers[SIZE/2] + numbers[SIZE/2 +1]) / 2;
    }
    else{
        median = numbers[SIZE/2 +1];
    }

    //find Mode
    int current = numbers[0], count = 0, Mode, countOfMode = 0;
    for(auto &i : numbers){
        if(i == current){
            count++;
        }
        else{
            if(count > countOfMode){
                countOfMode = count;
                Mode = current;
            }
            count = 1;
            current = i;
        }
    }

    cout << "\nMean: " << sum / SIZE << " Median: " << median << " Mode: " << Mode;
}

void Q2(void){
    int numbers[10];

    for(int i = 0; i < 10; i++){
        numbers[i] = rand() % 31;
    }

    for(auto &i : numbers){
        cout << setw(3) << i;
    }
    cout << endl;

    for(int i = 0; i < 10-1; i++){
        for(int j = 0; j < 10 - i - 1; j++){
            if(numbers[j] > numbers[j+1]){
                int temp = numbers[j];
                numbers[j] = numbers[j+1];
                numbers[j+1] = temp;
                for(auto &i : numbers){
                    cout << setw(3) << i;
                }
                cout << endl;
                
                //print the "---"
                for(int k = 0; k < 10; k++){
                    if(k == j || k==j+1){
                        cout << "---";
                    }
                    else{
                        cout << "   ";
                    }
                }
                cout << endl;
            }
        }
    }
}

void Q3(void){
    int matrix[3][3];
    cout << "Please input 9 numbers: ";
    for (int i = 0; i < 3; i++) {
        for(int j = 0; j < 3; j++) {
            cin >> matrix[i][j];
        }
    }
    
    cout << "Before transpose: " << endl;
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            cout << matrix[i][j] << " ";
        }
        cout << endl;
    }
    
    cout << "After transpose: " << endl;
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            cout << matrix[j][i] << " ";
        }
        cout << endl;
    }
}

int main(void){
    // Q1();
    // Q2();
    Q3();
}