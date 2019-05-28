#include <iostream>
using namespace std;

void strcat(char *to, const char *from);

int main() {
    cout << "Enter the first word:" << endl;
    char word1[50];
    cin >> word1;

    cout << "Enter the second word:" << endl;
    char word2[20];
    cin >> word2;
    
    strcat(word1, word2);
    cout << "It's concatenation is " << word1 << endl;
    
    return 0;
}

void strcat(char *to, const char *from) {
    for (; *to != '\0';++to);
    for (; *from != '\0';++from, ++to) {
        *to = *from;
    }
    *to = '\0';
}
