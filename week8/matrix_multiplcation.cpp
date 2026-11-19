#include <vector>
#include <string>
#include <fstream>
#include <sstream>
#include <iomanip>
#include <iostream>
#include <cstdlib>

// We need 4 functions  - line_to_vector, read matrix from file, sum matrix and matrix_string 

std::vector<double> line_to_vector(std::string s)
{
    std::stringstream ss;
    std::string tmp;
    std::vector<double> out;

    ss << s;
    while(ss >> tmp)
    {
        out.push_back(std::stod(tmp));
    }
    return out;
}

std::vector<std::vector<double>> read_matrix_from_file(std::string input_file)
{
    std::ifstream infile;
    infile.open(input_file);
    if(!infile.is_open())
    {
        std::cout << "Error openining " << input_file << std::endl;
        std::exit(EXIT_FAILURE);
    }
      std::string line;
      std::vector<std::vector<double>> out;
      while(std::getline(infile,line))
      {
        out.push_back(line_to_vector(line));
      }
      return out;
}

std::vector<std::vector<double>> matrix_multiplication
(
    const std::vector<std::vector<double>>& v1,
     const std::vector<std::vector<double>>& v2
)
{
 std::vector<std::vector<double>> out;
 
 for (int i = 0; i < v1.size(); ++i)
    {
        std::vector<double> row;

        for (int j = 0; j < v2[0].size(); ++j)
        {
            double sum = 0;

            for (int k = 0; k < v1[0].size(); ++k)
            {
                sum += v1[i][k] * v2[k][j];
            }

            row.push_back(sum);
        }

        out.push_back(row);
    }

    return out;
}

std::string matrix_to_string(std::vector<std::vector<double>> m)
{
    std::stringstream out;
    out << std::fixed << std::setprecision(2);
    for(int i = 0; i < m.size(); i++){
        for(int j = 0; j < m[0].size(); j++){
            out << (m[i][j]) << "\t";
        }
        out << "\n";
    }
    return out.str();
}
int main(int argc, char* argv[])
{
    if(argc !=3){
        std::cout << "two arguments needed" << std::endl;
        return EXIT_FAILURE;
    }
     std::vector<std::vector<double>> m1 = read_matrix_from_file(argv[1]);
     std::vector<std::vector<double>> m2 = read_matrix_from_file(argv[2]);
    std::vector<std::vector<double>> m3 = matrix_multiplication(m1, m2);

    std::cout << matrix_to_string(m1) << std::endl;
    std::cout << "*" << std::endl << std::endl;
    std::cout << matrix_to_string(m2) << std::endl;
    std::cout << "=" << std::endl << std::endl;
    std::cout << matrix_to_string(m3) << std::endl;

}
