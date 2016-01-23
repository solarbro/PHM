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
  class type_vec<T, 2>
  {
  public:
    
    /*************************************
    *              SWIZZLE               *
    *************************************/
    T&                     x()       { return X; }
    const T&               x() const { return X; }
    T&                     y()       { return Y; }
    const T&               y() const { return Y; }
    type_vec<T, 2>        xx() const { return type_vec<T, 2>(X); }
    type_vec<T, 2>&       xy()       { return *this; }
    const type_vec<T, 2>& xy() const { return *this; }
    type_vec<T, 2>        yx() const { return type_vec<T, 2>(Y, X); }
    type_vec<T, 2>        yy() const { return type_vec<T, 2>(Y); }

    T&                     r()       { return X; }
    const T&               r() const { return X; }
    T&                     g()       { return Y; }
    const T&               g() const { return Y; }
    type_vec<T, 2>        rr() const { return xx(); }
    type_vec<T, 2>&       rg()       { return xy(); }
    const type_vec<T, 2>& rg() const { return xy(); }
    type_vec<T, 2>        gr() const { return yx(); }
    type_vec<T, 2>        gg() const { return yy(); }

    /*************************************
    *               CTORS                *
    *************************************/
    type_vec() :
      X(static_cast<T>(0.0)), Y(static_cast<T>(0.0)){}

    template<typename T2>
    type_vec(T2 init) :
      X(static_cast<T>(init)), Y(static_cast<T>(init)){}

    template<typename T2>
    type_vec(T2* init) :
      X(static_cast<T>(init[0])), Y(static_cast<T>(init[1])){}

    template<typename T2>
    type_vec(const T2 &init_x, const T2 &init_y) :
      X(static_cast<T>(init_x)), Y(static_cast<T>(init_y)){}

    template<typename T2>
    type_vec(const type_vec<T2, 2> &v) :
      X(static_cast<T>(v.X)), Y(static_cast<T>(v.Y)){}

    /*************************************
    *             OPERATORS              *
    *************************************/
    
    template<typename T2>
    type_vec<T, 2>& operator= (const type_vec<T2, 2> &v)
    {
      X = static_cast<T>(v.X); Y = static_cast<T>(v.Y);
      return *this;
    }

    T operator[] (unsigned i) const
    {
      return *(&X + i);
    }

    T& operator[] (unsigned i)
    {
      return *(&X + i);
    }


  private:

    T X;
    T Y;

  };
  
  typedef type_vec<bool, 2> bvec2;
  typedef type_vec<short, 2> svec2;
  typedef type_vec<unsigned short, 2> usvec2;
  typedef type_vec<int, 2> ivec2;
  typedef type_vec<unsigned int, 2> uivec2;
  typedef type_vec<float, 2> vec2;
  typedef type_vec<double, 2> dvec2;
}