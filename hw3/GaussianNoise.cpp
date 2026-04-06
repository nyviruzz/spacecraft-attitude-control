#include "GaussianNoise.h"
#include <cmath>

namespace {
constexpr double kPi = 3.14159265358979323846;
}

GaussianNoise::GaussianNoise(double mean, double stddev, unsigned int seed)
    : mean(mean), stddev(stddev), rng(seed), dist(0.0, 1.0) {}

double GaussianNoise::sample() {
    double u1 = dist(rng);
    double u2 = dist(rng);
    if (u1 < 1e-12) {
        u1 = 1e-12;
    }

    double z = std::sqrt(-2.0 * std::log(u1)) * std::cos(2.0 * kPi * u2);
    return mean + stddev * z;
}

Vec3 GaussianNoise::sampleVec3() {
    return Vec3(sample(), sample(), sample());
}

void GaussianNoise::setSeed(unsigned int seed) {
    rng.seed(seed);
}