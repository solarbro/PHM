/******************************************************************************/
/*!
\filxe  Constants.hpp
\author Sagnik Chowdhury
\brief  Interface for getting various commonly used math constants 
*/
/******************************************************************************/
#include <limits>

namespace phm
{
  template<typename T>
  struct Constant
  {
    //Pi
    const static T pi;
    const static T half_pi;
    const static T two_pi;
    const static T radians_per_degree;
    const static T degrees_per_radian;
    //Euler's number
    const static T e;
    //Golden ratio
    const static T golden_ratio;
    //epsilon
    const static T epsilon;
    const static T inf;
  };
#pragma region INITIALIZATION
  template<typename T> const T Constant<T>::pi = static_cast<T>(3.14159265358979323846264338327950288);
  template<typename T> const T Constant<T>::half_pi = static_cast<T>(1.57079632679);
  template<typename T> const T Constant<T>::two_pi = static_cast<T>(6.28318530718);
  template<typename T> const T Constant<T>::radians_per_degree = static_cast<T>(0.0174532925);
  template<typename T> const T Constant<T>::degrees_per_radian = static_cast<T>(57.2957795);
  template<typename T> const T Constant<T>::e = static_cast<T>(2.71828182845904523536028747135266249);
  template<typename T> const T Constant<T>::golden_ratio = static_cast<T>(1.61803398874989484820458683436563811);
  template<typename T> const T Constant<T>::epsilon = std::numeric_limits<T>::epsilon();
  template<typename T> const T Constant<T>::inf = std::numeric_limits<T>::infinity();
#pragma endregion INITIALIZATION
}