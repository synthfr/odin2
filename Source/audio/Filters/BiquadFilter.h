#pragma once

class BiquadFilter {
public:
  BiquadFilter();
  ~BiquadFilter();

  inline void reset() { m_z1 = m_z2 = 0.; }

  void setFilterCoefficients(double p_a1, double p_a2, double p_b0, double p_b1,
                             double p_b2);

  virtual double doFilter(double p_input);

protected:
  // direkt form coefficients. note that in the normalized form, a0 is 1
  double m_a1;
  double m_a2;
  double m_b0;
  double m_b1;
  double m_b2;

  // buffer elements
  double m_z1 = 0.;
  double m_z2 = 0.;
};
