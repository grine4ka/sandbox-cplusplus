#include <iostream>
using namespace std;

void rotate(int a[], unsigned size, int shift);

void rotate1(int a[], unsigned size);

int main() {
    cout << "Enter the size of the array:" << endl;
    int size = 0;
    cin >> size;
    int arr[size] = {};
    
    cout << "Enter the array:" << endl;
    for (int i = 0; i < size; i++) {
        cin >> arr[i];
    }

    int shift = 0;
    cout << "Enter the shift of the array:" << endl;
    cin >> shift;

    rotate(arr, size, shift);
    
    for (int i = 0; i < size; i++) {
        cout << arr[i] << ' ';
    }
    cout << endl;
    
    return 0;
}

void rotate1(int a[], unsigned size) {
    int tmp = *a; // first element of the array
    for (int * p = a; p < a + size; ++p) {
        *p = *(p+1);
    }
    a[size - 1] = tmp;
}

void rotate(int a[], unsigned size, int shift) {
    int newShift = shift % size;
    for (int i = 0; i < newShift; i++) {
        rotate1(a, size);
    }
}
