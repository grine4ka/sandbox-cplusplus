#include <iostream>
#include <cstddef>
using namespace std;

int ** createArray2d(unsigned rows, unsigned cols);

int main() {
    int const *const *const arr = createArray2d(2, 2);
    
    // arr[1][0] = 1; Ошибка компиляции
    for (size_t i = 0; i != 2; ++i) {
        for (size_t j = 0; j != 2; ++j) {
            cout << arr[i][j] << ' ';
        }
        cout << endl;
    }
}

int ** createArray2d(unsigned rows, unsigned cols) {
    int ** m = new int *[rows];
    m[0] = new int [rows*cols];
    for (size_t i = 1; i != rows; ++i) {
        m[i] = m[i-1] + cols;
    }
    return m;
}
