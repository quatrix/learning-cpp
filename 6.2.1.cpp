#include <iostream>
#include <vector>
#include <stdexcept>
#include <numeric>
#include "student_info.h"
#include "grade.h"
#include "median.h"



using namespace std;


double average(const vector<double>& v) { 
	return accumulate(v.begin(),v.end(),0.0) / v.size();
}

double average_grade(const Student_info& s) { 
	return grade(s.midterm,s.final,average(s.homework));
}


double grade_aux(const Student_info& s) {
	double g; 
	
	try { 
		return grade(s);
	}
	catch (domain_error) {
		return grade(s.midterm,s.final,0);
	}
}

double optimistic_median(const Student_info& s) { 
	vector<double> non_zero;

	remove_copy(s.homework.begin(),s.homework.end(), back_inserter(non_zero), 0);

	if (non_zero.empty()) 
		return grade(s.midterm, s.final, 0);
	else
		return grade(s.midterm, s.final, median(non_zero));
}

double median_analysis(const vector<Student_info>& s) { 
	vector<double> grades;

	transform(s.begin(),s.end(),back_inserter(grades),grade_aux);

	return median(grades);
}

double average_analysis(const vector<Student_info>& s) { 
	vector<double> grades;

	transform(s.begin(),s.end(),back_inserter(grades),average_grade);

	return median(grades);
}

double optimistic_analysis(const vector<Student_info>& s) { 
	vector<double> grades;

	transform(s.begin(),s.end(),back_inserter(grades),optimistic_median);

	return median(grades);
}

void write_analysis(ostream& out, const string& name, 
			double analysis(const vector<Student_info>&),
			const vector<Student_info>& did,
			const vector<Student_info>& didnt)
{
	out << name << ": median(did) = " << analysis(did) << 
		       ": median(didnt) = " << analysis(didnt) << endl;
}

bool did_all_hw(const Student_info& s) {
	return ((find(s.homework.begin(),s.homework.end(),0)) == s.homework.end());
}

int main(void) { 
	vector<Student_info> did, didnt;
	Student_info student;

	while(read(cin,student)) {
		if (did_all_hw(student))
			did.push_back(student);
		else 
			didnt.push_back(student);
	}

	if (did.empty()) {
		cout << "No student did all homework!" << endl;
		return 1;
	}

	if (didnt.empty()) {
		cout << "Every student did all homework!" << endl;
		return 1;
	}

	/*
	for (vector<Student_info>::const_iterator i = didnt.begin(); i != didnt.end(); i++)
		cout << i->name << "\n";

	*/

	write_analysis(cout,"median", median_analysis, did, didnt);
	write_analysis(cout,"average", average_analysis, did, didnt);
	write_analysis(cout,"optimistic", optimistic_analysis, did, didnt);

	return 0;
} 
