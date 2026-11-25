#include <iostream>
#include <vector>
#include <cmath>

void next_binary(std::vector<int>& n)
{
    int value = 0;
    int size = n.size();
    for(int x = 0; x < size; ++x)
    {
        value += n[x] * pow(2,(size - x - 1));
    }
    int required = ++value ;
    n.clear();
    while(n.size() < size)
    {
        n.insert(n.begin(), required%2);
        required = required/2;
    }


}
int main() {
    std::vector<int> number = {0, 1, 1, 1};

    next_binary(number);

    for (int i = 0; i < number.size(); i++) {
        std::cout << number[i];
    }

    std::cout << std::endl;

    return 0;
}
