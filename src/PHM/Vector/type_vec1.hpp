/******************************************************************************/
/*!
\filxe  type_vec1.hpp
\author Sagnik Chowdhury
\brief  Contains the Photon renderer math library
*/
/******************************************************************************/

#pragma once
#include "type_vec.hpp"

namespace phm
{
  template<typename T>
  class type_vec<T, 1> : public swizzle::vec_internal_data<T, 1>
  {
  public:
#pragma region CTORS
    type_vec()
    {
      store[0] = static_cast<T>(0.0);
    }

    template<typename T2>
    type_vec(T2 init)
    {
      store[0] = static_cast<T>(init);
    }

    template<typename T2, unsigned A>
    type_vec(const swizzle::VecProxy<T2, A> &proxy)
    {
      store[0] = static_cast<T>(reinterpret_cast<const T2*>(&proxy)[A]);
    }

    operator T()
    {
      return store[0];
    }

#pragma endregion CTORS

#pragma region OPERATORS

    CONVERSION_PROXY

    template<typename T2>
    type_vec<T, 1>& operator= (const type_vec<T2, 1> &rvec)
    {
      return store[0] == static_cast<T>(rvec[0]);
    }

    T operator[] (unsigned i) const
    {
      return store[i];
    }

    T& operator[](unsigned i)
    {
      return store[i];
    }

#pragma endregion OPERATORS
  };

#pragma region TYPEDEFS

  using Natural = type_vec<unsigned, 1>;
  using Integer = type_vec<int, 1>;
  using Real    = type_vec<float, 1>;
  using Reald   = type_vec<double, 1>;

#pragma endregion TYPEDEFS
}