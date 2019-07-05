#include <iostream>
#include "arithmetics.h"

/*
 * Помните иерархию Expression, которую мы разрабатывали на четвёртой неделе?
 * Реализуйте ScopedPtr, который будет работать с указателями на базовый класс Expression.
 * В этом задании вам требуется реализовать методы get, release и reset, операторы * и -> так, как это было описано в предыдущем степе.
 * А также реализуйте конструктор ScopedPtr от указателя на Expression.
 *
 * Подсказка: в качестве признака того, что ScopedPtr не хранит никакого указателя (после вызова release), используйте нулевой указатель,
 * при этом вы можете явно проверить указатель в деструкторе, но делать это не обязательно, так как delete от нулевого указателя ничего не делает.
 */
struct ScopedPtr {
    // реализуйте следующие методы:
    explicit ScopedPtr(Expression *ptr = nullptr) : ptr_(ptr) {}

    ~ScopedPtr() {
        delete ptr_;
    }

    Expression* get() const {
        return ptr_;
    }

    Expression* release() {
        Expression *old = ptr_;
        ptr_ = nullptr;
        return old;
    }

    void reset(Expression *ptr = nullptr) {
        delete ptr_;
        ptr_ = ptr;
    }

    Expression& operator*() const {
        return *ptr_;
    }

    Expression* operator->() const {
        return ptr_;
    }

private:
    // запрещаем копирование ScopedPtr
    ScopedPtr(const ScopedPtr &);

    ScopedPtr &operator=(const ScopedPtr &);

    Expression *ptr_;
};

struct SharedPtr
{
    // реализуйте следующие методы
    explicit SharedPtr(Expression *ptr = nullptr) : ptr_(ptr), count_(nullptr) {
        if (ptr) count_ = new size_t(1);
    }

    ~SharedPtr() {
        if (count_) *count_ = *count_ - 1;
        if (count_ && *count_ == 0) {
            delete ptr_;
            delete count_;
        }
    }

    SharedPtr(const SharedPtr &other) : ptr_(other.ptr_), count_(other.count_) {
        if (ptr_) *count_ = *count_ + 1;
    }

    SharedPtr& operator=(const SharedPtr &other) {
        if (this != &other) {
            if (count_) *count_ = *count_ - 1;
            if (count_ && *count_ == 0) {
                delete ptr_;
                delete count_;
            }
            ptr_ = other.ptr_;
            count_ = other.count_;
            if (ptr_) *count_ = *count_ + 1;
        }
        return *this;
    }

    Expression* get() const {
        return ptr_;
    }

    void reset(Expression *ptr = nullptr) {
        if (count_) *count_ = *count_ - 1;
        if (count_ && *count_ == 0) {
            delete ptr_;
            delete count_;
        }
        this->ptr_ = ptr;
        if (ptr != nullptr) {
            count_ = new size_t(1);
        } else {
            count_ = nullptr;
        }
    }

    Expression& operator*() const {
        return *ptr_;
    }

    Expression* operator->() const {
        return ptr_;
    }

private:
    Expression *ptr_;
    size_t *count_;
};

int main() {
    // сначала создаём объекты для подвыражения 4.5 * 5
    Expression *sube = new BinaryOperation(new Number(4.5), '*', new Number(5));
    // потом используем его в выражении для +
    Expression *expr = new BinaryOperation(new Number(3), '+', sube);

    // вычисляем и выводим результат: 25.5
    std::cout << expr->evaluate() << std::endl;

    // тут освобождаются *все* выделенные объекты
    // (например, sube будет правым операндом expr, поэтому его удалять не нужно)
    delete expr;

    SharedPtr p1;
    {
        SharedPtr p2(new Number(2));
        SharedPtr p3(new Number(3));
        SharedPtr p4(p2);
        SharedPtr p5;
        p5 = p2;
        p5 = p4;
        p1 = p5;
        p3.reset(nullptr);
        p3 = p5;
        p5.reset(nullptr);
        SharedPtr p6;
        SharedPtr p7;
        p7 = p7;
        p7.reset(nullptr);
        p7.reset(new Number(7));
        SharedPtr p8(new Number(8));
        p8.reset(nullptr);
    }
    p1 = p1;
}

