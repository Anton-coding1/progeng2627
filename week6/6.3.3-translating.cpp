#include <iostream>
#include <fstream>
#include <cstdlib>
#include <vector>
#include <string> 
using namespace std;

int main()
{
    std::ifstream infile;
    infile.open("sketchy_ad.txt");
    if(!infile.is_open()){ 
        std::cout << "error opening file" << std::endl;
        return EXIT_FAILURE;
    }
    vector<string> input_add;
    string tmp;
    while(infile >> tmp)
    {
        input_add.push_back(tmp);
    }

    std::ifstream infile2;
    infile2.open("translator.txt");
    if(!infile2.is_open()){ 
        std::cout << "error opening file" << std::endl;
        return EXIT_FAILURE;
    }
    vector<string> input_tran;
    string tmp1;
    while(infile2 >> tmp1)
    {
        input_tran.push_back(tmp1);
    }
    std::ofstream outfile;
    outfile.open("true_meaning.txt");
     if(!outfile.is_open()){ 
        std::cout << "error opening file" << std::endl;
        return EXIT_FAILURE;}

    vector<string> sentance;
        int change = 0;
    for(string z : input_add){
        change = 0;
        for(int x = 0; x < input_tran.size() ; x+=2){
            if(z == input_tran[x]){
                sentance.push_back(input_tran[x+1]);
                change =1;}
           
     }
    if(change ==0)
        sentance.push_back(z);
}
     for(string f : sentance)
        outfile << f << " " << std::endl;

}