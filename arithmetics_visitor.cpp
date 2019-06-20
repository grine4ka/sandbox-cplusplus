/*
 * На прошлом степе вы познакомились с реализацией паттерна посетитель. Теперь пришло время воспользоваться этими знаниями. Ваш класс должен печатать
 * (используя std::cout) текстовое представление арифметического выражения. Т.е. для объекта класса Number он должен напечатать число, которое в нем
 * хранится, а для объекта класса BinaryOperation он должен напечатать левый операнд, затем операцию, а затем правый операнд.
 * 
 * Учтите, что операции + и - имеют меньший приоритет, чем операции * и /, т. е. возможно вам придется печатать дополнительные круглые скобки, чтобы
 * сохранить правильный порядок операций.
 * 
 * При проверке задания лишние пробелы или лишние скобки будут игнорироваться, т.е. вывод "1+2" эквивалентен выводу "( ( 1 )  +   ( 2 ) )", а вот вывод
 * "1 + 2 * 3" не эквивалентен выводу "((1 + 2) * 3)". Вы можете попытаться минимизировать количество скобок в выводе, но это не требуется.
 * 
 */
#include <iostream>
using namespace std;

struct Number;
struct BinaryOperation;

struct Visitor {
    virtual void visitNumber(Number const * number) = 0;
    virtual void visitBinaryOperation(BinaryOperation const * operation) = 0;
    virtual ~Visitor() { }
};

struct Expression
{
    virtual double evaluate() const = 0;
    virtual void visit(Visitor * vistitor) const = 0;
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
    
    void visit(Visitor * visitor) const { visitor->visitNumber(this); }
    
    double get_value() const { return value; }
    
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
    
    void visit(Visitor * visitor) const { visitor->visitBinaryOperation(this); }
    
    Expression const * get_left() const { return left; }
    Expression const * get_right() const { return right; }
    char get_op() const { return op; }

    ~BinaryOperation() {
        delete left;
        delete right;
    }
    
private:
    Expression const * left;
    Expression const * right;
    char op;
};

/* Этот класс вам нужно реализовать */
struct PrintVisitor : Visitor {
    void visitNumber(Number const * number)
    {
        std::cout << number->get_value();
    }

    void visitBinaryOperation(BinaryOperation const * bop)
    {
        std::cout << "(";
        bop->get_left()->visit(this);
        std::cout << " " << bop->get_op() << " ";
        bop->get_right()->visit(this);
        std::cout << ")";
    }
};

int main() {
    // сначала создаём объекты для подвыражения 4.5 * 5
    Expression * sube = new BinaryOperation(new Number(4.5), '+', new Number(5));
    // потом используем его в выражении для +
    Expression * expr = new BinaryOperation(new Number(3), '*', sube);

    PrintVisitor v;
    expr->visit(&v);
    
    cout << endl;
    // тут освобождаются *все* выделенные объекты
    // (например, sube будет правым операндом expr, поэтому его удалять не нужно)
    delete expr;
}
