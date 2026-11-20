#include <iostream>
#include <string>
#include <cmath>
#include <cstdlib>
#include <fstream>
#include <vector>

int twod_to_oned(int row, int col, int rowlen){
    return row*rowlen+col;
}

int mfind(int n, const std::vector<int>& v){
    for(int x = 0; x < v.size() ; ++x)
    {
        if(v[x] == n)
            return x;
    }
    return -1;
}

bool check_sequence(const std::vector<int>& v)
{
    for(int z = 1; z <= v.size() ; z++)
    {
        int in_v = mfind(z,v);
        if(in_v == -1)
        {
            return false;
        }
    }
    return true;
}

void get_row(int r, const std::vector<int>& in, std::vector<int>& out){
    int rowlen = sqrt(in.size());
    for(int x = 0 ; x <rowlen ; ++x)
    {
        out.push_back(in[(twod_to_oned(r,x,rowlen))]);
    }
}

void get_col(int c, const std::vector<int>& in, std::vector<int>& out){
    int column_number = sqrt(in.size());
    for(int row_number = 0; row_number < column_number;++row_number)
    {
        out.push_back(in[twod_to_oned(row_number,c,column_number)]);
    }
}

// note that this function must (meaningfully) use function twod_to_oned
void get_subsq(int subs, const std::vector<int>& in, std::vector<int>& out){
    int square_of_square = sqrt(sqrt(in.size()));
    int row_start = (subs / square_of_square) * square_of_square;
    int column_start = (subs % square_of_square) *square_of_square; 
    for(int row = row_start; row < row_start + square_of_square ; ++row)
    {
        for(int column = column_start; column < column_start + square_of_square; ++column)
        {
            out.push_back(in[twod_to_oned(row,column,sqrt(in.size()))]);
        }
    }
}