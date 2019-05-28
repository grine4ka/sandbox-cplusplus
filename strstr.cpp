#include <iostream>
using namespace std;

int strstr(const char *text, const char *pattern);

int main() {
    cout << "Enter the first word:" << endl;
    char word1[50];
    cin >> word1;

    cout << "Enter the second word:" << endl;
    char word2[20];
    cin >> word2;
    
    int index = strstr(word1, word2);
    cout << "Second word is at position " << index << " in first word" << endl;
    
    return 0;
}

int strstr(const char *text, const char *pattern) {
    if (*pattern == '\0') {
        return 0;
    }
    const char * textStart = text;
    for (; *text != '\0'; ++text) {
        const char *patternTmp = pattern;
        for (
            const char *patInterception = text;
            *patternTmp != '\0', *patInterception != '\0'; 
            ++patternTmp, ++patInterception
        ) {
            if (*patInterception != *patternTmp) {
                break;
            }
        }
        if (*patternTmp == '\0') {
            return text - textStart;
        }
    }
    return -1;
}
