// Example of using c++11 lambda (by Oleksii Reshta)
// Sorting vector of strings by size

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

using VS = vector<string>;

void out(const string& title, const VS& vs)
{
	cout << "\n=== " << title << " ===" << endl;
	for (auto s: vs)
	{
		cout << s << endl;
	}
}

int main()
{
	VS vs = {"ann","john","bill","alex","george","mary","abram"};

	out("Unsorted strings", vs);
	
	// trivial lexical sorting
	sort( vs.begin(),vs.end() );

	out("Sorting by Name", vs);

	// non-trivial sorting by size
	sort( vs.begin(),vs.end(), [](string& s1, string& s2) { return s1.size() < s2.size(); } );

	out("Sorting by Size", vs);
		
	return 0;
}
