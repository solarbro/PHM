/******************************************************************************/
/*!
\filxe  phm.hpp
\author Sagnik Chowdhury
\par    Course: GAM300
\brief  Contains the Photon renderer math library
*/
/******************************************************************************/
#pragma once

#include <iostream>
#include <cmath>
#include <cstdlib>
#include <limits>

#include "type_vec2.hpp"
#include "type_vec3.hpp"
#include "type_vec4.hpp"
#include "type_mat.hpp"

namespace phm
{

/******************************************************************************
*      =============================================
*                 Photon Math library
*      =============================================
*******************************************************************************/  

  float to_radians(float angle);
  float to_degrees(float angle);
  
  /*
  *     =============================================
  *                       CONSTANTS
  *     =============================================
  */

  static const float pi         = 3.14159265358f;
  static const float pi_over_2  = 1.57079632679f;
  static const float pi_times_2 = 6.28318530718f;
  static const float epsilon    = std::numeric_limits<float>::epsilon();
  
  static const float radians_per_degree = 0.0174532925f;
  static const float degrees_per_radian = 57.2957795f;


  /************************************************************/
/*      =============================================
*                       Functions
*       =============================================
*/

/*     float     dot         (vec2/3/4, vec2/3/4);
*      vec3      cross       (vec3, vec3);
*      vec2/3/4  normalize   (vec2/3/4);
*
*      mat4      lookat      (eye, centre, up);
*      mat4      perspective (fov, aspect, near, far);
*
*      mat2/3/4  transpose   (mat2/3/4);
*
*      mat4      scale       (float, float = 1, float = 1);
*      mat4      scale       (vec2);
*      mat4      scale       (vec3);
*      mat4      rotate      (float, vec3 = (0, 0, 1));
*      mat4      translate   (float, float = 0, float = 0);
*      mat4      identity    ()
*/
  /*************************************************************/

  vec3 cross(const vec3 &v1, const vec3 &v2);

  mat4 lookat(const vec3 &eye, const vec3 &centre, const vec3 &up);
  mat4 perspective(float fov, float aspect, float near_plane, float far_plane);
  mat4 perspectiveInf(float fov, float aspect, float near_plane);
  mat4 ortho(float left, float right, float bottom, float top, float zNear, float zFar);
  mat4 orthoInf(float left, float right, float bottom, float top);

  mat4 scale(float s);
  mat4 scale(float x, float y, float z = 1.f);
  mat4 scale(const vec2 &scale_vec);
  mat4 scale(const vec3 &scale_vec);
  
  mat4 rotate(float angle, const vec3 &axis = vec3(0, 0, 1));
  mat4 rotate(float angle, float axis_x, float axis_y, float axis_z);
  
  mat4 rotateX(float angle);
  mat4 rotateY(float angle);
  mat4 rotateZ(float angle);

  mat4 rotateXYZ(float x, float y, float z);
  mat4 rotateXZY(float x, float y, float z);
  mat4 rotateYXZ(float x, float y, float z);
  mat4 rotateYZX(float x, float y, float z);
  mat4 rotateZXY(float x, float y, float z);
  mat4 rotateZYX(float x, float y, float z);

  mat4 translate(float x, float y = 0.f, float z = 0.f);
  mat4 translate(const vec2 &d);
  mat4 translate(const vec3 &d);
  mat4 I();

  template<typename T>
  type_vec<T, 3> rotate(const type_vec<T, 3> &v, const type_vec<T,3> &axis, T angle)
  {
    type_vec<T, 3> n = phm::normalize(axis);
    T cs = cos(angle);
    T sn = sin(angle);
    type_vec<T, 3> res = v * cs + phm::cross(n, v) * sn + phm::dot(n, v) * (1 - cs) * n;
    return res;
  }


  template<typename T>
  float* value_ptr(const T& val)
  {
    return reinterpret_cast<float*>(const_cast<T *>(&val));
  }

  phm::vec3 rotateVector(const phm::vec3 &v, const phm::vec3 &axis, float angle);

  /*
  * Get a vec4 containing the homogenous representation of a half space.
  * The dividing plane is defined by a normal and a point. 
  */
  vec4 plane(const vec3 &normal, const vec3 &point);

  /*
  * Get a vec4 containing the homogenous representation of a half space.
  * The dividing plane is defined by 3 points that it passes through and
  * a point that is to be in the "inner" space.
  */
  vec4 plane(const vec3 &point1, const vec3 &point2, const vec3 &point3, const vec3 &inner_point);

  template <typename T>
  T linearRand(const T& Min, const T& Max)
  {
    return (float)(std::rand()) / (float)(RAND_MAX)* (Max - Min) + Min;
  }

  template <typename T>
  T mix(const T& Min, const T& Max, float Ammount)
  {
    return Min + Ammount * (Max - Min);
  }

}