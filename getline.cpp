#include <iostream>
using namespace std;

/*
 * Реализуйте функцию getline, которая считывает поток ввода посимвольно, пока не достигнет конца потока или не встретит символ переноса строки ('\n'), и возвращает C-style строку с прочитанными символами.

Обратите внимание, что так как размер ввода заранее неизвестен, то вам нужно будет перевыделять память в процессе чтения, если в потоке ввода оказалось больше символов, чем вы ожидали.

Память, возвращенная из функции будет освобождена оператором delete[]. Символ переноса строки ('\n') добавлять в строку не нужно, но не забудьте, что в конце C-style строки должен быть завершающий нулевой символ. 
 */

char *getline();

char *resize(const char *str, unsigned size, unsigned new_size);

int main() {
    char * str = getline();
    cout << "You entered: " << str << endl;
    delete [] str;
    return 0;
}

char *getline() {
    char c = '\0';
    unsigned i = 0, size = 16;
    float loadfactor = 0.75;
    
    char * str = new char[size];
    while (cin.get(c) && c != '\n') {
        if (i > size * loadfactor) {
            str = resize(str, size, size*2);
            size = size*2;
        }
        str[i++] = c;
    }
    str[i] = '\0';
    return str;
}

char *resize(const char *str, unsigned size, unsigned new_size) {
    char * new_str = new char[new_size];
    for (int i = 0; i < size && i < new_size; i++) {
        new_str[i] = str[i];
    }
    delete [] str;
    return new_str;
}
