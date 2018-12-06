#pragma once
#include <common/containers.hpp>
#include <common/stoi.hpp>

namespace cexp
{
template <size_t capacity>
constexpr array<std::string_view, capacity> parse_string_list(std::string_view str)
{
    array<std::string_view, capacity> result;

    const char* start = str.data();
    const char* end = start + str.size();
    const char* current = str.data();

    const char* current_segment_start = current;
    size_t current_segment_count = 0;

    while(current != end)
    {
        if(is_space(*current))
        {
            if(current_segment_count > 0)
            {
                push_back(result, std::string_view{current_segment_start, current_segment_count});
            }

            current_segment_start = current + 1;
            current_segment_count = 0;
        }
        else
        {
            ++current_segment_count;
        }

        ++current;
    }

    if(current_segment_count > 0)
    {
        push_back(result, std::string_view{current_segment_start, current_segment_count});
    }

    return result;
}
}
