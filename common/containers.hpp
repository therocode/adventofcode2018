#pragma once
#include <array>
#include <cstddef>

#include <iostream>
namespace cexp
{
template <typename T,  size_t capacity>
struct array
{
    std::array<T, capacity> elements = {};
    size_t size = {};

    constexpr const T& operator[](size_t index) const
    {
        return elements[index];
    }
    constexpr T& operator[](size_t index)
    {
        return elements[index];
    }
};

template <typename T,  size_t capacity>
constexpr auto begin(const array<T, capacity>& a)
{
    return a.elements.begin();
}

template <typename T,  size_t capacity>
constexpr auto end(const array<T, capacity>& a)
{
    return a.elements.begin() + a.size;
}

template <typename T,  size_t capacity>
constexpr auto begin(array<T, capacity>& a)
{
    return a.elements.begin();
}

template <typename T,  size_t capacity>
constexpr auto end(array<T, capacity>& a)
{
    return a.elements.begin() + a.size;
}

template <typename T,  size_t capacity>
constexpr void push_back(array<T, capacity>& arr, const T& val)
{
    if(arr.size == arr.elements.size())
    {
        throw("full");
    }

    size_t index = arr.size;
    ++arr.size;
    arr.elements[index] = val;
}

template <typename T,  size_t capacity>
constexpr const T& at(const array<T, capacity>& arr, size_t i)
{
    return arr.elements[i];
}

template <typename T, size_t capacity>
constexpr void resize(array<T, capacity>& arr, size_t size)
{
    arr.size = size;
}
}
