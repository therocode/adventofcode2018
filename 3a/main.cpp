#include <string_view>
#include <common/parse_rectangles.hpp>
#include "input.hpp"

template <size_t capacity>
constexpr int calculate_overlap(const cexp::array<cexp::rectangle, capacity>& rectangles)
{
    struct coord
    {
        int x;
        int y;
    };

    //find max dimensions
    coord max_coord = {};
    for(cexp::rectangle r : rectangles)
    {
        coord this_max = {r.x + r.width - 1, r.y + r.height - 1};

        max_coord.x = std::max(this_max.x, max_coord.x);
        max_coord.y = std::max(this_max.y, max_coord.y);
    }

    auto to_index = [max_coord] (coord c)
    {
        return static_cast<size_t>(c.x + c.y * max_coord.x);
    };

    cexp::array<int, capacity> overlaps{};
    resize(overlaps, max_coord.x * max_coord.y);

    //count overlaps
    for(cexp::rectangle r : rectangles)
    {
        for(int y = r.y; y < r.y + r.height; ++y)
        {
            for(int x = r.x; x < r.x + r.width; ++x)
            {
                ++overlaps[to_index({x, y})];
            }
        }
    }

    int overlap_count = 0;

    for(int individual_count : overlaps)
    {
        if(individual_count > 1)
            ++overlap_count;
    }

    return overlap_count;
}

template <size_t capacity>
constexpr int calculate_overlap(std::string_view sv)
{
    auto rectangles = cexp::parse_rectangles<capacity>(sv);
    
    return calculate_overlap(rectangles);
}

constexpr size_t capacity = 4948;
//constexpr int overlap = calculate_overlap<capacity>(input);

constexpr auto rects = cexp::parse_rectangles<capacity>(input);

static_assert(rects[0].x == 338);
static_assert(rects[0].y == 764);
static_assert(rects[0].width == 20);
static_assert(rects[0].height == 24);

static_assert(rects[1].x == 80);
static_assert(rects[1].y == 667);
static_assert(rects[1].width == 12);
static_assert(rects[1].height == 26);

static_assert(rects[9].x == 397);
static_assert(rects[9].y == 589);
static_assert(rects[9].width == 17);
static_assert(rects[9].height == 22);

static_assert(rects[99].x == 215);
static_assert(rects[99].y == 120);
static_assert(rects[99].width == 27);
static_assert(rects[99].height == 27);

static_assert(rects[299].x == 495);
static_assert(rects[299].y == 553);
static_assert(rects[299].width == 19);
static_assert(rects[299].height == 24);

static_assert(rects[300].x == 789);
static_assert(rects[300].y == 754);
static_assert(rects[300].width == 12);
static_assert(rects[300].height == 22);

static_assert(rects[301].x == 501);
static_assert(rects[301].y == 798);
static_assert(rects[301].width == 28);
static_assert(rects[301].height == 12);

static_assert(rects[302].x == 949);
static_assert(rects[302].y == 746);
static_assert(rects[302].width == 21);
static_assert(rects[302].height == 17);

static_assert(rects[303].x == 204);
static_assert(rects[303].y == 462);
static_assert(rects[303].width == 24);
static_assert(rects[303].height == 14);

static_assert(rects[304].x == 543);
static_assert(rects[304].y == 30);
static_assert(rects[304].width == 21);
static_assert(rects[304].height == 25);

static_assert(rects[305].x == 135);
static_assert(rects[305].y == 652);
static_assert(rects[305].width == 21);
static_assert(rects[305].height == 22);

static_assert(rects[306].x == 314);
static_assert(rects[306].y == 157);
static_assert(rects[306].width == 26);
static_assert(rects[306].height == 15);

static_assert(rects[307].x == 481);
static_assert(rects[307].y == 970);
static_assert(rects[307].width == 12);
static_assert(rects[307].height == 19);

static_assert(rects[308].x == 593);
static_assert(rects[308].y == 972);
static_assert(rects[308].width == 6);
static_assert(rects[308].height == 6);

static_assert(rects[309].x == 597); //failed when copying earlier safe numbers into it
static_assert(rects[309].y == 71);
static_assert(rects[309].width == 22);
static_assert(rects[309].height == 24);

static_assert(rects[310].x == 373); //bad one
static_assert(rects[310].y == 400);
static_assert(rects[310].width == 13);
static_assert(rects[310].height == 19);

static_assert(rects[311].x == 113);
static_assert(rects[311].y == 482);
static_assert(rects[311].width == 23);
static_assert(rects[311].height == 16);

static_assert(rects[312].x == 720);
static_assert(rects[312].y == 925);
static_assert(rects[312].width == 17);
static_assert(rects[312].height == 13);

static_assert(rects[313].x == 967);
static_assert(rects[313].y == 659);
static_assert(rects[313].width == 16);
static_assert(rects[313].height == 23);

static_assert(rects[314].x == 352);
static_assert(rects[314].y == 66);
static_assert(rects[314].width == 26);
static_assert(rects[314].height == 20);


static_assert(rects[315].x == 289);
static_assert(rects[315].y == 375);
static_assert(rects[315].width == 14);
static_assert(rects[315].height == 13);

static_assert(rects[333].x == 600);
static_assert(rects[333].y == 468);
static_assert(rects[333].width == 15);
static_assert(rects[333].height == 22);

static_assert(rects[374].x == 775);
static_assert(rects[374].y == 386);
static_assert(rects[374].width == 21);
static_assert(rects[374].height == 26);

static_assert(rects[449].x == 387);
static_assert(rects[449].y == 514);
static_assert(rects[449].width == 13);
static_assert(rects[449].height == 12);

static_assert(rects[599].x == 191);
static_assert(rects[599].y == 212);
static_assert(rects[599].width == 10);
static_assert(rects[599].height == 23);

static_assert(rects[799].x == 581);
static_assert(rects[799].y == 310);
static_assert(rects[799].width == 21);
static_assert(rects[799].height == 13);

static_assert(rects[1236].x == 245);
static_assert(rects[1236].y == 671);
static_assert(rects[1236].width == 18);
static_assert(rects[1236].height == 23);

//int answer()
//{
//    return overlap;
//}

int main(){}
