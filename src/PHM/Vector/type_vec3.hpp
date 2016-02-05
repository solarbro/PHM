/******************************************************************************/
/*!
\filxe  type_vec3.hpp
\author Sagnik Chowdhury
\par    Course: GAM300
\brief  Contains the Photon renderer math library
*/
/******************************************************************************/

#pragma once
#include "type_vec2.hpp"

namespace phm
{
  /*****************************************************************
  *        vec3
  *        - ctor(float*)
  *        - ctor(float)
  *        - ctor(float, float)
  *        - ctor(vec2)
  *        - operator +, +=, -, -=, *, *=
  *        - operator []
  *        - normalize (no return, normalizes internally)
  *****************************************************************/

  template<class T>
  class type_vec<T, 3> : public swizzle::vec3_internal_data<T>
  {
  public:

    /*************************************
    *               CTORS                *
    *************************************/
    type_vec() {}

    template<typename T2>
    type_vec(T2 init) :
      swizzle::vec3_internal_data<T>(
      static_cast<T>(init), 
      static_cast<T>(init), 
      static_cast<T>(init)){}

    template<typename T2>
    type_vec(T2* init) :
      swizzle::vec3_internal_data<T>(
      static_cast<T>(init[0]),
      static_cast<T>(init[1]),
      static_cast<T>(init[2])){}

    template<typename T2, typename T3, typename T4>
    type_vec(const T2 &init_x, const T3 &init_y, const T4 &init_z) :
      swizzle::vec3_internal_data<T>(
      static_cast<T>(init_x),
      static_cast<T>(init_y),
      static_cast<T>(init_z)){}

    template<typename T2, typename T3>
    type_vec(const type_vec<T2, 2> &v, T3 f) :
      swizzle::vec3_internal_data<T>(
      static_cast<T>(v[0]), 
      static_cast<T>(v[1]), 
      static_cast<T>(f)){}

    template<typename T2>
    type_vec(const type_vec<T2,3> &v) :
      swizzle::vec3_internal_data<T>(
      static_cast<T>(v[0]), 
      static_cast<T>(v[1]), 
      static_cast<T>(v[2])){}

    template<typename T2, unsigned A, unsigned B, unsigned C>
    type_vec(const swizzle::Vec3Proxy<T2, A, B, C> &proxy) :
      swizzle::vec3_internal_data<T>(
      static_cast<T>(reinterpret_cast<const T2*>(&proxy)[A]),
      static_cast<T>(reinterpret_cast<const T2*>(&proxy)[B]),
      static_cast<T>(reinterpret_cast<const T2*>(&proxy)[C])) {}

    /*************************************
    *             OPERATORS              *
    *************************************/
    CONVERSION_PROXY

    template<typename T2>
    type_vec<T, 3>& operator= (const type_vec<T2, 3> &v)
    {
      x = static_cast<T>(v[0]);
      y = static_cast<T>(v[1]);
      z = static_cast<T>(v[2]);
      return *this;
    }

    T operator[] (unsigned i) const
    {
      return *(&x + i);
    }

    T& operator[] (unsigned i)
    {
      return *(&x + i);
    }

  };


  typedef type_vec<bool, 3>           bvec3;
  typedef type_vec<short, 3>          svec3;
  typedef type_vec<unsigned short, 3> usvec3;
  typedef type_vec<int, 3>            ivec3;
  typedef type_vec<unsigned int, 3>   uivec3;
  typedef type_vec<float, 3>          vec3;
  typedef type_vec<double, 3>         dvec3;

  /*      =============================================
  *                       Functions
  *       =============================================
  *
  *       cross(v1, v2)
  *       rotateVector(vec, axis, angle)
  */

  template<typename T1, typename T2>
  type_vec<ptype<T1, T2>, 3> cross(const type_vec<T1, 3> &v1, const type_vec<T2, 3> &v2)
  {
    return type_vec<ptype<T1, T2>, 3>(
      static_cast<ptype<T1, T2>>(v1[1] * v2[2] - v1[2] * v2[1]),
      static_cast<ptype<T1, T2>>(v1[2] * v2[0] - v1[0] * v2[2]),
      static_cast<ptype<T1, T2>>(v1[0] * v2[1] - v1[1] * v2[0])
      );
  }

  template<typename T1, typename T2, typename T3>
  type_vec<ptype<T1, T2>, 3> rotateVector(const type_vec<T1, 3> &v, const type_vec<T2, 3> &axis, T3 angle)
  {
    type_vec<T2, 3> n = normalize(axis);
    T3 cs = cos(angle);
    T3 sn = sin(angle);
    type_vec<ptype<T1, T2, T3>, 3> res = v * cs + cross(n, v) * sn + dot(n, v) * (1.0 - cs) * n;
    return res;
  }
  
}