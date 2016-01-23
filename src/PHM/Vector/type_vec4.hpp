/******************************************************************************/
/*!
\filxe  type_vec3.hpp
\author Sagnik Chowdhury
\par    Course: GAM300
\brief  Contains the Photon renderer math library
*/
/******************************************************************************/

#pragma once
#include "type_vec3.hpp"

namespace phm
{
  /*****************************************************************
  *        vec4
  *        - ctor(float*)
  *        - ctor(float)
  *        - ctor(float, float)
  *        - ctor(vec2)
  *        - operator +, +=, -, -=, *, *=
  *        - operator []
  *        - normalize (no return, normalizes internally)
  *****************************************************************/

  template<class T>
  class type_vec<T, 4>
  {
  public:

    /*************************************
    *              SWIZZLE               *
    *************************************/
    T&                      x()        { return XYZ.x(); }
    const T&                x()  const { return XYZ.x(); }
    T&                      y()        { return XYZ.y(); }
    const T&                y()  const { return XYZ.y(); }
    T&                      z()        { return XYZ.z(); }
    const T&                z()  const { return XYZ.z(); }
    T&                      w()        { return W; }
    const T&                w()  const { return W; }
    type_vec<T,2>          xx()  const { return XYZ.xx(); }
    type_vec<T,2>&         xy()        { return XYZ.xy(); }
    const type_vec<T,2>&   xy()  const { return XYZ.xy(); }
    type_vec<T,2>          xz()  const { return XYZ.xz(); }
    type_vec<T,2>          xw()  const { return type_vec<T,2>(x(), W); }
    type_vec<T,2>          yx()  const { return XYZ.yx(); }
    type_vec<T,2>          yy()  const { return XYZ.yy(); }
    type_vec<T,2>          yz()  const { return XYZ.yz(); }
    type_vec<T,2>          yw()  const { return type_vec<T,2>(y(), W); }
    type_vec<T,2>          zx()  const { return XYZ.zx(); }
    type_vec<T,2>          zy()  const { return XYZ.zy(); }
    type_vec<T,2>          zz()  const { return XYZ.zz(); }
    type_vec<T,2>          zw()  const { return type_vec<T,2>(z(), W); }
    type_vec<T,2>          wx()  const { return type_vec<T,2>(W, x()); }
    type_vec<T,2>          wy()  const { return type_vec<T,2>(W, y()); }
    type_vec<T,2>          wz()  const { return type_vec<T,2>(W, z()); }
    type_vec<T,2>          ww()  const { return type_vec<T,2>(W); }
    type_vec<T,3>          xxx() const { return XYZ.xxx(); }
    type_vec<T,3>          xxy() const { return XYZ.xxy(); }
    type_vec<T,3>          xxz() const { return XYZ.xxz(); }
    type_vec<T,3>          xxw() const { return type_vec<T,3>(xx(), W); }
    type_vec<T,3>          xyx() const { return XYZ.xyx(); }
    type_vec<T,3>          xyy() const { return XYZ.xyy(); }
    type_vec<T,3>&         xyz()       { return XYZ; }
    const type_vec<T,3>&   xyz() const { return XYZ; }
    type_vec<T,3>          xyw() const { return type_vec<T,3>(xy(), W); }
    type_vec<T,3>          xzx() const { return XYZ.xzx(); }
    type_vec<T,3>          xzy() const { return XYZ.xzy(); }
    type_vec<T,3>          xzz() const { return XYZ.xzz(); }
    type_vec<T,3>          xzw() const { return type_vec<T,3>(xz(), W); }
    type_vec<T,3>          xwx() const { return type_vec<T,3>(xw(), x()); }
    type_vec<T,3>          xwy() const { return type_vec<T,3>(xw(), y()); }
    type_vec<T,3>          xwz() const { return type_vec<T,3>(xw(), z()); }
    type_vec<T,3>          xww() const { return type_vec<T,3>(xw(), W); }
    type_vec<T,3>          yxx() const { return XYZ.yxx(); }
    type_vec<T,3>          yxy() const { return XYZ.yxy(); }
    type_vec<T,3>          yxz() const { return XYZ.yxz(); }
    type_vec<T,3>          yxw() const { return type_vec<T,3>(yx(), W); }
    type_vec<T,3>          yyx() const { return XYZ.yyx(); }
    type_vec<T,3>          yyy() const { return XYZ.yyy(); }
    type_vec<T,3>          yyz() const { return XYZ.yyz(); }
    type_vec<T,3>          yyw() const { return type_vec<T,3>(yy(), W); }
    type_vec<T,3>          yzx() const { return XYZ.yzx(); }
    type_vec<T,3>          yzy() const { return XYZ.yzy(); }
    type_vec<T,3>          yzz() const { return XYZ.yzz(); }
    type_vec<T,3>          yzw() const { return type_vec<T,3>(yz(), W); }
    type_vec<T,3>          ywx() const { return type_vec<T,3>(yw(), x()); }
    type_vec<T,3>          ywy() const { return type_vec<T,3>(yw(), y()); }
    type_vec<T,3>          ywz() const { return type_vec<T,3>(yw(), z()); }
    type_vec<T,3>          yww() const { return type_vec<T,3>(yw(), w()); }
    type_vec<T,3>          zxx() const { return XYZ.zxx(); }
    type_vec<T,3>          zxy() const { return XYZ.zxy(); }
    type_vec<T,3>          zxz() const { return XYZ.zxz(); }
    type_vec<T,3>          zxw() const { return type_vec<T,3>(zx(), W); }
    type_vec<T,3>          zyx() const { return XYZ.zyx(); }
    type_vec<T,3>          zyy() const { return XYZ.zyy(); }
    type_vec<T,3>          zyz() const { return XYZ.zyz(); }
    type_vec<T,3>          zyw() const { return type_vec<T,3>(zy(), W); }
    type_vec<T,3>          zzx() const { return XYZ.zzx(); }
    type_vec<T,3>          zzy() const { return XYZ.zzy(); }
    type_vec<T,3>          zzz() const { return XYZ.zzz(); }
    type_vec<T,3>          zzw() const { return type_vec<T,3>(zz(), W); }
    type_vec<T,3>          zwx() const { return type_vec<T,3>(zw(), x()); }
    type_vec<T,3>          zwy() const { return type_vec<T,3>(zw(), y()); }
    type_vec<T,3>          zwz() const { return type_vec<T,3>(zw(), z()); }
    type_vec<T,3>          zww() const { return type_vec<T,3>(zw(), W); }
    type_vec<T,3>          wxx() const { return type_vec<T,3>(wx(), x()); }
    type_vec<T,3>          wxy() const { return type_vec<T,3>(wx(), y()); }
    type_vec<T,3>          wxz() const { return type_vec<T,3>(wx(), z()); }
    type_vec<T,3>          wxw() const { return type_vec<T,3>(wx(), W); }
    type_vec<T,3>          wyx() const { return type_vec<T,3>(wy(), x()); }
    type_vec<T,3>          wyy() const { return type_vec<T,3>(wy(), y()); }
    type_vec<T,3>          wyz() const { return type_vec<T,3>(wy(), z()); }
    type_vec<T,3>          wyw() const { return type_vec<T,3>(wy(), W); }
    type_vec<T,3>          wzx() const { return type_vec<T,3>(wz(), x()); }
    type_vec<T,3>          wzy() const { return type_vec<T,3>(wz(), y()); }
    type_vec<T,3>          wzz() const { return type_vec<T,3>(wz(), z()); }
    type_vec<T,3>          wzw() const { return type_vec<T,3>(wz(), W); }
    type_vec<T,3>          wwx() const { return type_vec<T,3>(ww(), x()); }
    type_vec<T,3>          wwy() const { return type_vec<T,3>(ww(), y()); }
    type_vec<T,3>          wwz() const { return type_vec<T,3>(ww(), z()); }
    type_vec<T,3>          www() const { return type_vec<T,3>(W); }
    type_vec<T, 4>         xxxx() const { return type_vec<T, 4>(xxx(), x()); }
    type_vec<T, 4>         xxxy() const { return type_vec<T, 4>(xxx(), y()); }
    type_vec<T, 4>         xxxz() const { return type_vec<T, 4>(xxx(), z()); }
    type_vec<T, 4>         xxxw() const { return type_vec<T, 4>(xxx(), w()); }
    type_vec<T, 4>         xxyx() const { return type_vec<T, 4>(xxy(), x()); }
    type_vec<T, 4>         xxyy() const { return type_vec<T, 4>(xxy(), y()); }
    type_vec<T, 4>         xxyz() const { return type_vec<T, 4>(xxy(), z()); }
    type_vec<T, 4>         xxyw() const { return type_vec<T, 4>(xxy(), w()); }
    type_vec<T, 4>         xxzx() const { return type_vec<T, 4>(xxz(), x()); }
    type_vec<T, 4>         xxzy() const { return type_vec<T, 4>(xxz(), y()); }
    type_vec<T, 4>         xxzz() const { return type_vec<T, 4>(xxz(), z()); }
    type_vec<T, 4>         xxzw() const { return type_vec<T, 4>(xxz(), w()); }
    type_vec<T, 4>         xxwx() const { return type_vec<T, 4>(xxw(), x()); }
    type_vec<T, 4>         xxwy() const { return type_vec<T, 4>(xxw(), y()); }
    type_vec<T, 4>         xxwz() const { return type_vec<T, 4>(xxw(), z()); }
    type_vec<T, 4>         xxww() const { return type_vec<T, 4>(xxw(), w()); }
    type_vec<T, 4>         xyxx() const { return type_vec<T, 4>(xyx(), x()); }
    type_vec<T, 4>         xyxy() const { return type_vec<T, 4>(xyx(), y()); }
    type_vec<T, 4>         xyxz() const { return type_vec<T, 4>(xyx(), z()); }
    type_vec<T, 4>         xyxw() const { return type_vec<T, 4>(xyx(), w()); }
    type_vec<T, 4>         xyyx() const { return type_vec<T, 4>(xyy(), x()); }
    type_vec<T, 4>         xyyy() const { return type_vec<T, 4>(xyy(), y()); }
    type_vec<T, 4>         xyyz() const { return type_vec<T, 4>(xyy(), z()); }
    type_vec<T, 4>         xyyw() const { return type_vec<T, 4>(xyy(), w()); }
    type_vec<T, 4>         xyzx() const { return type_vec<T, 4>(xyz(), x()); }
    type_vec<T, 4>         xyzy() const { return type_vec<T, 4>(xyz(), y()); }
    type_vec<T, 4>         xyzz() const { return type_vec<T, 4>(xyz(), z()); }
    type_vec<T, 4>&        xyzw()       { return *this; }
    const type_vec<T, 4>&  xyzw() const { return *this; }
    type_vec<T, 4>         xywx() const { return type_vec<T, 4>(xyw(), x()); }
    type_vec<T, 4>         xywy() const { return type_vec<T, 4>(xyw(), y()); }
    type_vec<T, 4>         xywz() const { return type_vec<T, 4>(xyw(), z()); }
    type_vec<T, 4>         xyww() const { return type_vec<T, 4>(xyw(), w()); }
    type_vec<T, 4>         xzxx() const { return type_vec<T, 4>(xzx(), x()); }
    type_vec<T, 4>         xzxy() const { return type_vec<T, 4>(xzx(), y()); }
    type_vec<T, 4>         xzxz() const { return type_vec<T, 4>(xzx(), z()); }
    type_vec<T, 4>         xzxw() const { return type_vec<T, 4>(xzx(), w()); }
    type_vec<T, 4>         xzyx() const { return type_vec<T, 4>(xzy(), x()); }
    type_vec<T, 4>         xzyy() const { return type_vec<T, 4>(xzy(), y()); }
    type_vec<T, 4>         xzyz() const { return type_vec<T, 4>(xzy(), z()); }
    type_vec<T, 4>         xzyw() const { return type_vec<T, 4>(xzy(), w()); }
    type_vec<T, 4>         xzzx() const { return type_vec<T, 4>(xzz(), x()); }
    type_vec<T, 4>         xzzy() const { return type_vec<T, 4>(xzz(), y()); }
    type_vec<T, 4>         xzzz() const { return type_vec<T, 4>(xzz(), z()); }
    type_vec<T, 4>         xzzw() const { return type_vec<T, 4>(xzz(), w()); }
    type_vec<T, 4>         xzwx() const { return type_vec<T, 4>(xzw(), x()); }
    type_vec<T, 4>         xzwy() const { return type_vec<T, 4>(xzw(), y()); }
    type_vec<T, 4>         xzwz() const { return type_vec<T, 4>(xzw(), z()); }
    type_vec<T, 4>         xzww() const { return type_vec<T, 4>(xzw(), w()); }
    type_vec<T, 4>         xwxx() const { return type_vec<T, 4>(xwx(), x()); }
    type_vec<T, 4>         xwxy() const { return type_vec<T, 4>(xwx(), y()); }
    type_vec<T, 4>         xwxz() const { return type_vec<T, 4>(xwx(), z()); }
    type_vec<T, 4>         xwxw() const { return type_vec<T, 4>(xwx(), w()); }
    type_vec<T, 4>         xwyx() const { return type_vec<T, 4>(xwy(), x()); }
    type_vec<T, 4>         xwyy() const { return type_vec<T, 4>(xwy(), y()); }
    type_vec<T, 4>         xwyz() const { return type_vec<T, 4>(xwy(), z()); }
    type_vec<T, 4>         xwyw() const { return type_vec<T, 4>(xwy(), w()); }
    type_vec<T, 4>         xwzx() const { return type_vec<T, 4>(xwz(), x()); }
    type_vec<T, 4>         xwzy() const { return type_vec<T, 4>(xwz(), y()); }
    type_vec<T, 4>         xwzz() const { return type_vec<T, 4>(xwz(), z()); }
    type_vec<T, 4>         xwzw() const { return type_vec<T, 4>(xwz(), w()); }
    type_vec<T, 4>         xwwx() const { return type_vec<T, 4>(xww(), x()); }
    type_vec<T, 4>         xwwy() const { return type_vec<T, 4>(xww(), y()); }
    type_vec<T, 4>         xwwz() const { return type_vec<T, 4>(xww(), z()); }
    type_vec<T, 4>         xwww() const { return type_vec<T, 4>(xww(), w()); }
    type_vec<T, 4>         yxxx() const { return type_vec<T, 4>(yxx(), x()); }
    type_vec<T, 4>         yxxy() const { return type_vec<T, 4>(yxx(), y()); }
    type_vec<T, 4>         yxxz() const { return type_vec<T, 4>(yxx(), z()); }
    type_vec<T, 4>         yxxw() const { return type_vec<T, 4>(yxx(), w()); }
    type_vec<T, 4>         yxyx() const { return type_vec<T, 4>(yxy(), x()); }
    type_vec<T, 4>         yxyy() const { return type_vec<T, 4>(yxy(), y()); }
    type_vec<T, 4>         yxyz() const { return type_vec<T, 4>(yxy(), z()); }
    type_vec<T, 4>         yxyw() const { return type_vec<T, 4>(yxy(), w()); }
    type_vec<T, 4>         yxzx() const { return type_vec<T, 4>(yxz(), x()); }
    type_vec<T, 4>         yxzy() const { return type_vec<T, 4>(yxz(), y()); }
    type_vec<T, 4>         yxzz() const { return type_vec<T, 4>(yxz(), z()); }
    type_vec<T, 4>         yxzw() const { return type_vec<T, 4>(yxz(), w()); }
    type_vec<T, 4>         yxwx() const { return type_vec<T, 4>(yxw(), x()); }
    type_vec<T, 4>         yxwy() const { return type_vec<T, 4>(yxw(), y()); }
    type_vec<T, 4>         yxwz() const { return type_vec<T, 4>(yxw(), z()); }
    type_vec<T, 4>         yxww() const { return type_vec<T, 4>(yxw(), w()); }
    type_vec<T, 4>         yyxx() const { return type_vec<T, 4>(yyx(), x()); }
    type_vec<T, 4>         yyxy() const { return type_vec<T, 4>(yyx(), y()); }
    type_vec<T, 4>         yyxz() const { return type_vec<T, 4>(yyx(), z()); }
    type_vec<T, 4>         yyxw() const { return type_vec<T, 4>(yyx(), w()); }
    type_vec<T, 4>         yyyx() const { return type_vec<T, 4>(yyy(), x()); }
    type_vec<T, 4>         yyyy() const { return type_vec<T, 4>(yyy(), y()); }
    type_vec<T, 4>         yyyz() const { return type_vec<T, 4>(yyy(), z()); }
    type_vec<T, 4>         yyyw() const { return type_vec<T, 4>(yyy(), w()); }
    type_vec<T, 4>         yyzx() const { return type_vec<T, 4>(yyz(), x()); }
    type_vec<T, 4>         yyzy() const { return type_vec<T, 4>(yyz(), y()); }
    type_vec<T, 4>         yyzz() const { return type_vec<T, 4>(yyz(), z()); }
    type_vec<T, 4>         yyzw() const { return type_vec<T, 4>(yyz(), w()); }
    type_vec<T, 4>         yywx() const { return type_vec<T, 4>(yyw(), x()); }
    type_vec<T, 4>         yywy() const { return type_vec<T, 4>(yyw(), y()); }
    type_vec<T, 4>         yywz() const { return type_vec<T, 4>(yyw(), z()); }
    type_vec<T, 4>         yyww() const { return type_vec<T, 4>(yyw(), w()); }
    type_vec<T, 4>         yzxx() const { return type_vec<T, 4>(yzx(), x()); }
    type_vec<T, 4>         yzxy() const { return type_vec<T, 4>(yzx(), y()); }
    type_vec<T, 4>         yzxz() const { return type_vec<T, 4>(yzx(), z()); }
    type_vec<T, 4>         yzxw() const { return type_vec<T, 4>(yzx(), w()); }
    type_vec<T, 4>         yzyx() const { return type_vec<T, 4>(yzy(), x()); }
    type_vec<T, 4>         yzyy() const { return type_vec<T, 4>(yzy(), y()); }
    type_vec<T, 4>         yzyz() const { return type_vec<T, 4>(yzy(), z()); }
    type_vec<T, 4>         yzyw() const { return type_vec<T, 4>(yzy(), w()); }
    type_vec<T, 4>         yzzx() const { return type_vec<T, 4>(yzz(), x()); }
    type_vec<T, 4>         yzzy() const { return type_vec<T, 4>(yzz(), y()); }
    type_vec<T, 4>         yzzz() const { return type_vec<T, 4>(yzz(), z()); }
    type_vec<T, 4>         yzzw() const { return type_vec<T, 4>(yzz(), w()); }
    type_vec<T, 4>         yzwx() const { return type_vec<T, 4>(yzw(), x()); }
    type_vec<T, 4>         yzwy() const { return type_vec<T, 4>(yzw(), y()); }
    type_vec<T, 4>         yzwz() const { return type_vec<T, 4>(yzw(), z()); }
    type_vec<T, 4>         yzww() const { return type_vec<T, 4>(yzw(), w()); }
    type_vec<T, 4>         ywxx() const { return type_vec<T, 4>(ywx(), x()); }
    type_vec<T, 4>         ywxy() const { return type_vec<T, 4>(ywx(), y()); }
    type_vec<T, 4>         ywxz() const { return type_vec<T, 4>(ywx(), z()); }
    type_vec<T, 4>         ywxw() const { return type_vec<T, 4>(ywx(), w()); }
    type_vec<T, 4>         ywyx() const { return type_vec<T, 4>(ywy(), x()); }
    type_vec<T, 4>         ywyy() const { return type_vec<T, 4>(ywy(), y()); }
    type_vec<T, 4>         ywyz() const { return type_vec<T, 4>(ywy(), z()); }
    type_vec<T, 4>         ywyw() const { return type_vec<T, 4>(ywy(), w()); }
    type_vec<T, 4>         ywzx() const { return type_vec<T, 4>(ywz(), x()); }
    type_vec<T, 4>         ywzy() const { return type_vec<T, 4>(ywz(), y()); }
    type_vec<T, 4>         ywzz() const { return type_vec<T, 4>(ywz(), z()); }
    type_vec<T, 4>         ywzw() const { return type_vec<T, 4>(ywz(), w()); }
    type_vec<T, 4>         ywwx() const { return type_vec<T, 4>(yww(), x()); }
    type_vec<T, 4>         ywwy() const { return type_vec<T, 4>(yww(), y()); }
    type_vec<T, 4>         ywwz() const { return type_vec<T, 4>(yww(), z()); }
    type_vec<T, 4>         ywww() const { return type_vec<T, 4>(yww(), w()); }
    type_vec<T, 4>         zxxx() const { return type_vec<T, 4>(zxx(), x()); }
    type_vec<T, 4>         zxxy() const { return type_vec<T, 4>(zxx(), y()); }
    type_vec<T, 4>         zxxz() const { return type_vec<T, 4>(zxx(), z()); }
    type_vec<T, 4>         zxxw() const { return type_vec<T, 4>(zxx(), w()); }
    type_vec<T, 4>         zxyx() const { return type_vec<T, 4>(zxy(), x()); }
    type_vec<T, 4>         zxyy() const { return type_vec<T, 4>(zxy(), y()); }
    type_vec<T, 4>         zxyz() const { return type_vec<T, 4>(zxy(), z()); }
    type_vec<T, 4>         zxyw() const { return type_vec<T, 4>(zxy(), w()); }
    type_vec<T, 4>         zxzx() const { return type_vec<T, 4>(zxz(), x()); }
    type_vec<T, 4>         zxzy() const { return type_vec<T, 4>(zxz(), y()); }
    type_vec<T, 4>         zxzz() const { return type_vec<T, 4>(zxz(), z()); }
    type_vec<T, 4>         zxzw() const { return type_vec<T, 4>(zxz(), w()); }
    type_vec<T, 4>         zxwx() const { return type_vec<T, 4>(zxw(), x()); }
    type_vec<T, 4>         zxwy() const { return type_vec<T, 4>(zxw(), y()); }
    type_vec<T, 4>         zxwz() const { return type_vec<T, 4>(zxw(), z()); }
    type_vec<T, 4>         zxww() const { return type_vec<T, 4>(zxw(), w()); }
    type_vec<T, 4>         zyxx() const { return type_vec<T, 4>(zyx(), x()); }
    type_vec<T, 4>         zyxy() const { return type_vec<T, 4>(zyx(), y()); }
    type_vec<T, 4>         zyxz() const { return type_vec<T, 4>(zyx(), z()); }
    type_vec<T, 4>         zyxw() const { return type_vec<T, 4>(zyx(), w()); }
    type_vec<T, 4>         zyyx() const { return type_vec<T, 4>(zyy(), x()); }
    type_vec<T, 4>         zyyy() const { return type_vec<T, 4>(zyy(), y()); }
    type_vec<T, 4>         zyyz() const { return type_vec<T, 4>(zyy(), z()); }
    type_vec<T, 4>         zyyw() const { return type_vec<T, 4>(zyy(), w()); }
    type_vec<T, 4>         zyzx() const { return type_vec<T, 4>(zyz(), x()); }
    type_vec<T, 4>         zyzy() const { return type_vec<T, 4>(zyz(), y()); }
    type_vec<T, 4>         zyzz() const { return type_vec<T, 4>(zyz(), z()); }
    type_vec<T, 4>         zyzw() const { return type_vec<T, 4>(zyz(), w()); }
    type_vec<T, 4>         zywx() const { return type_vec<T, 4>(zyw(), x()); }
    type_vec<T, 4>         zywy() const { return type_vec<T, 4>(zyw(), y()); }
    type_vec<T, 4>         zywz() const { return type_vec<T, 4>(zyw(), z()); }
    type_vec<T, 4>         zyww() const { return type_vec<T, 4>(zyw(), w()); }
    type_vec<T, 4>         zzxx() const { return type_vec<T, 4>(zzx(), x()); }
    type_vec<T, 4>         zzxy() const { return type_vec<T, 4>(zzx(), y()); }
    type_vec<T, 4>         zzxz() const { return type_vec<T, 4>(zzx(), z()); }
    type_vec<T, 4>         zzxw() const { return type_vec<T, 4>(zzx(), w()); }
    type_vec<T, 4>         zzyx() const { return type_vec<T, 4>(zzy(), x()); }
    type_vec<T, 4>         zzyy() const { return type_vec<T, 4>(zzy(), y()); }
    type_vec<T, 4>         zzyz() const { return type_vec<T, 4>(zzy(), z()); }
    type_vec<T, 4>         zzyw() const { return type_vec<T, 4>(zzy(), w()); }
    type_vec<T, 4>         zzzx() const { return type_vec<T, 4>(zzz(), x()); }
    type_vec<T, 4>         zzzy() const { return type_vec<T, 4>(zzz(), y()); }
    type_vec<T, 4>         zzzz() const { return type_vec<T, 4>(zzz(), z()); }
    type_vec<T, 4>         zzzw() const { return type_vec<T, 4>(zzz(), w()); }
    type_vec<T, 4>         zzwx() const { return type_vec<T, 4>(zzw(), x()); }
    type_vec<T, 4>         zzwy() const { return type_vec<T, 4>(zzw(), y()); }
    type_vec<T, 4>         zzwz() const { return type_vec<T, 4>(zzw(), z()); }
    type_vec<T, 4>         zzww() const { return type_vec<T, 4>(zzw(), w()); }
    type_vec<T, 4>         zwxx() const { return type_vec<T, 4>(zwx(), x()); }
    type_vec<T, 4>         zwxy() const { return type_vec<T, 4>(zwx(), y()); }
    type_vec<T, 4>         zwxz() const { return type_vec<T, 4>(zwx(), z()); }
    type_vec<T, 4>         zwxw() const { return type_vec<T, 4>(zwx(), w()); }
    type_vec<T, 4>         zwyx() const { return type_vec<T, 4>(zwy(), x()); }
    type_vec<T, 4>         zwyy() const { return type_vec<T, 4>(zwy(), y()); }
    type_vec<T, 4>         zwyz() const { return type_vec<T, 4>(zwy(), z()); }
    type_vec<T, 4>         zwyw() const { return type_vec<T, 4>(zwy(), w()); }
    type_vec<T, 4>         zwzx() const { return type_vec<T, 4>(zwz(), x()); }
    type_vec<T, 4>         zwzy() const { return type_vec<T, 4>(zwz(), y()); }
    type_vec<T, 4>         zwzz() const { return type_vec<T, 4>(zwz(), z()); }
    type_vec<T, 4>         zwzw() const { return type_vec<T, 4>(zwz(), w()); }
    type_vec<T, 4>         zwwx() const { return type_vec<T, 4>(zww(), x()); }
    type_vec<T, 4>         zwwy() const { return type_vec<T, 4>(zww(), y()); }
    type_vec<T, 4>         zwwz() const { return type_vec<T, 4>(zww(), z()); }
    type_vec<T, 4>         zwww() const { return type_vec<T, 4>(zww(), w()); }
    type_vec<T, 4>         wxxx() const { return type_vec<T, 4>(wxx(), x()); }
    type_vec<T, 4>         wxxy() const { return type_vec<T, 4>(wxx(), y()); }
    type_vec<T, 4>         wxxz() const { return type_vec<T, 4>(wxx(), z()); }
    type_vec<T, 4>         wxxw() const { return type_vec<T, 4>(wxx(), w()); }
    type_vec<T, 4>         wxyx() const { return type_vec<T, 4>(wxy(), x()); }
    type_vec<T, 4>         wxyy() const { return type_vec<T, 4>(wxy(), y()); }
    type_vec<T, 4>         wxyz() const { return type_vec<T, 4>(wxy(), z()); }
    type_vec<T, 4>         wxyw() const { return type_vec<T, 4>(wxy(), w()); }
    type_vec<T, 4>         wxzx() const { return type_vec<T, 4>(wxz(), x()); }
    type_vec<T, 4>         wxzy() const { return type_vec<T, 4>(wxz(), y()); }
    type_vec<T, 4>         wxzz() const { return type_vec<T, 4>(wxz(), z()); }
    type_vec<T, 4>         wxzw() const { return type_vec<T, 4>(wxz(), w()); }
    type_vec<T, 4>         wxwx() const { return type_vec<T, 4>(wxw(), x()); }
    type_vec<T, 4>         wxwy() const { return type_vec<T, 4>(wxw(), y()); }
    type_vec<T, 4>         wxwz() const { return type_vec<T, 4>(wxw(), z()); }
    type_vec<T, 4>         wxww() const { return type_vec<T, 4>(wxw(), w()); }
    type_vec<T, 4>         wyxx() const { return type_vec<T, 4>(wyx(), x()); }
    type_vec<T, 4>         wyxy() const { return type_vec<T, 4>(wyx(), y()); }
    type_vec<T, 4>         wyxz() const { return type_vec<T, 4>(wyx(), z()); }
    type_vec<T, 4>         wyxw() const { return type_vec<T, 4>(wyx(), w()); }
    type_vec<T, 4>         wyyx() const { return type_vec<T, 4>(wyy(), x()); }
    type_vec<T, 4>         wyyy() const { return type_vec<T, 4>(wyy(), y()); }
    type_vec<T, 4>         wyyz() const { return type_vec<T, 4>(wyy(), z()); }
    type_vec<T, 4>         wyyw() const { return type_vec<T, 4>(wyy(), w()); }
    type_vec<T, 4>         wyzx() const { return type_vec<T, 4>(wyz(), x()); }
    type_vec<T, 4>         wyzy() const { return type_vec<T, 4>(wyz(), y()); }
    type_vec<T, 4>         wyzz() const { return type_vec<T, 4>(wyz(), z()); }
    type_vec<T, 4>         wyzw() const { return type_vec<T, 4>(wyz(), w()); }
    type_vec<T, 4>         wywx() const { return type_vec<T, 4>(wyw(), x()); }
    type_vec<T, 4>         wywy() const { return type_vec<T, 4>(wyw(), y()); }
    type_vec<T, 4>         wywz() const { return type_vec<T, 4>(wyw(), z()); }
    type_vec<T, 4>         wyww() const { return type_vec<T, 4>(wyw(), w()); }
    type_vec<T, 4>         wzxx() const { return type_vec<T, 4>(wzx(), x()); }
    type_vec<T, 4>         wzxy() const { return type_vec<T, 4>(wzx(), y()); }
    type_vec<T, 4>         wzxz() const { return type_vec<T, 4>(wzx(), z()); }
    type_vec<T, 4>         wzxw() const { return type_vec<T, 4>(wzx(), w()); }
    type_vec<T, 4>         wzyx() const { return type_vec<T, 4>(wzy(), x()); }
    type_vec<T, 4>         wzyy() const { return type_vec<T, 4>(wzy(), y()); }
    type_vec<T, 4>         wzyz() const { return type_vec<T, 4>(wzy(), z()); }
    type_vec<T, 4>         wzyw() const { return type_vec<T, 4>(wzy(), w()); }
    type_vec<T, 4>         wzzx() const { return type_vec<T, 4>(wzz(), x()); }
    type_vec<T, 4>         wzzy() const { return type_vec<T, 4>(wzz(), y()); }
    type_vec<T, 4>         wzzz() const { return type_vec<T, 4>(wzz(), z()); }
    type_vec<T, 4>         wzzw() const { return type_vec<T, 4>(wzz(), w()); }
    type_vec<T, 4>         wzwx() const { return type_vec<T, 4>(wzw(), x()); }
    type_vec<T, 4>         wzwy() const { return type_vec<T, 4>(wzw(), y()); }
    type_vec<T, 4>         wzwz() const { return type_vec<T, 4>(wzw(), z()); }
    type_vec<T, 4>         wzww() const { return type_vec<T, 4>(wzw(), w()); }
    type_vec<T, 4>         wwxx() const { return type_vec<T, 4>(wwx(), x()); }
    type_vec<T, 4>         wwxy() const { return type_vec<T, 4>(wwx(), y()); }
    type_vec<T, 4>         wwxz() const { return type_vec<T, 4>(wwx(), z()); }
    type_vec<T, 4>         wwxw() const { return type_vec<T, 4>(wwx(), w()); }
    type_vec<T, 4>         wwyx() const { return type_vec<T, 4>(wwy(), x()); }
    type_vec<T, 4>         wwyy() const { return type_vec<T, 4>(wwy(), y()); }
    type_vec<T, 4>         wwyz() const { return type_vec<T, 4>(wwy(), z()); }
    type_vec<T, 4>         wwyw() const { return type_vec<T, 4>(wwy(), w()); }
    type_vec<T, 4>         wwzx() const { return type_vec<T, 4>(wwz(), x()); }
    type_vec<T, 4>         wwzy() const { return type_vec<T, 4>(wwz(), y()); }
    type_vec<T, 4>         wwzz() const { return type_vec<T, 4>(wwz(), z()); }
    type_vec<T, 4>         wwzw() const { return type_vec<T, 4>(wwz(), w()); }
    type_vec<T, 4>         wwwx() const { return type_vec<T, 4>(www(), x()); }
    type_vec<T, 4>         wwwy() const { return type_vec<T, 4>(www(), y()); }
    type_vec<T, 4>         wwwz() const { return type_vec<T, 4>(www(), z()); }
    type_vec<T, 4>         wwww() const { return type_vec<T, 4>(W); }

