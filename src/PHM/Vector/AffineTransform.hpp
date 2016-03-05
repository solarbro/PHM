/******************************************************************************/
/*!
\filxe  AffineTransform.hpp
\author Sagnik Chowdhury
\brief  Functions for constructing affine transformation matrices
*/
/******************************************************************************/
#pragma once

#include "type_mat.hpp"

namespace phm
{
  /************************************************************/
  /*      =============================================
  *                       Functions
  *       =============================================
  */

  /*     
  *      mat4      lookat         (eye, centre, up);
  *      mat4      perspective    (fov, aspect, near, far);
  *      mat4      perspectiveInf (fov, aspect, near);
  *      mat4      ortho          (xmin, xmax, ymin, ymax, near, far);
  *      mat4      orthoInf       (xmin, xmax, ymin, ymax, near);
  *      mat4      scale          (float, float = 1, float = 1);
  *      mat4      scale          (vec2);
  *      mat4      scale          (vec3);
  *      mat4      rotate         (float, vec3 = (0, 0, 1));
  *      mat4      translate      (float, float = 0, float = 0);
  *      mat4      translate      (vec3);
  */
  /*************************************************************/
  template<typename T1, typename T2, typename T3, Major major = Major::COL>
  tmat4<ptype<T1, T2, T3>, major> lookat(const type_vec<T1, 3> &eye, const type_vec<T2, 3> &centre, const type_vec<T3, 3> &up)
  {
    type_vec<ptype<T1, T2, T3>, 3> f = normalize(centre - eye);
    type_vec<ptype<T1, T2, T3>, 3> u = normalize(up);
    type_vec<ptype<T1, T2, T3>, 3> s = normalize(cross(f, u));
    u = cross(s, f);

    tmat4<ptype<T1, T2, T3>, major> Result;
    Result[0][0] = s.x();
    Result[1][0] = s.y();
    Result[2][0] = s.z();
    Result[0][1] = u.x();
    Result[1][1] = u.y();
    Result[2][1] = u.z();
    Result[0][2] = -f.x();
    Result[1][2] = -f.y();
    Result[2][2] = -f.z();
    Result[3][0] = -dot(s, eye);
    Result[3][1] = -dot(u, eye);
    Result[3][2] = dot(f, eye);
    return Result;
  }

  template<typename T1, typename T2, typename T3, typename T4, Major major = Major::COL>
  tmat4<ptype<T1, T2, T3, T4>, major> perspective(T1 fovy, T2 aspect, T3 near, T4 far)
  {
    //assert(abs(aspect - std::numeric_limits<float>::epsilon()) > static_cast<ptype<T1, T2, T3, T4>>(0));

    ptype<T1, T2, T3> const tanHalfFovy = tan(fovy * static_cast<ptype<T1, T2, T3>>(0.5));

    tmat4<ptype<T1, T2, T3, T4>, major> Result(0.f);
    Result[0][0] = static_cast<ptype<T1, T2, T3>>(1.0) / (aspect * tanHalfFovy);
    Result[1][1] = static_cast<ptype<T1, T2, T3>>(1.0) / (tanHalfFovy);
    Result[2][2] = static_cast<ptype<T1, T2, T3>>(-(far + near) / (far - near));
    Result[2][3] = static_cast<ptype<T1, T2, T3>>(-1.0);
    Result[3][2] = static_cast<ptype<T1, T2, T3>>(-(2.f * far * near) / (far - near));
    return Result;
  }

  template<typename T1, typename T2, typename T3, Major major = Major::COL>
  tmat4<ptype<T1, T2, T3>, major> perspectiveInf(T1 fovy, T2 aspect, T3 near)
  {
    double const tanHalfFovy = tan(fovy * 0.5);

    tmat4<ptype<T1, T2, T3>, major> Result(0.0);
    Result[0][0] = static_cast<ptype<T1, T2, T3>>(1.0 / (aspect * tanHalfFovy));
    Result[1][1] = static_cast<ptype<T1, T2, T3>>(1.0 / (tanHalfFovy));
    Result[2][2] = static_cast<ptype<T1, T2, T3>>(-1.0);
    Result[2][3] = static_cast<ptype<T1, T2, T3>>(-1.0);
    Result[3][2] = static_cast<ptype<T1, T2, T3>>(-(2.0 * near));
    return Result;
  }

