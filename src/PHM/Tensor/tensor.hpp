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

namespace phm
{
  namespace MPHelpers
  {
    //Strip last argument of a parameter pack
    template <typename T, unsigned ... args>
    struct strip_last;

    template <typename T, unsigned ... args>
    struct strip_first;
    //This will be completed after the generic definition of the tensor class.
  }
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
      return (reinterpret_cast<tensor<T, D1, Dimensions...>*>(this))[sub];
    }
  };

  namespace MPHelpers
  {
    //strip metaprogram contd.
    //Done here as it needs to know the tensor class.
    template <typename T, unsigned arg0, unsigned ... argsRest>
    struct strip_first<T, arg0, argsRest...>
    {
      using type = tensor<T, argsRest...>;
    };

    template <typename T, unsigned arg0, unsigned arg1, unsigned arg2>
    struct strip_first<T, arg0, arg1, arg2>
    {
      using type = tensor<T, arg1, arg2>;
    };

    //Specialize for 3 subscripts (turns into a matrix)
    template <typename T, unsigned last_arg0, unsigned last_arg1, unsigned last_arg2>
    struct strip_last<T, last_arg0, last_arg1, last_arg2>
    {
      using type = tensor<T, last_arg0, last_arg1>;
    };
    //Specialize for 4 subscripts (turns into a 3rd order tensor)
    template <typename T, unsigned la0, unsigned la1, unsigned la2, unsigned la3>
    struct strip_last<T, la0, la1, la2, la3>
    {
      using type = tensor<T, la0, la1, la2>;
    };

    //Concat will be used to reattach the front args that get removed
    template <typename , typename>
    struct concat{};

    template <typename T, unsigned ... args0, unsigned ... args1>
    struct concat<tensor<T, args0...>, tensor<T, args1...>>
    {
      using type = tensor<T, args0..., args1...>;
    };

    //For order 5 or more, the first 2 args are stripped out and the rest
    //recurse till the sequence is resolved. Then they are recursively concatenated
    //back into the original sequence of args.
    template <typename T, unsigned arg0, unsigned arg1, unsigned ... argsRest>
    struct strip_last<T, arg0, arg1, argsRest...>
    {
      using type = typename concat<tensor<T, arg0, arg1>, typename strip_last<T, argsRest...>::type>::type;
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
