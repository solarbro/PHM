/******************************************************************************/
/*!
\file   scalar.hpp
\author Sagnik Chowdhury
\brief  Contains the Photon renderer math library
*/
/******************************************************************************/
#pragma once
#include "../tensor.hpp"

namespace phm
{
  //Rank 0 tensors are scalars so allow cast operator.
  template <typename T>
  class tensor<T, 1, 1> : public internal::tensor_internal_data<T, 1>
  {
  public:
    tensor(T scalar = 0) :
      internal::tensor_internal_data<T, 1>{scalar}{}

    operator T()
    {
      return this->store;
    }
  };

  template <typename T>
  using scalar = tensor<T, 1, 1>;
}
