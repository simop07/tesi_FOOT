// some info are found at
// https://physics.nist.gov/PhysRefData/XrayMassCoef/tab1.html
// https://wiki.jlab.org/ciswiki/images/4/49/EJ-200.pdf
// https://pdg.lbl.gov/2018/AtomicNuclearProperties/HTML/polyvinyltoluene.html

// values of constants are found here
// https://physics.nist.gov/cuu/Constants/index.html

#ifndef CONSTANTS_H
#define CONSTANTS_H

namespace constants {
inline constexpr double Z{0.54141};
inline constexpr double I{64.7};                      // in eV
inline constexpr double rho{1032.};                   // in kg*m^{-3}
inline constexpr double N_a{6.02214076e23};           // in mol^{-1}
inline constexpr double m_e{0.51099895069e6};         // in ev
inline constexpr double epsilon_0{8.8541878188e-12};  // in C^2*N^{-1}*m^{-2}
inline constexpr double q_e{1.602176634e-19};         // in C
inline constexpr double c{299792458.};                // in m/s
inline constexpr double u{0.93149410372};             // in GeV
inline constexpr double M_u{1.00000000105e-3};        // in kg/mol
inline constexpr double k_energy_u_beam{0.200};       // in GeV
inline constexpr double d_SC_TGT{30.};                // in cm
inline constexpr double dx{6e-3};                     // in m
}  // namespace constants

#endif