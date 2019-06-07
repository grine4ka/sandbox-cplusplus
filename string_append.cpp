#include <cstddef> // size_t
#include <cstring> // strlen, strcpy
#include <iostream>
using namespace std;

/*
Для работы со строками можно придумать множество полезных методов (подумайте, какие методы пригодились бы вам, и чего вам не хватает для их реализации). Примером такого метода может послужить метод append — он добавляет копию строки-аргумента в конец текущей строки (т.е. в конец строки, у которой он был вызван).

String s1("Hello,");
String s2(" world!");

s1.append(s2); // теперь s1 хранит "Hello, world!"

Ваша задача реализовать метод append.

При выполнении задания будьте аккуратны при работе с памятью — при вызове метода не должно возникать утечек памяти. Кроме того, не забудьте, что size хранит размер без учета завершающего 0 символа. 
*/
struct String {

    /* Реализуйте этот конструктор */
	String(const char *str = "") {
        this->size = strlen(str);
        this->str = strcpy(new char[size+1], str);
    }

    /* Реализуйте этот конструктор */
	String(size_t n, char c) : size(n), str(new char[n+1]) {
        for (int i = 0; i != n; ++i) {
            str[i] = c;
        }
        str[n] = '\0';
    }

    /* и деструктор */
	~String() {
        delete [] str;
    }
    
    /* Реализуйте этот метод. */
	void append(String &other) {
        size += other.size;
        char *appended = strcpy(new char[size + 1], str);
        strcat(appended, other.str);
        delete [] str;
        str = appended;
    }

	size_t size;
	char *str;
};

int main() {
    cout << "Enter the first word:" << endl;
    char word[10];
    cin >> word;
    String newString(word);
    
    cout << "Enter the second word:" << endl;
    cin >> word;
    String newString2(word);
    
    newString.append(newString2);
    
    cout << "Size of string is " << newString.size << endl;
    cout << "Content of string is " << newString.str << endl;
    
    return 0;
}
