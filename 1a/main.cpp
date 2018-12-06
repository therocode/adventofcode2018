#include <string_view>
#include <common/parse_int.hpp>
#include "input.hpp"

template <size_t capacity>
constexpr int sum(std::string_view sv)
{
    auto ints = cexp::parse_int_list<capacity>(sv);
    int sum = 0;
    for(int i : ints)
        sum += i;
    
    return sum;
}

constexpr size_t input_sum_capacity = std::string_view(input).size();
constexpr int input_sum = sum<input_sum_capacity>(input);

int answer()
{
    return input_sum;
}

int main(){}
