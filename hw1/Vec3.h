#ifndef VEC3_H
#define VEC3_H

#include <iostream>
#include <cmath>
#include <stdexcept>

using namespace std;

class Vec3 {
private:
    double x;
    double y;
    double z;

public:
    Vec3() {
        x = 0.0;
        y = 0.0;
        z = 0.0;
    }

    Vec3(double vecX, double vecY, double vecZ) {
        x = vecX;
        y = vecY;
        z = vecZ;
    }

    double dot(const Vec3& other) const {
        return x * other.x + y * other.y + z * other.z;
    }

    Vec3 cross(const Vec3& other) const {
        double newX = (y * other.z) - (z * other.y);
        double newY = (z * other.x) - (x * other.z);
        double newZ = (x * other.y) - (y * other.x);
        return Vec3(newX, newY, newZ);
    }

    double norm() const {
        return sqrt(x * x + y * y + z * z);
    }

    Vec3 normalize() const {
        double magnitude = norm();

        if (magnitude < 1e-12) {
            throw runtime_error("Cannot normalize zero vector");
        }

        double newX = x / magnitude;
        double newY = y / magnitude;
        double newZ = z / magnitude;

        return Vec3(newX, newY, newZ);
    }

    Vec3 operator+(const Vec3& other) const {
        return Vec3(x + other.x, y + other.y, z + other.z);
    }

    Vec3 operator-(const Vec3& other) const {
        return Vec3(x - other.x, y - other.y, z - other.z);
    }

    Vec3 operator*(double scalar) const {
        return Vec3(x * scalar, y * scalar, z * scalar);
    }

    double getX() const {
        return x;
    }

    double getY() const {
        return y;
    }

    double getZ() const {
        return z;
    }

    void setX(double newX) {
        x = newX;
    }

    void setY(double newY) {
        y = newY;
    }

    void setZ(double newZ) {
        z = newZ;
    }
};

Vec3 operator*(double s, const Vec3& v) {
    return Vec3(v.getX() * s, v.getY() * s, v.getZ() * s);
}

#endif