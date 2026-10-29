#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

int min_vector_element(const std::vector<double>& vin)
{
    if(vin.size() ==0){
        return -1;}
    double smallest_number = vin[0];
    int smallest_index = 0;
    int smallest_count = 0;
    double x{};


    for(int i =0; i < vin.size(); ++i)
    {
        x = vin[i];
        if(x < smallest_number)
        {
            smallest_number = x;
            smallest_count = i;
        }

    }

   
    return smallest_count;

}

int main()
{
    vector<double> vin {1,2,3,4,5,6};
    cout << min_vector_element(vin);

}