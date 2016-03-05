/******************************************************************************/
/*!
\filxe  vector_swizzle_proxy.hpp
\author Sagnik Chowdhury
\brief  Contains the Photon renderer math library. TODO: overload all operators 
        for the proxies.
*/
/******************************************************************************/
#pragma once

namespace phm
{
  namespace swizzle
  {

#pragma region VEC_GENERIC_PROXY
    //This is a forward declaration as there'll be specializations for every usable type
    template<typename T, unsigned ... indices>
    struct VecProxy;

#pragma endregion VEC_GENERIC_PROXY

#pragma region Vec1Proxy

    template<typename T, unsigned A>
    struct VecProxy<T, A>
    {
      operator T()
      {
        return reinterpret_cast<T*>(this)[A];
      }

      template<typename T2, unsigned A2>
      VecProxy<T, A>& operator= (const VecProxy<T2, A2> &rhs)
      {
        reinterpret_cast<T*>(this)[A] = reinterpret_cast<const T2*>(&rhs)[A2];
        return *this;
      }

      template<typename T2, typename = std::enable_if_t<std::is_fundamental<T2>::value>>
      VecProxy<T, A>& operator= (const T2 &scalar)
      {
        reinterpret_cast<T*>(this)[A] = static_cast<T>(scalar);
        return *this;
      }

      template<typename T2, template <typename, unsigned> class ArrayType>
      VecProxy<T, A>& operator= (const ArrayType<T2, 1> &conv)
      {
        T*  this_ptr = reinterpret_cast<T*>(this);
        this_ptr[A] = static_cast<T>(conv[0]);
        return *this;
      }

    };

#pragma endregion Vec1Proxy

#pragma region Vec2Proxy

    template<typename T, unsigned A, unsigned B>
    struct VecProxy<T, A, B>
    {
      template<typename T2, unsigned A2, unsigned B2>
      VecProxy<T, A, B>& operator= (const VecProxy<T2, A2, B2> &rhs)
      {
        static_assert(A != B, "Cannot write to this component.");
        const T2* rhs_ptr = reinterpret_cast<const T2*>(&rhs);
        T*  this_ptr = reinterpret_cast<T*>(this);
        this_ptr[A] = rhs_ptr[A2];
        this_ptr[B] = rhs_ptr[B2];
        return *this;
      }

      template<typename T2, template <typename, unsigned> class ArrayType>
      VecProxy<T, A, B>& operator= (const ArrayType<T2, 2> &conv)
      {
        static_assert(A != B, "Cannot write to this component.");
        T*  this_ptr = reinterpret_cast<T*>(this);
        this_ptr[A] = static_cast<T>(conv[0]);
        this_ptr[B] = static_cast<T>(conv[1]);
        return *this;
      }
    };

#pragma endregion Vec2Proxy

#pragma region Vec3Proxy

    template<typename T, unsigned A, unsigned B, unsigned C>
    struct VecProxy<T, A, B, C>
    {
      template<typename T2, unsigned A2, unsigned B2, unsigned C2>
      VecProxy<T, A, B, C>& operator= (const VecProxy<T2, A2, B2, C2> &rhs)
      {
        static_assert(A != B && A != C && B != C, "Cannot write to this component.");
        T2* rhs_ptr = reinterpret_cast<T2*>(&rhs);
        T* this_ptr = reinterpret_cast<T*>(this);
        this_ptr[A] = rhs_ptr[A2];
        this_ptr[B] = rhs_ptr[B2];
        this_ptr[C] = rhs_ptr[C2];
        return *this;
      }

      template<typename T2, template <typename, unsigned> class ArrayType>
      VecProxy<T, A, B, C>& operator= (const ArrayType<T2, 3> &conv)
      {
        static_assert(A != B && A != C && B != C, "Cannot write to this component.");
        T*  this_ptr = reinterpret_cast<T*>(this);
        this_ptr[A] = static_cast<T2>(conv[0]);
        this_ptr[B] = static_cast<T2>(conv[1]);
        this_ptr[C] = static_cast<T2>(conv[2]);
        return *this;
      }
    };

#pragma endregion Vec3Proxy

#pragma region Vec4Proxy

    template<typename T, unsigned A, unsigned B, unsigned C, unsigned D>
    struct VecProxy<T, A, B, C, D>
    {
      template<typename T2, unsigned A2, unsigned B2, unsigned C2, unsigned D2>
      VecProxy<T, A, B, C, D>& operator= (const VecProxy<T2, A2, B2, C2, D2> &rhs)
      {
        static_assert(A != B && A != C && A != D && B != C && B != D && C != D, "Cannot write to this component.");
        const T2* rhs_ptr = reinterpret_cast<const T2*>(&rhs);
        T* this_ptr = reinterpret_cast<T*>(this);
        this_ptr[A] = rhs_ptr[A2];
        this_ptr[B] = rhs_ptr[B2];
        this_ptr[C] = rhs_ptr[C2];
        this_ptr[D] = rhs_ptr[D2];
        return *this;
      }

      template<typename T2, template <typename, unsigned> class ArrayType>
      VecProxy<T, A, B, C, D>& operator= (const ArrayType<T2, 4> &conv)
      {
        static_assert(A != B && A != C && A != D && B != C && B != D && C != D, "Cannot write to this component.");
        T*  this_ptr = reinterpret_cast<T*>(this);
        this_ptr[A] = static_cast<T2>(conv[0]);
        this_ptr[B] = static_cast<T2>(conv[1]);
        this_ptr[C] = static_cast<T2>(conv[2]);
        this_ptr[D] = static_cast<T2>(conv[3]);
        return *this;
      }
    };

#pragma endregion Vec4Proxy

  }
}