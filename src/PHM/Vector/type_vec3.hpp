/******************************************************************************/
/*!
\filxe  type_vec3.hpp
\author Sagnik Chowdhury
\brief  typedefs for common size 3 vector types, as well as vec3 specific operations
*/
/******************************************************************************/

#pragma once
#include "type_vec.hpp"

namespace phm
{
  typedef type_vec<bool, 3>           bvec3;
  typedef type_vec<short, 3>          svec3;
  typedef type_vec<unsigned short, 3> usvec3;
  typedef type_vec<int, 3>            ivec3;
  typedef type_vec<unsigned int, 3>   uivec3;
  typedef type_vec<float, 3>          vec3;
  typedef type_vec<double, 3>         dvec3;

  /*      =============================================
  *                       Functions
  *       =============================================
  *
  *       cross(v1, v2)
  *       rotateVector(vec, axis, angle)
  */

  template<typename T1, typename T2>
  type_vec<ptype<T1, T2>, 3> cross(const type_vec<T1, 3> &v1, const type_vec<T2, 3> &v2)
  {
    return type_vec<ptype<T1, T2>, 3>(
      static_cast<ptype<T1, T2>>(v1[1] * v2[2] - v1[2] * v2[1]),
      static_cast<ptype<T1, T2>>(v1[2] * v2[0] - v1[0] * v2[2]),
      static_cast<ptype<T1, T2>>(v1[0] * v2[1] - v1[1] * v2[0])
      );
  }

  template<typename T1, typename T2, typename T3>
  type_vec<ptype<T1, T2>, 3> rotateVector(const type_vec<T1, 3> &v, const type_vec<T2, 3> &axis, T3 angle)
  {
    type_vec<T2, 3> n = normalize(axis);
    T3 cs = cos(angle);
    T3 sn = sin(angle);
    type_vec<ptype<T1, T2, T3>, 3> res = v * cs + cross(n, v) * sn + dot(n, v) * (1.0 - cs) * n;
    return res;
  }
  
}