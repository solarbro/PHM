/******************************************************************************/
/*!
\filxe  type_vec2.hpp
\author Sagnik Chowdhury
\par    Course: GAM300
\brief  Contains the Photon renderer math library
*/
/******************************************************************************/

#pragma once
#include <algorithm>
#include <iostream>

#include "type_selector.h"

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

  template<class T, unsigned D>
  class type_vec
  {
  public:

    /*************************************
    *               CTORS                *
    *************************************/
    type_vec()
    {
      for (unsigned i = 0; i < D; ++i)
        v[i] = static_cast<T>(0.0);
    }

    template<typename T2>
    type_vec(T2 init)
    {
      for (unsigned i = 0; i < D; ++i)
        v[i] = static_cast<T>(init);
    }

    template<typename T2>
    type_vec(T2* init)
    {
      for (unsigned i = 0; i < D; ++i)
        v[i] = static_cast<T>(init[i]);
    }

    template<typename ... T2>
    type_vec(T2 ... init)
    {
      T2 temp[] = { init ... };
      for (unsigned i = 0; i < D; ++i)
        v[i] = static_cast<T>(temp[i]);
    }

    template<typename T2, unsigned D2, typename ... T3>
    type_vec(const type_vec<T2, D2> &vec, T3 ... rest)
    {
      unsigned from_v = std::min(D, D2);

      for (unsigned i = 0; i < from_v; ++i)
        v[i] = vec[i];

      T2 temp[] = { rest ... };
      for (unsigned i = from_v; i < D; ++i)
        v[i] = static_cast<T>(temp[i - from_v]);
    }

    /*************************************
    *             OPERATORS              *
    *************************************/
    template <typename T2>
    type_vec<T, D>& operator= (const type_vec<T2, D> &rvec)
    {
      for (unsigned i = 0; i < D; ++i)
        v[i] = static_cast<T>(rvec[i]);

      return *this;
    }
    
    T operator[] (unsigned i) const
    {
      return v[i];
    }

    T& operator[] (unsigned i)
    {
      return v[i];
    }

  private:

    T v[D];

  };


  /*************************************
  *             OPERATORS              *
  *************************************/
  template <typename T1, typename T2, unsigned D>
  bool operator== (const type_vec<T1, D> &lvec, const type_vec<T2, D> &rvec)
  {
    for (unsigned i = 0; i < D; ++i)
    {
      if (static_cast<PTYPE(T1, T2)>(lvec[i]) != static_cast<PTYPE(T1, T2)>(rvec[i]))
        return false;
    }
    return true;
  }

  template <typename T1, typename T2, unsigned D>
  bool operator != (const type_vec<T1, D> &lvec, const type_vec<T2, D> &rvec)
  {
    return !(lvec == rvec);
  }

  template <typename T1, typename T2, unsigned D>
  type_vec<PTYPE(T1,T2), D> operator+ (const type_vec<T1, D> &lvec, const type_vec<T2, D> &rvec)
  {
    type_vec<T1, D> temp;
    for (unsigned i = 0; i < D; ++i)
      temp[i] = static_cast<PTYPE(T1, T2)>(lvec[i]) + static_cast<PTYPE(T1, T2)>(rvec[i]);

    return temp;
  }

  template<typename T, unsigned D>
  type_vec<T, D> operator-(const type_vec<T, D> &vec)
  {
    type_vec<T, D> temp;
    for (unsigned i = 0; i < D; ++i)
      temp[i] = -vec[i];

    return temp;
  }

  template<typename T1, typename T2, unsigned D>
  type_vec<PTYPE(T1, T2), D> operator- (const type_vec<T1, D> &lvec, const type_vec<T2, D> &rvec)
  {
    return lvec + -rvec;
  }

  template<typename T1, typename T2, unsigned D>
  type_vec<T1, D> operator+ (const type_vec<T1, D> &vec, const T2 &f)
  {
    type_vec<T1, D> temp;
    for (unsigned i = 0; i < D; ++i)
      temp[i] = vec[i] + static_cast<T1>(f);

    return temp;
  }

  template<typename T1, typename T2, unsigned D>
  type_vec<T1, D> operator+ (const T2 &f, const type_vec<T1, D> &vec)
  {
    return vec + f;
  }

  template<typename T1, typename T2, unsigned D>
  type_vec<T1, D> operator- (const type_vec<T1, D> &vec, const T2 &f)
  {
    return vec + -f;
  }

  template<typename T1, typename T2, unsigned D>
  type_vec<T1, D>& operator+= (type_vec<T1, D> &lvec, const type_vec<T2, D> &rvec)
  {
    for (unsigned i = 0; i < D; ++i)
      lvec[i] += static_cast<T1>(rvec[i]);

    return lvec;
  }

  template<typename T1, typename T2, unsigned D>
  type_vec<T1, D>& operator-= (type_vec<T1, D> &lvec, const type_vec<T2, D> &rvec)
  {
    return lvec += -rvec;
  }

  template<typename T1, typename T2, unsigned D>
  type_vec<T1, D>& operator+= (type_vec<T1, D> &vec, const T2 &f)
  {
    for (unsigned i = 0; i < D; ++i)
      vec[i] += static_cast<T1>(f);

    return vec;
  }

  template<typename T1, typename T2, unsigned D>
  type_vec<T1, D>& operator-= (type_vec<T1, D> &vec, const T2 &f)
  {
    return vec += -f;
  }

  template<typename T1, typename T2, unsigned D>
  type_vec<PTYPE(T1,T2), D> operator* (const type_vec<T1, D> &lvec, const type_vec<T2, D> &rvec)
  {
    type_vec<PTYPE(T1, T2), D> temp;
    for (unsigned i = 0; i < D; ++i)
      temp[i] = static_cast<PTYPE(T1, T2)>(lvec[i]) * static_cast<PTYPE(T1, T2)>(rvec[i]);

    return temp;
  }

  template<typename T1, typename T2, unsigned D>
  type_vec<PTYPE(T1, T2), D> operator/ (const type_vec<T1, D> &lvec, const type_vec<T2, D> &rvec)
  {
    type_vec<T2, D> temp;
    for (unsigned i = 0; i < D; ++i)
      temp[i] = (static_cast<T2>(1.0) / rvec[i]);

    return lvec * temp;
  }

  template<typename T1, typename T2, unsigned D>
  type_vec<T1, D> operator* (const type_vec<T1, D> &vec, const T2 &f)
  {
    type_vec<T1, D> temp;
    for (unsigned i = 0; i < D; ++i)
      temp[i] = vec[i] * static_cast<T1>(f);

    return temp;
  }

  template<typename T1, typename T2, unsigned D>
  type_vec<T1, D> operator* (const T2 &f, const type_vec<T1, D> &vec)
  {
    return vec * f;
  }

  template<typename T1, typename T2, unsigned D>
  type_vec<T1, D> operator/ (const type_vec<T1, D> &vec, const T2 &f)
  {
    T2 invf = static_cast<T2>(1.0) / f;
    return vec * invf;
  }

  template<typename T1, typename T2, unsigned D>
  type_vec<T1, D>& operator*= (type_vec<T1, D> &vec, const T2 &f)
  {
    for (unsigned i = 0; i < D; ++i)
      vec[i] *= static_cast<T1>(f);

    return vec;
  }

  template<typename T1, typename T2, unsigned D>
  type_vec<T1, D>& operator*= (type_vec<T1, D> &lvec, const type_vec<T2, D> &rvec)
  {
    for (unsigned i = 0; i < D; ++i)
      lvec[i] *= static_cast<T1>(rvec[i]);

    return lvec;
  }

  template<typename T1, typename T2, unsigned D>
  type_vec<T1, D>& operator/= (type_vec<T1, D> &vec, const T2 &f)
  {
    T2 invf = static_cast<T2>(1.0) / f;
    return vec *= invf;
  }

  template<typename T1, typename T2, unsigned D>
  type_vec<T1, D>& operator/= (type_vec<T1, D> &lvec, const type_vec<T2, D> &rvec)
  {
    type_vec<T2, D> invf;
    for (unsigned i = 0; i < D; ++i)
      invf[i] = static_cast<T2>(1.0) / rvec[i];

    return lvec *= invf;
  }


  /*      =============================================
  *                       Functions
  *       =============================================
  *
  *       dot(v1, v2)
  *       sqlength(v)
  *       length(v)
  *       normalize(v)
  *       project(v, axis)
  *       abs(v)
  *       min(u, v)
  *       max(u, v)
  *       operator<<
  */

  template<typename T, unsigned D>
  T dot(const type_vec<T, D> &v1, const type_vec<T, D> &v2)
  {
    T Dot = static_cast<T>(0.0);
    for (unsigned i = 0; i < D; ++i)
      Dot += v1[i] * v2[i];
    return Dot;
  }

  template<typename T, unsigned D>
  T sqlength(const type_vec<T, D> v)
  {
    T sl = static_cast<T>(0.0);

    for (unsigned i = 0; i < D; ++i)
      sl += v[i] * v[i];

    return sl;
  }

  template<typename T, unsigned D>
  T length(const type_vec<T, D> v)
  {
    T sl = sqlength(v);
    return sqrt(sl);
  }

  template <typename T, unsigned D>
  type_vec<T,D> normalize(const type_vec<T, D> v)
  {
    T len = length(v);
    return v / len;
  }

  template<typename T, unsigned D>
  type_vec<T, D> project(const type_vec<T, D> &v, const type_vec<T, D> &axis)
  {
    type_vec<T, D> norm_axis = normalize(axis);
    return dot(v, norm_axis) * norm_axis;
  }

  template<typename T, unsigned D>
  type_vec<T, D> abs(const type_vec<T, D> &v)
  {
    type_vec<T, D> temp;
    for (unsigned i = 0; i < D; ++i)
      temp[i] = std::abs(v[i]);
    return temp;
  }

  template<typename T, unsigned D>
  type_vec<T, D> min(const type_vec<T, D> &u, const type_vec<T, D> &v)
  {
    type_vec<T, D> min_vec;
    for (unsigned i = 0; i < D; ++i)
      min_vec[i] = std::min(u[i], v[i]);
    return min_vec;
  }

  template<typename T, unsigned D>
  type_vec<T, D> max(const type_vec<T, D> &u, const type_vec<T, D> &v)
  {
    type_vec<T, D> min_vec;
    for (unsigned i = 0; i < D; ++i)
      min_vec[i] = std::max(u[i], v[i]);
    return min_vec;
  }

  template<typename T, unsigned D>
  std::ostream& operator<<(std::ostream &os, const type_vec<T,D> &v)
  {
    os << "<";
    for (unsigned i = 0; i < D - 1; ++i)
      os << v[i] << ", ";

    os << v[D - 1] << ">";
    return os;
  }
}