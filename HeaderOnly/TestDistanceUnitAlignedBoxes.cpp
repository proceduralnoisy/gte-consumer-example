#include "DistanceUnitAlignedBoxes.h"
#include <gtest/gtest.h>

namespace SimpleGeometry {

TEST(DistanceUnitAlignedBoxesTest, ComputesCorrectDistance) 
{
    Vector3 center1{0.0, 0.0, 0.0};
    Vector3 center2{2.0, 0.0, 0.0};
    double distance = DistanceUnitAlignedBoxes(center1, center2);
    EXPECT_DOUBLE_EQ(distance, 1.0);
}

} // namespace SimpleGeometry
