#pragma once
#include <common/containers.hpp>
#include <common/stoi.hpp>
#include <common/parse_string_list.hpp>

namespace cexp
{
struct rectangle
{
    int x;
    int y;
    int width;
    int height;
};


template <size_t capacity>
constexpr array<rectangle, capacity> parse_rectangles(std::string_view str)
{
    array<rectangle, capacity> result{};
    array<std::string_view, capacity> strings = parse_string_list<capacity>(str);

    //"#1 @ 1,3: 4x4" is every entry

    for(size_t i = 0; i < strings.size / 4; i += 4)
    {//jump 4 at a time 
        auto x_stoi = stoi(strings[i+2].data());
        auto y_stoi = stoi(x_stoi.next + 1);
        auto width_stoi = stoi(strings[i+3].data());
        auto height_stoi = stoi(width_stoi.next + 1);

        push_back(result, rectangle{x_stoi.result, y_stoi.result, width_stoi.result, height_stoi.result});
    }

    return result;
}
}
