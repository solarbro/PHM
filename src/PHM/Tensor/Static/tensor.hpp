/******************************************************************************/
/*!
\file   tensor.hpp
\author Sagnik Chowdhury
\brief  Contains the Photon tensor library
*/
/******************************************************************************/
#pragma once

#include "Internal/tensor_internal.hpp"

namespace phm
{
  //Generic tensor class
  template <typename T, unsigned ... Dimensions>
  class tensor : public internal::tensor_internal_data<T, Dimensions ...>
  {
  public:
    tensor() :
      internal::tensor_internal_data<T, Dimensions ...>{0}{}

    template <typename FirstType, typename ... OtherTypes>
    tensor(FirstType Init0, OtherTypes ... Initializers) :
        internal::tensor_internal_data<T, Dimensions ...>{Init0, Initializers ...}{}
  };

  template <typename T, unsigned R>
  class tensor<T, R, 1> : public internal::tensor_internal_data<T, R>
  {
  public:
    //This makes single column rank 2 tensors (matrices) contain the same
    //internal data as rank 1 tensors (vectors). This allows them to have
    //swizzling when possible.
  };
}
