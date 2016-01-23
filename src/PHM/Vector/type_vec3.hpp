/******************************************************************************/
/*!
\filxe  type_vec3.hpp
\author Sagnik Chowdhury
\par    Course: GAM300
\brief  Contains the Photon renderer math library
*/
/******************************************************************************/

#pragma once
#include "type_vec2.hpp"

namespace phm
{
  /*****************************************************************
  *        vec3
  *        - ctor(float*)
  *        - ctor(float)
  *        - ctor(float, float)
  *        - ctor(vec2)
  *        - operator +, +=, -, -=, *, *=
  *        - operator []
  *        - normalize (no return, normalizes internally)
  *****************************************************************/

  template<class T>
  class type_vec<T, 3>
  {
  public:

    /*************************************
    *              SWIZZLE               *
    *************************************/
    T&                      x()       { return XY.x(); }
    const T&                x() const { return XY.x(); }
    T&                      y()       { return XY.y(); }
    const T&                y() const { return XY.y(); }
    T&                      z()       { return Z; }
    const T&                z() const { return Z; }
    type_vec<T,2>          xx() const { return XY.xx(); }
    type_vec<T,2>&         xy()       { return XY; }
    const type_vec<T,2>&   xy() const { return XY; }
    type_vec<T,2>          xz() const { return type_vec2<T>(x(), Z); }
    type_vec<T,2>          yx() const { return XY.yx(); }
    type_vec<T,2>          yy() const { return XY.yy(); }
    type_vec<T,2>          yz() const { return type_vec<T,2>(y(), Z); }
    type_vec<T,2>          zx() const { return type_vec<T,2>(Z, x()); }
    type_vec<T,2>          zy() const { return type_vec<T,2>(Z, y()); }
    type_vec<T,2>          zz() const { return type_vec<T,2>(Z); }
    type_vec<T,3>         xxx() const { return type_vec<T,3>(x()); }
    type_vec<T,3>         xxy() const { return type_vec<T,3>(xx(), y()); }
    type_vec<T,3>         xxz() const { return type_vec<T,3>(xx(), Z); }
    type_vec<T,3>         xyx() const { return type_vec<T,3>(XY, x()); }
    type_vec<T,3>         xyy() const { return type_vec<T,3>(XY, y()); }
    type_vec<T,3>&        xyz()       { return *this; }
    const type_vec<T,3>&  xyz() const { return *this; }
    type_vec<T,3>         xzx() const { return type_vec<T,3>(x(), Z, x()); }
    type_vec<T,3>         xzy() const { return type_vec<T,3>(x(), Z, y()); }
    type_vec<T,3>         xzz() const { return type_vec<T,3>(x(), Z, Z); }
    type_vec<T,3>         yxx() const { return type_vec<T,3>(yx(), x()); }
    type_vec<T,3>         yxy() const { return type_vec<T,3>(yx(), y()); }
    type_vec<T,3>         yxz() const { return type_vec<T,3>(yx(), Z); }
    type_vec<T,3>         yyx() const { return type_vec<T,3>(yy(), x()); }
    type_vec<T,3>         yyy() const { return type_vec<T,3>(y()); }
    type_vec<T,3>         yyz() const { return type_vec<T,3>(yy(), Z); }
    type_vec<T,3>         yzx() const { return type_vec<T,3>(yz(), x()); }
    type_vec<T,3>         yzy() const { return type_vec<T,3>(yz(), y()); }
    type_vec<T,3>         yzz() const { return type_vec<T,3>(yz(), Z); }
    type_vec<T,3>         zxx() const { return type_vec<T,3>(zx(), x()); }
    type_vec<T,3>         zxy() const { return type_vec<T,3>(zx(), y()); }
    type_vec<T,3>         zxz() const { return type_vec<T,3>(zx(), z()); }
    type_vec<T,3>         zyx() const { return type_vec<T,3>(zy(), x()); }
    type_vec<T,3>         zyy() const { return type_vec<T,3>(zy(), y()); }
    type_vec<T,3>         zyz() const { return type_vec<T,3>(zy(), Z); }
    type_vec<T,3>         zzx() const { return type_vec<T,3>(zz(), x()); }
    type_vec<T,3>         zzy() const { return type_vec<T,3>(zz(), y()); }
    type_vec<T,3>         zzz() const { return type_vec<T,3>(Z); }

