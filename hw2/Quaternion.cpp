#include <iostream>
#include <cmath>
#include <stdexcept>
#include <Vec3.h>
using namespace std;

class Quaternion {
    private:
        double w;
        double x;
        double y;
        double z;
    
    public:
        Quaternion() {
            w = 1;
            x = 0;
            y = 0;
            z = 0;
        }

        Quaternion(double w, double x, double y, double z) {
            w = this->w;
            x = this->x;
            y = this->y;
            z = this->z;
        }

        static Quaternion fromAxisAngle(const Vec3& axis, double angleRad) {
            double half = angleRad * 0.5;
            double s = sin(half);

            // normalize axis (VERY IMPORTANT)
            double mag = sqrt(axis.x * axis.x + axis.y * axis.y + axis.z * axis.z);

            double ux = axis.x / mag;
            double uy = axis.y / mag;
            double uz = axis.z / mag;

            return Quaternion(cos(half), ux * s, uy * s, uz * s);

        }

        Quaternion operator*(const Quaternion& other) const {
            double quartW = w*other.w - x*other.x - y*other.y - z*other.z;
            double quartX = w*other.x + x*other.w + y*other.z - z*other.y;
            double quartY = w*other.y - x*other.z + y*other.w + z*other.x;
            double quartZ = w*other.z + x*other.y - y*other.x + z*other.w;
            return Quaternion(quartW, quartX, quartY, quartZ);
        }

        Quaternion conjugate() const {
            return Quaternion(w, -x, -y, -z);
        }

        double norm() const {
            return sqrt(w*w + x*x + y*y + z*z);
        }

        Quaternion normalize() const {

        }
};