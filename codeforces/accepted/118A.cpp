#include <iostream>
#include <cstring>

using namespace std;

int main() {
    char str[1000];
    bool consonant[1000];
    int i;

    cin >> str;
    for (i = 0; i < strlen(str); i++) {
	consonant[i] = false;
        char s = str[i];
	switch(s) {
	case 'A': case 'a':
	case 'O': case 'o':
	case 'Y': case 'y':
	case 'E': case 'e':
	case 'U': case 'u':
	case 'I': case 'i':
		str[i] = '_';	
		break;
	default:
		str[i] = (str[i] <= 'Z') ? (str[i] - 'A' + 'a') : str[i];
		consonant[i] = true;
		break;
	}
    }
    for (i = 0; i < strlen(str); i++) {
	if (consonant[i]) {
		cout << '.' << str[i];
	}
    }
    cout << endl;
    return 0;
}
