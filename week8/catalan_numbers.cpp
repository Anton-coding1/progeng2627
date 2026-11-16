#include <iostream>
#include <vector>
using namespace std;
unsigned long catalan_calculator(const vector<unsigned long>& v);
std::vector<unsigned long> catalan_numbers(int n)
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


int main() {
    int n;

    std::cout << "Enter n: ";
    std::cin >> n;

    std::vector<unsigned long> numbers = catalan_numbers(n);

    for (int i = 0; i < numbers.size(); i++) {
        std::cout << "C" << i << " = " << numbers[i] << std::endl;
    }

    return 0;
}
