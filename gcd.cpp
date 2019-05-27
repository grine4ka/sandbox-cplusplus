#include <iostream>
using namespace std;

unsigned gcd(unsigned a, unsigned b);

int main() {
    
    unsigned a = 0, b = 0;
    cin >> a >> b;
    cout << gcd(a, b) << endl;
    
    return 0;
}

unsigned gcd(unsigned a, unsigned b) {
    if (a == 0) {
        return b;
    }
    if (b == 0) {
        return a;
    }
    if (a > b) {
        return gcd(b, a % b);
    } else {
        return gcd(a, b % a);
    }
}
