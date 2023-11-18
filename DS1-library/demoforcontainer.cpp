#include "DynamicContainer.h"
#include <iostream>
bool a() {

  DynamicContainer<int> container;
  container.push_back(10);
  container.push_back(20);
  container.push_back(31);
  container.push_back(25);
  container.push_back(20);
  container.push_back(25);
  container.push_back(22);
  container.push_back(23);
  container.push_back(23);
  container.push_back(28);
  container.push_back(28);

  container[0] = 15;
  container.push_front(2);

  container.push_back(10);
  container.push_back(20);
  container.push_back(30);

  for (DynamicContainer<int>::Iterator it = container.begin();
       it != container.end(); ++it) {
    std::cout << *it << " ";
  }

  std::cout << "rna \n";
  // Using range-based for loop
  for (const int &value : container) {
    std::cout << value << " ";
  }
  return 0;
}
bool b() {
  DynamicContainer<std::string> stringContainer = {"cat", "dog"};

  stringContainer.push_back("apple");
  stringContainer.push_back("banana");
  stringContainer.push_back("cherry");

  std::cout << "Original Container:" << std::endl;
  for (const std::string &str : stringContainer) {
    std::cout << str << " ";
  }
  std::cout << std::endl;

  // Reverse the container
  stringContainer.reverse();

  std::cout << "Reversed Container:" << std::endl;
  for (const std::string &str : stringContainer) {
    std::cout << str << " ";
  }
  std::cout << std::endl;

  DynamicContainer<std::string> otherContainer;
  otherContainer.push_back("date");
  otherContainer.push_back("aig");

  stringContainer.merge(otherContainer);

  stringContainer.sort();
  std::cout << "Merged Container:" << std::endl;
  for (const std::string &str : stringContainer) {
    std::cout << str << " ";
  }
  std::cout << std::endl;

  return 0;
}
bool c() {
  DynamicContainer<int> container1;
  container1.push_back(1);
  container1.push_back(2);
  container1.push_back(3);
  for (const int &value : container1) {
    std::cout << value << " ";
  }
  std::cout << std::endl;

  DynamicContainer<int> container2;
  container2.push_back(4);
  container2.push_back(5);

  container2 = container1;
  for (const int &value : container2) {
    std::cout << value << " ";
  }
  return 0;
}
int main(int argc, char *argv[]) {
  c();
  return 0;
}