  template<typename T1, typename T2, typename T3, typename T4, typename T5, typename T6, Major major = Major::COL>
  tmat4<ptype<T1, T2, T3, T4, T5, T6>, major> ortho(T1 left, T2 right, T3 bottom, T4 top, T5 zNear, T6 zFar)
  {
    tmat4<ptype<T1, T2, T3, T4, T5, T6>, major> Result(1.0);
    Result[0][0] = static_cast<ptype<T1, T2, T3, T4, T5, T6>>(2.0 / (right - left));
    Result[1][1] = static_cast<ptype<T1, T2, T3, T4, T5, T6>>(2.0 / (top - bottom));
    Result[2][2] = static_cast<ptype<T1, T2, T3, T4, T5, T6>>(-2.0 / (zFar - zNear));
    Result[3][0] = static_cast<ptype<T1, T2, T3, T4, T5, T6>>(-(right + left) / (right - left));
    Result[3][1] = static_cast<ptype<T1, T2, T3, T4, T5, T6>>(-(top + bottom) / (top - bottom));
    Result[3][2] = static_cast<ptype<T1, T2, T3, T4, T5, T6>>(-(zFar + zNear) / (zFar - zNear));
    return Result;
  }

  template<typename T1, typename T2, typename T3, typename T4, Major major = Major::COL>
  tmat4<ptype<T1, T2, T3, T4>, major> orthoInf(T1 left, T2 right, T3 bottom, T4 top)
  {
    tmat4<ptype<T1, T2, T3, T4>, major> Result(1.0);
    Result[0][0] = static_cast<ptype<T1, T2, T3, T4>>(2.0 / (right - left));
    Result[1][1] = static_cast<ptype<T1, T2, T3, T4>>(2.0 / (top - bottom));
    Result[2][2] = static_cast<ptype<T1, T2, T3, T4>>(0.0);
    Result[3][0] = static_cast<ptype<T1, T2, T3, T4>>(-(right + left) / (right - left));
    Result[3][1] = static_cast<ptype<T1, T2, T3, T4>>(-(top + bottom) / (top - bottom));
    Result[3][2] = static_cast<ptype<T1, T2, T3, T4>>(-1.0);
    return Result;
  }

  template<typename T, Major major = Major::COL>
  tmat4<T, major> scale(T s)
  {
    return scale(s, s, s);
  }

  template<typename T1, typename T2, typename T3, Major major = Major::COL>
  tmat4<ptype<T1, T2, T3>, major> scale(T1 x, T2 y, T3 z)
  {
    return scale(type_vec<ptype<T1, T2, T3>, 3>(x, y, z));
  }

  template<typename T, Major major = Major::COL>
  tmat4<T, major> scale(const type_vec<T, 2> &scale_vec)
  {
    return scale(type_vec<T, 3>(scale_vec, 1.0));
  }

  template<typename T, Major major = Major::COL>
  tmat4<T, major> scale(const type_vec<T, 3> &scale_vec)
  {
    return tmat4<T, major>(
      type_vec<T, 4>(scale_vec.x(), 0.0, 0.0, 0.0),
      type_vec<T, 4>(0.0, scale_vec.y(), 0.0, 0.0),
      type_vec<T, 4>(0.0, 0.0, scale_vec.z(), 0.0),
      type_vec<T, 4>(0.0, 0.0, 0.0, 1.0));
  }

  template<typename T1, typename T2>
  tmat4<std::common_type_t<T1, T2>, Major::COL> rotate(T1 angle, const type_vec<T2, 3> &axis)
  {
    T1 c = std::cos(angle);
    T1 s = std::sin(angle);
    T1 t = 1 - c;
    type_vec<T2, 3> n_axis = normalize(axis);

    tmat4<std::common_type_t<T1, T2>, Major::COL> m;
    m[0][0] = t * x * x + c;
    m[0][1] = t * x * y + z * s;
    m[0][2] = t * x * z - y * s;
    m[1][0] = t * x * y - z * s;
    m[1][1] = t * y * y + c;
    m[1][2] = t * y * z + x * s;
    m[2][0] = t * x * z + y * s;
    m[2][1] = t * y * z - x * s;
    m[2][2] = t * z * z + c;

    return m;
  }

