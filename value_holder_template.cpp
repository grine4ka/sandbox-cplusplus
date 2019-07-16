#include <cstddef>
#include <iostream>

using namespace std;

struct ICloneable {
    virtual ICloneable *clone() const = 0;

    virtual ~ICloneable() {}
};

template<typename T>
struct ValueHolder : ICloneable {

    explicit ValueHolder(const T &value) : data_(value) {}

    ICloneable *clone() const override {
        return new ValueHolder(data_);
    }

    T data_;
};

