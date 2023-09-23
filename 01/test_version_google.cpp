#include <gtest/gtest.h>

#include "lib.h"

TEST(
        VersionTest,
        given_version__when_get_version__then_correct_version_returned
) {
    ASSERT_TRUE(version() > 0);
}