  template<typename T1, typename T2, typename T3, typename T4>
  tmat4<std::common_type_t<T1, T2, T3, T4>, Major::COL> rotate(T1 angle, T2 axis_x, T3 axis_y, T4 axis_z)
  {
    return rotate(angle, type_vec<std::common_type_t<T2, T3, T4>, 3>(axis_x, axis_y, axis_z));
  }

  template<typename T, Major major = Major::COL>
  tmat4<T, major> rotateX(T angle)
  {
    T cosa = std::cos(angle);
    T sina = std::sin(angle);
    return tmat4<T, major>(
      type_vec<T, 4>(1.f, 0.f, 0.f, 0.f),
      type_vec<T, 4>(0.f, cosa, sina, 0.f),
      type_vec<T, 4>(0.f, -sina, cosa, 0.f),
      type_vec<T, 4>(0.f, 0.f, 0.f, 1.f));
  }

  template<typename T, Major major = Major::COL>
  tmat4<T, major> rotateY(T angle)
  {
    T cosa = std::cos(angle);
    T sina = std::sin(angle);
    return tmat4<T, major>(
      type_vec<T, 4>(cosa, 0.f, -sina, 0.f),
      type_vec<T, 4>(0.f, 1.f, 0.f, 0.f),
      type_vec<T, 4>(sina, 0.f, cosa, 0.f),
      type_vec<T, 4>(0.f, 0.f, 0.f, 1.f));
  }

  template<typename T, Major major = Major::COL>
  tmat4<T, major> rotateZ(T angle)
  {
    T cosa = cosf(angle);
    T sina = sinf(angle);
    return tmat4<T, major>(
      type_vec<T, 4>(cosa, sina, 0.f, 0.f),
      type_vec<T, 4>(-sina, cosa, 0.f, 0.f),
      type_vec<T, 4>(0.f, 0.f, 1.f, 0.f),
      type_vec<T, 4>(0.f, 0.f, 0.f, 1.f));
  }

  template<typename T1, typename T2, typename T3, Major major = Major::COL>
  tmat4<std::common_type_t<T1, T2, T3>, major> rotateXYZ(T1 x, T2 y, T3 z)
  {
    return rotateZ(z) * rotateY(y) * rotateX(x);
  }

  template<typename T1, typename T2, typename T3, Major major = Major::COL>
  tmat4<std::common_type_t<T1, T2, T3>, major> rotateXZY(T1 x, T2 y, T3 z)
  {
    return rotateY(y) * rotateZ(z) * rotateX(x);
  }

  template<typename T1, typename T2, typename T3, Major major = Major::COL>
  tmat4<std::common_type_t<T1, T2, T3>, major> rotateYXZ(T1 x, T2 y, T3 z)
  {
    return rotateZ(z) * rotateX(x) * rotateY(y);
  }

  template<typename T1, typename T2, typename T3, Major major = Major::COL>
  tmat4<std::common_type_t<T1, T2, T3>, major> rotateYZX(T1 x, T2 y, T3 z)
  {
    return rotateX(x) * rotateZ(z) * rotateY(y);
  }

  template<typename T1, typename T2, typename T3, Major major = Major::COL>
  tmat4<std::common_type_t<T1, T2, T3>, major> rotateZXY(T1 x, T2 y, T3 z)
  {
    return rotateY(y) * rotateX(x) * rotateZ(z);
  }

  template<typename T1, typename T2, typename T3, Major major = Major::COL>
  tmat4<std::common_type_t<T1, T2, T3>, major> rotateZYX(T1 x, T2 y, T3 z)
  {
    return rotateX(x) * rotateY(y) * rotateZ(z);
  }

  template<typename T1, typename T2, typename T3, Major major = Major::COL>
  tmat4<std::common_type_t<T1, T2, T3>, major> translate(T1 x, T2 y, T3 z)
  {
    return translate(type_vec<std::common_type_t<T1, T2, T3>, 3>(x, y, z));
  }

  template<typename T, Major major = Major::COL>
  tmat4<T, major> translate(const type_vec<T, 2> &d)
  {
    return translate(type_vec<T, 3>(d, 0.0));
  }

  template<typename T, Major major = Major::COL>
  tmat4<T, major> translate(const type_vec<T, 3> &d)
  {
    tmat4<T, major> res;
    res[3] = vec4(d, 1.0);
    return res;
  }

}