#include <iostream>
#include <vector>
#include <cmath>

void next_binary(std::vector<int>& n);
bool rows_in_order(std::vector<std::vector<int>>& matrix, int& row)
{
   
    for(int i = 0; i < matrix.size() - 1  ; ++i)
    {
        std::vector<int> next = matrix[i];
        next_binary(next);
        if(matrix[i+1] != next)
        {
            row = i+1;
            return false;
        }

    }
    return true;
}




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
    std::vector<std::vector<int>> matrix = {
        {0, 1, 0, 1, 0},
        {0, 1, 0, 1, 1},
        {0, 1, 1, 0, 0},
        {0, 1, 1, 0, 1},
        {0, 1, 1, 1, 0},
        {0, 1, 1, 1, 1},
        {1, 0, 0, 0, 1},
        {1, 0, 0, 0, 0},
        {1, 0, 0, 1, 0}
    };

    int row = -1;

    if (rows_in_order(matrix, row)) {
        std::cout << "Rows are in order" << std::endl;
    } else {
        std::cout << "Rows are not in order" << std::endl;
        std::cout << "First incorrect row: " << row << std::endl;
    }

    return 0;
}
