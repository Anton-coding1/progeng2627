#include <iostream>
#include <vector>

// this header is needed to use vectors

int main(){
std::vector<int> storage = {};
storage.push_back(1);
storage.push_back(3);
storage.push_back(5);
storage.push_back(7);
std::cout << (storage[0] * (storage[1] + storage[2] + storage[3])) << std::endl;


}