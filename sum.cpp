#include <iostream>
using namespace std;

int main()
{
    int lines = 0;
    cin >> lines;
    for (int i = 0; i < lines; i++) {
        int first = 0;
        int second = 0;
        cin >> first >> second;
        cout << (first + second) << endl;
    }
    return 0;
}
