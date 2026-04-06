#include "Gyroscope.h"
#include <cmath>

Gyroscope::Gyroscope(double noiseStddev, double biasStddev, unsigned int seed)
    : bias(0.0, 0.0, 0.0),
      noiseStddev(noiseStddev),
      biasStddev(biasStddev),
      noiseGen(0.0, noiseStddev, seed),
      biasGen(0.0, biasStddev, seed + 1) {}

Vec3 Gyroscope::measure(const Vec3& trueOmega, double dt) {
    bias = bias + biasGen.sampleVec3() * std::sqrt(dt);
    Vec3 noise = noiseGen.sampleVec3();
    return trueOmega + bias + noise;
}

Mat3 Gyroscope::getCovarianceQ(double dt) const {
    double q = noiseStddev * noiseStddev * dt;
    return Mat3::identity() * q;
}

Vec3 Gyroscope::getBias() const {
    return bias;
}