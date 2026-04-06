#ifndef VEC3_H
#define VEC3_H

#include <stdexcept>

class Vec3 {
private:
    double x;
    double y;
    double z;

public:
    Vec3();
    Vec3(double vecX, double vecY, double vecZ);

    double dot(const Vec3& other) const;
    Vec3 cross(const Vec3& other) const;
    double norm() const;
    Vec3 normalize() const;

    Vec3 operator+(const Vec3& other) const;
    Vec3 operator-(const Vec3& other) const;
    Vec3 operator*(double scalar) const;

    double getX() const;
    double getY() const;
    double getZ() const;

    void setX(double newX);
    void setY(double newY);
    void setZ(double newZ);
};

Vec3 operator*(double s, const Vec3& v);

#endif