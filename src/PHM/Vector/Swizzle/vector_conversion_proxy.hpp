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

    template<typename T, unsigned Size>
    struct conversion_proxy
    {

      T operator[](unsigned index) const
      {
        return data[index];
      }

      T data[Size];
    };

  }
}