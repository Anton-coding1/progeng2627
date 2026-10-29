#include <iostream>
#include <vector>

int main()
{
int n {};
std::vector<int> v = {};
std::cout << "Please enter the numer of values you want in vector: ";
std::cin>>n; 
int current {};
 for(int i = 0; i<n ; ++i)
{
std::cout<< "Please enter a number " << std::endl;
std::cin >> current;
v.push_back(current);
}
int s {};
std::cout << "please enter s: ";
std::cin>>s;
int count {};
for(int z : v)
    {
        if(z==s)
            ++count;
    }
if(count == 0)
    std::cout << " No occurances";
else
     std::cout << count << " occurances of " << s;


}