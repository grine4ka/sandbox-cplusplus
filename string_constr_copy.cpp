#include <cstddef> // size_t
#include <cstring> // strlen, strcpy
#include <iostream>
using namespace std;

/*
 * Добавьте в класс String реализацию конструктора копирования.
 * Инвариант класса остается тем же (в size хранится размер строки без завершающего 0 символа, str указывает на C-style строку, т.е. с завершающим нулевым символом).
 */
struct String {

    /* Реализуйте этот конструктор */
	String(const char *str = "") {
        this->size = strlen(str);
        this->str = strcpy(new char[size+1], str);
    }

    /* Реализуйте конструктор копирования */
	String(const String &other) : size(other.size), str(strcpy(new char[size+1], other.str)) {}

	size_t size;
	char *str;
};

int main() {
    cout << "Enter the word:" << endl;
    char word[10];
    cin >> word;
    
    cout << "It's length is " << strlen(word) << endl;
    
    String newString(word);
    cout << "Size of word is " << newString.size << endl;
    cout << "Content of word is " << newString.str << endl;
    
    String copy(newString);
    
    cout << "Size of copied word is " << copy.size << endl;
    cout << "Content of copied word is " << copy.str << endl;
    
    return 0;
}
