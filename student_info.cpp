#include "student_info.h"
#include "median.h"
#include <stdexcept>

using std::vector;
using std::cin;
using std::istream;
using std::string;
using std::domain_error;

istream& read_hw(istream& in, vector<double>& homework) { 
	if (in) { 
		double x;
		homework.clear();
		while (in >> x)
			homework.push_back(x);

		in.clear();
	}

	return in;
}

istream& read(istream& in, Student_info& student) {
	in >> student.name >> student.midterm >> student.final;
	read_hw(in,student.homework);
	
	return in;
}

bool compare (const Student_info& x, const Student_info& y) {
	return x.name < y.name;
}
