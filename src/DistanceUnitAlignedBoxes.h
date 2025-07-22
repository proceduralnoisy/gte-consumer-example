#pragma once

namespace SimpleGeometry
{

// Toy struct representing a 3D vector
struct Vector3 
{
    double x = 0.0;
    double y = 0.0;
    double z = 0.0;
};

// Toy function returning the distance between two axis-aligned unit-sized bounding boxes centered at the given points
double DistanceUnitAlignedBoxes(const Vector3& center1, const Vector3& center2);

}