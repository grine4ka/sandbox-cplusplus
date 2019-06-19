/*
 * (Задание повышенной сложности) Предполагаемое решение этого задания не переносимо с точки зрения стандарта, однако оно проверено на различных версиях 
 * компиляторов g++/clang++/msvc. Решение этого задания не обязательно для получения диплома по этому курсу, однако мы считаем его полезным, чтобы лучше 
 * понять как устроены виртуальные функции внутри.
 * 
 * Вам требуется реализовать функцию, которая принимает на вход два указателя на базовый класс Expression, и возвращает true, если оба указателя
 * указывают на самом деле на объекты одного и того же класса, и false в противном случае (т.е. если оба указателя указывают на BinaryOperation, то
 * возвращается true, а если один из них указывает на Number, а второй на BinaryOperation, то false).
 */
#include <iostream>
#include <cstddef>
using namespace std;

struct Expression
{
    virtual double evaluate() const = 0;
    
    virtual ~Expression() {}
};

struct Number : Expression
{
    Number(double value)
        : value(value)
    {}

    double evaluate() const {
        return value;
    }
    
private:
    double value;
};

struct BinaryOperation : Expression
{
    /*
      Здесь op это один из 4 символов: '+', '-', '*' или '/', соответствующих операциям,
      которые вам нужно реализовать.
     */
    BinaryOperation(Expression const * left, char op, Expression const * right)
        : left(left), op(op), right(right)
    { }

    double evaluate() const {
        switch (op) {
            case '+':
                return left->evaluate() + right->evaluate();
            case '-':
                return left->evaluate() - right->evaluate();
            case '*':
                return left->evaluate() * right->evaluate();
            case '/': {
                const double r = right->evaluate();
                if (r) {
                    return left->evaluate() / r;
                }
            }
            default: return 0.0;
        }
    }
    
    ~BinaryOperation() {
        delete left;
        delete right;
    }
    
private:
    Expression const * left;
    Expression const * right;
    char op;
};

bool check_equals(Expression const *left, Expression const *right);

int main() {
    Number * num = new Number(3);
    Number * num2 = new Number(5);
    Expression * expr = new BinaryOperation(num, '+', num2);
    
    cout << check_equals(num, num2) << endl;
    cout << check_equals(num, expr) << endl;
}

bool check_equals(Expression const *left, Expression const *right) {
    // int * - указатель на таблицу виртуальных методов
    int * l = (int *)left;
    int * r = (int *)right;
    
    cout << "Vtable begins" << endl;
    cout << "Left 0 " << *l << endl;
    cout << "Right 0 " << *r << endl;
    
    return *l == *r;
}
