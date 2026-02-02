#include <iostream>
#include <vector>

template<typename T>
void print( const T & lista){
  for(const auto & n: lista){
    std::cout<<n <<" ";
  }
  std::cout<< std::endl;
}

int main (int argc, char *argv[]) {
  std::vector<int>lista{1,2,3,4,5,6};
  std::cout<< lista.capacity() <<std::endl;
  std::cout<< lista.size() << std::endl;
  lista.pop_back();
  std::cout<< lista.capacity() <<std::endl;
  std::cout<< lista.size() << std::endl;
  lista.resize(5);
  std::cout<< lista.capacity() <<std::endl;
  std::cout<< lista.size() << std::endl;
  lista.clear();
  print(lista);
  std::cout<< lista.capacity() <<std::endl;
  std::cout<< lista.size() << std::endl;
  lista.shrink_to_fit();
  std::cout<< lista.capacity() <<std::endl;
  std::cout<< lista.size() << std::endl;



  return 0;
}
