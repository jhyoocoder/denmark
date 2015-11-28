#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main() {
	string c = "ACM";
	vector<string> a;
	if (c == "ACM") cout << "yes" << endl;
	if (c[0] == 'A') cout << "yes" << endl;	
	a.clear();
	a.push_back("A");
	a.push_back("B");
	if (a[1][0] == 'B') cout << "B" << endl;
	cout << c.length() << endl;
	cout << a.size() << endl;
	return 0;
}
