#include "Vec3.h"
#include <cmath>

Vec3::Vec3() : x(0.0), y(0.0), z(0.0) {}

Vec3::Vec3(double vecX, double vecY, double vecZ) : x(vecX), y(vecY), z(vecZ) {}

double Vec3::dot(const Vec3& other) const {
    return x * other.x + y * other.y + z * other.z;
}

Vec3 Vec3::cross(const Vec3& other) const {
    double newX = (y * other.z) - (z * other.y);
    double newY = (z * other.x) - (x * other.z);
    double newZ = (x * other.y) - (y * other.x);
    return Vec3(newX, newY, newZ);
}

double Vec3::norm() const {
    return std::sqrt(x * x + y * y + z * z);
}

Vec3 Vec3::normalize() const {
    double magnitude = norm();
    if (magnitude < 1e-12) {
        throw std::runtime_error("Cannot normalize zero vector");
    }
    return Vec3(x / magnitude, y / magnitude, z / magnitude);
}

Vec3 Vec3::operator+(const Vec3& other) const {
    return Vec3(x + other.x, y + other.y, z + other.z);
}

Vec3 Vec3::operator-(const Vec3& other) const {
    return Vec3(x - other.x, y - other.y, z - other.z);
}

Vec3 Vec3::operator*(double scalar) const {
    return Vec3(x * scalar, y * scalar, z * scalar);
}

double Vec3::getX() const {
    return x;
}

double Vec3::getY() const {
    return y;
}

double Vec3::getZ() const {
    return z;
}

void Vec3::setX(double newX) {
    x = newX;
}

void Vec3::setY(double newY) {
    y = newY;
}

void Vec3::setZ(double newZ) {
    z = newZ;
}

Vec3 operator*(double s, const Vec3& v) {
    return Vec3(v.getX() * s, v.getY() * s, v.getZ() * s);
}