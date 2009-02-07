#include <iostream>
#include <string>
#include <vector>
#include <map>
#include "useful.hpp"

using namespace std;

map <string, vector<int> > xref(istream& in, vector<string> find_words(const string&) = split ) { 
	string line;
	int line_number = 0;
	map <string, vector<int> > ret;

	while (getline(in,line)) { 
		line_number++;
		vector<string> words = find_words(line);
		
		for (vector<string>::const_iterator it = words.begin(); it != words.end(); it++)
			ret[*it].push_back(line_number);


	}

	return ret;
}

int main(void) {
	map <string, vector<int> > words_index = xref(cin);


	for (map<string, vector<int> >::const_iterator i = words_index.begin(); i != words_index.end(); i++) {
		cout << i->first << " : ";
		
		vector<int>::const_iterator j = i->second.begin();
		cout << *j;
		j++;
		while (j != i->second.end()) { 
			cout << ", " << *j;
			j++;
		}
		cout << endl;
	}

	return 0;
}
