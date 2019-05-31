#include <iostream>
using namespace std;

/*
 * В этой задаче вам нужно реализовать функцию resize. Функция resize принимает на вход три аргумента: указатель на область памяти, выделенную с помощью оператора new[], размер области (size) и новый размер (new_size). Функция должна выделить память размера new_size, скопировать в нее данные из переданной области памяти, освободить старую область памяти и вернуть выделенную область памяти нового размера со скопированными данными.  

Обратите внимание, что память, возвращенная из функции, будет освобождена с помощью оператора delete[]. Несмотря на то, что входной тип данных — это const char *, не стоит рассчитывать, что там хранится C-style строка. При выполнении задания также учтите, что new_size может быть меньше size. 
 */
char *resize(const char *str, unsigned size, unsigned new_size);

int main() {
    char * str = new char[12];
    str[0] = 'H';
    str[1] = 'e';
    str[2] = 'l';
    str[3] = 'l';
    str[4] = 'o';
    str[5] = ' ';
    str[6] = 'w';
    str[7] = 'o';
    str[8] = 'r';
    str[9] = 'l';
    str[10] = 'd';
    str[11] = '\0';
    
    cout << "The word: " << str << endl;
    
    char * new_str = resize(str, 12, 5);
    
    cout << "New word: " << new_str << endl;
    delete [] new_str;
    return 0;
}

char *resize(const char *str, unsigned size, unsigned new_size) {
    char * new_str = new char[new_size];
    for (int i = 0; i < size && i < new_size; i++) {
        new_str[i] = str[i];
    }
    delete [] str;
    return new_str;
}
