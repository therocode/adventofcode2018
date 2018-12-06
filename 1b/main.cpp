#include <string_view>
#include <common/parse_int.hpp>
#include "input.hpp"

template <size_t capacity>
constexpr int find_first_recurrence(const cexp::array<int, capacity>& numbers)
{
    std::array<bool, capacity> occurrences {};

    auto has_occurred = [&occurrences] (int number)
    {
        return occurrences[number + static_cast<int>(capacity / 2)];
    };

    auto set_occurred = [&occurrences] (int number)
    {
        occurrences[number + static_cast<int>(capacity / 2)] = true;
    };

    int current_num = 0;
    size_t current_index = 0;

    while(true)
    {
        bool occurred = has_occurred(current_num);

        if(occurred)
        {
            return current_num;
        }
        else
            set_occurred(current_num);

        current_num += at(numbers, current_index);

        ++current_index;
        if(current_index == numbers.size)
            current_index = 0;
    }

    return 0;
}

template <size_t capacity>
constexpr int find_first_recurrence_from_string(std::string_view sv)
{
    auto ints = cexp::parse_int_list<capacity>(sv);
    
    return find_first_recurrence(ints);
}

constexpr size_t capacity = 233010;
constexpr int first_recurrence = find_first_recurrence_from_string<capacity>(input);

int answer()
{
    return first_recurrence;
}

int main(){}
