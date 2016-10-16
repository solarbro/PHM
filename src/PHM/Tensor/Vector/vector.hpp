/******************************************************************************/
/*!
\file   vector.hpp
\author Sagnik Chowdhury
\brief  Contains the Photon renderer vector library
*/
/******************************************************************************/
#ifndef VECTOR_HPP
#define VECTOR_HPP

#include "../tensor.hpp"

#include <initializer_list>

namespace phm
{
  template <typename T, unsigned D>
  class tensor<T, 1, D> : public internal::tensor_internal_data<T, D>
  {
  public:
    //This makes single row rank 2 tensors (row matrix) contain the same
    //internal data as 1st order tensors (vectors).
    tensor() :
      internal::tensor_internal_data<T, D>{0}{}

    template <typename FirstType, typename ... OtherTypes>
    tensor(FirstType Init0, OtherTypes ... Initializers) :
        internal::tensor_internal_data<T, D>{Init0, Initializers ...}{}

    template <typename T2, unsigned ... indices>
    tensor(const swizzle::Proxy<T2, indices...> &proxy)
    {
      static_assert(sizeof...(indices) >= D, "Illegal construction parameter. Insufficient data provided.");
      const T2* rhs_ptr = reinterpret_cast<const T2*>(&proxy);
      unsigned ix_array[] = { indices... };
      for (unsigned i = 0; i < D; ++i)
        this->store[i] = static_cast<T>(rhs_ptr[ix_array[i]]);
    }

    tensor<T>& operator[](unsigned sub)
    {
        return (*reinterpret_cast<tensor<T>*>(this))[sub];
    }

    tensor<T> operator[](unsigned sub) const
    {
      return this->store[sub];
    }
  };

  template <typename T, unsigned D>
  class tensor<T, D, 1> : public internal::tensor_internal_data<T, D>
  {
  public:
    //This makes single column rank 2 tensors (column matrix) contain the same
    //internal data as 1st order tensors (vector). This allows them to have
    //swizzling when possible.

    tensor() :
      internal::tensor_internal_data<T, D>{0}{}

    template <typename FirstType, typename ... OtherTypes>
    tensor(FirstType Init0, OtherTypes ... Initializers) :
        internal::tensor_internal_data<T, D>{Init0, Initializers ...}{}

    template <typename T2, unsigned ... indices>
    tensor(const swizzle::Proxy<T2, indices...> &proxy)
    {
      static_assert(sizeof...(indices) >= D, "Illegal construction parameter. Insufficient data provided.");
      const T2* rhs_ptr = reinterpret_cast<const T2*>(&proxy);
      unsigned ix_array[] = { indices... };
      for (unsigned i = 0; i < D; ++i)
        this->store[i] = static_cast<T>(rhs_ptr[ix_array[i]]);
    }

    // template <typename T2, unsigned ... indices>
    // tensor<T, D> operator=(const swizzle::Proxy<T2, indices...> &proxy)
    // {
    //   static_assert(sizeof...(indices) >= D, "Illegal construction parameter. Insufficient data provided.");
    //   const T2* rhs_ptr = reinterpret_cast<const T2*>(&proxy);
    //   unsigned ix_array[] = { indices... };
    //   unsigned Ixs = sizeof...(indices);
    //   for (unsigned i = 0; i < Ixs; ++i)
    //     this->store[i] = static_cast<T>(rhs_ptr[ix_array[i]]);
    //
    //   return *this;
    // }

    //make column matrices implicitly convert to row matrices when necessary
    operator tensor<T, 1, D>()
    {
      return *reinterpret_cast<tensor<T, 1, D>*>(this);
    }

    tensor<T>& operator[](unsigned sub)
    {
      return (reinterpret_cast<tensor<T>*>(this->store))[sub];
    }

    tensor<T> operator[](unsigned sub) const
    {
      return this->store[sub];
    }
  };


  template <typename T, unsigned D>
  using vector = tensor<T, D, 1>;

  template <typename T, unsigned D>
  using columnVector = tensor<T, D, 1>;

  template <typename T, unsigned D>
  using rowVector = tensor<T, 1, D>;
}


#endif /* end of include guard: VECTOR_HPP */
