#include "Wavefunction.h"
#include <cmath>
Wavefunction::Wavefunction(double h, double mass) : h(h), mass(mass) {}
void Wavefunction::initialize(double x0, double dx, int numPoints) {
    psi.resize(numPoints, 0.0);
    double x = x0;
    for (int i = 0; i < numPoints; ++i) {
        psi[i] = std::exp(-(x - x0) * (x - x0) / (2.0 * dx * dx));
        x += h;
    }
}
void Wavefunction::evolve(const Potential& potential, double energy) {
    double hSquared = h * h;
    double factor = hSquared / (12.0 * mass);
    double factor2 = 5.0 * hSquared / (12.0 * mass);
    for (int i = 2; i < psi.size(); ++i) {
        psi[i] = (2.0 * (1.0 - factor * potential(i * h) - energy) * psi[i - 1] -
                  (1.0 + factor2 * potential(i * h) + energy) * psi[i - 2]) /
                 (1.0 + factor2 * potential((i - 1) * h) + energy);
    }
}
double Wavefunction::operator()(int i) const {
    return psi[i];
}
