#include "../util.hpp"


void p1(std::vector<std::string>& input)
{
    std::unordered_map<char, int> map{};
    map.insert(std::make_pair('^', 1));  // y += 1
    map.insert(std::make_pair('v', -1)); // y -= 1
    map.insert(std::make_pair('>', 1));  // x += 1
    map.insert(std::make_pair('<', -1)); // x -= 1

    std::unordered_set<std::pair<int, int>, util::pair_hash> ans;
    std::pair<int, int>                                      loc;
    ans.insert(loc);
    for (const auto& inp : input)
    {
        for (const auto& i : inp)
        {
            if (i == '^' || i == 'v')
            {
                loc.second += map[i];
            }
            else if (i == '<' || i == '>')
            {
                loc.first += map[i];
            }
            if (ans.find(loc) != ans.end())
            {
                // in the ans map already,continue
                continue;
            }
            else
            {
                ans.insert(loc);
            }
        }
    }
    std::cout << std::format("Part 1 Answer: {}\n", ans.size());
}

void p2(std::vector<std::string>& input)
{
    std::unordered_map<char, int> map{};
    map.insert(std::make_pair('^', 1));  // y += 1
    map.insert(std::make_pair('v', -1)); // y -= 1
    map.insert(std::make_pair('>', 1));  // x += 1
    map.insert(std::make_pair('<', -1)); // x -= 1

    std::unordered_set<std::pair<int, int>, util::pair_hash> santa;
    std::unordered_set<std::pair<int, int>, util::pair_hash> robo;
    std::pair<int, int>                                      loc_santa;
    std::pair<int, int>                                      loc_robo;
    santa.insert(loc_santa);
    robo.insert(loc_robo);
    int index{};
    for (const auto& inp : input)
    {
        for (const auto& i : inp)
        {
            if (index++ % 2 == 0)
            {
                if (i == '^' || i == 'v')
                {
                    loc_santa.second += map[i];
                }
                else if (i == '<' || i == '>')
                {
                    loc_santa.first += map[i];
                }

                santa.insert(loc_santa);
            }
            else
            {
                if (i == '^' || i == 'v')
                {
                    loc_robo.second += map[i];
                }
                else if (i == '<' || i == '>')
                {
                    loc_robo.first += map[i];
                }
                robo.insert(loc_robo);
            }
        }
    }
    auto cmp = [](const std::pair<int, int>& lhs, const std::pair<int, int>& rhs) { return lhs.first < rhs.first; };
    std::vector<std::pair<int, int>> dest{};
    for (const auto elem : santa)
    {
        robo.insert(elem);
    }
    std::set_union(santa.begin(), santa.end(), robo.begin(), robo.end(), std::back_inserter(dest));
    std::cout << std::format("Part 2 Answer: {}\n", robo.size());
}


int main(int argc, char* argv[])
{
    auto vector = util::FileToVector(argv[1]);
    p1(vector);
    p2(vector);
}
