/******************************************************************************/
/*!
\filxe  phm.hpp
\author Sagnik Chowdhury
\brief  Contains the Photon renderer math library
*/
/******************************************************************************/

#include <type_traits>

namespace phm
{
  template<typename T>
  T abs(T x)
  {
    return x < static_cast<T>(0.0) ? -x : x;
  }

  template<typename T>
  T pow(T x, int power)
  {
    assert(x != static_cast<T>(0.0) && power != 0);

    if (x == static_cast<T>(0.0))
      return static_cast<T>(0.0);

    T product = static_cast<T>(1.0);
    int last = abs(power);
    for (int i = 0; i < last; ++i)
      product *= x;
    return power > 1 ? product : static_cast<T>(1.0) / product;
  }

  template<typename T>
  typename std::enable_if_t<std::is_integral<T>::value, T> factorial(T x)
  {
    return (x == static_cast<T>(1.0) || x == static_cast<T>(0.0)) ? 
      static_cast<T>(1.0) : factorial(x - static_cast<T>(1)) * x;
  }

  template<typename T, unsigned iterations = 896>
  T ln(T x)
  {
    double x_minus_1_over_x = (x - 1) / x;
    double power_accum = 1.0;
    double sum = static_cast<T>(0.0);
    for (unsigned i = 1; i <= iterations; ++i)
    {
      power_accum *= x_minus_1_over_x;
      sum += (static_cast<T>(1.0) / static_cast<T>(i)) * power_accum;
    }
    return static_cast<T>(sum);
  }

  template<typename T1, typename T2>
  std::common_type_t<T1, T2> log(T1 base, T2 x)
  {
    T2 lnx = ln(x);
    T1 lnbase = ln(static_cast<T1>(base));
    return lnx / lnbase;
  }

  template<typename T, unsigned iterations = 128>
  T exp(T x)
  {
    T accumulator = static_cast<T>(1.0);
    T sum = static_cast<T>(0.0);

    for (unsigned i = 1; i <= iterations; ++i)
    {
      sum += accumulator;
      accumulator *= x / static_cast<T>(i);
    }
    return sum;
  }
  
  template<typename T>
  T pow(T x, T n)
  {
    return exp(n * ln(x));
  }

  //trig
  template<typename T, unsigned iterations = 256>
  T cos(T x)
  {
    double accumulator = static_cast<double>(1.0);
    double sum = static_cast<T>(1.0);
    const double xSq = x * x;

    for (unsigned i = 2; i < iterations; i += 2)
    {
      accumulator *= -xSq / (static_cast<double>(i - 1) * static_cast<double>(i));
      sum += accumulator;
    }

    return static_cast<T>(sum);
  }

  template<typename T, unsigned iterations = 256>
  T sin(T x)
  {
    double accumulator = static_cast<double>(x);
    double sum = static_cast<T>(x);
    const double xSq = x * x;

    for (unsigned i = 3; i < iterations; i += 2)
    {
      accumulator *= -xSq / (static_cast<double>(i - 1) * static_cast<double>(i));
      sum += accumulator;
    }

    return static_cast<T>(sum);
  }

 /* template<typename T, unsigned iterations = 256>
  T tan(T x)
  {

  }*/
}