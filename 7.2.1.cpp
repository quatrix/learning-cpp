#include <iostream>
#include <string>
#include <map>

using namespace std;


int main(void) {
	map <string,int> counters;
	string s;

	while (cin >> s) 
		counters[s]++;
	
	cout << string(79,'*') << endl;

	for (map<string,int>::const_iterator i = counters.begin(); i != counters.end(); i++) 
		cout << i->first << "\t" << i->second << endl;


}
