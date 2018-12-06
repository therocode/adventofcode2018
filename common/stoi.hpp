#pragma once

namespace cexp
{
constexpr bool is_digit(char c)
{
    return c <= '9' && c >= '0';
}

constexpr bool is_space(char c)
{
    return c == ' ' ||
        c == '\f' ||
        c == '\n' ||
        c == '\r' ||
        c == '\t' || 
        c == '\v';
}

struct stoi_result
{
    int result;
    bool error;
    const char* next;

    constexpr operator bool()
    {
        return !error;
    }
};

namespace impl
{
constexpr stoi_result stoi_impl(const char* str, bool first, int value = 0)
{
    char current = *str;
    
    if(is_space(current) && first)
    {
        return stoi_impl(str + 1, first, value);
    }
    if(is_digit(*str))
    {
        return stoi_impl(str + 1, false, (*str - '0') + value * 10);
    }
    else if(*str == '+' && first)
    {
        return stoi_impl(str + 1, first, value);
    }
    else if(*str == '-' && first)
    {
        auto res = stoi_impl(str + 1, first, value);
        res.result *= -1;
        return res;
    }
    else if(!first) //reached a non-valid character and we have parsed stuff previously, then we end parsing and return
    {
        return {value, false, str};
    }
    else //reached a non-valid character and we have not parsed anything. error in input
    {
        return {0, true, str};
    }
}
}

constexpr stoi_result stoi(const char* str) {
    return impl::stoi_impl(str, true);
}

static_assert(!stoi(""));
static_assert(stoi("0"));
static_assert(stoi("\n\n+30"));
static_assert(stoi("   -6+2"));
static_assert(!stoi(" -s6"));
static_assert(!stoi(" \n+hhj2344"));
static_assert(!stoi("ssdf"));
static_assert(stoi(" \t0").result == 0);
static_assert(stoi("\n\n \t102").result == 102);
static_assert(stoi(" -10+23").result == -10);
static_assert(stoi("-0").result == 0);
static_assert(stoi("   +0").result == 0);
static_assert(stoi("+230").result == 230);
}
