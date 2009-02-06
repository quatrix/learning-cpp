#include <vector>
#include <string>
#include "useful.hpp"

using namespace std;

int main(void) { 
	string str = "hey, check out this link http://www.baba.com they have some cool stuff there. also, you'd want to look at http://pita.bad.kittie.net it's wild";

	vector<string> urls = find_urls(str);
	print_vec(urls);

}
