#include "calculator.h"
#include <stdexcept>
#include <limits>

int Calculator::add(int a, int b) {
    if (b > 0 && a > std::numeric_limits<int>::max() - b) {
        throw std::overflow_error("Integer overflow in addition!");
    }
    if (b < 0 && a < std::numeric_limits<int>::min() - b) {
        throw std::overflow_error("Integer underflow in addition!");
    }
    return a + b;
}

int Calculator::sub(int a, int b) {
    if (b < 0 && a > std::numeric_limits<int>::max() + b) {
        throw std::overflow_error("Integer overflow in subtraction!");
    }
    if (b > 0 && a < std::numeric_limits<int>::min() + b) {
        throw std::overflow_error("Integer underflow in subtraction!");
    }
    return a - b;
}


int Calculator::mul(int a, int b) {
    if (a == 0 || b == 0) return 0;

    if (a > 0) {
        if (b > 0) {
            if (a > std::numeric_limits<int>::max() / b) {
                throw std::overflow_error("Integer overflow in multiplication!");
            }
        } else {
            if (b < std::numeric_limits<int>::min() / a) {
                throw std::overflow_error("Integer underflow in multiplication!");
            }
        }
    } else {
        if (b > 0) {
            if (a < std::numeric_limits<int>::min() / b) {
                throw std::overflow_error("Integer underflow in multiplication!");
            }
        } else {
            if (a != 0 && b < std::numeric_limits<int>::max() / a) {
                throw std::overflow_error("Integer overflow in multiplication!");
            }
        }
    }

    return a * b;
}


int Calculator::div(int a, int b) {
    // TODO
    if (b==0) {
        throw std::invalid_argument("Cannot divide by zero!");
    }
    if (a == std::numeric_limits<int>::min() && b == -1) {
        throw std::overflow_error("Integer overflow in division!");
    }
    return a/b;
}