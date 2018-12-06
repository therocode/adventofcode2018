#include <string_view>
#include <common/parse_int.hpp>
#include <common/parse_string_list.hpp>
#include "input.hpp"

constexpr size_t letter_amount = 26;

template <size_t capacity>
constexpr auto calculate_diff_string(const cexp::array<std::string_view, capacity>& strings)
{
    std::string_view correct_a;
    std::string_view correct_b;

    for(size_t first_i = 0; first_i < strings.size; ++first_i)
    {
        for(size_t second_i = 0; second_i < strings.size; ++second_i)
        {
            if(first_i == second_i)
                continue;

            std::string_view first = strings.elements[first_i];
            std::string_view second = strings.elements[second_i];

            int diff_count = 0;

            for(size_t char_i = 0; char_i < first.size(); ++char_i)
            {
                if(first[char_i] != second[char_i])
                {
                    ++diff_count;
                    if(diff_count > 1)
                        continue;
                }
            }

            if(diff_count == 1)
            {
                correct_a = first;
                correct_b = second;

                //hack to break out of loops
                first_i = strings.size;
                second_i = strings.size;
            }
        }
    }

    cexp::array<char, 40> result;

    for(size_t i = 0; i < correct_a.size(); ++i)
    {
        char c = correct_a[i];

        if(c == correct_b[i])
            push_back(result, c);
    }

    push_back(result, '\0'); //terminate our string

    return result;
}

template <size_t capacity>
constexpr auto calculate_diff_string(std::string_view sv)
{
    auto strings = cexp::parse_string_list<capacity>(sv);
    
    return calculate_diff_string<capacity>(strings);
}

constexpr size_t capacity = 270;
constexpr auto checksum = calculate_diff_string<capacity>(input);

auto answer()
{
    return checksum;
}

int main(){}