    T&                      r()       { return x(); }
    const T&                r() const { return x(); }
    T&                      g()       { return y(); }
    const T&                g() const { return y(); }
    T&                      b()       { return z(); }
    const T&                b() const { return z(); }
    T&                      a()       { return w(); }
    const T&                a() const { return w(); }
    type_vec<T,2>           rr() const { return xx(); }
    type_vec<T,2>&          rg()       { return xy(); }
    const type_vec<T,2>&    rg() const { return xy(); }
    type_vec<T,2>           rb() const { return xz(); }
    type_vec<T,2>           ra() const { return xw(); }
    type_vec<T,2>           gr() const { return yx(); }
    type_vec<T,2>           gg() const { return yy(); }
    type_vec<T,2>           gb() const { return yz(); }
    type_vec<T,2>           ga() const { return yw(); }
    type_vec<T,2>           br() const { return zx(); }
    type_vec<T,2>           bg() const { return zy(); }
    type_vec<T,2>           bb() const { return zz(); }
    type_vec<T,2>           ba() const { return zw(); }
    type_vec<T,2>           ar() const { return wx(); }
    type_vec<T,2>           ag() const { return wy(); }
    type_vec<T,2>           ab() const { return wz(); }
    type_vec<T,2>           aa() const { return ww(); }
    type_vec<T,3>          rrr() const { return xxx(); }
    type_vec<T,3>          rrg() const { return xxy(); }
    type_vec<T,3>          rrb() const { return xxz(); }
    type_vec<T,3>          rra() const { return xxw(); }
    type_vec<T,3>          rgr() const { return xyx(); }
    type_vec<T,3>          rgg() const { return xyy(); }
    type_vec<T,3>&         rgb()       { return xyz(); }
    const type_vec<T,3>&   rgb() const { return xyz(); }
    type_vec<T,3>          rga() const { return xyw(); }
    type_vec<T,3>          rbr() const { return xzx(); }
    type_vec<T,3>          rbg() const { return xzy(); }
    type_vec<T,3>          rbb() const { return xzz(); }
    type_vec<T,3>          rba() const { return xzw(); }
    type_vec<T,3>          rar() const { return xwx(); }
    type_vec<T,3>          rag() const { return xwy(); }
    type_vec<T,3>          rab() const { return xwz(); }
    type_vec<T,3>          raa() const { return xww(); }
    type_vec<T,3>          grr() const { return yxx(); }
    type_vec<T,3>          grg() const { return yxy(); }
    type_vec<T,3>          grb() const { return yxz(); }
    type_vec<T,3>          gra() const { return yxw(); }
    type_vec<T,3>          ggr() const { return yyx(); }
    type_vec<T,3>          ggg() const { return yyy(); }
    type_vec<T,3>          ggb() const { return yyz(); }
    type_vec<T,3>          gga() const { return yyw(); }
    type_vec<T,3>          gbr() const { return yzx(); }
    type_vec<T,3>          gbg() const { return yzy(); }
    type_vec<T,3>          gbb() const { return yzz(); }
    type_vec<T,3>          gba() const { return yzw(); }
    type_vec<T,3>          gar() const { return ywx(); }
    type_vec<T,3>          gag() const { return ywy(); }
    type_vec<T,3>          gab() const { return ywz(); }
    type_vec<T,3>          gaa() const { return yww(); }
    type_vec<T,3>          brr() const { return zxx(); }
    type_vec<T,3>          brg() const { return zxy(); }
    type_vec<T,3>          brb() const { return zxz(); }
    type_vec<T,3>          bra() const { return zxw(); }
    type_vec<T,3>          bgr() const { return zyx(); }
    type_vec<T,3>          bgg() const { return zyy(); }
    type_vec<T,3>          bgb() const { return zyz(); }
    type_vec<T,3>          bga() const { return zyw(); }
    type_vec<T,3>          bbr() const { return zzx(); }
    type_vec<T,3>          bbg() const { return zzy(); }
    type_vec<T,3>          bbb() const { return zzz(); }
    type_vec<T,3>          bba() const { return zzw(); }
    type_vec<T,3>          bar() const { return zwx(); }
    type_vec<T,3>          bag() const { return zwy(); }
    type_vec<T,3>          bab() const { return zwz(); }
    type_vec<T,3>          baa() const { return zww(); }
    type_vec<T,3>          arr() const { return wxx(); }
    type_vec<T,3>          arg() const { return wxy(); }
    type_vec<T,3>          arb() const { return wxz(); }
    type_vec<T,3>          ara() const { return wxw(); }
    type_vec<T,3>          agr() const { return wyx(); }
    type_vec<T,3>          agg() const { return wyy(); }
    type_vec<T,3>          agb() const { return wyz(); }
    type_vec<T,3>          aga() const { return wyw(); }
    type_vec<T,3>          abr() const { return wzx(); }
    type_vec<T,3>          abg() const { return wzy(); }
    type_vec<T,3>          abb() const { return wzz(); }
    type_vec<T,3>          aba() const { return wzw(); }
    type_vec<T,3>          aar() const { return wwx(); }
    type_vec<T,3>          aag() const { return wwy(); }
    type_vec<T,3>          aab() const { return wwz(); }
    type_vec<T,3>          aaa() const { return www(); }
    type_vec<T, 4>         rrrr() const { return xxxx(); }
    type_vec<T, 4>         rrrg() const { return xxxy(); }
    type_vec<T, 4>         rrrb() const { return xxxz(); }
    type_vec<T, 4>         rrra() const { return xxxw(); }
    type_vec<T, 4>         rrgr() const { return xxyx(); }
    type_vec<T, 4>         rrgg() const { return xxyy(); }
    type_vec<T, 4>         rrgb() const { return xxyz(); }
    type_vec<T, 4>         rrga() const { return xxyw(); }
    type_vec<T, 4>         rrbr() const { return xxzx(); }
    type_vec<T, 4>         rrbg() const { return xxzy(); }
    type_vec<T, 4>         rrbb() const { return xxzz(); }
    type_vec<T, 4>         rrba() const { return xxzw(); }
    type_vec<T, 4>         rrar() const { return xxwx(); }
    type_vec<T, 4>         rrag() const { return xxwy(); }
    type_vec<T, 4>         rrab() const { return xxwz(); }
    type_vec<T, 4>         rraa() const { return xxww(); }
    type_vec<T, 4>         rgrr() const { return xyxx(); }
    type_vec<T, 4>         rgrg() const { return xyxy(); }
    type_vec<T, 4>         rgrb() const { return xyxz(); }
    type_vec<T, 4>         rgra() const { return xyxw(); }
    type_vec<T, 4>         rggr() const { return xyyx(); }
    type_vec<T, 4>         rggg() const { return xyyy(); }
    type_vec<T, 4>         rggb() const { return xyyz(); }
    type_vec<T, 4>         rgga() const { return xyyw(); }
    type_vec<T, 4>         rgbr() const { return xyzx(); }
    type_vec<T, 4>         rgbg() const { return xyzy(); }
    type_vec<T, 4>         rgbb() const { return xyzz(); }
    type_vec<T, 4>&        rgba()       { return *this; }
    const type_vec<T, 4>&  rgba() const { return *this; }
    type_vec<T, 4>         rgar() const { return xywx(); }
    type_vec<T, 4>         rgag() const { return xywy(); }
    type_vec<T, 4>         rgab() const { return xywz(); }
    type_vec<T, 4>         rgaa() const { return xyww(); }
    type_vec<T, 4>         rbrr() const { return xzxx(); }
    type_vec<T, 4>         rbrg() const { return xzxy(); }
    type_vec<T, 4>         rbrb() const { return xzxz(); }
    type_vec<T, 4>         rbra() const { return xzxw(); }
    type_vec<T, 4>         rbgr() const { return xzyx(); }
    type_vec<T, 4>         rbgg() const { return xzyy(); }
    type_vec<T, 4>         rbgb() const { return xzyz(); }
    type_vec<T, 4>         rbga() const { return xzyw(); }
    type_vec<T, 4>         rbbr() const { return xzzx(); }
    type_vec<T, 4>         rbbg() const { return xzzy(); }
    type_vec<T, 4>         rbbb() const { return xzzz(); }
    type_vec<T, 4>         rbba() const { return xzzw(); }
    type_vec<T, 4>         rbar() const { return xzwx(); }
    type_vec<T, 4>         rbag() const { return xzwy(); }
    type_vec<T, 4>         rbab() const { return xzwz(); }
    type_vec<T, 4>         rbaa() const { return xzww(); }
    type_vec<T, 4>         rarr() const { return xwxx(); }
    type_vec<T, 4>         rarg() const { return xwxy(); }
    type_vec<T, 4>         rarb() const { return xwxz(); }
    type_vec<T, 4>         rara() const { return xwxw(); }
    type_vec<T, 4>         ragr() const { return xwyx(); }
    type_vec<T, 4>         ragg() const { return xwyy(); }
    type_vec<T, 4>         ragb() const { return xwyz(); }
    type_vec<T, 4>         raga() const { return xwyw(); }
    type_vec<T, 4>         rabr() const { return xwzx(); }
    type_vec<T, 4>         rabg() const { return xwzy(); }
    type_vec<T, 4>         rabb() const { return xwzz(); }
    type_vec<T, 4>         raba() const { return xwzw(); }
    type_vec<T, 4>         raar() const { return xwwx(); }
    type_vec<T, 4>         raag() const { return xwwy(); }
    type_vec<T, 4>         raab() const { return xwwz(); }
    type_vec<T, 4>         raaa() const { return xwww(); }
    type_vec<T, 4>         grrr() const { return yxxx(); }
    type_vec<T, 4>         grrg() const { return yxxy(); }
    type_vec<T, 4>         grrb() const { return yxxz(); }
    type_vec<T, 4>         grra() const { return yxxw(); }
    type_vec<T, 4>         grgr() const { return yxyx(); }
    type_vec<T, 4>         grgg() const { return yxyy(); }
    type_vec<T, 4>         grgb() const { return yxyz(); }
    type_vec<T, 4>         grga() const { return yxyw(); }
    type_vec<T, 4>         grbr() const { return yxzx(); }
    type_vec<T, 4>         grbg() const { return yxzy(); }
    type_vec<T, 4>         grbb() const { return yxzz(); }
    type_vec<T, 4>         grba() const { return yxzw(); }
    type_vec<T, 4>         grar() const { return yxwx(); }
    type_vec<T, 4>         grag() const { return yxwy(); }
    type_vec<T, 4>         grab() const { return yxwz(); }
    type_vec<T, 4>         graa() const { return yxww(); }
    type_vec<T, 4>         ggrr() const { return yyxx(); }
    type_vec<T, 4>         ggrg() const { return yyxy(); }
    type_vec<T, 4>         ggrb() const { return yyxz(); }
    type_vec<T, 4>         ggra() const { return yyxw(); }
    type_vec<T, 4>         gggr() const { return yyyx(); }
    type_vec<T, 4>         gggg() const { return yyyy(); }
    type_vec<T, 4>         gggb() const { return yyyz(); }
    type_vec<T, 4>         ggga() const { return yyyw(); }
    type_vec<T, 4>         ggbr() const { return yyzx(); }
    type_vec<T, 4>         ggbg() const { return yyzy(); }
    type_vec<T, 4>         ggbb() const { return yyzz(); }
    type_vec<T, 4>         ggba() const { return yyzw(); }
    type_vec<T, 4>         ggar() const { return yywx(); }
    type_vec<T, 4>         ggag() const { return yywy(); }
    type_vec<T, 4>         ggab() const { return yywz(); }
    type_vec<T, 4>         ggaa() const { return yyww(); }
    type_vec<T, 4>         gbrr() const { return yzxx(); }
    type_vec<T, 4>         gbrg() const { return yzxy(); }
    type_vec<T, 4>         gbrb() const { return yzxz(); }
    type_vec<T, 4>         gbra() const { return yzxw(); }
    type_vec<T, 4>         gbgr() const { return yzyx(); }
    type_vec<T, 4>         gbgg() const { return yzyy(); }
    type_vec<T, 4>         gbgb() const { return yzyz(); }
    type_vec<T, 4>         gbga() const { return yzyw(); }
    type_vec<T, 4>         gbbr() const { return yzzx(); }
    type_vec<T, 4>         gbbg() const { return yzzy(); }
    type_vec<T, 4>         gbbb() const { return yzzz(); }
    type_vec<T, 4>         gbba() const { return yzzw(); }
    type_vec<T, 4>         gbar() const { return yzwx(); }
    type_vec<T, 4>         gbag() const { return yzwy(); }
    type_vec<T, 4>         gbab() const { return yzwz(); }
    type_vec<T, 4>         gbaa() const { return yzww(); }
    type_vec<T, 4>         garr() const { return ywxx(); }
    type_vec<T, 4>         garg() const { return ywxy(); }
    type_vec<T, 4>         garb() const { return ywxz(); }
    type_vec<T, 4>         gara() const { return ywxw(); }
    type_vec<T, 4>         gagr() const { return ywyx(); }
    type_vec<T, 4>         gagg() const { return ywyy(); }
    type_vec<T, 4>         gagb() const { return ywyz(); }
    type_vec<T, 4>         gaga() const { return ywyw(); }
    type_vec<T, 4>         gabr() const { return ywzx(); }
    type_vec<T, 4>         gabg() const { return ywzy(); }
    type_vec<T, 4>         gabb() const { return ywzz(); }
    type_vec<T, 4>         gaba() const { return ywzw(); }
    type_vec<T, 4>         gaar() const { return ywwx(); }
    type_vec<T, 4>         gaag() const { return ywwy(); }
    type_vec<T, 4>         gaab() const { return ywwz(); }
    type_vec<T, 4>         gaaa() const { return ywww(); }
    type_vec<T, 4>         brrr() const { return zxxx(); }
    type_vec<T, 4>         brrg() const { return zxxy(); }
    type_vec<T, 4>         brrb() const { return zxxz(); }
    type_vec<T, 4>         brra() const { return zxxw(); }
    type_vec<T, 4>         brgr() const { return zxyx(); }
    type_vec<T, 4>         brgg() const { return zxyy(); }
    type_vec<T, 4>         brgb() const { return zxyz(); }
    type_vec<T, 4>         brga() const { return zxyw(); }
    type_vec<T, 4>         brbr() const { return zxzx(); }
    type_vec<T, 4>         brbg() const { return zxzy(); }
    type_vec<T, 4>         brbb() const { return zxzz(); }
    type_vec<T, 4>         brba() const { return zxzw(); }
    type_vec<T, 4>         brar() const { return zxwx(); }
    type_vec<T, 4>         brag() const { return zxwy(); }
    type_vec<T, 4>         brab() const { return zxwz(); }
    type_vec<T, 4>         braa() const { return zxww(); }
    type_vec<T, 4>         bgrr() const { return zyxx(); }
    type_vec<T, 4>         bgrg() const { return zyxy(); }
    type_vec<T, 4>         bgrb() const { return zyxz(); }
    type_vec<T, 4>         bgra() const { return zyxw(); }
    type_vec<T, 4>         bggr() const { return zyyx(); }
    type_vec<T, 4>         bggg() const { return zyyy(); }
    type_vec<T, 4>         bggb() const { return zyyz(); }
    type_vec<T, 4>         bgga() const { return zyyw(); }
    type_vec<T, 4>         bgbr() const { return zyzx(); }
    type_vec<T, 4>         bgbg() const { return zyzy(); }
    type_vec<T, 4>         bgbb() const { return zyzz(); }
    type_vec<T, 4>         bgba() const { return zyzw(); }
    type_vec<T, 4>         bgar() const { return zywx(); }
    type_vec<T, 4>         bgag() const { return zywy(); }
    type_vec<T, 4>         bgab() const { return zywz(); }
    type_vec<T, 4>         bgaa() const { return zyww(); }
    type_vec<T, 4>         bbrr() const { return zzxx(); }
    type_vec<T, 4>         bbrg() const { return zzxy(); }
    type_vec<T, 4>         bbrb() const { return zzxz(); }
    type_vec<T, 4>         bbra() const { return zzxw(); }
    type_vec<T, 4>         bbgr() const { return zzyx(); }
    type_vec<T, 4>         bbgg() const { return zzyy(); }
    type_vec<T, 4>         bbgb() const { return zzyz(); }
    type_vec<T, 4>         bbga() const { return zzyw(); }
    type_vec<T, 4>         bbbr() const { return zzzx(); }
    type_vec<T, 4>         bbbg() const { return zzzy(); }
    type_vec<T, 4>         bbbb() const { return zzzz(); }
    type_vec<T, 4>         bbba() const { return zzzw(); }
    type_vec<T, 4>         bbar() const { return zzwx(); }
    type_vec<T, 4>         bbag() const { return zzwy(); }
    type_vec<T, 4>         bbab() const { return zzwz(); }
    type_vec<T, 4>         bbaa() const { return zzww(); }
    type_vec<T, 4>         barr() const { return zwxx(); }
    type_vec<T, 4>         barg() const { return zwxy(); }
    type_vec<T, 4>         barb() const { return zwxz(); }
    type_vec<T, 4>         bara() const { return zwxw(); }
    type_vec<T, 4>         bagr() const { return zwyx(); }
    type_vec<T, 4>         bagg() const { return zwyy(); }
    type_vec<T, 4>         bagb() const { return zwyz(); }
    type_vec<T, 4>         baga() const { return zwyw(); }
    type_vec<T, 4>         babr() const { return zwzx(); }
    type_vec<T, 4>         babg() const { return zwzy(); }
    type_vec<T, 4>         babb() const { return zwzz(); }
    type_vec<T, 4>         baba() const { return zwzw(); }
    type_vec<T, 4>         baar() const { return zwwx(); }
    type_vec<T, 4>         baag() const { return zwwy(); }
    type_vec<T, 4>         baab() const { return zwwz(); }
    type_vec<T, 4>         baaa() const { return zwww(); }
    type_vec<T, 4>         arrr() const { return wxxx(); }
    type_vec<T, 4>         arrg() const { return wxxy(); }
    type_vec<T, 4>         arrb() const { return wxxz(); }
    type_vec<T, 4>         arra() const { return wxxw(); }
    type_vec<T, 4>         argr() const { return wxyx(); }
    type_vec<T, 4>         argg() const { return wxyy(); }
    type_vec<T, 4>         argb() const { return wxyz(); }
    type_vec<T, 4>         arga() const { return wxyw(); }
    type_vec<T, 4>         arbr() const { return wxzx(); }
    type_vec<T, 4>         arbg() const { return wxzy(); }
    type_vec<T, 4>         arbb() const { return wxzz(); }
    type_vec<T, 4>         arba() const { return wxzw(); }
    type_vec<T, 4>         arar() const { return wxwx(); }
    type_vec<T, 4>         arag() const { return wxwy(); }
    type_vec<T, 4>         arab() const { return wxwz(); }
    type_vec<T, 4>         araa() const { return wxww(); }
    type_vec<T, 4>         agrr() const { return wyxx(); }
    type_vec<T, 4>         agrg() const { return wyxy(); }
    type_vec<T, 4>         agrb() const { return wyxz(); }
    type_vec<T, 4>         agra() const { return wyxw(); }
    type_vec<T, 4>         aggr() const { return wyyx(); }
    type_vec<T, 4>         aggg() const { return wyyy(); }
    type_vec<T, 4>         aggb() const { return wyyz(); }
    type_vec<T, 4>         agga() const { return wyyw(); }
    type_vec<T, 4>         agbr() const { return wyzx(); }
    type_vec<T, 4>         agbg() const { return wyzy(); }
    type_vec<T, 4>         agbb() const { return wyzz(); }
    type_vec<T, 4>         agba() const { return wyzw(); }
    type_vec<T, 4>         agar() const { return wywx(); }
    type_vec<T, 4>         agag() const { return wywy(); }
    type_vec<T, 4>         agab() const { return wywz(); }
    type_vec<T, 4>         agaa() const { return wyww(); }
    type_vec<T, 4>         abrr() const { return wzxx(); }
    type_vec<T, 4>         abrg() const { return wzxy(); }
    type_vec<T, 4>         abrb() const { return wzxz(); }
    type_vec<T, 4>         abra() const { return wzxw(); }
    type_vec<T, 4>         abgr() const { return wzyx(); }
    type_vec<T, 4>         abgg() const { return wzyy(); }
    type_vec<T, 4>         abgb() const { return wzyz(); }
    type_vec<T, 4>         abga() const { return wzyw(); }
    type_vec<T, 4>         abbr() const { return wzzx(); }
    type_vec<T, 4>         abbg() const { return wzzy(); }
    type_vec<T, 4>         abbb() const { return wzzz(); }
    type_vec<T, 4>         abba() const { return wzzw(); }
    type_vec<T, 4>         abar() const { return wzwx(); }
    type_vec<T, 4>         abag() const { return wzwy(); }
    type_vec<T, 4>         abab() const { return wzwz(); }
    type_vec<T, 4>         abaa() const { return wzww(); }
    type_vec<T, 4>         aarr() const { return wwxx(); }
    type_vec<T, 4>         aarg() const { return wwxy(); }
    type_vec<T, 4>         aarb() const { return wwxz(); }
    type_vec<T, 4>         aara() const { return wwxw(); }
    type_vec<T, 4>         aagr() const { return wwyx(); }
    type_vec<T, 4>         aagg() const { return wwyy(); }
    type_vec<T, 4>         aagb() const { return wwyz(); }
    type_vec<T, 4>         aaga() const { return wwyw(); }
    type_vec<T, 4>         aabr() const { return wwzx(); }
    type_vec<T, 4>         aabg() const { return wwzy(); }
    type_vec<T, 4>         aabb() const { return wwzz(); }
    type_vec<T, 4>         aaba() const { return wwzw(); }
    type_vec<T, 4>         aaar() const { return wwwx(); }
    type_vec<T, 4>         aaag() const { return wwwy(); }
    type_vec<T, 4>         aaab() const { return wwwz(); }
    type_vec<T, 4>         aaaa() const { return wwww(); }

