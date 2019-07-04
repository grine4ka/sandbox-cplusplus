#include <cstddef> // size_t
#include <cstring> // strlen, strcpy
#include <iostream>

using namespace std;

/*
 * В этой задаче вам требуется реализовать оператор [] для уже известного вам класса String.
 * Однако на этот раз оператор должен реализовывать нестандартное поведение:
 * оператор нужно реализовать таким образом, чтобы для объекта str класса String можно было писать str[i][j] и
 * это выражение возвращало подстроку начинающуюся в позиции i (считая с 0) и заканчивающуюся в позиции j (не включая).
 *
 * Например:
 *
 * String const hello("hello");
 * String const hell = hello[0][4]; // теперь в hell хранится подстрока "hell"
 * String const ell  = hello[1][4]; // теперь в ell хранится подстрока "ell"
 *
 * Обратите внимание, что i может равняться j, в этом случае результатом должна быть пустая строка.
 * Гарантируется, что i никогда не будет больше j, и они не будут выходить за пределы длины строки.
 */

struct String {

    struct Proxy {
        Proxy(size_t start, size_t size, const char *str) {
            this->start = start;
            char *proxy = new char[size + 1];
            size_t pi = 0;
            for (size_t pii = start; pi != size; pii++, pi++) {
                proxy[pi] = str[pii];
            }
            proxy[size] = '\0';
            this->str = proxy;
        }

        String const operator[](int i) const {
            size_t n = i - start;
            return String(str, n);
        }

        ~Proxy() {
            delete[] str;
        }

        size_t start;
        char *str;
    };

    String(const char *str = "") {
        this->size = strlen(str);
        this->str = strcpy(new char[size + 1], str);
    }

    String(const char *str, size_t size) {
        this->size = size;
        char *strn = new char[size + 1];
        for (size_t pi = 0; pi != size; pi++) {
            strn[pi] = str[pi];
        }
        strn[size] = '\0';
        this->str = strn;
    }

    String(size_t n, char c) : size(n), str(new char[n + 1]) {
        for (int i = 0; i != n; ++i) {
            str[i] = c;
        }
        str[n] = '\0';
    }

    String(const String &other) : size(other.size), str(strcpy(new char[size + 1], other.str)) {}

    void append(String &other) {
        size += other.size;
        char *appended = strcpy(new char[size + 1], str);
        strcat(appended, other.str);
        delete[] str;
        str = appended;
    }

    String &operator=(const String &other) {
        if (this != &other) {
            delete[] str;
            size = other.size;
            str = strcpy(new char[size + 1], other.str);
        }
        return *this;
    }

    Proxy const operator[](int i) const {
        int n = size - i;
        return Proxy(i, n, str);
    }

    ~String() {
        delete[] str;
    }

    size_t size;
    char *str;
};

int main() {
    cout << "Double index! Welcome!" << endl;

    String const hello("hello");
    String const hell = hello[0][4]; // теперь в hell хранится подстрока "hell"
    String const ell = hello[1][4]; // теперь в ell хранится подстрока "ell"
    String const empty = hello[4][4];

    cout << "hell = " << hell.str << endl;
    cout << "ell = " << ell.str << endl;
    cout << "ell = " << empty.str << endl;
}