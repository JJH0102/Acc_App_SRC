#include <iostream>
#include <fstream>
#include <string>
#include <list>
#include <stdexcept>
#include <ios>
#include <iomanip>
#include <algorithm>
#include "student_info.h"
#include "grade.h"

bool fgrade(const Student_info& s)
{
    return grade(s) < 60;
}

std::list<Student_info> extract_fials(std::list<Student_info>& passes)
{
    std::list<Student_info> fails;

    for (std::list<Student_info>::iterator it = passes.begin(); it != passes.end(); ) {
        if (fgrade(*it)) {
            fails.push_back(*it);
            it = passes.erase(it);
        }
        else {
            ++it;
        }
    }

    return fails;
}

bool compare(const Student_info s1, const Student_info& s2)
{
    return s1.name < s2.name;
}

int main()
{
    std::string::size_type maxLen = 0;
    std::list<Student_info> students;

    std::ifstream in("../score.dat");

    Student_info s;
    
    while (read(std::cin, s)) {
        students.push_back(s);

        maxLen = std::max(maxLen, s.name.size());    
    }

    // std::sort(students.begin(), students.end(), compare); --> 연속적인 데이터에 한해서만 사용할 수 있음
    students.sort(compare); // --> 그러므로 list는 자체로 sort 함수를 사용해야 함.

    std::list<Student_info> passes, fails;
    passes = students;
    fails = extract_fials(passes);

    try {
        std::cout << "pass list : " << std::endl;
        for (std::list<Student_info>::const_iterator it = passes.cbegin(); it != passes.cend(); ++it) {
            const double finalScore = grade(*it);

            std::streamsize prec = std::cout.precision();
            std::cout << it->name << std::string(maxLen - it->name.size() + 1, ' ')
            << std::setprecision(3) << finalScore << std::setprecision(prec) << std::endl;
        }

        std::cout << "fail list : " << std::endl;
        for (std::list<Student_info>::const_iterator it = fails.cbegin(); it != fails.cend(); ++it) {
            const double finalScore = grade(*it);

            std::streamsize prec = std::cout.precision();
            std::cout << it->name << std::string(maxLen - it->name.size() + 1, ' ')
            << std::setprecision(3) << finalScore << std::setprecision(prec) << std::endl;
        }
    
    }
    catch (const std::domain_error& e) {
        std::cerr << e.what() << std::endl;

        return 1;
    }
    
    return 0;
}