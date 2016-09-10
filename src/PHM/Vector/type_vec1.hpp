/******************************************************************************/
/*!
\filxe  type_vec1.hpp
\author Sagnik Chowdhury
\brief  Specialization of size 1 vectors to enable special behavior
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
    //Apparently g++ can't access members of templated parent class without this->
    type_vec()
    {
      this->store = static_cast<T>(0.0);
    }

    template<typename T2>
    type_vec(T2 init)
    {
      this->store = static_cast<T>(init);
    }

    template<typename T2, unsigned A>
    type_vec(const swizzle::VecProxy<T2, A> &proxy)
    {
      this->store = static_cast<T>(reinterpret_cast<const T2*>(&proxy)[A]);
    }

    operator T()
    {
      return this->store;
    }

#pragma endregion CTORS

#pragma region OPERATORS

    template<typename T2>
    type_vec<T, 1>& operator= (const type_vec<T2, 1> &rvec)
    {
      return this->store == static_cast<T>(rvec[0]);
    }

    T operator[] (unsigned i) const
    {
      return this->store;//[i];
    }

    T& operator[](unsigned i)
    {
      return this->store;//[i];
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
