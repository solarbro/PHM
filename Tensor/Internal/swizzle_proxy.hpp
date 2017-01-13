/******************************************************************************/
/*!
\file   vector_swizzle_proxy.hpp
\author Sagnik Chowdhury
\brief  Implementation of vector swizzle
*/
/******************************************************************************/
#pragma once

#include <type_traits>

namespace phm
{
  namespace swizzle
  {

    //This is a forward declaration as there'll be specializations for every usable type
    template<typename T, unsigned ... indices>
    struct Proxy;


    template<typename T, unsigned A>
    struct Proxy<T, A>
    {
      operator T()
      {
        return reinterpret_cast<T*>(this)[A];
      }

      template<typename T2, unsigned A2>
      Proxy<T, A>& operator= (const Proxy<T2, A2> &rhs)
      {
        reinterpret_cast<T*>(this)[A] = reinterpret_cast<const T2*>(&rhs)[A2];
        return *this;
      }

      template<typename T2, typename = std::enable_if_t<std::is_fundamental<T2>::value>>
      Proxy<T, A>& operator= (const T2 &scalar)
      {
        reinterpret_cast<T*>(this)[A] = static_cast<T>(scalar);
        return *this;
      }

      template<typename T2, class ArrayType>
      Proxy<T, A>& operator= (const ArrayType &conv)
      {
        T*  this_ptr = reinterpret_cast<T*>(this);
        this_ptr[A] = static_cast<T>(conv[0]);
        return *this;
      }

    };


    template<typename T, unsigned A, unsigned B>
    struct Proxy<T, A, B>
    {
      template<typename T2, unsigned A2, unsigned B2>
      Proxy<T, A, B>& operator= (const Proxy<T2, A2, B2> &rhs)
      {
        static_assert(A != B, "Cannot write to this component.");
        const T2* rhs_ptr = reinterpret_cast<const T2*>(&rhs);
        T rhsArr[] = {static_cast<T>(rhs_ptr[A2]), static_cast<T>(rhs_ptr[B2])};
        T*  this_ptr = reinterpret_cast<T*>(this);
        this_ptr[A] = rhs_ptr[0];
        this_ptr[B] = rhs_ptr[1];
        return *this;
      }

      template<class ArrayType>
      Proxy<T, A, B>& operator= (const ArrayType &conv)
      {
        static_assert(A != B, "Cannot write to this component.");
        T*  this_ptr = reinterpret_cast<T*>(this);
        this_ptr[A] = static_cast<T>(conv[0]);
        this_ptr[B] = static_cast<T>(conv[1]);
        return *this;
      }
    };


    template<typename T, unsigned A, unsigned B, unsigned C>
    struct Proxy<T, A, B, C>
    {
      template<typename T2, unsigned A2, unsigned B2, unsigned C2>
      Proxy<T, A, B, C>& operator= (const Proxy<T2, A2, B2, C2> &rhs)
      {
        static_assert(A != B && A != C && B != C, "Cannot write to this component.");
        const T2* rhs_ptr = reinterpret_cast<const T2*>(&rhs);
        T rhsArr[] = {static_cast<T>(rhs_ptr[A2]), static_cast<T>(rhs_ptr[B2]), static_cast<T>(rhs_ptr[C2])};
        T* this_ptr = reinterpret_cast<T*>(this);
        this_ptr[A] = rhsArr[0];
        this_ptr[B] = rhsArr[1];
        this_ptr[C] = rhsArr[2];
        return *this;
      }

      template<typename T2, class ArrayType>
      Proxy<T, A, B, C>& operator= (const ArrayType &conv)
      {
        static_assert(A != B && A != C && B != C, "Cannot write to this component.");
        T*  this_ptr = reinterpret_cast<T*>(this);
        this_ptr[A] = static_cast<T2>(conv[0]);
        this_ptr[B] = static_cast<T2>(conv[1]);
        this_ptr[C] = static_cast<T2>(conv[2]);
        return *this;
      }
    };

    template<typename T, unsigned A, unsigned B, unsigned C, unsigned D>
    struct Proxy<T, A, B, C, D>
    {
      template<typename T2, unsigned A2, unsigned B2, unsigned C2, unsigned D2>
      Proxy<T, A, B, C, D>& operator= (const Proxy<T2, A2, B2, C2, D2> &rhs)
      {
        static_assert(A != B && A != C && A != D && B != C && B != D && C != D, "Cannot write to this component.");
        const T2* rhs_ptr = reinterpret_cast<const T2*>(&rhs);
        T rhsArr[] = {static_cast<T>(rhs_ptr[A2]), static_cast<T>(rhs_ptr[B2]), static_cast<T>(rhs_ptr[C2]), static_cast<T>(rhs_ptr[D2])};
        T* this_ptr = reinterpret_cast<T*>(this);
        this_ptr[A] = rhsArr[0];
        this_ptr[B] = rhsArr[1];
        this_ptr[C] = rhsArr[2];
        this_ptr[D] = rhsArr[3];
        return *this;
      }

      template<typename T2, class ArrayType>
      Proxy<T, A, B, C, D>& operator= (const ArrayType &conv)
      {
        static_assert(A != B && A != C && A != D && B != C && B != D && C != D, "Cannot write to this component.");
        T*  this_ptr = reinterpret_cast<T*>(this);
        this_ptr[A] = static_cast<T>(conv[0]);
        this_ptr[B] = static_cast<T>(conv[1]);
        this_ptr[C] = static_cast<T>(conv[2]);
        this_ptr[D] = static_cast<T>(conv[3]);
        return *this;
      }
    };

  }
}
