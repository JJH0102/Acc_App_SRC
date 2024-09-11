#include <iostream>
#include <string>
#include <ios>
#include <iomanip>

int main()
{
    double midterm, finalterm;
    double homework;
    double sum = 0;
    int count = 0;
    double finalScore;

    std::cout << "input name : ";
    std::string name;
    std::cin >> name;

    std::cout << "input midterm finalterm : ";
    std::cin >> midterm >> finalterm;

    while (std::cin >> homework) {
        sum += homework;
        ++count;
    }

    finalScore = 0.2 * midterm + 0.4 * finalterm + 0.4 * sum / count;
    std::streamsize prec = std::cout.precision();
    std::cout << "Your final score : " << std::setprecision(3) << finalScore << std::endl << std::setprecision(prec) << std::endl;
    
    return 0;
}