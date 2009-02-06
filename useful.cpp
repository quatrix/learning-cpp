#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <iterator>
#include <cctype>

using namespace std;

bool space(char c) { 
	return isspace(c);
}

bool not_space(char c) { 
	return !isspace(c);
}

bool not_url_char(char c) { 
	static const string url_ch = "~;/?:@=&$-_.+!*'(),";

	return !(isalnum(c) || find(url_ch.begin(),url_ch.end(),c) != url_ch.end());
}

string::const_iterator url_end(string::const_iterator b, string::const_iterator e) {
	return find_if(b,e,not_url_char);	
}


string::const_iterator url_beg(string::const_iterator b, string::const_iterator e) {
	static const string sep = "://";

	typedef string::const_iterator iter;

	// i marks where the separator was found
	iter i = b;

	while ((i = search(i,e,sep.begin(),sep.end())) != e) {
		// make sure the separator isn't at the beginning or end of the line
		if (i != b && i + sep.size() != e) {
			
			// beg marks the begininng of the protocol name
			iter beg = i;
			while (beg != b && isalpha(beg[-1]))
				--beg;

			// is there at least one appropriate char before and after the seperator
			if (beg != i && !not_url_char(i[sep.size()]))
				return beg;
		}

		i += sep.size();
	}

	return e;
}
	
vector<string> split(const string& s) { 
	vector<string> ret;
	typedef string::const_iterator iter;

	iter i = s.begin();

	while (i != s.end()) { 
		i = find_if(i,s.end(),not_space);

		iter j = find_if(i,s.end(),space);

		if (i != s.end()) 
			ret.push_back(string(i,j));

		i = j;	
	}	
	return ret;
}

void print_vec(const vector<string>& s) { 
	vector<string>::const_iterator i = s.begin();
	while (i != s.end()) { 
		cout << (*i++) << endl;
	}	
}


vector<string> find_urls(const string& s) { 
	vector<string> ret;
	typedef string::const_iterator iter;

	iter b = s.begin(), e = s.end();

	while (b != e) { 
		b = url_beg(b,e);

		if (b != e) { 
			iter after = url_end(b,e);

			ret.push_back(string(b,after));

			b = after;	
		}
	}	
	return ret;
}
