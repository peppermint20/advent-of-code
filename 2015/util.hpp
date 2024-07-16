#ifndef UTIL_HPP
#define UTIL_HPP
#include <algorithm>
#include <format>
#include <fstream>
#include <iostream>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <utility>
#include <vector>
namespace util
{


struct pair_hash
{
    inline std::size_t operator()(const std::pair<int, int>& v) const
    {
        return v.first * 31 + v.second;
    }
};


std::vector<std::string> FileToVector(const std::string& filename)
{
    std::vector<std::string> arr;
    std::ifstream            file{filename};
    std::string              s;

    if (file.fail())
    {
        std::runtime_error(std::format("FILE {} could not be opened", filename));
    }
    while (file >> s)
    {
        arr.push_back(std::move(s));
    }
    return arr;
}
} // namespace util

#endif
