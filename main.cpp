#include <iostream>
#include <vector>

using namespace std;


int main (int argc, char *argv[]) {
  vector <int > lista {1,2,3};
  int * pointer = lista.data();
  int * pointer2 = &lista[0];
  cout << *pointer << " " << *pointer2 << endl;
  cout << pointer << " " << pointer2 << endl;
  ++++pointer2;
  ++++pointer;
  cout << *pointer << " " << *pointer2 << endl;
  cout << "------" << endl;
  ++pointer;
  cout << *pointer << endl;;
  cout << "------" << endl;
  ++pointer2;
  cout << *pointer2 << endl;
  cout << "------" << endl;
  auto it = lista.insert(lista.end()-1,lista.begin(),lista.end());
  for(auto u : lista ) {
    cout << u << " ";
  }
  cout << endl;
  lista.assign({1,2,3,4,5,6});
  for (auto u : lista) {
    cout << u << " ";
  }
  cout << endl;
  cout << "Lista : ";
  auto iterator = lista.erase( lista.end()-1);
  for (auto u : lista) {
    cout << u << " ";
  }
  cout << endl;
  cout << iterator - lista.begin() << endl;
  if (iterator == lista.end()){
    cout << "Son iguales" << endl;
  }
  for (auto it2 = lista.rbegin(); it2 != lista.rend(); it2++ ){
    cout << *it2 << " ";
  }
  cout << endl;
  cout << "*lista.rbegin(): " << *lista.rbegin()<< endl;
  cout << "*lista.rbegin().base(): " << *lista.rbegin().base() << endl;
  cout << lista.rend()-lista.rbegin() << endl;
  cout << lista.end()-(lista.rbegin().base()-1) << endl;
  if (lista.end() == lista.rbegin().base()) {
    cout << "Son iguales" << endl;
  }
  for (auto u : lista){
    cout << u << " ";
  }
  cout << endl;
  // 1 2 3 4  5       5 4       3    2 1 => lista.begin()+1 
  // lista.begin()+ size(5) 
  cout << lista.end() - (lista.rbegin()+2).base() << endl;
  for (auto it2 = lista.rend(); it2 != lista.rbegin() ; it2--) {
    cout <<  (it2.base()-lista.begin()) << " ";
  }
  cout << endl;
  return 0; 
}
