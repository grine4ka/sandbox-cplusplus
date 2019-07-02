/*
 * Первая часть
 * Вам дан класс Rational, который описывает рациональное число.
 * В нем определены методы add, sub, mul и div, которые прибавляют к нему число, отнимают число, умножают на число и делят на число соответственно.
 * Кроме того в нем определен метод neg, который меняет знак на противоположный.
 * Вам нужно определить операторы +=, -=, *=, /= для класса Rational так, чтобы они могли принимать в качестве аргументов и объекты типа Rational и целые числа.
 * Кроме того вам необходимо определить операторы унарного минуса и плюса для класса Rational.
 *
 * Вторая часть
 * Определите для класса Rational операторы сложения, вычитания, умножения и деления,
 * так чтобы объекты типа Rational можно было складывать (вычитать, умножать и делить) не только друг с другом но и с целыми числами.
 *
 * Третья часть
 * Еще одна важная группа операторов, которые полезно реализовать для класса рациональных чисел — это операторы сравнения.
 * Реализуйте операторы <, <=, >, >=, ==, != для класса Rational так, чтобы можно было сравнивать объекты класса Rational не только друг с другом, но и с целыми числами.
 *
 * Четвертая часть
 * Добавьте в класс Rational оператор приведения к double.
 * Все операторы из предыдущих заданий отсутствуют и реализовывать их не нужно. Метод to_double можно использовать в этом задании.
 *
 */
#include <iostream>

struct Rational {
    Rational(int numerator = 0, int denominator = 1) : numerator_(numerator), denominator_(denominator) {};

    void add(Rational rational) {
        numerator_ = numerator_ * rational.denominator_ + rational.numerator_ * denominator_;
        denominator_ *= rational.denominator_;
    }

    void sub(Rational rational) {
        numerator_ = numerator_ * rational.denominator_ - rational.numerator_ * denominator_;
        denominator_ *= rational.denominator_;
    }

    void mul(Rational rational) {
        numerator_ *= rational.numerator_;
        denominator_ *= rational.denominator_;
    }

    void div(Rational rational) {
        numerator_ *= rational.denominator_;
        denominator_ *= rational.numerator_;
    }

    void neg() {
        numerator_ = -numerator_;
    }

    void inv() {}

    double to_double() const {
        return numerator_ / (double) denominator_;
    }

    // Первая часть
    Rational & operator+=(Rational const &r) {
        this->add(r);
        return *this;
    }

    Rational & operator*=(Rational const &r) {
        this->mul(r);
        return *this;
    }

    Rational & operator-=(Rational const &r) {
        this->sub(r);
        return *this;
    }

    Rational & operator/=(Rational const &r) {
        this->div(r);
        return *this;
    }

    Rational operator-() const {
        Rational rn(this->numerator_, this->denominator_);
        rn.neg();
        return rn;
    }

    Rational operator+() const {
        Rational rn(this->numerator_, this->denominator_);
        return rn;
    }

    // Третья часть
    friend bool operator<(Rational const &r1, Rational const &r) {
        return (r1.numerator_ * r.denominator_) < (r.numerator_ * r1.denominator_);
    }

    friend bool operator==(Rational const &r1, Rational const &r) {
        return (r1.numerator_ * r.denominator_) == (r.numerator_ * r1.denominator_);
    }

    // Четвертая часть
    operator double() const {
        return this->to_double();
    }

private:
    int numerator_;
    int denominator_;
};

// Вторая часть
Rational operator+(Rational r1, Rational const &r) {
    return r1+=r;
}

Rational operator-(Rational r1, Rational const &r) {
    return r1-=r;
}

Rational operator*(Rational r1, Rational const &r) {
    return r1*=r;
}

Rational operator/(Rational r1, Rational const &r) {
    return r1/=r;
}

// Третья часть
bool operator!=(Rational const &r1, Rational const &r) {
    return !(r1 == r);
}

bool operator>(Rational const &r1, Rational const &r) {
    return r < r1;
}

bool operator<=(Rational const &r1, Rational const &r) {
    return !(r < r1);
}

bool operator>=(Rational const &r1, Rational const &r) {
    return !(r1 < r);
}

int main() {
    Rational r1(1, 2);
    Rational r2(1, 3);
    Rational r3(5);

    // Первая часть
    r1 += r2;
    std::cout << r1.to_double() << std::endl;
    r1 -= r2;
    std::cout << r1.to_double() << std::endl;
    Rational rm = -r1;
    std::cout << rm.to_double() << std::endl;
    r3 *= rm;
    std::cout << r3.to_double() << std::endl;
    r3 /= r2;
    std::cout << r3.to_double() << std::endl;

    // Третья часть
    Rational r4(5, 10);
    std::cout << (r1 == r4) << std::endl;
    Rational r5(2, 3);
    Rational r6(3, 4);
    std::cout << (r5 >= r6) << std::endl;

    // Четвертая часть
    double d = (double) r1;
    std::cout << d << std::endl;
}

