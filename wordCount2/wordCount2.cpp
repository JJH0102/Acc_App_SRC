#include <iostream>
#include <fstream>
#include <string>
#include <map>

int main()
{
    std::map<std::string, int> words;
    std::string word;
    std::ifstream in("lylics.txt");

    while (in >> word) {
        ++words[word];
    }

    for (auto it = words.cbegin(); it != words.cend(); ++it) {
        std::cout << it->first << " : " << it->second << std::endl;
    }

    return 0;
}