    T&                      r()       { return x(); }
    const T&                r() const { return x(); }
    T&                      g()       { return y(); }
    const T&                g() const { return y(); }
    T&                      b()       { return Z; }
    const T&                b() const { return Z; }
    type_vec<T,2>          rr() const { return xx(); }
    type_vec<T,2>&         rg()       { return XY; }
    const type_vec<T,2>&   rg() const { return XY; }
    type_vec<T,2>          rb() const { return xz(); }
    type_vec<T,2>          gr() const { return yx(); }
    type_vec<T,2>          gg() const { return yy(); }
    type_vec<T,2>          gb() const { return yz(); }
    type_vec<T,2>          br() const { return zx(); }
    type_vec<T,2>          bg() const { return zy(); }
    type_vec<T,2>          bb() const { return zz(); }
    type_vec<T,3>         rrr() const { return xxx(); }
    type_vec<T,3>         rrg() const { return xxy(); }
    type_vec<T,3>         rrb() const { return xxz(); }
    type_vec<T,3>         rgr() const { return xyx(); }
    type_vec<T,3>         rgg() const { return xyy(); }
    type_vec<T,3>&        rgb()       { return xyz(); }
    const type_vec<T,3>&  rgb() const { return xyz(); }
    type_vec<T,2>         rbr() const { return xzx(); }
    type_vec<T,2>         rbg() const { return xzy(); }
    type_vec<T,2>         rbb() const { return xzz(); }
    type_vec<T,2>         grr() const { return yxx(); }
    type_vec<T,2>         grg() const { return yxy(); }
    type_vec<T,2>         grb() const { return yxz(); }
    type_vec<T,2>         ggr() const { return yyx(); }
    type_vec<T,2>         ggg() const { return yyy(); }
    type_vec<T,2>         ggb() const { return yyz(); }
    type_vec<T,2>         gbr() const { return yzx(); }
    type_vec<T,2>         gbg() const { return yzy(); }
    type_vec<T,2>         gbb() const { return yzz(); }
    type_vec<T,2>         brr() const { return zxx(); }
    type_vec<T,2>         brg() const { return zxy(); }
    type_vec<T,2>         brb() const { return zxz(); }
    type_vec<T,2>         bgr() const { return zyx(); }
    type_vec<T,2>         bgg() const { return zyy(); }
    type_vec<T,2>         bgb() const { return zyz(); }
    type_vec<T,2>         bbr() const { return zzx(); }
    type_vec<T,2>         bbg() const { return zzy(); }
    type_vec<T,2>         bbb() const { return zzz(); }

    /*************************************
    *               CTORS                *
    *************************************/
    type_vec() :
      XY(), Z(static_cast<T>(0.0)){}

    template<typename T2>
    type_vec(T2 init) :
      XY(init), Z(static_cast<T>(init)){}

    template<typename T2>
    type_vec(T2* init) :
      XY(init), Z(static_cast<T>(init[2])){}

    template<typename T2>
    type_vec(const T2 &init_x, const T2 &init_y, const T2 &init_z) :
      XY(init_x, init_y), Z(static_cast<T>(init_z)){}

    template<typename T2>
    type_vec(const type_vec<T2, 2> &v, T2 f) :
      XY(v), Z(static_cast<T>(f)){}

    template<typename T2>
    type_vec(const type_vec<T2,3> &v) :
      XY(v.XY), Z(static_cast<T>(v.Z)){}

    /*************************************
    *             OPERATORS              *
    *************************************/

    template<typename T2>
    type_vec<T, 3>& operator= (const type_vec<T2, 3> &v)
    {
      XY = v.XY; Z = static_cast<T>(v.Z);
      return *this;
    }

    T operator[] (unsigned i) const
    {
      return *(&(XY.x()) + i);
    }

    T& operator[] (unsigned i)
    {
      return *(&(XY.x()) + i);
    }


  private:

    type_vec<T,2> XY;
    T Z;

  };


  typedef type_vec<bool, 3> bvec3;
  typedef type_vec<short, 3> svec3;
  typedef type_vec<unsigned short, 3> usvec3;
  typedef type_vec<int, 3> ivec3;
  typedef type_vec<unsigned int, 3> uivec3;
  typedef type_vec<float, 3> vec3;
  typedef type_vec<double, 3> dvec3;

  /*      =============================================
  *                       Functions
  *       =============================================
  *
  *       cross(v1, v2)
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

}