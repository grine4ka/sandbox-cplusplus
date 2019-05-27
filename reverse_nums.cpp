#include <iostream>
using namespace std;

void reverse();

int main() {
    reverse();
    cout << endl;
    return 0;
}

void reverse() {
    int num = 0;
    cin >> num;
    if (num != 0) {
        reverse();
        cout << num << " ";
    }
}
