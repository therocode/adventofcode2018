#pragma once
#include <array>
#include <cstddef>

namespace cexp
{
template <typename T,  size_t capacity>
struct array
{
    std::array<T, capacity> elements = {};
    size_t size = {};
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
    arr.elements[arr.size++] = val;
}

template <typename T,  size_t capacity>
constexpr const T& at(const array<T, capacity>& arr, size_t i)
{
    return arr.elements[i];
}
}
