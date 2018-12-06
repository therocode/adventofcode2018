#pragma once
#include <common/stoi.hpp>
#include <common/containers.hpp>

namespace cexp
{
template <size_t capacity>
constexpr array<int, capacity> parse_int_list(std::string_view str)
{
    array<int, capacity> result;

    const char* start = str.data();
    const char* end = start + str.size();
    const char* current = start;

    while(current != end)
    {
        stoi_result sr = stoi(current);

        if(sr)
        {
            push_back(result, sr.result);
            current = sr.next;
        }
        else
        {
            throw "error when parsing string";
        }
    }

    return result;
}
}
