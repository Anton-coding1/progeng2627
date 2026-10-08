
#include <iostream>
#include <vector>
using namespace std;
#include <queue>
#include <unordered_map>



int main(){

    double length_in, length_out;
    std::string unit_in, unit_out;

    const double celcius_to_farenheit = 1.609;

    // stage 1: input

    std::cin >> length_in >> unit_in;

    bool valid_unit = true;
    // we assume the user will input a valid unit

    // stage 2: data processing

    if((unit_in == "C") || (unit_in == "c")){
        unit_out = "farenheit";
        length_out = (length_in *(9/5)) +32;

    }
    else if(unit_in == "F" || (unit_in == "f")){
        unit_out = "celcius";
        length_out = (length_in - 32) / (9/5);
    }
    else{
        valid_unit = false;
        // if the user inputs an invalid unit name
        // we update this variable
    }

    // stage 3: output 

    if(valid_unit){
        std::cout << length_out << " " << unit_out << std::endl;
    }
    else{
        std::cout << "error, unit not recognised" << std::endl;
    }

}