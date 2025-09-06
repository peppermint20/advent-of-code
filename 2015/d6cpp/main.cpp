#include <array>
#include <fstream>
#include <iostream>
#include <regex>
#include <string>
#include <vector>

void part1()
{
    std::vector<std::vector<int>> grids{1000, std::vector<int>(1000, 0)};

    std::cout << "starting part 1 ";
    std::ifstream    file{"../inputs/day6_input.txt"};
    std::string      s;
    const std::regex regex{R"(\d+)"};
    long long        ans = 0;
    while (std::getline(file, s))
    {
        auto                     words_begin = std::sregex_token_iterator(s.cbegin(), s.cend(), regex);
        auto                     words_end   = std::sregex_token_iterator();
        std::vector<std::string> vec{words_begin, words_end};
        std::array<int, 4>       array = {
            std::stoi(vec[0]),
            std::stoi(vec[1]),
            std::stoi(vec[2]),
            std::stoi(vec[3]),
        };

        if (s.find("turn off") != std::string::npos)
        {
            for (int i = array[0]; i <= array[2]; ++i)
            {
                for (int j = array[1]; j <= array[3]; ++j)
                {
                    grids[i][j] = 0;
                }
            }
        }
        else if (s.find("turn on") != std::string::npos)
        {
            for (int i = array[0]; i <= array[2]; ++i)
            {
                for (int j = array[1]; j <= array[3]; ++j)
                {
                    grids[i][j] = 1;
                }
            }
        }
        else if (s.find("toggle") != std::string::npos)
        {
            for (int i = array[0]; i <= array[2]; ++i)
            {
                for (int j = array[1]; j <= array[3]; ++j)
                {
                    grids[i][j] ^= 1;
                }
            }
        }
    }
    for (const auto& grid : grids)
    {
        for (const auto& elem : grid)
        {
            ans += elem;
        }
    }

    std::cout << "Answer Part 1: " << ans << '\n';
}

void part2()
{
    std::vector<std::vector<int>> grids{1000, std::vector<int>(1000, 0)};


    std::cout << "starting part 2 ";
    std::ifstream    file{"../inputs/day6_input.txt"};
    std::string      s;
    const std::regex regex{R"(\d+)"};
    std::smatch      base_match;
    long long        ans = 0;
    while (std::getline(file, s))
    {
        auto                     words_begin = std::sregex_token_iterator(s.cbegin(), s.cend(), regex);
        auto                     words_end   = std::sregex_token_iterator();
        std::vector<std::string> vec{words_begin, words_end};
        std::array<int, 4>       array = {
            std::stoi(vec[0]),
            std::stoi(vec[1]),
            std::stoi(vec[2]),
            std::stoi(vec[3]),
        };

        if (s.find("turn off") != std::string::npos)
        {
            for (int i = array[0]; i <= array[2]; ++i)
            {
                for (int j = array[1]; j <= array[3]; ++j)
                {
                    if (grids[i][j] > 0)
                    {
                        grids[i][j] -= 1;
                    }
                }
            }
        }
        else if (s.find("turn on") != std::string::npos)
        {
            for (int i = array[0]; i <= array[2]; ++i)
            {
                for (int j = array[1]; j <= array[3]; ++j)
                {
                    grids[i][j] += 1;
                }
            }
        }
        else if (s.find("toggle") != std::string::npos)
        {
            for (int i = array[0]; i <= array[2]; ++i)
            {
                for (int j = array[1]; j <= array[3]; ++j)
                {
                    grids[i][j] += 2;
                }
            }
        }
    }
    for (const auto& grid : grids)
    {
        for (const auto& elem : grid)
        {
            ans += elem;
        }
    }

    std::cout << "Answer Part 2: " << ans << '\n';
}


int main()
{
    part1();
    part2();
}
