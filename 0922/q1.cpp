#include <iostream>
#include <string>

using namespace std;

int main(void) {
  int n;
  string str = "";
  cout << "Please enter an integer: ";
  cin >> n;
  cout << "This number is a multiple of";
  if (n % 2 == 0) {
    str += " 2,";
  }
  else if (n % 3 == 0) {
    str += " 3,";
  }
  if (n % 5 == 0) {
    str += " 5,";
  }
  if (n % 7 == 0) {
    str += " 7,";
  }
  str.pop_back();
  cout << str << endl;
}
