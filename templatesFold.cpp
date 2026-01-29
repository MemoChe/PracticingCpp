#include <iostream>
#include <ostream>


template <typename... Args>
void printElements (Args... args){ // this expression is equal to 
  ((std::cout << args << " "),...); // (std::cout << arg1 << " ")
  std::cout << std::endl;           // (std::cout << arg2 << " ")
}                                   // (std::cout << arg3 << " ")

void printname (){
  std::cout << "guillermo"<< std::endl;
}
void printage (){
  std::cout << 35<< std::endl;
}
void printlastname (){
  std::cout << "manrique"<< std::endl;
}
template <typename... Args>
void FunctionsRecursive (Args... args){
  (args(),...);
}

template <typename... Args>
auto SumOfNumbers (Args... args){
  return (...+args);
}

template <typename... Args, typename T> //forces us to define <int,int,int> 
bool NumberLessThan (Args... args, T num){//according to how many arguments we have
  return (... && (args < num));
}
template <typename... Args, typename T>
bool NumberLessThan2(T num ,Args... args){
  return (... && (args < num));
}

template <typename... Args>
void NumberOfArguments (Args... args){
  std::cout << "The number of arguments is/are " <<sizeof... (args) << std::endl;
}
template <typename... Args>
auto AverageOfNumbers (Args... args){
  auto u = (...+args)/sizeof...(args);
  return 0 + u;
}


int main (int argc, char *argv[]) {
  printElements(1,2,3);
  FunctionsRecursive(printname,printlastname,printage);
  std::cout << SumOfNumbers(1,2,3,4) << std::endl; 
  if (NumberLessThan <int,int,int> (1,2,3,10)){
    std::cout << "The numbers are less than 10"<< std::endl;
  }else{
    std::cout << "The numbers are greater than 10"<< std::endl;
  }
  if (NumberLessThan2 (10,1,2,3,4,5)){
    std::cout << "The numbers are less than 10"<< std::endl;
  }else{
    std::cout << "The numbers are greater than 10"<< std::endl;
  }
  NumberOfArguments(1,2,"string",1.2);
  std::cout << "The average of 1,2,3,4,5 is: " << AverageOfNumbers(1,2,3,4,5) << std::endl;

  return 0;
}
