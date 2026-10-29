#include <iostream>
#include <vector>

void append_vectors(const std::vector<int>& vin1, const std::vector<int>& vin2, std::vector<int>& vout)
{
    for(int x : vin1)
    {
        vout.push_back(x);
    }
    for(int y : vin2)
    {
        vout.push_back(y);
    }

    for(int z : vout)
    {
        std::cout << z << " ";
    }
}
int main()
{
    std::vector<int> vin1{1,2,7,8,9};
    std::vector<int> vin2{7,5,6,7,8,3};
    std::vector<int> vout{};
    append_vectors(vin1,vin2,vout);

}