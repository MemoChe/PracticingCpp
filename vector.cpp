#include <algorithm>
#include <cstddef>
#include <initializer_list>
#include <iterator>
#include <memory>
#include <vector>
#include <iostream>

template <typename T >
void print (T & container) {
  for (auto u : container){
    std::cout << u << " ";
  }
  std::cout << std::endl;
}


int main (int argc, char *argv[]) {
  std::vector <int> lista {1,2,3};
  //ADD ELEMENTS
  lista.push_back(4); // Add an element at the end
  lista.push_back(5); // Add an element at the end efficiently
  print(lista);

  // ERASE ELEMENTS
  lista.pop_back(); // Remove the last element 
  print(lista);
  lista.erase(lista.begin());// Remove the first element 
  print(lista);
  lista.erase(lista.begin()+1); // Remove the element from position 1
  //lista.erase (lista.begin(),lista.begin ()+2); // Removes elements from position 0 to position 1, remenber is exclusice function like [>
  print(lista);
  // ACCESS
  int v1 = lista[0];
  int v2 = lista.at(0);
  int v3 = lista.front();
  int v4 = lista.back();
  std::cout << v1 << " " << v2 << " " << v3 << " " << v4 << std::endl;
  print(lista);
  //INFORMATION
  size_t size = lista.size();
  bool empty = lista.empty();
  size_t capacity = lista.capacity();
  std::cout << size << std::endl;
  std::cout << empty << std::endl;
  std::cout << capacity << std::endl;
  //MODIFY SIZE
  lista.resize(10); //Number of elements
  print(lista);
  lista.reserve(100); // Capacity 100
  print(lista);
  // INSERT
  lista.insert (lista.begin(),100); //Insert 100 at the beginning
  print(lista);
  lista.insert (lista.begin()+2,100); // Insert 100 at the position two
  print(lista);
  //REPLACE
  lista.assign(5,100); // replace the content with 5x100
  print(lista);
  std::cout << lista.size() << std::endl; // 5
  std::cout << size << std::endl; // 2
  std::cout << lista.max_size() << std::endl; // max size posible of container vector
  //  initializer_list with assign
  lista.assign(std::initializer_list<int> {1,2,3});
  print(lista);
  int * pointer = lista.data(); // point to the first position of the vector
  std::cout << pointer << std::endl;
  std::cout << *pointer << " " << *++pointer << " " << *++pointer  << std::endl;
  std::allocator<int> locator = lista.get_allocator(); 
  size_t elements = 3;
  int * rawMemory = locator.allocate(elements);
  locator.construct(rawMemory, 1);
  locator.construct(rawMemory + 1, 2);
  locator.construct(rawMemory + 2, 3);
  std::cout << std::endl;
  std::cout << rawMemory[0] << " " << rawMemory[1] << " " << rawMemory[2] << std::endl;
  locator.destroy(rawMemory);
  locator.destroy(rawMemory+1);
  locator.destroy(rawMemory+2);
  locator.deallocate(rawMemory, 3);
  print(lista);
  std::vector<int>::iterator it;
  std::vector<int>::const_iterator const_it;
  std::vector<int>::reverse_iterator rever_it;
  std::cout << "------------------------" << std::endl;
  for (auto iterator = lista.begin(); iterator != lista.end(); iterator++) {
    std::cout << *iterator << " ";
  }
  std::cout << std::endl;
  std::cout << *lista.end() << std::endl;
  auto at = lista.begin();
  std::cout << *++++++at << std::endl; // it work
  at = std::find(lista.begin(),lista.end(),3);
  std::cout << at-lista.begin() << std::endl;
  size_t sizetam = at - lista.begin();
  std::cout << sizetam << std::endl;
  at = lista.begin();
  ++++at;
  std::cout << *at << std::endl;
  size_t tam = at - lista.begin();
  std::cout << tam << std::endl;
  std::cout << lista.end() - lista.begin() << std::endl;
  std::vector <int> lista2;
  std::copy(lista.begin(),lista.begin()+2,std::back_inserter(lista2));
  print(lista2);
  for (int i = 0; i < lista.size() ; i ++ ) {
    std::cout << &lista[i] << " ";
  }
  std::cout << std::endl;
  std::cout << "---------------------"<<std::endl;
  lista2.emplace_back(3);
  print(lista2);
  for (auto iterator = lista2.rbegin() ; iterator != lista2.rend() ; iterator++) {
    std::cout << *iterator <<  " " ;
  }
  std::cout << std::endl;
  std::cout << &lista2[0] << " " << lista2.data() <<std::endl; // its the same memory location

  return 0;
}
