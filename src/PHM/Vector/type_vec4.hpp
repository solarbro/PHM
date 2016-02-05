/******************************************************************************/
/*!
\filxe  type_vec3.hpp
\author Sagnik Chowdhury
\par    Course: GAM300
\brief  Contains the Photon renderer math library
*/
/******************************************************************************/

#pragma once
#include "type_vec3.hpp"

namespace phm
{
  /*****************************************************************
  *        vec4
  *        - ctor(float*)
  *        - ctor(float)
  *        - ctor(float, float)
  *        - ctor(vec2)
  *        - operator +, +=, -, -=, *, *=
  *        - operator []
  *        - normalize (no return, normalizes internally)
  *****************************************************************/

  template<class T>
  class type_vec<T, 4> : public swizzle::vec4_internal_data<T>
  {
  public:

    /*************************************
    *               CTORS                *
    *************************************/
    type_vec() {}

    template<typename T2>
    type_vec(T2 init) :
      swizzle::vec4_internal_data<T>(
       static_cast<T>(init),
       static_cast<T>(init),
       static_cast<T>(init),
       static_cast<T>(init)){}

    template<typename T2>
    type_vec(T2* init) :
      swizzle::vec4_internal_data<T>(
      static_cast<T>(init[0]), 
      static_cast<T>(init[1]), 
      static_cast<T>(init[2]),
      static_cast<T>(init[3])){}

    template<typename T2, typename T3, typename T4, typename T5>
    type_vec(const T2 &init_x, const T3 &init_y, const T4 &init_z, const T5 &init_w) :
      swizzle::vec4_internal_data<T>(
      static_cast<T>(init_x), 
      static_cast<T>(init_y), 
      static_cast<T>(init_z), 
      static_cast<T>(init_w)){}

    template<typename T2, typename T3, typename T4>
    type_vec(const type_vec<T2,2> &v, T3 f_z, T4 f_w) :
      swizzle::vec4_internal_data<T>(
      static_cast<T>(f_x),
      static_cast<T>(f_y),
      static_cast<T>(f_z),
      static_cast<T>(f_w)){}

    template <typename T2>
    type_vec(const type_vec<T2,3> &v, T2 f) :
      swizzle::vec4_internal_data<T>(
      static_cast<T>(v[0]),
      static_cast<T>(v[1]),
      static_cast<T>(v[2]),
      static_cast<T>(f)){}

    template<typename T2>
    type_vec(const type_vec<T2, 4> &v) :
      swizzle::vec4_internal_data<T>(
      static_cast<T>(v[0]),
      static_cast<T>(v[1]),
      static_cast<T>(v[2]),
      static_cast<T>(v[3])){}

    template<typename T2, unsigned A, unsigned B, unsigned C, unsigned D>
    type_vec(const swizzle::Vec4Proxy<T2, A, B, C, D> &proxy) :
      swizzle::vec4_internal_data<T>(
      static_cast<T>(reinterpret_cast<const T2*>(&proxy)[A]),
      static_cast<T>(reinterpret_cast<const T2*>(&proxy)[B]),
      static_cast<T>(reinterpret_cast<const T2*>(&proxy)[C]),
      static_cast<T>(reinterpret_cast<const T2*>(&proxy)[D])) {}

    /*************************************
    *             OPERATORS              *
    *************************************/
    operator swizzle::conversion_proxy<T, 4>() const
    {
      swizzle::conversion_proxy<T, 4> proxy{ x, y, z, w };
      return proxy;
    }

    template<typename T2>
    type_vec<T, 4>& operator= (const type_vec<T2, 4> &v)
    {
      x = static_cast<T>(v[0]);
      y = static_cast<T>(v[1]);
      z = static_cast<T>(v[2]);
      w = static_cast<T>(v[3]);
      
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

  typedef type_vec<bool, 4> bvec4;
  typedef type_vec<short, 4> svec4;
  typedef type_vec<unsigned short, 4> usvec4;
  typedef type_vec<int, 4> ivec4;
  typedef type_vec<unsigned int, 4> uivec4;
  typedef type_vec<float, 4> vec4;
  typedef type_vec<double, 4> dvec4;
}