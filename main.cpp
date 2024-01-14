// Created: October 2022
#include <iostream>
#include "Wavefunction.h"
#include "Potential.h"
int main() {
    double h = 0.01;
    double mass = 1.0;
    int numPoints = 1000;
    double x0 = -5.0;
    double dx = 0.01;
    double energy = 5.0;
    Potential potential([](double x) { return 0.5 * x * x; });
    Wavefunction wavefunction(h, mass);
    wavefunction.initialize(x0, dx, numPoints);
    wavefunction.evolve(potential, energy);
    std::cout << "Numerical solution using Numerov algorithm:\n";
    for (int i = 0; i < numPoints; ++i) {
        double x = x0 + i * h;
        std::cout << "x = " << x << ", psi(x) = " << wavefunction(i) << "\n";
    }
    return 0;
}
