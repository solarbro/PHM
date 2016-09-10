/******************************************************************************/
/*!
\filxe  type_vec.hpp
\author Sagnik Chowdhury
\brief  Template vector class
*/
/******************************************************************************/

#pragma once
#include <algorithm>
#include <iostream> //operator<<
#include <cstring> //memcpy

#include "type_selector.h"
#include "Swizzle/vector_base_data.hpp"

namespace phm
{
  //compile time min function
  template<unsigned m, unsigned n>
  using Min = std::conditional_t < m >= n, std::integral_constant<unsigned, n>, std::integral_constant<unsigned, m >>;

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
  class type_vec : public swizzle::vec_internal_data<T, D>
  {
  public:

    /*************************************
    *               CTORS                *
    *************************************/
#pragma region CTORS
    type_vec()
    {
      T init_data[D] = { static_cast<T>(0.0) };
      std::memcpy(this->store, init_data, sizeof(T) * D);
    }

    explicit type_vec(T init)
    {
      for (unsigned i = 0; i < D; ++i)
        this->store[i] = init;
    }

    template<typename ArrayType, typename = std::enable_if_t<!std::is_fundamental<ArrayType>::value>>
    explicit type_vec(const ArrayType &init)
    {
      for (unsigned i = 0; i < D; ++i)
        this->store[i] = static_cast<T>(init[i]);
    }

    template<typename ... T2,
      typename = typename std::enable_if<sizeof...(T2) != 0>::type> /*sfinae single argument ctors to avoid conflicts*/
    explicit type_vec(T init0, T2 ... init)
    {
      static_assert(1 + sizeof...(T2) >= D, "Too few arguments. Cannot pass less arguments than the size of the vector.");
      static_assert(1 + sizeof...(T2) <= D, "Too many arguments. Cannot pass more arguments than the size of the vector.");

      T temp[] = { static_cast<T>(init0), static_cast<T>(init) ... };

      std::memcpy(this->store, temp, D * sizeof(T));
    }

    template<typename T2, unsigned D2, typename ... T3>
    explicit type_vec(const type_vec<T2, D2> &vec, T3 ... rest)
    {
      static_assert(sizeof...(T3) == 0 || (D2 + sizeof...(T3)) >= D, "Too few arguments. Cannot pass less arguments than the size of the vector.");
      static_assert(sizeof...(T3) == 0 || (D2 + sizeof...(T3)) <= D, "Too many arguments. Cannot pass more arguments than the size of the vector.");

      for (unsigned i = 0; i < Min<D, D2>::value; ++i)
        this->store[i] = static_cast<T>(vec[i]);

      if (D <= D2)
        return;

      std::conditional_t<D >= D2 + 1, T[D - D2], T[1]> temp = { static_cast<T>(rest) ... };

      std::memcpy(this->store + D2, temp, sizeof(T) * sizeof...(T3));
    }

    template<typename T2, unsigned ... indices>
    type_vec(const swizzle::VecProxy<T2, indices ...> &proxy)
    {
      static_assert(sizeof...(indices) >= D, "Illegal construction parameter. Insufficient data provided.");
      const T2* rhs_ptr = reinterpret_cast<const T2*>(&proxy);
      unsigned ix_array[] = { indices... };
      for (unsigned i = 0; i < D; ++i)
        this->store[i] = static_cast<T>(rhs_ptr[ix_array[i]]);
    }
#pragma endregion CTORS

    /*************************************
    *             OPERATORS              *
    *************************************/

    template <typename T2>
    type_vec<T, D>& operator= (const type_vec<T2, D> &rvec)
    {
      for (unsigned i = 0; i < D; ++i)
        this->store[i] = static_cast<T>(rvec[i]);

      return *this;
    }

    template<typename T2, unsigned ... indices>
    type_vec<T, D>& operator= (const swizzle::VecProxy<T2, indices ...> &proxy)
    {
      static_assert(sizeof...(indices) >= D, "Illegal assignment. Insufficient data in input array.");
      static_assert(sizeof...(indices) <= D, "Illegal assignment. Cannot assign to a smaller vector.");
      const T2* rhs_ptr = reinterpret_cast<const T2*>(&proxy);
      unsigned ix_array[] = { indices... };
      for (unsigned i = 0; i < D; ++i)
        this->store[i] = static_cast<T>(rhs_ptr[ix_array[i]]);

      return *this;
    }

    T operator[] (unsigned i) const
    {
      return this->store[i];
    }

    T& operator[] (unsigned i)
    {
      return this->store[i];
    }
  };

  //size 0 vectors should be constructable but not usable with anything
  template<typename T>
  class type_vec<T, 0> {};

  /*************************************
  *             OPERATORS              *
  *************************************/
  template <typename T1, typename T2, unsigned D>
  bool operator== (const type_vec<T1, D> &lvec, const type_vec<T2, D> &rvec)
  {
    for (unsigned i = 0; i < D; ++i)
    {
      if (static_cast<ptype<T1, T2>>(lvec[i]) != static_cast<ptype<T1, T2>>(rvec[i]))
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
  type_vec<ptype<T1,T2>, D> operator+ (const type_vec<T1, D> &lvec, const type_vec<T2, D> &rvec)
  {
    type_vec<T1, D> temp;
    for (unsigned i = 0; i < D; ++i)
      temp[i] = static_cast<ptype<T1, T2>>(lvec[i]) + static_cast<ptype<T1, T2>>(rvec[i]);

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
  type_vec<ptype<T1, T2>, D> operator- (const type_vec<T1, D> &lvec, const type_vec<T2, D> &rvec)
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
  type_vec<ptype<T1,T2>, D> operator* (const type_vec<T1, D> &lvec, const type_vec<T2, D> &rvec)
  {
    type_vec<ptype<T1, T2>, D> temp;
    for (unsigned i = 0; i < D; ++i)
      temp[i] = static_cast<ptype<T1, T2>>(lvec[i]) * static_cast<ptype<T1, T2>>(rvec[i]);

    return temp;
  }

  template<typename T1, typename T2, unsigned D>
  type_vec<ptype<T1, T2>, D> operator/ (const type_vec<T1, D> &lvec, const type_vec<T2, D> &rvec)
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
  *       normSq(v)
  *       norm(v)
  *       normalize(v)
  *       project(v, axis)
  *       abs(v)
  *       min(u, v)
  *       max(u, v)
  *       operator<<
  *       similar(u, v, epsilon)
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
  T normSq(const type_vec<T, D> v)
  {
    T sl = static_cast<T>(0.0);

    for (unsigned i = 0; i < D; ++i)
      sl += v[i] * v[i];

    return sl;
  }

  template<typename T, unsigned D>
  T norm(const type_vec<T, D> v)
  {
    T sl = normSq(v);
    return sqrt(sl);
  }

  template <typename T, unsigned D>
  type_vec<T,D> normalize(const type_vec<T, D> v)
  {
    T len = norm(v);
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

  template<typename T1, typename T2, typename T3, unsigned D>
  bool similar(const type_vec<T1, D> &v1, const type_vec<T2, D> &v2, const T3 &eps = std::numeric_limits<T3>::epsilon())
  {
    for (unsigned i = 0; i < D; ++i)
      if (std::abs(v1[i] - v2[i]) > static_cast<ptype<T1, T2>>(eps))
        return false;
  }
}
