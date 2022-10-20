#pragma once

#include <type_traits>

struct IndexGroup {
    unsigned index0 = 0;
    unsigned index1 = 0;
    unsigned index2 = 0;

    constexpr void advance(unsigned value) {
        index0 += value;
        index1 += value;
        index2 += value;
    }
};

static_assert(std::is_standard_layout_v<IndexGroup>);
