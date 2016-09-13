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
  namespace MPHelpers
  {
    //Strip last argument of a parameter pack
    template <typename T, unsigned ... args>
    struct strip;


  }
  //Generic tensor class
  template <typename T, unsigned D0 = 1, unsigned D1 = 1, unsigned ... Dimensions>
  class tensor : public internal::tensor_internal_data<T, D0, D1, Dimensions ...>
  {
  public:
    tensor() :
      internal::tensor_internal_data<T, D0, D1, Dimensions ...>{0}{}

    template <typename FirstType, typename ... OtherTypes>
    tensor(FirstType Init0, OtherTypes ... Initializers) :
        internal::tensor_internal_data<T, D0, D1, Dimensions ...>{Init0, Initializers ...}{}

    typename MPHelpers::strip<T, D0, D1, Dimensions...>::type& operator[](unsigned sub)
    {
      return (reinterpret_cast<typename MPHelpers::strip<T, D0, D1, Dimensions...>::type*>(this))[sub];
    }

    typename MPHelpers::strip<T, D0, D1, Dimensions...>::type operator[](unsigned sub) const
    {
      return (reinterpret_cast<typename MPHelpers::strip<T, D0, D1, Dimensions...>::type*>(this))[sub];
    }
  };

  namespace MPHelpers
  {
    //strip metaprogram contd.
    //Done here as it needs to know the tensor class.
    template <typename T, unsigned last_arg0, unsigned last_arg1, unsigned last_arg2>
    struct strip<T, last_arg0, last_arg1, last_arg2>
    {
      using type = tensor<T, last_arg0, last_arg1>;
    };

    template <typename T, unsigned la0, unsigned la1, unsigned la2, unsigned la3>
    struct strip<T, la0, la1, la2, la3>
    {
      using type = tensor<T, la0, la1, la2>;
    };

    template <typename , typename>
    struct concat{};

    template <typename T, unsigned ... args0, unsigned ... args1>
    struct concat<tensor<T, args0...>, tensor<T, args1...>>
    {
      using type = tensor<T, args0..., args1...>;
    };

    template <typename T, unsigned arg0, unsigned arg1, unsigned ... argsRest>
    struct strip<T, arg0, arg1, argsRest...>
    {
      using type = typename concat<tensor<T, arg0, arg1>, typename strip<T, argsRest...>::type>::type;
    };
  }

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
