#include <deque>
#include <iostream>


template <typename T>
void print (const T& container){
  for(const auto& u : container){
    std::cout << u << " ";
  }
  std::cout << std::endl;
}



int main (int argc, char *argv[]) {
  std::deque <int> cola {1,2,3,4,5};
  std::deque <int> cola2;
  cola2.assign({9,9,9,9,8});
  cola.swap(cola2); // Swap between two deques
  print(cola);
  print(cola2);
  cola2.push_back(6); // Add an elemente at the end
  cola2.emplace_back(7); //Add an element at the end
  cola2.push_front(0); // Add an element at the beginning
  cola2.emplace_front(-1);// Add an element at the beginning
  print(cola2);
  cola2.pop_back();// Remove the last element 
  cola2.pop_front(); // Remove the first element
  print(cola2);
  std::cout << cola2.front();// First element 
  std::cout << cola2.back(); // Last element
  for(auto it = cola2.begin(); it!= cola2.end() ; it++){
    std::cout << *it << " ";
  }
  std::cout << std::endl;




  
  return 0;
}
