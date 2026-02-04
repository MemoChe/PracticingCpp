#include <forward_list>
#include <iostream>

using namespace std;


int main (int argc, char *argv[]) {
  int num2 = 10;
  int num3 = 5;
  int & num = num2;
  num = num3;
  cout << num << endl;
  forward_list<int> l;
  return 0;
}
