#include "Quaternion.h"
#include <cmath>
#include <stdexcept>

Quaternion::Quaternion() : w(1.0), x(0.0), y(0.0), z(0.0) {}

Quaternion::Quaternion(double w, double x, double y, double z)
    : w(w), x(x), y(y), z(z) {}

Quaternion Quaternion::fromAxisAngle(const Vec3& axis, double angleRad) {
    double half = angleRad * 0.5;
    double s = std::sin(half);

    double mag = axis.norm();
    if (mag < 1e-12) {
        throw std::runtime_error("Axis must be non-zero");
    }

    double ux = axis.getX() / mag;
    double uy = axis.getY() / mag;
    double uz = axis.getZ() / mag;

    return Quaternion(std::cos(half), ux * s, uy * s, uz * s);
}

Quaternion Quaternion::operator*(const Quaternion& other) const {
    double quartW = w * other.w - x * other.x - y * other.y - z * other.z;
    double quartX = w * other.x + x * other.w + y * other.z - z * other.y;
    double quartY = w * other.y - x * other.z + y * other.w + z * other.x;
    double quartZ = w * other.z + x * other.y - y * other.x + z * other.w;
    return Quaternion(quartW, quartX, quartY, quartZ);
}

Quaternion Quaternion::conjugate() const {
    return Quaternion(w, -x, -y, -z);
}

double Quaternion::norm() const {
    return std::sqrt(w * w + x * x + y * y + z * z);
}

Quaternion Quaternion::normalize() const {
    double n = norm();
    if (n < 1e-12) {
        throw std::runtime_error("Cannot normalize zero quaternion");
    }
    return Quaternion(w / n, x / n, y / n, z / n);
}

Quaternion Quaternion::inverse() const {
    double n = norm();
    if (n < 1e-12) {
        throw std::runtime_error("Zero quaternion has no inverse");
    }

    Quaternion conj = conjugate();
    double n2 = n * n;

    return Quaternion(conj.w / n2, conj.x / n2, conj.y / n2, conj.z / n2);
}

Vec3 Quaternion::rotate(const Vec3& v) const {
    Quaternion vq(0.0, v.getX(), v.getY(), v.getZ());
    Quaternion result = (*this) * vq * this->inverse();
    return Vec3(result.getX(), result.getY(), result.getZ());
}

Quaternion Quaternion::fromRotationMatrix(const Mat3& R) {
    double r00 = R.get(0, 0);
    double r11 = R.get(1, 1);
    double r22 = R.get(2, 2);

    double trace = r00 + r11 + r22;

    double w;
    double x;
    double y;
    double z;

    if (trace > 0.0) {
        double s = std::sqrt(trace + 1.0) * 2.0;
        w = 0.25 * s;
        x = (R.get(2, 1) - R.get(1, 2)) / s;
        y = (R.get(0, 2) - R.get(2, 0)) / s;
        z = (R.get(1, 0) - R.get(0, 1)) / s;
    } else if (r00 > r11 && r00 > r22) {
        double s = std::sqrt(1.0 + r00 - r11 - r22) * 2.0;
        w = (R.get(2, 1) - R.get(1, 2)) / s;
        x = 0.25 * s;
        y = (R.get(0, 1) + R.get(1, 0)) / s;
        z = (R.get(0, 2) + R.get(2, 0)) / s;
    } else if (r11 > r22) {
        double s = std::sqrt(1.0 + r11 - r00 - r22) * 2.0;
        w = (R.get(0, 2) - R.get(2, 0)) / s;
        x = (R.get(0, 1) + R.get(1, 0)) / s;
        y = 0.25 * s;
        z = (R.get(1, 2) + R.get(2, 1)) / s;
    } else {
        double s = std::sqrt(1.0 + r22 - r00 - r11) * 2.0;
        w = (R.get(1, 0) - R.get(0, 1)) / s;
        x = (R.get(0, 2) + R.get(2, 0)) / s;
        y = (R.get(1, 2) + R.get(2, 1)) / s;
        z = 0.25 * s;
    }

    return Quaternion(w, x, y, z).normalize();
}

double Quaternion::getX() const {
    return x;
}

double Quaternion::getY() const {
    return y;
}

double Quaternion::getZ() const {
    return z;
}