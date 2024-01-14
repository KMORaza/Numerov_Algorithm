#ifndef POTENTIAL_H
#define POTENTIAL_H
#include <functional>
class Potential {
private:
    std::function<double(double)> potentialFunction;
public:
    Potential(const std::function<double(double)>& function);
    double operator()(double x) const;
};
#endif
