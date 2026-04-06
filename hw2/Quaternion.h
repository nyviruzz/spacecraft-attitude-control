#ifndef QUATERNION_H
#define QUATERNION_H

#include "../hw1/Mat3.h"

class Quaternion {
private:
    double w;
    double x;
    double y;
    double z;

public:
    Quaternion();
    Quaternion(double w, double x, double y, double z);

    static Quaternion fromAxisAngle(const Vec3& axis, double angleRad);
    static Quaternion fromRotationMatrix(const Mat3& R);

    Quaternion operator*(const Quaternion& other) const;
    Quaternion conjugate() const;
    double norm() const;
    Quaternion normalize() const;
    Quaternion inverse() const;
    Vec3 rotate(const Vec3& v) const;

    double getX() const;
    double getY() const;
    double getZ() const;
};

#endif