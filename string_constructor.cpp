#include <cstddef> // size_t
#include <cstring> // strlen, strcpy
#include <iostream>
using namespace std;

/*
Начнем мы с написания конструктора. В этой задаче вам требуется реализовать конструктор, который принимает на вход C-style строку, вычисляет ее размер (без учета завершающего 0 символа) и сохраняет его в поле size, кроме того, конструктор должен аллоцировать память достаточную для хранения копии переданной строки (вместе с завершающим 0 символом), копирует переданную строку в выделенную память и сохраняет указатель на начало этой области памяти в поле str. Т.е. в результате работы конструктора в поле str должен оказаться указатель на C-строку c копией исходной строки, а в поле size — длина строки без учета завершающего нулевого символа. 
*/
struct String {

    /* Реализуйте этот конструктор */
	String(const char *str = "") {
        this->size = strlen(str);
        this->str = strcpy(new char[size+1], str);
    }

	size_t size;
	char *str;
};

int main() {
    cout << "Enter the word:" << endl;
    char word[10];
    cin >> word;
    
    cout << "It's length is " << strlen(word) << endl;
    
    String newString(word);
    
    cout << "Size of copied string is " << newString.size << endl;
    cout << "Content of copied string is " << newString.str << endl;
    
    return 0;
}
