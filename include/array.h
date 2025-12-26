#pragma once

#include <cstddef>
#include <memory>
#include <stdexcept>
#include <utility>

template <class T>
class Array {
private:
    std::shared_ptr<T[]> data;
    std::size_t sz;
    std::size_t cap;

private:
    void reserve(std::size_t new_cap) {//задание нового cap
        if (new_cap <= cap) {
            return;
        }

        std::shared_ptr<T[]> new_data;
        new_data = std::shared_ptr<T[]>(new T[new_cap], std::default_delete<T[]>());//чтобы не delete ptr, а delete ptr[]

        std::size_t i;
        i = 0;

        while (i < sz) {
            new_data[i] = std::move(data[i]);
            i = i + 1;
        }

        data = new_data;
        cap = new_cap;
    }

public:
    Array() {
        sz = 0;
        cap = 4;
        data = std::shared_ptr<T[]>(new T[cap], std::default_delete<T[]>());//массив по умолчанию с капасити=cap=4
    }

    Array(const Array& other) {
        sz = other.sz;
        cap = other.cap;

        data = std::shared_ptr<T[]>(new T[cap], std::default_delete<T[]>());

        std::size_t i;
        i = 0;

        while (i < sz) {
            data[i] = other.data[i];
            i = i + 1;
        }
    }

    Array& operator=(const Array& other) {
        if (this == &other) {
            return *this;
        }

        sz = other.sz;
        cap = other.cap;

        data = std::shared_ptr<T[]>(new T[cap], std::default_delete<T[]>());

        std::size_t i;
        i = 0;

        while (i < sz) {
            data[i] = other.data[i];
            i = i + 1;
        }

        return *this;
    }

    Array(Array&& other) noexcept {
        data = std::move(other.data);
        sz = other.sz;
        cap = other.cap;

        other.sz = 0;
        other.cap = 0;
    }

    Array& operator=(Array&& other) noexcept {
        if (this == &other) {
            return *this;
        }

        data = std::move(other.data);
        sz = other.sz;
        cap = other.cap;

        other.sz = 0;
        other.cap = 0;

        return *this;
    }

    ~Array() = default;

public:
    std::size_t size() const {
        return sz;
    }

public:
    T& operator[](std::size_t index) {//перегрузка [] в качестве вз€ти€ элемента
        if (index >= sz) {
            throw std::out_of_range("Array: bad index");
        }
        return data[index];
    }

    const T& operator[](std::size_t index) const {//если const Array
        if (index >= sz) {
            throw std::out_of_range("Array: bad index");
        }
        return data[index];
    }

public:
    void push_back(T value) {
        if (sz == cap) {//эмул€ци€ работы капасити при добавении нового элемента
            std::size_t new_cap;
            new_cap = cap * 2;

            reserve(new_cap);
        }

        data[sz] = std::move(value);
        sz = sz + 1;
    }

    void remove(std::size_t index) {
        if (index >= sz) {
            throw std::out_of_range("Array: bad remove index");
        }

        std::size_t i;
        i = index;

        while (i + 1 < sz) {
            data[i] = std::move(data[i + 1]);//сдвиг ээлементов старого массива на 1 индекс влево
            i = i + 1;
        }

        sz = sz - 1;
    }
};
