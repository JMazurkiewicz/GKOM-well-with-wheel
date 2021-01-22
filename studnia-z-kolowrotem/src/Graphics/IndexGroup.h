#pragma once

#include <type_traits>

struct IndexGroup {
	unsigned i0 = 0;
	unsigned i1 = 0;
	unsigned i2 = 0;
};

static_assert(std::is_standard_layout_v<IndexGroup>);
