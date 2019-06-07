#include <cstddef> // size_t
#include <cstring> // strlen, strcpy
#include <iostream>
using namespace std;

/*
Конструкторов у структуры может быть несколько. Для строки может оказаться полезным заполняющий конструктор (например, чтобы создать строку пробелов). Заполняющий конструктор принимает число и символ, и создает строку с заданным количеством повторений переданного символа. Условия налагаемые на реализацию конструктора те же самые (в поле size размер без учета завершающего 0 символа, в поле str C-style строка, т.е. с завершающим 0 символом). Кроме конструктора в этой задаче вам нужно также реализовать и деструктор, который освободит выделенную память.
*/
struct String {

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

	size_t size;
	char *str;
};

int main() {
    cout << "Enter the symbol:" << endl;
    char word;
    cin >> word;
    
    String newString(6, word);
    
    cout << "Size of copied string is " << newString.size << endl;
    cout << "Content of copied string is " << newString.str << endl;
    
    return 0;
}
