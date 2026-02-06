#include <map>
#include <string>
#include <utility>
#include <vector>
#include <iostream>


int main (int argc, char *argv[]) {
  std::map<std::string, int > d1 { {"viviana",19} , {"jenifer",24}};
  std::map<std::string, int > d2 (d1);
  std::map<std::string, int > d3 (d1.begin(),d1.end());
  //ACCESS,INSERT AND ADD ELEMENTS
  //Important: operator[] always creates the entry if it does not exist, even if you are only reading.
  d1["tania"] = 50;
  std::vector<std::string> lista { "viviana", "jenifer", "tania", "guillermo"};
  for (auto u : lista){
    std::cout << d1[u] << " ";
  }
  //Set "guillermo" to 0 because there no element call "guillermo"
  std::cout << std::endl;
  auto check = d1.insert({"guillermo",25}); // dont work beacause "guillermo" -> 0 only we can modify with []
  d1.insert(std::pair<std::string, int> ("alexa",25));
  std::cout << check.second << std::endl;
  for (auto u : d1) {
    std::cout << u.first << " " << u.second << std::endl; 
  }
  auto [it,check2] = d1.insert({"alondra", 32}); 
  std::cout << it->first << " " << it->second << "\n"<< "Se ingreso?: " << check2 << std::endl;
  std::cout << d1.at("guillermo") << std::endl;
  //std::cout << d1.at ("guillmermoj") // show us an error
  d1.insert ({{"cristofer", 26}, {"reishell", 26}});
  d1.insert(std::make_pair("quicke", 34));
  auto it3 = d1.insert({"junior",20});
  std::cout << it3.first->first << ": " << it3.first->second<< std::endl;
  std::cout << "Se inserto ?: " << it3.second << std::endl;
  d2.insert({{"jose",10}, {"maria",15}});
  d2.insert(d1.begin(),d1.end()) ; //Insert with iterators
  for (auto [key,value]: d2){ // new form to iterate dictionary
    std::cout << key <<  ": " << value << " | ";
  }
  std::cout << std::endl;
  auto it2 = d1.emplace("hugo", 28); // different form to insert elements
  std::cout << it2.first->first << ": " << it2.first->second << std::endl;
  std::cout << "Insertado ?: " <<it2.second << std::endl;
  d1.insert_or_assign("guillermo",25);
  d1.insert_or_assign(d1.begin(),"julia",22);
  for (auto [key,value] : d1) {
    std::cout << key << " " << value << " | ";
  }
  std::cout << std::endl;
  auto iterator = d1.find("maria");
  d1.emplace_hint(++iterator,"marko",25);//suggest insert in that position to obtain a log(1) insert
  d1.try_emplace("guillermo",12); // try to construct only if it doesnt exists
  std::vector<std::pair<std::string,int> > lista2 {{"julio",12},{"piero",25}};
  d2.insert_range(lista2);
  //REMOVE ELEMENTS
  size_t count = d2.erase("julio"); // return 1 
  std::cout << count << std::endl;
  count = d2.erase("asdasdasd"); // return 0 
  std::cout << count << std::endl;







  //USEFULL METHODS 
  auto it4 = d1.find("guillermo"); 
  std::cout << it4->first << " " <<  it4->second  << std::endl;
  it4 = d1.find("gasdasd");
  if (it4 == d1.end()){
    std::cout << "Valor no encontrado" << std::endl;
  }else {
    std::cout << "Valor encontrado! " << it4->first <<": " << it4->second << std::endl;
  }

  



  return 0;

}
