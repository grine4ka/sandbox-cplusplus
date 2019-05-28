#include <iostream>
using namespace std;

int main()
{
	char prev, c = '\0';
    while (cin.get(c)) {
        if (prev == ' ' && c == ' ') {
        	continue;
        } else {
        	cout << c;
        	prev = c;
        }
    }
	return 0;
}