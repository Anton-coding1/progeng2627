#include <iostream>
#include <fstream>
#include <cstdlib>
#include <vector>
#include <string> 

int search_vector(std::string s, const std::vector<std::string>& vin)
{
 for (int i = 0; i < vin.size(); ++i) {
        if (vin[i] == s) {
            return i;
        }
    }

    return -1;
}

void union_vector(const std::vector<std::string>& vin1, const std::vector<std::string>& vin2, std::vector<std::string>& vout)
{
    for (int i = 0; i < vin1.size(); ++i) {
    if (search_vector(vin1[i], vout) == -1) {
        vout.push_back(vin1[i]);
    }
}
for (int i = 0; i < vin2.size(); ++i) {
    if (search_vector(vin2[i], vout) == -1) {
        vout.push_back(vin2[i]);
    }
}
}

void intersection_vector(const std::vector<std::string>& vin1, const std::vector<std::string>& vin2, std::vector<std::string>& vout)
{
    for (int i = 0; i < vin1.size(); ++i) {
        if (search_vector(vin1[i], vin2) != -1 &&
            search_vector(vin1[i], vout) == -1) {

            vout.push_back(vin1[i]);
        }
    }
}

int main()
{
    std::vector<std::string> vin1 {};
    std::vector<std::string> vin2 {};
    std::vector<std::string> vin_union {};
    std::vector<std::string> vin_intersection {};

    std::string inputfilename1;
    std::string inputfilename2;
    
    std::cout << "enter name of input file 1" << std::endl;
    std::cout << "enter name of input file 2" << std::endl;

    std::cin >> inputfilename1;
    std::cin >> inputfilename2;

    std::ifstream infile1; 
    infile1.open(inputfilename1);
    std::string tmp;
    while(infile1 >> tmp)
    {
        vin1.push_back(tmp);
    }

    std::ifstream infile2; 
    infile2.open(inputfilename2);
    std::string tmp2;
    while(infile2 >> tmp2)
    {
        vin2.push_back(tmp2);
    }
    union_vector(vin1,vin2,vin_union);
    intersection_vector(vin1,vin2,vin_intersection);

     std::ofstream union1;
    union1.open("union.txt");
    

    if(!union1.is_open()){
        std::cout << "error opening file" << std::endl;
        return EXIT_FAILURE;
    }
    for(std::string x : vin_union)
    {
        union1 << x << std::endl;
    }
    
    
    union1.close();

     std::ofstream intersection1;
    intersection1.open("intersection.txt");
    

    if(!intersection1.is_open()){
        std::cout << "error opening file" << std::endl;
        return EXIT_FAILURE;
    }
    for(std::string z : vin_intersection)
    {
        intersection1 << z << std::endl;
    }
    
    intersection1.close();

    infile1.close();
    infile2.close();

}