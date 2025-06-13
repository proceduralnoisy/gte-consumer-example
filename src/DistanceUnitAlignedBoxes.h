#pragma once

namespace SimpleGeometry
{

struct Vector3 
{
    double x = 0.0;
    double y = 0.0;
    double z = 0.0;
};

double DistanceUnitAlignedBoxes(const Vector3& center1, const Vector3& center2);

}