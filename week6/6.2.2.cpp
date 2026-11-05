#include <iostream>
#include <fstream>
#include <cstdlib>
#include <vector>

int main(){
    std::ifstream infile; 
    infile.open("input.txt");

    std::vector<int> v;

    if(!infile.is_open()){ 
        std::cout << "error opening file" << std::endl;
        return EXIT_FAILURE;
    }

    int tmp;

    while(infile >> tmp){
        v.push_back(tmp); 
        // instead of printing the values
        // as in the example above
        // first we store them in a vector
    }

    infile.close(); 
    std::ofstream outfile; 

    outfile.open("output.txt");
    
    if(!outfile.is_open()){
        std::cout << "error opening file" << std::endl;
        return EXIT_FAILURE;
    }

    for(int z = v.size() -1; z >=0 ;--z)
    {
        outfile << v[z] << std::endl;
    }

}
