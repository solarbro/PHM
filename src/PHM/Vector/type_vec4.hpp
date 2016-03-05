/******************************************************************************/
/*!
\filxe  type_vec4.hpp
\author Sagnik Chowdhury
\brief  typedefs for common size 4 vectors
*/
/******************************************************************************/

#pragma once
#include "type_vec.hpp"

namespace phm
{
  typedef type_vec<bool, 4>           bvec4;
  typedef type_vec<short, 4>          svec4;
  typedef type_vec<unsigned short, 4> usvec4;
  typedef type_vec<int, 4>            ivec4;
  typedef type_vec<unsigned int, 4>   uivec4;
  typedef type_vec<float, 4>          vec4;
  typedef type_vec<double, 4>         dvec4;
}