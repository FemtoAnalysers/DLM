
#ifndef CATSCONSTANTS_H
#define CATSCONSTANTS_H

#include <complex>

#include <limits>

// Very small value (approx 2e-16) used to avoid divisions by zero
const double EPSILON = std::numeric_limits<double>::epsilon();

const double Pi(3.141592653589793);
    const double HalfPi(1.570796326794897);
    const double TwoPi(6.283185307179586);

// fine-structure constant (==e^2 in Gaussian units)
const double AlphaFS(0.0072973525664);
const double RevSqrt2(0.7071067811865475);
const std::complex<double> i(0, 1);
const double EulerConst = 0.57721566490153;
// convert fm into natural units (1/MeV)
const double FmToNu(5.067731237e-3);
const double NuToFm(197.3269602);
const double hbarc(197.3269602);
const double RadToDeg(57.295779513082);
const double DegToRad(0.017453292519943);

#endif
