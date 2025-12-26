#pragma once

#include "figure.h"

#include <memory>
#include <stdexcept>
#include <iostream>

template <Scalar T>
class Pentagon : public Figure<T> {
private:
    std::unique_ptr<Point<T>> p0;
    std::unique_ptr<Point<T>> p1;
    std::unique_ptr<Point<T>> p2;
    std::unique_ptr<Point<T>> p3;
    std::unique_ptr<Point<T>> p4;

public:
    Pentagon() {
        p0 = std::make_unique<Point<T>>();
        p1 = std::make_unique<Point<T>>();
        p2 = std::make_unique<Point<T>>();
        p3 = std::make_unique<Point<T>>();
        p4 = std::make_unique<Point<T>>();
    }

    Pentagon(const Pentagon& other) {
        p0 = std::make_unique<Point<T>>(*other.p0);
        p1 = std::make_unique<Point<T>>(*other.p1);
        p2 = std::make_unique<Point<T>>(*other.p2);
        p3 = std::make_unique<Point<T>>(*other.p3);
        p4 = std::make_unique<Point<T>>(*other.p4);
    }

    Pentagon& operator=(const Pentagon& other) {
        if (this == &other) {
            return *this;
        }

        p0 = std::make_unique<Point<T>>(*other.p0);
        p1 = std::make_unique<Point<T>>(*other.p1);
        p2 = std::make_unique<Point<T>>(*other.p2);
        p3 = std::make_unique<Point<T>>(*other.p3);
        p4 = std::make_unique<Point<T>>(*other.p4);

        return *this;
    }

    Pentagon(Pentagon&&) noexcept = default;
    Pentagon& operator=(Pentagon&&) noexcept = default;

    ~Pentagon() override = default;

public:
    std::size_t vertices_count() const override {
        return 5;
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

        throw std::out_of_range("Pentagon: bad index");
    }

public:
    bool operator==(const Pentagon& other) const {
        if (*p0 == *other.p0 && *p1 == *other.p1 && *p2 == *other.p2 && *p3 == *other.p3 && *p4 == *other.p4) {
            return true;
        }
        return false;
    }

public:
    friend std::istream& operator>>(std::istream& in, Pentagon& r) {
        Point<T> t0;
        Point<T> t1;
        Point<T> t2;
        Point<T> t3;
        Point<T> t4;

        in >> t0;
        in >> t1;
        in >> t2;
        in >> t3;
        in >> t4;

        r.p0 = std::make_unique<Point<T>>(t0);
        r.p1 = std::make_unique<Point<T>>(t1);
        r.p2 = std::make_unique<Point<T>>(t2);
        r.p3 = std::make_unique<Point<T>>(t3);
        r.p4 = std::make_unique<Point<T>>(t4);

        return in;
    }
};
