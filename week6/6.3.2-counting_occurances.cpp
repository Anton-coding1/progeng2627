#include <iostream>
#include <fstream>
#include <cstdlib>
#include <vector>
#include <string> 
using namespace std;
#include <unordered_map>

int main()
{
     std::ifstream infile; 
    infile.open("text.txt");

    std::vector<std::string> v;

    if(!infile.is_open()){ 
        std::cout << "error opening file" << std::endl;
        return EXIT_FAILURE;
    }
    std::string tmp;

    while(infile >> tmp){
        v.push_back(tmp); 
       
    }

    infile.close(); 

     std::ifstream wordfile; 
    wordfile.open("words.txt");

    std::vector<std::string> x;

    if(!wordfile.is_open()){ 
        std::cout << "error opening file" << std::endl;
        return EXIT_FAILURE;
    }
    std::string tmp1;

    while(wordfile >> tmp1){
        x.push_back(tmp1); 
       
    }
    vector<int> counter {};
    for(string t : x)
        counter.push_back(0);
    wordfile.close();

    std::ofstream output;
    output.open("output.txt");
     if(!output.is_open()){
        std::cout << "error opening file" << std::endl;
        return EXIT_FAILURE;}
    


    int minicout =0;
    for(std::string y : v)
        {   
            int minicount = 0;
            for(std::string u : x)
            {
                if(y == u)
                    counter[minicount] +=1;
                else
                    ++minicount;
            }
        }
for(int r = 0; r< x.size(); ++r)
{
    output << x[r] << ": " <<  counter[r] << std::endl;
}
   

}