    /*************************************
    *               CTORS                *
    *************************************/
    type_vec() :
      XYZ(), W(static_cast<T>(0.0)){}

    template<typename T2>
    type_vec(T2 init) :
      XYZ(init), W(static_cast<T>(init)){}

    template<typename T2>
    type_vec(T2* init) :
      XYZ(init), W(static_cast<T>(init[3])){}

    template<typename T2>
    type_vec(const T2 &init_x, const T2 &init_y, const T2 &init_z, const T2 &init_w) :
      XYZ(init_x, init_y, init_z), W(static_cast<T>(init_w)){}

    template<typename T2>
    type_vec(const type_vec<T2,2> &v, T2 f_z, T2 f_w) :
      XYZ(v, f_z), W(static_cast<T>(f_w)){}

    template <typename T2>
    type_vec(const type_vec<T2,3> &v, T2 f) :
      XYZ(v), W(static_cast<T>(f)){}

    template<typename T2>
    type_vec(const type_vec<T2, 4> &v) :
      XYZ(v.XYZ), W(static_cast<T>(v.W)){}

    /*************************************
    *             OPERATORS              *
    *************************************/

    template<typename T2>
    type_vec<T, 4>& operator= (const type_vec<T2, 4> &v)
    {
      XYZ = v.XYZ; W = static_cast<T>(v.W);
      return *this;
    }

    T operator[] (unsigned i) const
    {
      return *(&(XYZ.x()) + i);
    }

    T& operator[] (unsigned i)
    {
      return *(&(XYZ.x()) + i);
    }


  private:

    type_vec<T, 3> XYZ;
    T W;

  };

  typedef type_vec<bool, 4> bvec4;
  typedef type_vec<short, 4> svec4;
  typedef type_vec<unsigned short, 4> usvec4;
  typedef type_vec<int, 4> ivec4;
  typedef type_vec<unsigned int, 4> uivec4;
  typedef type_vec<float, 4> vec4;
  typedef type_vec<double, 4> dvec4;
}