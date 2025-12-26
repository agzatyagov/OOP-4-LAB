#include <gtest/gtest.h>

#include "rhombus.h"
#include "array.h"
#include "figure.h"

#include <sstream>
#include <memory>

TEST(RhombusTest, AreaAndCenter) {//вычисление площади и геом.центра
    Rhombus<double> r;

    std::istringstream in("0 1  1 0  0 -1  -1 0");
    in >> r;

    double a;
    a = r.area();

    EXPECT_NEAR(a, 2.0, 1e-9);

    Point<double> c;
    c = r.geometric_center();

    EXPECT_NEAR(c.x, 0.0, 1e-9);
    EXPECT_NEAR(c.y, 0.0, 1e-9);
}

TEST(ArrayTest, RemoveAndSize) {//проверка push_back и remove
    Array<int> a;

    a.push_back(10);
    a.push_back(20);
    a.push_back(30);

    EXPECT_EQ(a.size(), 3u);

    a.remove(1);

    EXPECT_EQ(a.size(), 2u);
    EXPECT_EQ(a[0], 10);
    EXPECT_EQ(a[1], 30);
}

TEST(FiguresArrayTest, TotalArea) {//правильность приведения к double и суммирование площадей
    using T = double;

    Array<std::shared_ptr<Figure<T>>> figs;

    std::shared_ptr<Rhombus<T>> r;
    r = std::make_shared<Rhombus<T>>();

    std::istringstream in("0 1  1 0  0 -1  -1 0");
    in >> *r;

    std::shared_ptr<Figure<T>> f;
    f = r;

    figs.push_back(f);

    double sum;
    sum = 0.0;

    std::size_t i;
    i = 0;

    while (i < figs.size()) {
        double a;
        a = static_cast<double>(*figs[i]);

        sum = sum + a;

        i = i + 1;
    }

    EXPECT_NEAR(sum, r->area(), 1e-9);
}
