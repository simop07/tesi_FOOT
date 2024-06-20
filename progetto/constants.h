// some info are found at
// https://physics.nist.gov/PhysRefData/XrayMassCoef/tab1.html
// https://wiki.jlab.org/ciswiki/images/4/49/EJ-200.pdf
// https://pdg.lbl.gov/2018/AtomicNuclearProperties/HTML/polyvinyltoluene.html

#ifndef CONSTANTS_H
#define CONSTANTS_H

namespace constants {
inline constexpr double Z{0.54141};
inline constexpr double I{64.7};                      // in eV
inline constexpr double rho{1023.};                   // in kg*m^{-3}
inline constexpr double N_a{6.02214076e23};           // in mol^{-1}
inline constexpr double m_e_kg{9.1093837e-31};        // in kg
inline constexpr double m_e_eV{0.51099895000e6};      // in ev
inline constexpr double epsilon_0{8.8541878128e-12};  // in C^2*N^{-1}*m^{-2}
inline constexpr double q_e{1.60217663e-19};          // in C
inline constexpr double c{299792458.};                // in m/s
inline constexpr double u{0.9315};                    // in GeV
inline constexpr double U{1.660538921e-27};           // in kg
inline constexpr double k_energy_u_beam{0.200};       // in GeV
inline constexpr double d_SC_TGT{30.};                // in cm
inline constexpr double dx{6e-3};                     // in m
inline constexpr double number_mass_beam{12.};
}  // namespace constants

#endif