#pragma once

#include "figure.h"

#include <memory>
#include <stdexcept>
#include <iostream>

template <Scalar T>
class Hexagon : public Figure<T> {
private:
    std::unique_ptr<Point<T>> p0;
    std::unique_ptr<Point<T>> p1;
    std::unique_ptr<Point<T>> p2;
    std::unique_ptr<Point<T>> p3;
    std::unique_ptr<Point<T>> p4;
    std::unique_ptr<Point<T>> p5;

public:
    Hexagon() {
        p0 = std::make_unique<Point<T>>();
        p1 = std::make_unique<Point<T>>();
        p2 = std::make_unique<Point<T>>();
        p3 = std::make_unique<Point<T>>();
        p4 = std::make_unique<Point<T>>();
        p5 = std::make_unique<Point<T>>();
    }

    Hexagon(const Hexagon& other) {
        p0 = std::make_unique<Point<T>>(*other.p0);
        p1 = std::make_unique<Point<T>>(*other.p1);
        p2 = std::make_unique<Point<T>>(*other.p2);
        p3 = std::make_unique<Point<T>>(*other.p3);
        p4 = std::make_unique<Point<T>>(*other.p4);
        p5 = std::make_unique<Point<T>>(*other.p5);
    }

    Hexagon& operator=(const Hexagon& other) {
        if (this == &other) {
            return *this;
        }

        p0 = std::make_unique<Point<T>>(*other.p0);
        p1 = std::make_unique<Point<T>>(*other.p1);
        p2 = std::make_unique<Point<T>>(*other.p2);
        p3 = std::make_unique<Point<T>>(*other.p3);
        p4 = std::make_unique<Point<T>>(*other.p4);
        p5 = std::make_unique<Point<T>>(*other.p5);

        return *this;
    }

    Hexagon(Hexagon&&) noexcept = default;
    Hexagon& operator=(Hexagon&&) noexcept = default;

    ~Hexagon() override = default;

public:
    std::size_t vertices_count() const override {
        return 6;
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
        if (index == 4) {
            return *p4;
        }
        if (index == 5) {
            return *p5;
        }

        throw std::out_of_range("Hexagon: bad index");
    }

public:
    bool operator==(const Hexagon& other) const {
        if (*p0 == *other.p0 && *p1 == *other.p1 && *p2 == *other.p2 &&
            *p3 == *other.p3 && *p4 == *other.p4 && *p5 == *other.p5) {
            return true;
        }
        return false;
    }

public:
    friend std::istream& operator>>(std::istream& in, Hexagon& r) {
        Point<T> t0;
        Point<T> t1;
        Point<T> t2;
        Point<T> t3;
        Point<T> t4;
        Point<T> t5;

        in >> t0;
        in >> t1;
        in >> t2;
        in >> t3;
        in >> t4;
        in >> t5;

        r.p0 = std::make_unique<Point<T>>(t0);
        r.p1 = std::make_unique<Point<T>>(t1);
        r.p2 = std::make_unique<Point<T>>(t2);
        r.p3 = std::make_unique<Point<T>>(t3);
        r.p4 = std::make_unique<Point<T>>(t4);
        r.p5 = std::make_unique<Point<T>>(t5);

        return in;
    }
};

