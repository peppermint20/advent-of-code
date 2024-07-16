#include "../util.hpp"

#include <format>
#include <initializer_list>
#include <iostream>
#include <sstream>

#include <cstdint>
/*
The elves are running low on wrapping paper, and so they need to submit an order for more. They have a list of the dimensions (length l, width w, and height h) 
of each present, and only want to order exactly as much as they need.

Fortunately, every present is a box (a perfect right rectangular prism), 
which makes calculating the required wrapping paper for each gift a little easier: find the surface area of the box, which is 2*l*w + 2*w*h + 2*h*l. 
The elves also need a little extra paper for each present: the area of the smallest side.

For example:

A present with dimensions 2x3x4 requires 2*6 + 2*12 + 2*8 = 52 square feet of wrapping paper plus 6 square feet of slack, for a total of 58 square feet.
A present with dimensions 1x1x10 requires 2*1 + 2*10 + 2*10 = 42 square feet of wrapping paper plus 1 square foot of slack, for a total of 43 square feet.
All numbers in the elves' list are in feet. How many total square feet of wrapping paper should they order?


 */

constexpr int calcDimension(int l, int w, int h)
{
    uint64_t sa    = 2 * l * w + 2 * w * h + 2 * h * l;
    uint64_t slack = std::min(std::min(l * w, w * h), l * h);

    return sa + slack;
}

void p1(char* argv[])
{
    uint64_t ans    = 0;
    auto     vector = util::FileToVector(argv[1]);
    for (int i = 0; i < vector.size(); ++i)
    {
        std::stringstream ss;
        ss << vector[i];
        uint64_t x{}, y{}, z{};
        char     filter{};
        ss >> x >> filter >> y >> filter >> z;
        // std::cout << std::format("x: {}, y: {}, z: {}\n", x, y, z);
        ans += calcDimension(x, y, z);
    }
    std::cout << std::format("Part 1 Answer: {}\n", ans);
}

constexpr int calcP2(int l, int w, int h)
{
    uint64_t p1, p2, p3;
    p1               = 2 * (l + w);
    p2               = 2 * (l + h);
    p3               = 2 * (w + h);
    uint64_t wrapper = std::min(std::min(p1, p2), p3);
    uint64_t ribbon  = l * w * h;
    return wrapper + ribbon;
}


void p2(char* argv[])
{
    uint64_t ans    = 0;
    auto     vector = util::FileToVector(argv[1]);

    for (int i = 0; i < vector.size(); ++i)
    {
        std::stringstream ss;
        ss << vector[i];
        uint64_t x{}, y{}, z{};
        char     filter{};

        ss >> x >> filter >> y >> filter >> z;
        ans += calcP2(x, y, z);
    }
    std::cout << std::format("Part 2 Answer: {}\n", ans);
}


int main(int argc, char* argv[])
{
    p1(argv);
    p2(argv);
}
