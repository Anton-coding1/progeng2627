#include <iostream>
#include <vector>

void filter_v(const std::vector<double>& vin, double t, std::vector<double>& vout)
{
    for(double x : vin)
    {
        if(x<t)
            vout.push_back(x);
    }
for(double y : vout)
{
    std::cout << y << " ";
}
}
int main()
{
std::vector<double> vin {1,5,6,8,5,3,3,5,6,4,3,33,4,55,6,7,7,3,2,1,1,32,4,5,7};
double t = 5;
std::vector<double> vout{};
filter_v(vin,t,vout);

}