#include <array>
#include <iostream>

int main (int argc, char *argv[]) {
  std::array<int, 6> arrayEstatico {1,2,3,4,5,6};
  int arrayC [] {1,2,3,4,5,6};
  for (auto u: arrayC){
    std::cout << u << " ";
  }
  std::cout << std::endl;
  for (auto u: arrayEstatico){
    std::cout << u << " ";
  }
  std::cout << std::endl;
  //ACCESS
  std::cout << arrayEstatico.at(0) << " " << arrayEstatico[0] << std::endl; 
  std::cout << arrayEstatico.front() << std::endl; // First element 
  std::cout << arrayEstatico.back() << std::endl; // Last element 
  // IT CAN ITERATE THE ARRAY WITH ITERATORS
  for (auto it {arrayEstatico.begin()}; it!= arrayEstatico.end(); it++){
    std::cout << *it << " ";
  }
  std::cout << std::endl;
  //UTIL METHODS LIKE SIZE EMPTY
  std::cout << arrayEstatico.size() << std::endl;
  for (auto it {arrayEstatico.rbegin()}; it!=arrayEstatico.rend(); it ++){
    std::cout << *it << " ";
  }
  std::cout << std::endl;
  bool ItsEmpty = arrayEstatico.empty(); // Check the array if it is empty
  std::cout << ItsEmpty << std::endl; 
  int * pointer = arrayEstatico.data();// A pointer of the firs element
  for (int i =0 ; i < 6; i++) {
    std::cout << *pointer << " " ;
    pointer++;
  }
  pointer++;
  std::cout << pointer << std::endl; // it works like a normal pointer
  arrayEstatico.fill(100); //change all values to the entered data
  for (auto u : arrayEstatico) {
    std::cout << u << " ";
  }
  std::cout << std::endl;
  std::array<int, 6> anotherArray; // only work if it has the same number of elements
  // dont work if i create an array anotherArray <int,7>
  arrayEstatico.swap(anotherArray);
  //std::array<int,6 > otherArray (std::to_array(arrayC));
  std::cout << arrayEstatico.max_size() << std::endl; //size () == max_size () because they are an array 
  return 0;
}
