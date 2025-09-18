#include "../../util.hpp"

#include <fstream>
#include <iostream>
#include <iterator>
#include <string>
#include <vector>
std::vector<std::string> read_to_vec(std::ifstream& file)
{
    std::vector<std::string> vec;

    std::string line;
    while (std::getline(file, line))
    {
        std::cout << line;
    }
    return vec;
}
std::string Part1(std::vector<std::string>& input);

int main()
{
    std::ifstream file("../inputs/day7_input.txt");
    if (!file)
    {
        std::cerr << "Error opening input\n";
        return 1;
    }
    auto          vec = read_to_vec(file);
    return 0;

}
