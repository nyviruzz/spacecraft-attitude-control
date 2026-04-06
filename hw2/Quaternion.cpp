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

Quaternion Quaternion::slerp(const Quaternion& q1, const Quaternion& q2, double t) {
    if (t < 0.0 || t > 1.0) {
        throw std::out_of_range("Interpolation parameter t must be in [0, 1]");
    }

    Quaternion qa = q1.normalize();
    Quaternion qb = q2.normalize();

    double dot = qa.w * qb.w + qa.x * qb.x + qa.y * qb.y + qa.z * qb.z;

    if (dot < 0.0) {
        qb = Quaternion(-qb.w, -qb.x, -qb.y, -qb.z);
        dot = -dot;
    }

    if (dot > 0.9995) {
        Quaternion result(
            qa.w + t * (qb.w - qa.w),
            qa.x + t * (qb.x - qa.x),
            qa.y + t * (qb.y - qa.y),
            qa.z + t * (qb.z - qa.z));
        return result.normalize();
    }

    dot = std::fmax(-1.0, std::fmin(1.0, dot));
    double theta0 = std::acos(dot);
    double theta = theta0 * t;

    double sinTheta0 = std::sin(theta0);
    double sinTheta = std::sin(theta);

    double s0 = std::cos(theta) - dot * sinTheta / sinTheta0;
    double s1 = sinTheta / sinTheta0;

    return Quaternion(
               s0 * qa.w + s1 * qb.w,
               s0 * qa.x + s1 * qb.x,
               s0 * qa.y + s1 * qb.y,
               s0 * qa.z + s1 * qb.z)
        .normalize();
}

Mat3 Quaternion::toRotationMatrix() const {
    Quaternion q = normalize();

    double xx = q.x * q.x;
    double yy = q.y * q.y;
    double zz = q.z * q.z;
    double xy = q.x * q.y;
    double xz = q.x * q.z;
    double yz = q.y * q.z;
    double wx = q.w * q.x;
    double wy = q.w * q.y;
    double wz = q.w * q.z;

    double m[3][3] = {
        {1.0 - 2.0 * (yy + zz), 2.0 * (xy - wz), 2.0 * (xz + wy)},
        {2.0 * (xy + wz), 1.0 - 2.0 * (xx + zz), 2.0 * (yz - wx)},
        {2.0 * (xz - wy), 2.0 * (yz + wx), 1.0 - 2.0 * (xx + yy)}};

    return Mat3(m);
}

double Quaternion::getW() const {
    return w;
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