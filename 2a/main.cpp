#include <string_view>
#include <common/parse_int.hpp>
#include <common/parse_string_list.hpp>
#include "input.hpp"

constexpr size_t letter_amount = 26;

template <size_t capacity>
constexpr int calculate_checksum(const cexp::array<std::string_view, capacity>& strings)
{
    struct LetterInfo
    {
        bool has_twoer;
        bool has_threer;
    };

    std::array<LetterInfo, capacity> letter_infos{};

    for(size_t i = 0; i < strings.size; ++i)
    {
        std::array<int, letter_amount> letter_counts{};

        LetterInfo& info = letter_infos[i];

        for(char c : strings.elements[i])
        {
            size_t letter_index = static_cast<size_t>(c - 'a');
            ++letter_counts[letter_index];
        }
        for(int count : letter_counts)
        {
            if(count == 2)
                info.has_twoer = true;
            else if(count == 3)
                info.has_threer = true;
        }
    }

    int total_twoers = 0;
    int total_threers = 0;

    for(LetterInfo info : letter_infos)
    {
        total_twoers += info.has_twoer ? 1 : 0;
        total_threers += info.has_threer ? 1 : 0;
    }

    return total_twoers * total_threers;
}

template <size_t capacity>
constexpr int calculate_checksum(std::string_view sv)
{
    auto strings = cexp::parse_string_list<capacity>(sv);
    
    return calculate_checksum(strings);
}

constexpr size_t capacity = 270;
constexpr int checksum = calculate_checksum<capacity>(input);

int answer()
{
    return checksum;
}

int main(){}
