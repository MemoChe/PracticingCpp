#include <iostream>
#include <iterator>
#include <list>

template <typename T>
void print (const T & container) {
  for (auto u: container) {
    std::cout << u << " ";
  }
  std::cout << std::endl;
}

int main (int argc, char *argv[]) {
  //DECLARATION
  std::list <int> LinkList {1,2,3,4,5,6}; // list is a doubly linked list
  std::list <int> LinkList2 (5,7); // create a list with a value 7
  std::list <int> LinkList3 (LinkList2);// COPY ITS CONSTRUCTOR OF LINKLIST2
  // Copy iterators std::list <int> LinkList  (lista.begin(), lista.end ());
  //ACCESS TO ELEMENTS
  int firstElement = LinkList.front();
  int secondeElement = LinkList2.back();
  for (auto it {LinkList.begin()}; it!= LinkList.end(); it++){
    std::cout << *it << " "; 
  }
  std::cout << std::endl;
  for (auto it {LinkList.rbegin()}; it != LinkList.rend(); it++){
    std::cout << *it << " ";
  }
  std::cout << std::endl;
  std::cout << std::endl;
  std::cout << *LinkList.begin() << std::endl; // DONT WORK LINKLIST.BEGIN()+1 or LINKLIST.BEGIN ()+2
  auto iterator = std::next(LinkList.begin(),2);//The unique posible way it is with the methos next or prev
  iterator = std::next (iterator,2); //METHOD NEXT TO ITERATOR
  iterator = std::prev(iterator,1);
  std::list <int> l {1,2,3,4,5,6};
  auto secIt = l.begin();
  std::advance(secIt,5);
  std::advance(secIt,-2);
  std::cout << *secIt << std::endl;
  // WE CAN USE ADVANCE TO MOVE OUT ITERATOR WITHOUT ERROS
  std::cout << *iterator  << std::endl;
  LinkList.front() = 9; 
  LinkList.back() = 0; 
  LinkList.sort();// SORT THE DOUBLE LINKED LIST
  print(LinkList);
  //INSERTING ELEMENTS AND REMOVES ELEMENTS
  LinkList.push_back(10);
  LinkList.push_front(1);
  LinkList.pop_back(); // REMOVES THE LAST ELEMENT
  LinkList.pop_front(); //REMOVES THE FIRST ELEMENT
  LinkList.emplace_back(10);
  LinkList.emplace_front(1);
  LinkList.emplace(LinkList.begin(), 11);
  print(LinkList);
  LinkList.sort();
  print(LinkList);
  auto iterator1 = LinkList.begin();
  auto iterator2 = LinkList.begin();
  std::advance(iterator1,6);
  std::advance(iterator2,9); // REMEMBER [lista.begin(), lista.begin()+9 > lista.begin ()+9 = lista.end()
  print(LinkList);
  LinkList.erase(iterator1,iterator2);
  print(LinkList);
  //DONT EXIST OPERATOR [] nor .at()
  //LinkList.clear();//DELETES EVERYTHING
  LinkList.sort();
  //UNIQUES OPERATIONS
  std::list <int> l1 {1,2,3};
  std::list <int> l2 {4,5,6};
  l1.splice(l1.end(),l2);
  print(l1); // l1 = {1,2,3,4,5,6}
  print(l2); // l2 = {}
  l1.assign({1,2,3});
  l2.assign({4,5,6});
  auto iterator3 = l2.begin();
  std::advance(iterator3,1);
  l1.splice(l1.end(),l2,iterator3); // GRAB THE CONTAINER AND ONE OF ITS ITERATORS
  print(l1);
  print(l2);
  l1.assign({1,2,3});
  l2.assign({4,5,6});
  auto iterator4 = l2.begin();
  auto iterator5 = l2.end(); //l2.begin()+3
  auto iterator6 = l2.begin();
  std::advance(iterator6,3);
  l1.splice(l1.end(),l2,iterator4,iterator6);
  print(l1);
  l1.push_back(6);
  l1.push_back(6);
  print(l1);
  l1.remove(6);
  print(l1);
  l1.remove_if([](int value) { return value % 2 == 0;});
  print(l1);
  l1.assign({1,2,3,4,5,6});
  l1.remove_if([](int value) { return value % 2 == 1;});
  print(l1);
  l1.assign({1,2,3,4,5,6});
  print(l1);
  l1.push_back(1);
  l1.push_back(6);
  l1.push_back(2);
  l1.push_back(6);
  l1.push_back(4);
  print(l1);
  l1.unique(); // Nothing happened, the list remains the same. because only element consecutives work
  print(l1); //
  l1.sort();
  print(l1); //1 2 3 4 5 6 1 6 2 6 4
  l1.unique(); // {1 1 2 2 3 4 4 5 6 6 6}
  print(l1); // Now we have {1,2,3,4,5,6};
  l1.reverse();
  print(l1);
  l1.assign(3,7);
  print(l1);
  l1.assign({1,2,3,4,5,6});
  print(l1);
  std::cout<< l1.size()<<std::endl;





  return 0;
}
