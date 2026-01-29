#include <vector>
#include <iostream>

int main (int argc, char *argv[]) {
  std::vector <int> lista {1,2,3};
  //ADD ELEMENTS
  lista.push_back(4); // Add an element at the end
  lista.emplace_back(5); // Add an element at the end efficiently
  // ERASE ELEMENTS
  lista.pop_back(); // Remove the last element 
  lista.erase(lista.begin());// Remove the first element 
  lista.erase(lista.begin()+1); // Remove the element from position 1
  // ACCESS
  int v1 = lista[0];
  int v2 = lista.at(0);
  int v3 = lista.front();
  int v4 = lista.back();
  //INFORMATION
  size_t size = lista.size();
  bool empty = lista.empty();
  size_t capacity = lista.capacity();
  //MODIFY SIZE
  lista.resize(10); //Number of elements
  lista.reserve(100); // Capacity 100
  // INSERT
  lista.insert (lista.begin(),100); //Insert 100 at the beginning
  lista.insert (lista.begin()+2,100); // Insert 100 at the position two
  //REPLACE
  lista.assign(5,100); // replace the content with 5x100


  for (auto u : lista){ 
    std::cout << u << " ";
  }
  std::cout << std::endl;

  return 0;
}
