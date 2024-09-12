#include <iostream>
#include <string>
#include <vector>
#include <stdexcept>
#include <ios>
#include <iomanip>
#include <algorithm>
#include "student_info.h"
#include "grade.h"

// std::vector<Student_info> extract_fials(std::vector<Student_info>& students)
// {
//     std::vector<Student_info> passes, fails;

//     for (std::vector<Student_info>::size_type i = 0; i != students.size(); ++i) {
//         if (grade(students[i]) >= 60) {
//             passes.push_back(students[i]);
//         }
//         else {
//             fails.push_back(students[i]);
//         }
//     }

//     students = passes;

//     return fails;
// }

bool fgrade(const Student_info& s)
{
    return grade(s) < 60;
}

// std::vector<Student_info> extract_fials(std::vector<Student_info>& passes)
// {
//     std::vector<Student_info> fails;

//     for (std::vector<Student_info>::size_type i = 0; i != passes.size(); ) {
//         if (fgrade(passes[i])) {
//             fails.push_back(passes[i]);
//             passes.erase(passes.begin() + i);   // passes.begin() --> 시작 주소를 구하고 +i를 해서 i번째 주소를 구해서 i를 삭제
//         }
//         else {
//             ++i;
//         }
//     }

//     return fails;
// }

std::vector<Student_info> extract_fials(std::vector<Student_info>& passes)
{
    std::vector<Student_info> fails;

    for (std::vector<Student_info>::iterator it = passes.begin(); it != passes.end(); ) {
        if (fgrade(*it)) {
            fails.push_back(*it);
            passes.erase(it);
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
    // int maxLen = 0;
    std::string::size_type maxLen = 0;
    
    std::vector<Student_info> students;
    Student_info s;
    
    while (read(std::cin, s)) {
        students.push_back(s);

        maxLen = std::max(maxLen, s.name.size());    
    }

    std::sort(students.begin(), students.end(), compare);

    std::vector<Student_info> passes, fails;
    passes = students;
    fails = extract_fials(passes);

    try {
        std::cout << "pass list : " << std::endl;
        for (std::vector<Student_info>::size_type i = 0; i != passes.size(); ++i) {
            const double finalScore = grade(passes[i]);

            std::streamsize prec = std::cout.precision();
            std::cout << passes[i].name << std::string(maxLen - passes[i].name.size() + 1, ' ')
            << std::setprecision(3) << finalScore << std::setprecision(prec) << std::endl;
        }

        std::cout << "fail list : " << std::endl;
        for (std::vector<Student_info>::const_iterator it = fails.cbegin(); it != fails.cend(); ++it) {
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