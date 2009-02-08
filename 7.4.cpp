#include <iostream>
#include <vector>
#include <map>
#include <string>
#include <stdexcept>
#include <cstdlib>
#include <ctime>

#include "useful.hpp";

using namespace std;

typedef vector<string> Rule;
typedef vector<Rule> Rule_Collection;
typedef map<string, Rule_Collection> Grammer;

int nrand(int n) { 
	if (n  <= 0 || n > RAND_MAX)
		throw domain_error("argument to nrand is out of range");

	int bucket_size = RAND_MAX / n;
	int r;

	do 
		r = rand() / bucket_size;
	while (r >= n);

	return r;
}

// this should build a grammer map
Grammer parse_grammer(istream& in) { 
	Grammer ret;
	string line;

	while (getline(in,line)) { 
		vector<string> entry = split(line);	
		ret[entry[0]].push_back(Rule(entry.begin() + 1, entry.end()));
	}

	return ret;
}

bool bracketed(const string& s) { 
	return s.size() > 1 && s[0] == '<' && s[s.size() - 1] == '>';
}

void gen_aux(const Grammer& g,const string& word, vector<string>& ret) { 
	if (!bracketed(word)) {
		ret.push_back(word);
	}
	else {
		Grammer::const_iterator it = g.find(word);

		if (it == g.end())
			throw logic_error("empty rule");

		const Rule_Collection& c = it->second;

		const Rule& r = c[nrand(c.size())];

		for (Rule::const_iterator i = r.begin(); i != r.end(); i++) {	
			gen_aux(g,*i,ret);
		}
	}
}

vector<string> gen_sentence(const Grammer& g) { 
	vector<string> ret;
	gen_aux(g,"<sentence>",ret);
	return ret;
}

int main(void) { 
	srand(time(0));

	Grammer language = parse_grammer(cin);

	vector<string> sentence = gen_sentence(language);

	vector<string>::const_iterator it = sentence.begin();

	cout << *it;
	it++;

	while (it != sentence.end()) {
		cout << " " << *it;
		it++;
	}	
	cout << endl;

	return 0;
}
