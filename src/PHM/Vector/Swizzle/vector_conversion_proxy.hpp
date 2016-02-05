/******************************************************************************/
/*!
\filxe  vector_conversion_proxy.hpp
\author Sagnik Chowdhury
\brief  Contains the Photon renderer math library
*/
/******************************************************************************/
#pragma once

#include <string>

namespace phm
{
  namespace swizzle
  {
#define CONVERSION_PROXY                                                    \
  operator swizzle::conversion_proxy<T>()                                   \
  {                                                                         \
    swizzle::conversion_proxy<T> proxy(reinterpret_cast<const T*>(this) );  \
    return proxy;                                                           \
  }                                                                         \

    template<typename T>
    struct conversion_proxy
    {
      conversion_proxy(const T* vec) : data(vec) {}

      T operator[](unsigned index) const
      {
        return data[index];
      }

    private:
      const T* data;
    };

  }
}