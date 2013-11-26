#include "stdafx.h"

#include "gtest/gtest.h"

#include "cpp_range.h"

TEST(•Â‹æŠÔ‚ğì¬‚Å‚«‚é, •’Ê‚Éì¬‚Å‚«‚é) {
	ClosedRange range = ClosedRange(3, 8);
	ASSERT_EQ(3, range.getLowerEndpoint());
	ASSERT_EQ(8, range.getUpperEndpoint());
}