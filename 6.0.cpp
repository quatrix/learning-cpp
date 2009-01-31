#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <iterator>

using namespace std;


void print_vec(const vector<string>& s) {
	for (vector<string>::const_iterator i = s.begin(); i != s.end(); i++) 
		cout << *i << "\n";
}

bool space(char c) {
	return isspace(c);
}

bool not_space(char c) { 
	return !isspace(c);
}

vector<string> split(const string& str) {
	typedef string::const_iterator iter;
	vector<string> ret;

	iter i = str.begin();
	while (i != str.end()) { 
		i = find_if(i,str.end(),not_space);

		iter j = find_if(i,str.end(),space);

		if (i != str.end())
			ret.push_back(string(i,j));

		i = j;
	}

	return ret;
}

int main(void) { 
	
	string baba = "baba";
	string asa  = "asa";

	vector<string> first (5,baba);
	vector<string> second (3,asa);
	
	copy(second.begin(),second.end(),first.rbegin());
	print_vec(first);
	


	/*
	string str = "Damn fox, how can you be so quick?";
	vector<string> str_s = split(str);
	print_vec(str_s);
	*/




}
