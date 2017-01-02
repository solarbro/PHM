/******************************************************************************/
/*!
\file   tensor.hpp
\author Sagnik Chowdhury
\brief  Contains the Photon tensor library
*/
/******************************************************************************/
#pragma once

#include "Internal/tensor_internal.hpp"
#include <initializer_list>
#include <cstring>

namespace phm
{

  //Generic tensor class
  template <typename T, unsigned D0 = 1, unsigned D1 = 1, unsigned ... Dimensions>
  class tensor : public internal::tensor_internal_data<T, D0, D1, Dimensions ...>
  {
  public:
    tensor() :
      internal::tensor_internal_data<T, D0, D1, Dimensions ...>{0}{}

    tensor(std::initializer_list<tensor<T, D1, Dimensions...>> Initializers)
    {
      std::memcpy(this->store, Initializers.begin(), sizeof(this->store));
    }

    tensor<T, D1, Dimensions...>& operator[](unsigned sub)
    {
      return (reinterpret_cast<tensor<T, D1, Dimensions...>*>(this))[sub];
    }

    tensor<T, D1, Dimensions...> operator[](unsigned sub) const
    {
      return (reinterpret_cast<const tensor<T, D1, Dimensions...>*>(this))[sub];
    }
  };


  //Operations
  template <typename ... types>
  using common = internal::MPHelpers::ptype<types...>;

  //Addition
  template <typename T1, typename T2, unsigned D0, unsigned D1, unsigned ... Drest>
  tensor<common<T1, T2>, D0, D1, Drest...> operator+(const tensor<T1, D0, D1, Drest...>&t0,
                                                     const tensor<T2, D0, D1, Drest...>&t1)
  {
    tensor<common<T1, T2>, D0, D1, Drest...> result;
    unsigned arraySize = internal::MPHelpers::Product<D0, D1, Drest...>::Value;
    for(unsigned i = 0; i < arraySize; ++i)
      result.store[i] = t0.store[i] + t1.store[i];

    return result;
  }
}
