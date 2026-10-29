#include <iostream>
#include <vector>

int main()
{
int n {};
std::vector<int> v = {};
std::cout << "Please enter the numer of values you want in vector: ";
std::cin>>n;
 std::cout<< "PLease enter " << n << " values for the vector: " ;
 int current {};
for(int i = 0; i<n ; ++i)
{
   std::cin >> current;
   v.push_back(current);
}
int t {};
std::cout << "Please enter a number which will filter all values below it: ";
std::cin >> t;
std::cout <<"your final numbers are" << std::endl;
for(int z : v)
{
    if(z>=t)
        std::cout << z << std::endl;
    
}
}