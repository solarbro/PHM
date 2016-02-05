/******************************************************************************/
/*!
\filxe  vector_swizzle_proxy.hpp
\author Sagnik Chowdhury
\brief  Contains the Photon renderer math library
*/
/******************************************************************************/
#include "vector_conversion_proxy.hpp"

namespace phm
{
  namespace swizzle
  {

#pragma region Vec1Proxy

    template<typename T, unsigned A>
    struct Vec1Proxy
    {
      operator T()
      {
        return static_cast<T>(reinterpret_cast<T*>(this)[A]);
      }

      template<typename T2, unsigned A2>
      Vec1Proxy<T, A>& operator= (const Vec1Proxy<T2, A2> &rhs)
      {
        reinterpret_cast<T*>(this)[A] = reinterpret_cast<const T2*>(&rhs)[A2];
        return *this;
      }
    };

#pragma endregion Vec1Proxy

#pragma region Vec2Proxy

    template<typename T, unsigned A, unsigned B>
    struct Vec2Proxy
    {
      template<typename T2, unsigned A2, unsigned B2>
      Vec2Proxy<T, A, B>& operator= (const Vec2Proxy<T2, A2, B2> &rhs)
      {
        static_assert(A != B, "Cannot write to this component.");
        const T2* rhs_ptr = reinterpret_cast<const T2*>(&rhs);
        T*  this_ptr = reinterpret_cast<T*>(this);
        this_ptr[A] = rhs_ptr[A2];
        this_ptr[B] = rhs_ptr[B2];
        return *this;
      }

      Vec2Proxy<T, A, B>& operator= (const conversion_proxy<T, 2> &conv)
      {
        static_assert(A != B, "Cannot write to this component.");
        T*  this_ptr = reinterpret_cast<T*>(this);
        this_ptr[A] = conv[0];
        this_ptr[B] = conv[1];
        return *this;
      }
    };

#pragma endregion Vec2Proxy

#pragma region Vec3Proxy

    template<typename T, unsigned A, unsigned B, unsigned C>
    struct Vec3Proxy
    {
      template<typename T2, unsigned A2, unsigned B2, unsigned C2>
      Vec3Proxy<T, A, B, C>& operator= (const Vec3Proxy<T2, A2, B2, C2> &rhs)
      {
        static_assert(A != B && A != C && B != C, "Cannot write to this component.");
        T2* rhs_ptr = reinterpret_cast<T2*>(&rhs);
        T* this_ptr = reinterpret_cast<T*>(this);
        this_ptr[A] = rhs_ptr[A2];
        this_ptr[B] = rhs_ptr[B2];
        this_ptr[C] = rhs_ptr[C2];
        return *this;
      }
    };

#pragma endregion Vec3Proxy

#pragma region Vec4Proxy

    template<typename T, unsigned A, unsigned B, unsigned C, unsigned D>
    struct Vec4Proxy
    {
      template<typename T2, unsigned A2, unsigned B2, unsigned C2, unsigned D2>
      Vec4Proxy<T, A, B, C, D>& operator= (const Vec4Proxy<T2, A2, B2, C2, D2> &rhs)
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
    };

#pragma endregion Vec4Proxy

  }
}