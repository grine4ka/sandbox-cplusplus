#include <iostream>
#include <cmath>
using namespace std;

int main()
{
    // ax^2 + bx + c = 0 - quadratic formula
    // x = (-b±√b^2-4ac)/2a, a!=0 - roots
    int a, b, c;
    cin >> a >> b >> c;
    
    double discriminant = b*b - 4*a*c;
    if (discriminant < 0) {
        cout << "No real roots" << endl;
        return 0;
    }
    double sqrt_disc = sqrt(discriminant);
    double root1 = (double)(-1*b + sqrt_disc)/(2*a);
    double root2 = (double)(-1*b - sqrt_disc)/(2*a);

    cout << root1 << " " << root2 << endl;
    
    return 0;
}
