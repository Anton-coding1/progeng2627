#include <iostream>
#include <fstream>
#include <cstdlib>
#include <vector>
#include <string> 

int main(){

    std::string inputfilename;
    std::string outputfilename;
    
    std::cout << "enter name of input file" << std::endl;
    std::cout << "enter name of output file" << std::endl;

    std::cin >> inputfilename;
    std::cin >> outputfilename;

    std::ifstream infile; 
    infile.open(inputfilename);

   

    std::vector<int> v;

    if(!infile.is_open()){ 
        std::cout << "error opening file" << std::endl;
        return EXIT_FAILURE;
    }

    int tmp;

    while(infile >> tmp){
        v.push_back(tmp); 
    }

    infile.close(); 
    std::ofstream outfile; 

    outfile.open(outputfilename);
    
    if(!outfile.is_open()){
        std::cout << "error opening file" << std::endl;
        return EXIT_FAILURE;
    }

    for(int z = v.size() -1; z >=0 ;--z)
    {
        outfile << v[z] << std::endl;
    }
}