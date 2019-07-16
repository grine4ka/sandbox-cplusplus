#include <cstddef>
#include <iostream>
#include <new>

using namespace std;

template<typename T>
class Array {
    // Список операций:

public:
    explicit Array(size_t size, const T &value = T()) : size_(size) {
        data_ = static_cast<T *> (operator new[](size_ * sizeof(T)));
        for (int i = 0; i < size_; i++) {
            new(data_ + i) T(value);
        }
    }

    Array() {
        size_ = 0;
        data_ = static_cast<T *> (operator new[](size_ * sizeof(T)));
    }

    Array(const Array &other) : size_(other.size_) {
        data_ = static_cast<T *> (operator new[](size_ * sizeof(T)));
        for (int i = 0; i != size_; ++i) {
            new(data_ + i) T(other.data_[i]);
        }
    }

    ~Array() {
        for (int i = 0; i < size_; i++) {
            data_[i].~T();
        }
        operator delete[](data_);
    }

    Array &operator=(const Array &other) {
        if (this != &other) {
            this->~Array();
            size_ = other.size_;
            data_ = static_cast<T *> (operator new[](size_ * sizeof(T)));
            for (int i = 0; i != size_; ++i) {
                new(data_ + i) T(other.data_[i]);
            }
        }
        return *this;
    }

    size_t size() const {
        return size_;
    }

    T &operator[](size_t i) {
        return data_[i];
    }

    const T &operator[](size_t i) const {
        return data_[i];
    }

    void print() {
        for (size_t i = 0; i < size_; ++i) {
            cout << *(data_ + i);
        }
        cout << endl;
    }

private:
    size_t size_;
    T *data_;
};

// Класс с закрытым оператором присваивания
template<typename Tx>
struct X {
    X() {
        this->x_ = new Tx();
        *this->x_ = 1;
    }

    X(const X &inX) {
        this->x_ = new Tx();
        *this->x_ = *inX.x_;
    }

    ~X() { delete this->x_; }

    friend std::ostream &operator<<(std::ostream &s, const X &obj) {
        s << *(obj.x_);
        return s;
    }

    void set(Tx i) {
        *(this->x_) = i;
    }

private:
    X &operator=(const X &inX);

    Tx *x_;
};

/******************************T E S T *********************/
void test0();

void test1();

void test2();

void test3();

void test4();

void test5();

void test6();

void test7();

int main(int c, char **v) {
    setlocale(LC_ALL, "");
    test0();
    test1();
    test2();
    test3();
    test4();
    test5();
    test6();
    test7();

    return 0;
}

void test0() {
    cout << endl << "*****Test 0(primitives)**********" << endl;
    {
        cout << endl << "*****CHAR**********" << endl;
        Array<char> ar(size_t(5), '0');
        Array<char> x(size_t(4), '4');
        ar = x;
        ar.print();

        Array<char> x2(size_t(6), '6');
        ar = x2;
        ar.print();
    }
    cout << endl;
    {
        cout << endl << "*****STRING**********" << endl;
        Array<string> cr(size_t(5), "0");
        Array<string> cx(size_t(4), "4");
        cr = cx;
        cr.print();

        Array<string> cx2(size_t(6), "6");
        cr = cx2;
        cr.print();
    }
    cout << endl;
    {
        cout << endl << "*****INT**********" << endl;
        Array<int> ir(size_t(5), 0);
        Array<int> ix(size_t(4), 4);
        ir = ix;
        ir.print();

        Array<int> ix2(size_t(6), 6);
        ir = ix2;
        ir.print();
    }
    cout << endl;
    {
        cout << endl << "*****DOUBLE**********" << endl;
        Array<double> dr(size_t(5), 0.0);
        Array<double> dx(size_t(4), 4.0);
        dr = dx;
        dx.print();

        Array<double> ix2(size_t(6), 6.0);
        dr = ix2;
        dr.print();
    }
    cout << endl;
}


void test1() {
    {
        cout << endl << "*****Test 1(assigment)**********" << endl;
        Array<char> ar(size_t(100), '0');
        Array<char> x(size_t(0), '1');
        ar = x;
        ar.print();
    }
    {
        cout << "*****STRING**********" << endl;
        Array<string> cr(size_t(100), "Str0");
        Array<string> cx(size_t(0), "Str1");
        cr = cx;
        cr.print();

        Array<string> cx2(size_t(2), "Str3");
        cr = cx2;
        cr.print();
    }
    {
        cout << "*****INT**********" << endl;
        Array<int> cr(size_t(100), 0);
        Array<int> cx(size_t(0), 15);
        cr = cx;
        cr.print();

        Array<int> cx2(size_t(2), 55);
        cr = cx2;
        cr.print();
    }
}

void test2() {
    cout << endl << "*****Test 2(copy constructor)**********" << endl;
    {
        cout << "*****CHAR**********" << endl;
        Array<char> x(size_t(3), '3');
        Array<char> ar(x);
        ar.print();
    }
    {
        cout << "*****STRING**********" << endl;
        Array<string> x(size_t(3), "333");
        Array<string> ar(x);
        ar.print();
    }
}

void test3() {
    cout << endl << "*****Test 3(Empty)**********" << endl;
    {
        cout << "*****CHAR**********" << endl;
        Array<char> ar(size_t(0), '0');
        ar = ar;
        ar.print();
    }
    {
        cout << "*****STRING**********" << endl;
        Array<string> ar(size_t(0), "0");
        ar = ar;
        ar.print();
    }
}

void test4() {
    cout << endl << "*****Test 4(assigment A=A) **********" << endl;
    {
        Array<char> ar(size_t(4), '0');
        ar = ar;
        ar.print();
    }
}

void test5() {
    cout << endl << "*****Test 5(out bound)**********" << endl;
    {
        cout << "*****more**********" << endl;
        Array<char> ar(size_t(4), '0');
        cout << ar[10] << endl;
    }
    {
        cout << "*****less**********" << endl;
        Array<char> ar(size_t(4), '0');
        cout << ar[-10] << endl;
    }
}

void test6() {
    cout << endl << "*****Test 6(pointer)**********" << endl;
    {
        cout << "*****CHAR(copy)**********" << endl;
        Array<char> *ar = new Array<char>(size_t(4), '4');
        ar->print();
        delete ar;
    }
    {
        cout << "*****CHAR(=)**********" << endl;
        Array<char> *ar = new Array<char>(size_t(5), '5');
        ar->print();
        Array<char> *xr = ar;
        xr->print();
        delete ar;
    }
}

void test7() {
    cout << endl << "*****Test 7(X-object)**********" << endl;
    {
        cout << "***** X<INT> **********" << endl;
        X<int> x;
        x.set(4);
        Array<X<int>> *ar = new Array<X<int>>(size_t(4), x);
        ar->print();
        delete ar;
    }
    {
        cout << "***** X<CHAR> (new, =, copy) **********" << endl;
        X<char> x;
        x.set('c');
        Array<X<char>> *ar = new Array<X<char>>(size_t(4), x);
        ar->print();
        Array<X<char>> *xr = ar;
        xr->print();
        Array<X<char>> y(*xr);
        y.print();
        delete ar;
    }
    {
        cout << "***** X<STRING> (new, =, copy)**********" << endl;
        X<string> x;
        x.set("There are no tests for this task");
        Array<X<string>> *ar = new Array<X<string>>(size_t(1), x);
        ar->print();
        Array<X<string>> *xr = ar;
        xr->print();
        Array<X<string>> y(*xr);
        y.print();
        delete ar;
    }
}
