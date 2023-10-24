#include<iostream>
#include<cmath>

using namespace std;

int main(void){
    double height, weight, BMI;
    cin >> height >> weight;
    weight*=0.45;
    height*=0.025;
    BMI = weight/pow(height, 2);
    if(BMI < 18.5){
        cout << BMI << " Underweight.";
    }
    else if(BMI >= 18.5 && BMI <= 24.9){
        cout << BMI << " Normal.";
    }
    else if(BMI >= 25.0 && BMI <=29.9){
        cout << BMI << " Overweight.";
    }
    else{
        cout << BMI << " Obesity.";
    }
    return 0;
}