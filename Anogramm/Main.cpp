#include <algorithm>
#include <iostream>
#include <vector>
#include <unordered_map>
#include <string>
#include <list>


using StringList = std::list<std::string>;
using AnogrammMap = std::unordered_map<std::string, StringList>;

AnogrammMap getAnogramm(const StringList &list)
{
    AnogrammMap result;
    for (const auto &word : list)
    {
        std::string key(word.size(), '\0');
        std::partial_sort_copy(word.begin(), word.end(), key.begin(), key.end());
        result[key].push_back(word);
    }

    return result;
}


int main()
{
    StringList list = { "ababa", "baaab", "abab", "baba", "abcd", "dcba", "abdc" };
    auto result = getAnogramm(list);

    for (const auto&[key, value] : result)
    {
        std::cout << key << " : ";
        std::for_each(value.begin(), value.end(), [](const auto &v) 
        {
            std::cout << "[" << v << "] ";
        });
        std::cout << std::endl;
    }

    system("pause");

    return 0;
}