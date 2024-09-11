#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <ios>
#include <iomanip>

int main()
{
    double midterm, finalterm;
    double homework;
    double finalScore;
    double median;
    int mid;


    std::cout << "input name : ";
    std::string name;
    std::cin >> name;

    std::cout << "input midterm finalterm : ";
    std::cin >> midterm >> finalterm;

    std::vector<double> homeworks;

    while (std::cin >> homework) {
        homeworks.push_back(homework);
    }

    if (homeworks.size() == 0) {
        std::cerr << "try input homework agin" << std::endl;

        return 1;
    } 

    std::sort(homeworks.begin(), homeworks.end());

    std::vector<double>::size_type mid = homeworks.size() / 2;

    if (homeworks.size() % 2 != 0) {
        median = homeworks[mid];
    }
    else {
        median = (homeworks[mid] + homeworks[mid - 1]) / 2;
    }

    finalScore = 0.2 * midterm + 0.4 * finalterm + 0.4 * median;

    std::streamsize prec = std::cout.precision();
    std::cout << "Your final score : " << std::setprecision(3) << finalScore << std::endl << std::setprecision(prec) << std::endl;
    
    return 0;
}