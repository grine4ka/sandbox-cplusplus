#include <iostream>
using namespace std;

/*
 * Реализуйте функцию swap_min, которая принимает на вход двумерный массив целых чисел, ищет в этом массиве строку, содержащую наименьшее среди всех элементов массива значение, и меняет эту строку местами с первой строкой массива. 
 * Подумайте, как обменять строки массива, не обменивая элементы строк по-отдельности. 
 */

int ** createArray2d(unsigned rows, unsigned cols);

void swap_min(int *m[], unsigned rows, unsigned cols);

void swapLines(int *m[], unsigned l1, unsigned l2);

void printMatrix(int ** m, unsigned rows, unsigned cols);

int main() {
    int ** m = createArray2d(3, 3);
    for (size_t i = 0; i != 3; i++) {
        for (size_t j = 0; j != 3; j++) {
            m[i][j] = i*3 + j + 1;
        }
    }
    cout << "Matrix to swap lines: " << endl;
    printMatrix(m, 3, 3);
    
    cout << "Swapped: " << endl;
    swapLines(m, 0, 2);
    printMatrix(m, 3, 3);
    
    cout << "Swapped 0 with min: " << endl;
    swap_min(m, 3, 3);
    printMatrix(m, 3, 3);
    
    return 0;
}

void swap_min(int *m[], unsigned rows, unsigned cols) {
    int min = m[0][0], minLine = 0;
    for (unsigned i = 0; i != rows; i++) {
        for (unsigned j = 0; j != cols; j++) {
            if (m[i][j] < min) {
                min = m[i][j];
                minLine = i;
            }
        }
    }
    
    if (minLine != 0) {
        int * t = m[0];
        m[0] = m[minLine];
        m[minLine] = t;
    }
}

void swapLines(int *m[], unsigned l1, unsigned l2) {
    int * t = m[l1];
    m[l1] = m[l2];
    m[l2] = t;
}

int ** createArray2d(unsigned rows, unsigned cols) {
    int ** m = new int *[rows];
    m[0] = new int [rows*cols];
    for (size_t i = 1; i != rows; ++i) {
        m[i] = m[i-1] + cols;
    }
    return m;
}

void printMatrix(int ** m, unsigned rows, unsigned cols) {
    for (size_t i = 0; i != rows; i++) {
        for (size_t j = 0; j != cols; j++) {
            cout << m[i][j] << ' ';
        }
        cout << endl;
    }
}
