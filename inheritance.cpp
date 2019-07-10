/* 
 * Вам дан класс Foo.
 * Как видно, создатель класса не хотел чтобы его использовали и "спрятал" конструктор класса. Но вам очень нужен объект этого класса, чтобы передать его в функцию foo_says.
 * В этом задании вам нужно реализовать функцию get_foo (сигнатура которой намерено не приводится в задании полностью, вам нужно подумать и вывести ее самостоятельно) так, чтобы следующий код компилировался и работал:
 *
 * foo_says(get_foo(msg));
 * Где msg — произвольная C-style строка.
 *
 */
#include <iostream>
       
struct Foo {
    void say() const { std::cout << "Foo says: " << msg << "\n"; }
protected:
    Foo(const char *msg) : msg(msg) { }
private:
    const char *msg;
};

struct FooCopy : Foo {
	FooCopy(const char *msg) : Foo(msg) {}
};

void foo_says(const Foo &foo);

const Foo get_foo(const char *msg);

int main(int argc, char const *argv[])
{
	foo_says(get_foo("Hello!"));
	return 0;
}

void foo_says(const Foo &foo) { 
	foo.say(); 
}


// Вам нужно определить функцию get_foo, как описано в задании,
// чтобы компилировался и работал как ожидается следующий код:
//
// foo_says(get_foo("Hello!"));


const Foo get_foo(const char *msg) {
	return FooCopy(msg);
}