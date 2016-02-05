/******************************************************************************/
/*!
\filxe  type_vec2.hpp
\author Sagnik Chowdhury
\par    Course: GAM300
\brief  Contains the Photon renderer math library
*/
/******************************************************************************/

#pragma once
#include "type_vec.hpp"
#include "Swizzle/vector_base_data.hpp"

namespace phm
{
  /*****************************************************************      
  *        vec2
  *        - ctor(float*)
  *        - ctor(float)
  *        - ctor(float, float)
  *        - ctor(vec2)
  *        - operator +, +=, -, -=, *, *=
  *        - operator []
  *        - normalize (no return, normalizes internally)
  *****************************************************************/

  template<class T>
  class type_vec<T, 2> : public swizzle::vec2_internal_data<T> 
  {
  public:

    /*************************************
    *               CTORS                *
    *************************************/
    type_vec() {}

    template<typename T2>
    explicit type_vec(T2 init) :
      swizzle::vec2_internal_data<T>(
      static_cast<T>(init), 
      static_cast<T>(init)){}

    template<typename T2>
    type_vec(T2* init) :
      swizzle::vec2_internal_data<T>(
      static_cast<T>(init[0]), 
      static_cast<T>(init[1])){}

    template<typename T2, typename T3>
    type_vec(const T2 &init_x, const T3 &init_y) :
      swizzle::vec2_internal_data<T>(
      static_cast<T>(init_x), 
      static_cast<T>(init_y)){}

    template<typename T2>
    type_vec(const type_vec<T2, 2> &v) :
      swizzle::vec2_internal_data<T>(
      static_cast<T>(v[0]), 
      static_cast<T>(v[1])) {}

    template<typename T2, unsigned A, unsigned B>
    type_vec(const swizzle::Vec2Proxy<T2, A, B> &proxy) :
      swizzle::vec2_internal_data<T>(
      static_cast<T>(reinterpret_cast<const T2*>(&proxy)[A]), 
      static_cast<T>(reinterpret_cast<const T2*>(&proxy)[B])) {}

    /*************************************
    *             OPERATORS              *
    *************************************/
    operator swizzle::conversion_proxy<T, 2>() const
    {
      swizzle::conversion_proxy<T, 2> proxy{x, y};
      return proxy;
    }

    template<typename T2>
    type_vec<T, 2>& operator= (const type_vec<T2, 2> &v)
    {
      x = static_cast<T>(v.[0]); 
      y = static_cast<T>(v.[1]);
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
  
  typedef type_vec<bool, 2> bvec2;
  typedef type_vec<short, 2> svec2;
  typedef type_vec<unsigned short, 2> usvec2;
  typedef type_vec<int, 2> ivec2;
  typedef type_vec<unsigned int, 2> uivec2;
  typedef type_vec<float, 2> vec2;
  typedef type_vec<double, 2> dvec2;
}