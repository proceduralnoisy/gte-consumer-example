#include "DistanceUnitAlignedBoxes.h"

#ifdef PN_USE_GTE
#include <Mathematics/AlignedBox.h>
#include <Mathematics/DistAlignedBoxAlignedBox.h>
#else
#include <stdexcept>
#endif

namespace SimpleGeometry
{

double DistanceUnitAlignedBoxes(const Vector3& center1, const Vector3& center2) 
{
#ifdef PN_USE_GTE
    const auto gteCenter1 = gte::Vector<3, double>{center1.x, center1.y, center1.z};
    const auto gteCenter2 = gte::Vector<3, double>{center2.x, center2.y, center2.z};
    const auto halfUnit = gte::Vector<3, double>{0.5, 0.5, 0.5};

    gte::AlignedBox3<double> box1(gteCenter1 - halfUnit, gteCenter1 + halfUnit);
    gte::AlignedBox3<double> box2(gteCenter2 - halfUnit, gteCenter2 + halfUnit);

    gte::DCPQuery<double, gte::AlignedBox3<double>, gte::AlignedBox3<double>> query;
    return query(box1, box2).distance;
#else
    throw std::runtime_error("GTE is not enabled. Please define PN_USE_GTE to use GTE functionality.");
#endif
}

}