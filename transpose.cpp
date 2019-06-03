#include <iostream>
using namespace std;

/*
 * Напишите функцию, которая принимает на вход целочисленную матрицу M (другими словами, просто двумерный целочисленный массив) размера rows×cols, и возвращает транспонированную матрицу MT (тоже двумерный целочисленный массив) размера cols×rows. Если в M на пересечении i-ой строки и j-ого столбца стояло число x, то на пересечении  j-ой строки и i-ого столбца в матрице MT тоже будет стоять число x, или другими словами MT[j][i]=M[i][j].
Обратите внимание, что вам неизвестно, каким именно способом выделялась память для массива M. 
Выделять память под массив MT можете любым удобным вам способом. Изменять исходную матрицу нельзя. 
 */

int ** createArray2d(unsigned rows, unsigned cols);

int ** transpose(int ** m, unsigned rows, unsigned cols);

void printMatrix(int ** m, unsigned rows, unsigned cols);

void freeArray2d(int ** m, unsigned rows, unsigned cols);

int main() {
    int ** m = createArray2d(3, 4);
    for (size_t i = 0; i != 3; i++) {
        for (size_t j = 0; j != 4; j++) {
            m[i][j] = i*4 + j + 1;
        }
    }
    cout << "Matrix to transpose: " << endl;
    printMatrix(m, 3, 4);
    
    cout << "Transposed: " << endl;
    int ** t = transpose(m, 3, 4);
    printMatrix(t, 4, 3);
    
    freeArray2d(t, 4, 3);
    freeArray2d(m, 3, 4);
    
    return 0;
}

int ** transpose(int ** m, unsigned rows, unsigned cols)
{
    int ** trans = createArray2d(cols, rows);
    for (size_t i = 0; i != rows; i++) {
        for (size_t j = 0; j != cols; j++) {
            trans[j][i]=m[i][j];
        }
    }
    return trans;
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

void freeArray2d(int ** m, unsigned rows, unsigned cols) {
    delete [] m[0];
    delete [] m;
}
