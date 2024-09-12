#ifndef STUDENT_INFO_H
#define STUDENT_INFO_H

#include <vector>
#include <string>
#include <iostream>

struct Student_info
{
    std::string name;
    double midterm;
    double finalterm;
    std::vector<double> homeworks;
};

std::istream& read(std::istream& in, Student_info& s);

#endif