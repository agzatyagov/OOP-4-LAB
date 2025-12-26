#include "array.h"
#include "figure.h"
#include "rhombus.h"
#include "pentagon.h"
#include "hexagon.h"

#include <iostream>
#include <memory>

int main() {
    using T = double;

    Array<std::shared_ptr<Figure<T>>> figures;

    bool work;
    work = true;

    while (work) {
        std::cout << "\n";
        std::cout << "1 - Add Rhombus (4 points)\n";
        std::cout << "2 - Add Pentagon (5 points)\n";
        std::cout << "3 - Add Hexagon (6 points)\n";
        std::cout << "4 - Print all info about figures in massiv\n";
        std::cout << "5 - Total area\n";
        std::cout << "6 - Remove by index\n";
        std::cout << "0 - Stop programm\n";
        std::cout << "Command: ";

        int cmd;
        std::cin >> cmd;

        if (cmd == 0) {
            work = false;
        }

        if (cmd == 1) {
            std::cout << "Enter 4 points: x y x y x y x y\n";

            std::shared_ptr<Rhombus<T>> r;
            r = std::make_shared<Rhombus<T>>();

            std::cin >> *r;

            std::shared_ptr<Figure<T>> f;
            f = r;

            figures.push_back(f);

            std::cout << "Added.\n";
        }

        if (cmd == 2) {
            std::cout << "Enter 5 points: x y ... (10 numbers)\n";

            std::shared_ptr<Pentagon<T>> p;
            p = std::make_shared<Pentagon<T>>();

            std::cin >> *p;

            std::shared_ptr<Figure<T>> f;
            f = p;

            figures.push_back(f);

            std::cout << "Added.\n";
        }

        if (cmd == 3) {
            std::cout << "Enter 6 points: x y ... (12 numbers)\n";

            std::shared_ptr<Hexagon<T>> h;
            h = std::make_shared<Hexagon<T>>();

            std::cin >> *h;

            std::shared_ptr<Figure<T>> f;
            f = h;

            figures.push_back(f);

            std::cout << "Added.\n";
        }

        if (cmd == 4) {
            if (figures.size() == 0) {
                std::cout << "Array is empty.\n";
            }

            std::size_t i;
            i = 0;

            while (i < figures.size()) {
                std::cout << "Index: " << i << "\n";

                figures[i]->print(std::cout);

                i = i + 1;
            }
        }

        if (cmd == 5) {
            double sum;
            sum = 0.0;

            std::size_t i;
            i = 0;

            while (i < figures.size()) {
                double a;
                a = static_cast<double>(*figures[i]);   // т.к double перегружен для вычисления площади фигуры

                sum = sum + a;

                i = i + 1;
            }

            std::cout << "Total area: " << sum << "\n";
        }

        if (cmd == 6) {
            std::cout << "Enter index: ";

            int idx;
            std::cin >> idx;

            if (idx < 0) {
                std::cout << "Bad index.\n";
            }
            else {
                std::size_t uidx;
                uidx = static_cast<std::size_t>(idx);

                if (uidx >= figures.size()) {
                    std::cout << "Bad index.\n";
                }
                else {
                    figures.remove(uidx);
                    std::cout << "Removed.\n";
                }
            }
        }
    }

    return 0;
}
