#pragma once

#include "figure.h"

#include <memory>
#include <stdexcept>
#include <iostream>

template <Scalar T>
class Rhombus : public Figure<T> {
private:
    std::unique_ptr<Point<T>> p0;
    std::unique_ptr<Point<T>> p1;
    std::unique_ptr<Point<T>> p2;
    std::unique_ptr<Point<T>> p3;

public:
    Rhombus() {
        p0 = std::make_unique<Point<T>>();
        p1 = std::make_unique<Point<T>>();
        p2 = std::make_unique<Point<T>>();
        p3 = std::make_unique<Point<T>>();
    }

    Rhombus(const Rhombus& other) {
        p0 = std::make_unique<Point<T>>(*other.p0);
        p1 = std::make_unique<Point<T>>(*other.p1);
        p2 = std::make_unique<Point<T>>(*other.p2);
        p3 = std::make_unique<Point<T>>(*other.p3);
    }

    Rhombus& operator=(const Rhombus& other) {
        if (this == &other) {
            return *this;
        }

        p0 = std::make_unique<Point<T>>(*other.p0);
        p1 = std::make_unique<Point<T>>(*other.p1);
        p2 = std::make_unique<Point<T>>(*other.p2);
        p3 = std::make_unique<Point<T>>(*other.p3);

        return *this;
    }

    Rhombus(Rhombus&&) noexcept = default;
    Rhombus& operator=(Rhombus&&) noexcept = default;

    ~Rhombus() override = default;

public:
    std::size_t vertices_count() const override {
        return 4;
    }

    const Point<T>& vertex(std::size_t index) const override {
        if (index == 0) {
            return *p0;
        }
        if (index == 1) {
            return *p1;
        }
        if (index == 2) {
            return *p2;
        }
        if (index == 3) {
            return *p3;
        }

        throw std::out_of_range("Rhombus: bad index");
    }

public:
    bool operator==(const Rhombus& other) const {
        if (*p0 == *other.p0 && *p1 == *other.p1 && *p2 == *other.p2 && *p3 == *other.p3) {
            return true;
        }
        return false;
    }

public:
    friend std::istream& operator>>(std::istream& in, Rhombus& r) {
        Point<T> t0;
        Point<T> t1;
        Point<T> t2;
        Point<T> t3;

        in >> t0;
        in >> t1;
        in >> t2;
        in >> t3;

        r.p0 = std::make_unique<Point<T>>(t0);
        r.p1 = std::make_unique<Point<T>>(t1);
        r.p2 = std::make_unique<Point<T>>(t2);
        r.p3 = std::make_unique<Point<T>>(t3);

        return in;
    }
};

