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
  std::cout << cola2.front() << " ";// First element 
  std::cout << cola2.back() << std::endl; // Last element
  for(auto it = cola2.begin(); it!= cola2.end() ; it++){ // it can itera
    std::cout << *it << " ";
  }
  std::cout << std::endl;
  for (auto it = cola2.rbegin() ; it!= cola2.rend(); it++){
    std::cout << *it << " ";
  }
  std::cout << std::endl;
  cola2.assign({9,8,7,6});
  print(cola2);
  int e1 = cola2[0]; // element at position 0
  int e2 = cola2.at(0); //element at position 0
  int e3 = cola2.front(); // first element
  int e4 = cola2.back(); // last element
  std::cout << e1 << " " << e2 << " " << e3 << " " <<  e4 << std::endl;
  std::cout << "------------------------"<< std::endl;
  cola2.erase(cola2.end()-1);
  print(cola2);
  cola2.erase(cola2.begin(),cola2.end()-1); // Openly elimintes, that is[lista.begin(),lista.end()-1>
  print(cola2);
  //cola2.resize(2);
  std::cout << cola2.size() << std::endl; 
  //cola2.clear(); // Eliminates all the elements
  return 0;
}
