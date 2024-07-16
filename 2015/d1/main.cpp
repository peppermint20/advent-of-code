#include <format>
#include <fstream>
#include <iostream>
#include <string>
#include <utility>
#include <vector>

std::vector<std::string> FileToVector(const std::string &filename)
{
    std::vector<std::string> arr;
    std::ifstream file{filename};
    std::string s;
    while (file >> s)
    {
        arr.push_back(std::move(s));
    }
    return arr;
}

int main()
{
    const std::string FILENAME = "input.txt";
    std::vector<std::string> input{FileToVector(FILENAME)};
    int acc = 0;
    int pos = 0;
    for (std::size_t i = 0; i < input.size(); ++i)
    {
        for (const auto &s : input[i])
        {
            if (s == '(')
            {
                ++acc;
            }
            else if (s == ')')
            {
                --acc;
            }
            else
            {
                std::cerr << "BAD INPUT!";
            }
            ++pos;
            if (acc == -1)
            {
                break;
            }
        }
    }
    std::cout << std::format("ANS DAY 1: {}\n", acc);
    std::cout << std::format("ANS PART 2: {}\n", pos);
    return 0;
}
