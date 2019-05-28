#include <iostream>
using namespace std;

unsigned strlen(const char *str);

int main() {
    cout << "Enter the word:" << endl;
    char word[10];
    cin >> word;
    
    cout << "It's length is " << strlen(word) << endl;
    
    return 0;
}

unsigned strlen(const char * str) {
    unsigned length = 0;
    while (*str != '\0') {
        length++;
        str++;
    }
    return length;
}
