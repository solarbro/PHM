/******************************************************************************/
/*!
\filxe  phm.hpp
\author Sagnik Chowdhury
\par    Course: GAM300
\brief  Contains the Photon renderer math library
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

  mat4 rotate(float angle, const vec3 &axis)
  {
    return mat4();
  }

  mat4 rotate(float angle, float axis_x, float axis_y, float axis_z)
  {
    return mat4();
  }

  mat4 rotateX(float angle)
  {
    float cosa = cosf(angle);
    float sina = sinf(angle);
    return mat4(
      vec4(1.f, 0.f, 0.f, 0.f),
      vec4(0.f, cosa, sina, 0.f),
      vec4(0.f, -sina, cosa, 0.f),
      vec4(0.f, 0.f, 0.f, 1.f));
  }

  mat4 rotateY(float angle)
  {
    float cosa = cosf(angle);
    float sina = sinf(angle);
    return mat4(
      vec4(cosa, 0.f, -sina, 0.f),
      vec4(0.f, 1.f, 0.f, 0.f),
      vec4(sina, 0.f, cosa, 0.f),
      vec4(0.f, 0.f, 0.f, 1.f));
  }

  mat4 rotateZ(float angle)
  {
    float cosa = cosf(angle);
    float sina = sinf(angle);
    return mat4(
      vec4(cosa, sina, 0.f, 0.f),
      vec4(-sina, cosa, 0.f, 0.f),
      vec4(0.f, 0.f, 1.f, 0.f),
      vec4(0.f, 0.f, 0.f, 1.f));
  }

  mat4 rotateXYZ(float x, float y, float z)
  {
    return rotateZ(z) * rotateY(y) * rotateX(x);
  }

  mat4 rotateXZY(float x, float y, float z)
  {
    return rotateY(y) * rotateZ(z) * rotateX(x);
  }

  mat4 rotateYXZ(float x, float y, float z)
  {
    return rotateZ(z) * rotateX(x) * rotateY(y);
  }

  mat4 rotateYZX(float x, float y, float z)
  {
    return rotateX(x) * rotateZ(z) * rotateY(y);
  }

  mat4 rotateZXY(float x, float y, float z)
  {
    return rotateY(y) * rotateX(x) * rotateZ(z);
  }

  mat4 rotateZYX(float x, float y, float z)
  {
    return rotateX(x) * rotateY(y) * rotateZ(z);
  }

  mat4 translate(float x, float y, float z)
  {
    return translate(vec3(x, y, z));
  }

  mat4 translate(const vec2 &d)
  {
    return translate(vec3(d, 0.f));
  }

  mat4 translate(const vec3 &d)
  {
    mat4 res;
    res[3] = vec4(d, 1.f);
    return res;
  }

}