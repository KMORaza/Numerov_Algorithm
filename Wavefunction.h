#ifndef WAVEFUNCTION_H
#define WAVEFUNCTION_H
#include <vector>
#include "Potential.h"
class Wavefunction {
private:
    std::vector<double> psi;
    double h;
    double mass;
public:
    Wavefunction(double h, double mass);
    void initialize(double x0, double dx, int numPoints);
    void evolve(const Potential& potential, double energy);
    double operator()(int i) const;
};
#endif
