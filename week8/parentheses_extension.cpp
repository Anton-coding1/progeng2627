#include <iostream>
#include <vector>
#include <fstream>
#include <cstdlib>
#include <string>
using namespace std;


unsigned long catalan_calculator(const vector<unsigned long>& v);
vector<unsigned long> catalan_numbers(int n)
{
vector<unsigned long> catalan = {1};
for(int z = 0; z < n ; ++z)
    {
        catalan.push_back(catalan_calculator(catalan));
    }
    return catalan;


}

unsigned long catalan_calculator(const vector<unsigned long>& v)
{
    int size = v.size();
    unsigned long catalan_sum = 0;
    for(int x = 0; x < v.size() ; ++x)
    {
        catalan_sum+= (v[x] * v[size - 1 -x ] );
    }
    return catalan_sum;
}
int main()
{
    std::ifstream infile;
    infile.open("expressions.txt");
    if(!infile.is_open())
    {
        std::cout << "error opening file" << std::endl;
        return EXIT_FAILURE;
    }

    std::ofstream outfile;
    outfile.open("expression_counts.txt") ;
    if(!outfile.is_open())
    {
        std::cout << "error opening file" << std::endl;
        return EXIT_FAILURE;
    }

    std::string expression;
    while (getline(infile, expression))
    {
        int counter = 0;
    
        for (char tmp : expression)
        {
            if (tmp == '+' || tmp == '-' ||
                tmp == '*' || tmp == '/')
            {
                ++counter;
            }
        }
    
        unsigned long result = catalan_numbers(counter).back();
        outfile << expression << '\t' << result << '\n';
    }
    infile.close();
    outfile.close();

}
