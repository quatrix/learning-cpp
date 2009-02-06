#ifndef GUARD_student_info_h
#define GUARD_student_info_h

#include <string>
#include <vector>
#include <iostream>

struct Student_info {
	std::string name;
	double midterm;
	double final;
	std::vector<double> homework;
};

std::istream& read_hw(std::istream&, std::vector<double>&);
std::istream& read(std::istream&, Student_info&);
bool compare (const Student_info&, const Student_info&);

#endif
