/******************************************************************************/
/*!
\file   matrix.hpp
\author Sagnik Chowdhury
\brief  matrix specialization of tensor class
*/
/******************************************************************************/
#include "../tensor.hpp"

namespace phm
{
  template <typename T, unsigned D0, unsigned D1>
  class tensor<T, D0, D1> : public internal::tensor_internal_data<T, D0, D1>
  {
  public:
    tensor():
      internal::tensor_internal_data<T, D0, D1>{0}{}

    template <typename FirstType, typename ... OtherTypes>
    tensor(FirstType Init0, OtherTypes ... Initializers) :
        internal::tensor_internal_data<T, D0, D1>{Init0, Initializers ...}{}

    tensor<T, D0>& operator[](unsigned sub)
    {
      return (reinterpret_cast<tensor<T, D0>*>(this))[sub];
    }

    tensor<T, D0> operator[](unsigned sub) const
    {
      return (reinterpret_cast<tensor<T, D0>*>(this))[sub];
    }
  };

  template <typename T, unsigned D0, unsigned D1>
  using matrix = tensor<T, D0, D1>;

}
