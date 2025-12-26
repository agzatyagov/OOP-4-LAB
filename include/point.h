#pragma once

#include "scalar.h"
#include <iostream>

template <Scalar T>
class Point {
public:
    T x;
    T y;

public:
    Point() {
        x = T{};
        y = T{};
    }

    Point(T x_value, T y_value) {
        x = x_value;
        y = y_value;
    }

public:
    bool operator==(const Point& other) const {
        if (x != other.x) {
            return false;
        }
        if (y != other.y) {
            return false;
        }
        return true;
    }
};

template <Scalar T>
std::istream& operator>>(std::istream& in, Point<T>& p) {
    T x_value;
    T y_value;

    in >> x_value;
    in >> y_value;

    p.x = x_value;
    p.y = y_value;

    return in;
}

template <Scalar T>
std::ostream& operator<<(std::ostream& out, const Point<T>& p) {
    out << "(" << p.x << ", " << p.y << ")";
    return out;
}
