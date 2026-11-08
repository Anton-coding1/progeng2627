#include <iostream>
#include <fstream>
#include <cstdlib>
#include <vector>
#include <string> 

void merge_vectors_int(const std::vector<int>& v1, const std::vector<int>& v2, std::vector<int>& merged)
{
int i = 0;
int z = 0;

while(i < v1.size() && z < v2.size())
{
    if(v1[i] < v2[z]){
        merged.push_back(v1[i]);
    ++i;}
     else if(v2[z] <= v1[i]) 
        {
        merged.push_back(v2[z]);
        ++z;}
    
}
if(z < v2.size())
{
    for(int x = z; x < v2.size() ; ++x)
     merged.push_back(v2[x]);
}
if(i < v1.size())
{
    for(int y = i; y< v1.size() ; ++y)
        merged.push_back(v1[y]);
}
}
int main(){

    std::vector<int> v1;
    std::vector<int> v2;
    std::vector<int> out;

    std::vector<int> expected_output;

    v1 = {1, 3, 5, 6};
    v2 = {4, 6, 10};
    expected_output = {1, 3, 4, 5, 6, 6, 10};

    merge_vectors_int(v1, v2, out);

    if(out == expected_output){ // we can compare the content of vectors (at least in some cases)
        std::cout << "passed" << std::endl;
    }
    else{
        std::cout << "not passed" << std::endl;
    }
    for(int z : out)
        std::cout << z << " ";
}