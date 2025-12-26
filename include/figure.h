#pragma once

#include "scalar.h"
#include "point.h"

#include <cstddef>
#include <stdexcept>

template <Scalar T>
class Figure {
public:
    virtual ~Figure() = default;

public:
    virtual std::size_t vertices_count() const = 0;
    virtual const Point<T>& vertex(std::size_t index) const = 0;

public:
    double area() const {
        std::size_t n;
        n = vertices_count();

        if (n < 3) {
            return 0.0;
        }

        long double s;
        s = 0.0L;

        std::size_t i;
        i = 0;

        while (i < n) {
            std::size_t j;
            j = i + 1;

            if (j == n) {
                j = 0;
            }

            const Point<T>& p1 = vertex(i);
            const Point<T>& p2 = vertex(j);

            long double x1;
            long double y1;
            long double x2;
            long double y2;

            x1 = static_cast<long double>(p1.x);
            y1 = static_cast<long double>(p1.y);
            x2 = static_cast<long double>(p2.x);
            y2 = static_cast<long double>(p2.y);

            s = s + (x1 * y2 - x2 * y1);

            i = i + 1;
        }

        if (s < 0.0L) {
            s = -s;
        }

        s = s / 2.0L;

        return static_cast<double>(s);
    }

    Point<double> geometric_center() const {
        std::size_t n;
        n = vertices_count();

        long double sum_x;
        long double sum_y;

        sum_x = 0.0L;
        sum_y = 0.0L;

        std::size_t i;
        i = 0;

        while (i < n) {
            const Point<T>& p = vertex(i);

            sum_x = sum_x + static_cast<long double>(p.x);
            sum_y = sum_y + static_cast<long double>(p.y);

            i = i + 1;
        }

        long double cx;
        long double cy;

        cx = sum_x / static_cast<long double>(n);
        cy = sum_y / static_cast<long double>(n);

        Point<double> res;
        res.x = static_cast<double>(cx);
        res.y = static_cast<double>(cy);

        return res;
    }

public:
    void print(std::ostream& out) const {
        std::size_t n;
        n = vertices_count();

        out << "Vertices:\n";

        std::size_t i;
        i = 0;

        while (i < n) {
            out << "  ";
            out << i;
            out << ": ";
            out << vertex(i);
            out << "\n";
            i = i + 1;
        }

        Point<double> c;
        c = geometric_center();

        out << "Center: ";
        out << "(" << c.x << ", " << c.y << ")";
        out << "\n";

        double a;
        a = area();

        out << "Area: ";
        out << a;
        out << "\n";
    }

public:
    operator double() const {
        double a;
        a = area();
        return a;
    }
};
