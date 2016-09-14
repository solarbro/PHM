/******************************************************************************/
/*!
\file   matrix.hpp
\author Sagnik Chowdhury
\brief  matrix specialization of tensor class
*/
/******************************************************************************/
#include "../tensor.hpp"
#include <initializer_list>
#include <array>

namespace phm
{
  template <typename T, unsigned D0, unsigned D1>
  class tensor<T, D0, D1> : public internal::tensor_internal_data<T, D0, D1>
  {
  public:
    tensor():
      internal::tensor_internal_data<T, D0, D1>{0}{}

    tensor(std::initializer_list<tensor<T, D1>> InitList)
    {
      std::memcpy(this->store, InitList.begin(), sizeof(this->store));
    }

    tensor<T, D1>& operator[](unsigned sub)
    {
      return (reinterpret_cast<tensor<T, D1>*>(this))[sub];
    }

    tensor<T, D1> operator[](unsigned sub) const
    {
      return (reinterpret_cast<tensor<T, D1>*>(this))[sub];
    }
  };

  template <typename T, unsigned D0, unsigned D1>
  using matrix = tensor<T, D0, D1>;

}
