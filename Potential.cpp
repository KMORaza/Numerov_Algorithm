#include "Potential.h"
Potential::Potential(const std::function<double(double)>& function) : potentialFunction(function) {}
double Potential::operator()(double x) const {
    return potentialFunction(x);
}
