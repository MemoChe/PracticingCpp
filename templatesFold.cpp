#include <iostream>
#include <ostream>


template <typename... Args>
void printElements (Args... args){
  ((std::cout << args << " "),...);
  std::cout << std::endl;
}

void printname (){
  std::cout << "guillermo"<< std::endl;
}

void printage (){
  std::cout << 18<< std::endl;
}

void printlastname (){
  std::cout << "manrique"<< std::endl;
}

template <typename... Args>
void FunctionsRecursive (Args... args){
  (args(),...);
}


int main (int argc, char *argv[]) {
  printElements(1,2,3);
  FunctionsRecursive(printname,printlastname,printage);

  
  return 0;
}
