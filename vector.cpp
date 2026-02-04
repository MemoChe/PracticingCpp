#include <algorithm>
#include <cstddef>
#include <initializer_list>
#include <iterator>
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
  std::vector<int> lista2({1,2,3});
  std::vector<int>lista3(5,3);//initialize the vector with thwe value {3,3,3,3,3,3} 
  //┌────┬────┬────┬────┬────┐
  //│  1 │  2 │  3 │  4 │  5 │
  //└────┴────┴────┴────┴────┘
  //  ^                         ^
  //begin()                   end()
  print(lista);
  print(lista2);
  print(lista3);
  //ADD ELEMENTS AND ERASE ELEMENTS
  std::cout << "-----------------------------" << std::endl;
  lista.push_back(4); // Add an element at the end
  lista.emplace_back(5);
  lista.emplace(lista.begin(),0); //
  print(lista);
  std::cout << "-----------------------------" << std::endl;
  lista.pop_back(); // Remove the last element 
  print(lista);
  lista.erase(lista.begin());// Remove the first element 
  print(lista);
  lista.erase (lista.end()-1,lista.end()); // Removes elements from position end()-1 (last) to the end
  print(lista);
  // INSERT
  lista.insert (lista.begin(),100); //Insert 100 at the beginning
  print(lista);
  lista.insert (lista.begin()+2,100); // Insert 100 at the position two
  print(lista);
  lista.erase(lista.begin());
  print(lista);
  lista.erase(lista.begin()+1);
  print(lista);
  // ACCESS
  int v1 = lista[0];
  int v2 = lista.at(0);
  int v3 = lista.front(); // lista.front () = 100; 
  int v4 = lista.back(); // lista.front () = 200;
  std::cout << "lista[0]: " <<  v1 << "\nlista.at(0): " << v2 << " " << 
    "\nlista.front(): " <<v3 << "\nlista.back(): " << v4 << std::endl;
  print(lista);
  //INFORMATION
  std::cout << "-----------------------------" << std::endl;
  size_t size = lista.size();
  bool empty = lista.empty();
  size_t capacity = lista.capacity();
  size_t max_size = lista.max_size();
  std::cout << "size: " << size << std::endl;
  std::cout << "is it empy? : " << empty << std::endl;
  std::cout << "capacity: " << capacity << std::endl;
  std::cout << "max size: " << max_size << std::endl;
  lista.shrink_to_fit();
  std::cout << "size and capacity: " <<size << "-" << lista.capacity()<< std::endl;
  std::cout << "-----------------------------" << std::endl;
  //MODIFY SIZE
  std::cout << "Resize the elements of the vector to 10!" << std::endl;
  lista.resize(10); //Number of elements
  print(lista);
  std::cout << "reserving the capacity to 100!" << std::endl;
  lista.reserve(100); // Capacity 100
  print(lista);
  std::cout << "-----------------------------" << std::endl;
  //REPLACE
  std::cout << "Assign its like replacing everything with an initializer_list or two arguments like this:" <<std::endl;
  lista.assign(5,100); // replace the content with 5x100
  print(lista);
  //  initializer_list with assign
  lista.assign(std::initializer_list<int> {1,2,3});
  print(lista);
  int * pointer = lista.data(); // point to the first position of the vector
  std::cout << pointer << std::endl;
  std::cout << *pointer << " " << *++pointer << " " << *++pointer  << std::endl;
  print(lista);
  std::vector<int>::iterator it;
  std::vector<int>::const_iterator const_it;
  std::vector<int>::reverse_iterator rever_it;
  std::cout << "------------------------" << std::endl;
  for (auto iterator = lista.begin(); iterator != lista.end(); iterator++) {
    std::cout << *iterator << " ";
  }
  std::cout << std::endl;
  auto at = lista.begin();
  std::cout << *++++++at << std::endl; // it work
  std::cout << "We can use methods like find,sort,etc of the library algorithm" <<std::endl;
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
  lista2.assign({1,2,3,4,5,6});
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
  //ASSIGN MORE IN DETAIL
  std::cout << "---------------------"<<std::endl;
  std::cout << "Assign in more detail" <<std::endl;
  lista.assign({1,2,3});//initializer_list
  lista2.assign({4,5,6});
  lista3.assign(5,3);// assign(number of elements to be assign, value of the elements);
  print(lista3);
  lista3.assign(lista.begin(),lista.end());// {3,3,3,3,3} ->  {1,2,3}
  print(lista3);

  return 0;
}
