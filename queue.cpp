#include <iostream>
#include <print>
#include <queue>
#include <vector>



int main (int argc, char *argv[]) {
  std::vector <int> lista {1,2,3,4,5,6};
  std::queue<int> cola; // A queue don't accept initializer_list only with push method
  // that is, std::queue<int> queue {1,2,3,4,5,6}
  // Only we can add an container to a queue
  // Only if we have another queue list ({1,2,3})
  std::queue<int> cola2 ({1,2,3,4,5,6,7});
  std::queue<int> cola3;
  for (int i = 1 ; i <= 9 ; i++){
    cola3.push(i);
  }
  std::queue <int,std::vector<int>> cola4 (lista);
  //cola3.pop(); Show an error if it is a vector of container, only a list and another queue work
  //std::queue<int, std::deque<int>> cola1;
  //std::queue<int, std::list<int>> cola2;
  //INSERTION
  cola.push(1);
  cola.push(2);
  cola.push(3);
  //ACCESS
  std::cout << cola.front() << std::endl;
  std::cout << cola.back() << std::endl;
  //MODIFICATION
  cola.front() = 1;
  cola.back() = 3;
  //REMOVAL 
  //cola.pop() removes the first element inserted
  while (!cola.empty()){
    std::cout << cola.front() << " ";
    cola.pop();
  }
  std::cout << std::endl;
  //cola.push_range();
  return 0;
}
