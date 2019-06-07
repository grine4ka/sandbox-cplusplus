#include <iostream>
#include <cstddef>
using namespace std;

/*
Задание повышенной сложности.

Определен следующий класс (он также приведен в комментарии в шаблоне кода):

 * Класс Cls определен точно таким образом:
 *
 * struct Cls {
 * Cls(char c, double d, int i);
 * private:
 *     char c;
 *     double d;
 *     int i;
 * };
 *

Как видно, все поля этого класса закрытые, ваша задача реализовать несколько функций, которые дают полный доступ к этим полям (см. шаблон кода), несмотря на то, что они закрытые.

Внимание: предполагаемое решение этого задания существенно опирается на Undefined Behaviour и является исключительно учебным, но полезно для лучшего понимания того, как работают модификаторы доступа. Решение было проверено на различных компиляторах (g++/clang++/icc/msvc), но мы настоятельно не рекомендуем использовать подобные трюки в боевом коде.
 */

struct Cls {
  public:
    Cls(char c, double d, int i) : c(c), d(d), i(i) {}
  private:
    char c;
    double d;
    int i;
};

struct ClsCopy {
    ClsCopy(char c, double d, int i) : c(c), d(d), i(i) {}
  public:
    char c;
    double d;
    int i;
};

char &get_c(Cls &cls);

double &get_d(Cls &cls);

int &get_i(Cls &cls);

int main() {
  Cls x('1', 2.5, 3);

  char c = get_c(x);
  cout << "Char c of class Cls = " << c << endl;
  cout << "Double d of class Cls = " << get_d(x) << endl;
  cout << "Int i of class Cls = " << get_i(x) << endl;
  
  return 0;
}

// Эта функция должна предоставить доступ к полю c объекта cls.
// Обратите внимание, что возвращается ссылка на char, т. е.
// доступ предоставляется на чтение и запись.
char &get_c(Cls &cls) {
    return *(char*)((void*)&cls + offsetof(ClsCopy, c));
}

// Эта функция должна предоставить доступ к полю d объекта cls.
// Обратите внимание, что возвращается ссылка на double, т. е.
// доступ предоставляется на чтение и запись.
double &get_d(Cls &cls) {
    return *(double*)((void*)&cls + offsetof(ClsCopy, d));
}

// Эта функция должна предоставить доступ к полю i объекта cls.
// Обратите внимание, что возвращается ссылка на int, т. е.
// доступ предоставляется на чтение и запись.
int &get_i(Cls &cls) {
    return *(int*)((void*)&cls + offsetof(ClsCopy, i));
}
