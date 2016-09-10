/******************************************************************************/
/*!
\filxe  vector_base_data.hpp
\author Sagnik Chowdhury
\brief  Contains the Photon renderer math library
*/
/******************************************************************************/
#pragma once
#include "vector_swizzle_proxy.hpp"

namespace phm
{
  namespace swizzle
  {
    template<typename T, unsigned ... indices>
    using Swizzle = VecProxy<T, indices ... >;

#pragma region VEC_GENERIC_INTERNAL

    template<typename T, unsigned Size>
    class vec_internal_data
    {
    public:
      union
      {
        T store[Size];
      };
    };

#pragma endregion VEC_GENERIC_INTERNAL

#pragma region VEC1_INTERNAL

    template<typename T>
    class vec_internal_data<T, 1>
    {
    public:
      union
      {
#pragma region vec1_swizzle
        T store;
        Swizzle<T, 0> x;
        Swizzle<T, 0, 0> xx;
        Swizzle<T, 0, 0, 0> xxx;
        Swizzle<T, 0, 0, 0, 0> xxxx;

        Swizzle<T, 0> r;
        Swizzle<T, 0, 0> rr;
        Swizzle<T, 0, 0, 0> rrr;
        Swizzle<T, 0, 0, 0, 0> rrrr;
#pragma endregion vec1_swizzle

      };
    };

#pragma endregion VEC1_INTERNAL

#pragma region VEC2_INTERNAL

    template <typename T>
    class vec_internal_data<T, 2>
    {
    public:
      union
      {
        T store[2];
#pragma region vec2_xy
        Swizzle<T, 0> x;
        Swizzle<T, 1> y;
        Swizzle<T, 0, 0> xx;
        Swizzle<T, 0, 1> xy;
        Swizzle<T, 1, 0> yx;
        Swizzle<T, 1, 1> yy;
        Swizzle<T, 0, 0, 0> xxx;
        Swizzle<T, 0, 0, 1> xxy;
        Swizzle<T, 0, 1, 0> xyx;
        Swizzle<T, 0, 1, 1> xyy;
        Swizzle<T, 1, 0, 0> yxx;
        Swizzle<T, 1, 0, 1> yxy;
        Swizzle<T, 1, 1, 0> yyx;
        Swizzle<T, 1, 1, 1> yyy;
        Swizzle<T, 0, 0, 0, 0> xxxx;
        Swizzle<T, 0, 0, 0, 1> xxxy;
        Swizzle<T, 0, 0, 1, 0> xxyx;
        Swizzle<T, 0, 0, 1, 1> xxyy;
        Swizzle<T, 0, 1, 0, 0> xyxx;
        Swizzle<T, 0, 1, 0, 1> xyxy;
        Swizzle<T, 0, 1, 1, 0> xyyx;
        Swizzle<T, 0, 1, 1, 1> xyyy;
        Swizzle<T, 1, 0, 0, 0> yxxx;
        Swizzle<T, 1, 0, 0, 1> yxxy;
        Swizzle<T, 1, 0, 1, 0> yxyx;
        Swizzle<T, 1, 0, 1, 1> yxyy;
        Swizzle<T, 1, 1, 0, 0> yyxx;
        Swizzle<T, 1, 1, 0, 1> yyxy;
        Swizzle<T, 1, 1, 1, 0> yyyx;
        Swizzle<T, 1, 1, 1, 1> yyyy;
#pragma endregion vec2_xy
#pragma region vec2_rg
        Swizzle<T, 0> r;
        Swizzle<T, 1> g;
        Swizzle<T, 0, 0> rr;
        Swizzle<T, 0, 1> rg;
        Swizzle<T, 1, 0> gr;
        Swizzle<T, 1, 1> gg;
        Swizzle<T, 0, 0, 0> rrr;
        Swizzle<T, 0, 0, 1> rrg;
        Swizzle<T, 0, 1, 0> rgr;
        Swizzle<T, 0, 1, 1> rgg;
        Swizzle<T, 1, 0, 0> grr;
        Swizzle<T, 1, 0, 1> grg;
        Swizzle<T, 1, 1, 0> ggr;
        Swizzle<T, 1, 1, 1> ggg;
        Swizzle<T, 0, 0, 0, 0> rrrr;
        Swizzle<T, 0, 0, 0, 1> rrrg;
        Swizzle<T, 0, 0, 1, 0> rrgr;
        Swizzle<T, 0, 0, 1, 1> rrgg;
        Swizzle<T, 0, 1, 0, 0> rgrr;
        Swizzle<T, 0, 1, 0, 1> rgrg;
        Swizzle<T, 0, 1, 1, 0> rggr;
        Swizzle<T, 0, 1, 1, 1> rggg;
        Swizzle<T, 1, 0, 0, 0> grrr;
        Swizzle<T, 1, 0, 0, 1> grrg;
        Swizzle<T, 1, 0, 1, 0> grgr;
        Swizzle<T, 1, 0, 1, 1> grgg;
        Swizzle<T, 1, 1, 0, 0> ggrr;
        Swizzle<T, 1, 1, 0, 1> ggrg;
        Swizzle<T, 1, 1, 1, 0> gggr;
        Swizzle<T, 1, 1, 1, 1> gggg;
#pragma endregion vec2_rg
      };
    };

#pragma endregion VEC2_INTERNAL

#pragma region VEC3_INTERNAL

    template <typename T>
    class vec_internal_data<T, 3>
    {
    public:
      union
      {
        T store[3];
#pragma region vec3_xyz
        Swizzle<T, 0> x;
        Swizzle<T, 1> y;
        Swizzle<T, 2> z;
        Swizzle<T, 0, 0> xx;
        Swizzle<T, 0, 1> xy;
        Swizzle<T, 0, 2> xz;
        Swizzle<T, 1, 0> yx;
        Swizzle<T, 1, 1> yy;
        Swizzle<T, 1, 2> yz;
        Swizzle<T, 2, 0> zx;
        Swizzle<T, 2, 1> zy;
        Swizzle<T, 2, 2> zz;
        Swizzle<T, 0, 0, 0> xxx;
        Swizzle<T, 0, 0, 1> xxy;
        Swizzle<T, 0, 0, 2> xxz;
        Swizzle<T, 0, 1, 0> xyx;
        Swizzle<T, 0, 1, 1> xyy;
        Swizzle<T, 0, 1, 2> xyz;
        Swizzle<T, 0, 2, 0> xzx;
        Swizzle<T, 0, 2, 1> xzy;
        Swizzle<T, 0, 2, 2> xzz;
        Swizzle<T, 1, 0, 0> yxx;
        Swizzle<T, 1, 0, 1> yxy;
        Swizzle<T, 1, 0, 2> yxz;
        Swizzle<T, 1, 1, 0> yyx;
        Swizzle<T, 1, 1, 1> yyy;
        Swizzle<T, 1, 1, 2> yyz;
        Swizzle<T, 1, 2, 0> yzx;
        Swizzle<T, 1, 2, 1> yzy;
        Swizzle<T, 1, 2, 2> yzz;
        Swizzle<T, 2, 0, 0> zxx;
        Swizzle<T, 2, 0, 1> zxy;
        Swizzle<T, 2, 0, 2> zxz;
        Swizzle<T, 2, 1, 0> zyx;
        Swizzle<T, 2, 1, 1> zyy;
        Swizzle<T, 2, 1, 2> zyz;
        Swizzle<T, 2, 2, 0> zzx;
        Swizzle<T, 2, 2, 1> zzy;
        Swizzle<T, 2, 2, 2> zzz;
        Swizzle<T, 0, 0, 0, 0> xxxx;
        Swizzle<T, 0, 0, 0, 1> xxxy;
        Swizzle<T, 0, 0, 0, 2> xxxz;
        Swizzle<T, 0, 0, 1, 0> xxyx;
        Swizzle<T, 0, 0, 1, 1> xxyy;
        Swizzle<T, 0, 0, 1, 2> xxyz;
        Swizzle<T, 0, 1, 0, 0> xyxx;
        Swizzle<T, 0, 1, 0, 1> xyxy;
        Swizzle<T, 0, 1, 0, 2> xyxz;
        Swizzle<T, 0, 1, 1, 0> xyyx;
        Swizzle<T, 0, 1, 1, 1> xyyy;
        Swizzle<T, 0, 1, 1, 2> xyyz;
        Swizzle<T, 0, 1, 2, 0> xyzx;
        Swizzle<T, 0, 1, 2, 1> xyzy;
        Swizzle<T, 0, 1, 2, 2> xyzz;
        Swizzle<T, 0, 2, 0, 0> xzxx;
        Swizzle<T, 0, 2, 0, 1> xzxy;
        Swizzle<T, 0, 2, 0, 2> xzxz;
        Swizzle<T, 0, 2, 1, 0> xzyx;
        Swizzle<T, 0, 2, 1, 1> xzyy;
        Swizzle<T, 0, 2, 1, 2> xzyz;
        Swizzle<T, 0, 2, 2, 0> xzzx;
        Swizzle<T, 0, 2, 2, 1> xzzy;
        Swizzle<T, 0, 2, 2, 2> xzzz;
        Swizzle<T, 1, 0, 0, 0> yxxx;
        Swizzle<T, 1, 0, 0, 1> yxxy;
        Swizzle<T, 1, 0, 0, 2> yxxz;
        Swizzle<T, 1, 0, 1, 0> yxyx;
        Swizzle<T, 1, 0, 1, 1> yxyy;
        Swizzle<T, 1, 0, 1, 2> yxyz;
        Swizzle<T, 1, 0, 2, 0> yxzx;
        Swizzle<T, 1, 0, 2, 1> yxzy;
        Swizzle<T, 1, 0, 2, 2> yxzz;
        Swizzle<T, 1, 1, 0, 0> yyxx;
        Swizzle<T, 1, 1, 0, 1> yyxy;
        Swizzle<T, 1, 1, 0, 2> yyxz;
        Swizzle<T, 1, 1, 1, 0> yyyx;
        Swizzle<T, 1, 1, 1, 1> yyyy;
        Swizzle<T, 1, 1, 1, 2> yyyz;
        Swizzle<T, 1, 1, 2, 0> yyzx;
        Swizzle<T, 1, 1, 2, 1> yyzy;
        Swizzle<T, 1, 1, 2, 2> yyzz;
        Swizzle<T, 1, 2, 0, 0> yzxx;
        Swizzle<T, 1, 2, 0, 1> yzxy;
        Swizzle<T, 1, 2, 0, 2> yzxz;
        Swizzle<T, 1, 2, 1, 0> yzyx;
        Swizzle<T, 1, 2, 1, 1> yzyy;
        Swizzle<T, 1, 2, 1, 2> yzyz;
        Swizzle<T, 1, 2, 2, 0> yzzx;
        Swizzle<T, 1, 2, 2, 1> yzzy;
        Swizzle<T, 1, 2, 2, 2> yzzz;
        Swizzle<T, 2, 0, 0, 0> zxxx;
        Swizzle<T, 2, 0, 0, 1> zxxy;
        Swizzle<T, 2, 0, 0, 2> zxxz;
        Swizzle<T, 2, 0, 1, 0> zxyx;
        Swizzle<T, 2, 0, 1, 1> zxyy;
        Swizzle<T, 2, 0, 1, 2> zxyz;
        Swizzle<T, 2, 0, 2, 0> zxzx;
        Swizzle<T, 2, 0, 2, 1> zxzy;
        Swizzle<T, 2, 0, 2, 2> zxzz;
        Swizzle<T, 2, 1, 0, 0> zyxx;
        Swizzle<T, 2, 1, 0, 1> zyxy;
        Swizzle<T, 2, 1, 0, 2> zyxz;
        Swizzle<T, 2, 1, 1, 0> zyyx;
        Swizzle<T, 2, 1, 1, 1> zyyy;
        Swizzle<T, 2, 1, 1, 2> zyyz;
        Swizzle<T, 2, 1, 2, 0> zyzx;
        Swizzle<T, 2, 1, 2, 1> zyzy;
        Swizzle<T, 2, 1, 2, 2> zyzz;
        Swizzle<T, 2, 2, 0, 0> zzxx;
        Swizzle<T, 2, 2, 0, 1> zzxy;
        Swizzle<T, 2, 2, 0, 2> zzxz;
        Swizzle<T, 2, 2, 1, 0> zzyx;
        Swizzle<T, 2, 2, 1, 1> zzyy;
        Swizzle<T, 2, 2, 1, 2> zzyz;
        Swizzle<T, 2, 2, 2, 0> zzzx;
        Swizzle<T, 2, 2, 2, 1> zzzy;
        Swizzle<T, 2, 2, 2, 2> zzzz;
#pragma endregion vec3_xyz
#pragma region vec3_rgb
        Swizzle<T, 0> r;
        Swizzle<T, 1> g;
        Swizzle<T, 2> b;
        Swizzle<T, 0, 0> rr;
        Swizzle<T, 0, 1> rg;
        Swizzle<T, 0, 2> rb;
        Swizzle<T, 1, 0> gr;
        Swizzle<T, 1, 1> gg;
        Swizzle<T, 1, 2> gb;
        Swizzle<T, 2, 0> br;
        Swizzle<T, 2, 1> bg;
        Swizzle<T, 2, 2> bb;
        Swizzle<T, 0, 0, 0> rrr;
        Swizzle<T, 0, 0, 1> rrg;
        Swizzle<T, 0, 0, 2> rrb;
        Swizzle<T, 0, 1, 0> rgr;
        Swizzle<T, 0, 1, 1> rgg;
        Swizzle<T, 0, 1, 2> rgb;
        Swizzle<T, 0, 2, 0> rbr;
        Swizzle<T, 0, 2, 1> rbg;
        Swizzle<T, 0, 2, 2> rbb;
        Swizzle<T, 1, 0, 0> grr;
        Swizzle<T, 1, 0, 1> grg;
        Swizzle<T, 1, 0, 2> grb;
        Swizzle<T, 1, 1, 0> ggr;
        Swizzle<T, 1, 1, 1> ggg;
        Swizzle<T, 1, 1, 2> ggb;
        Swizzle<T, 1, 2, 0> gbr;
        Swizzle<T, 1, 2, 1> gbg;
        Swizzle<T, 1, 2, 2> gbb;
        Swizzle<T, 2, 0, 0> brr;
        Swizzle<T, 2, 0, 1> brg;
        Swizzle<T, 2, 0, 2> brb;
        Swizzle<T, 2, 1, 0> bgr;
        Swizzle<T, 2, 1, 1> bgg;
        Swizzle<T, 2, 1, 2> bgb;
        Swizzle<T, 2, 2, 0> bbr;
        Swizzle<T, 2, 2, 1> bbg;
        Swizzle<T, 2, 2, 2> bbb;
        Swizzle<T, 0, 0, 0, 0> rrrr;
        Swizzle<T, 0, 0, 0, 1> rrrg;
        Swizzle<T, 0, 0, 0, 2> rrrb;
        Swizzle<T, 0, 0, 1, 0> rrgr;
        Swizzle<T, 0, 0, 1, 1> rrgg;
        Swizzle<T, 0, 0, 1, 2> rrgb;
        Swizzle<T, 0, 1, 0, 0> rgrr;
        Swizzle<T, 0, 1, 0, 1> rgrg;
        Swizzle<T, 0, 1, 0, 2> rgrb;
        Swizzle<T, 0, 1, 1, 0> rggr;
        Swizzle<T, 0, 1, 1, 1> rggg;
        Swizzle<T, 0, 1, 1, 2> rggb;
        Swizzle<T, 0, 1, 2, 0> rgbr;
        Swizzle<T, 0, 1, 2, 1> rgbg;
        Swizzle<T, 0, 1, 2, 2> rgbb;
        Swizzle<T, 0, 2, 0, 0> rbrr;
        Swizzle<T, 0, 2, 0, 1> rbrg;
        Swizzle<T, 0, 2, 0, 2> rbrb;
        Swizzle<T, 0, 2, 1, 0> rbgr;
        Swizzle<T, 0, 2, 1, 1> rbgg;
        Swizzle<T, 0, 2, 1, 2> rbgb;
        Swizzle<T, 0, 2, 2, 0> rbbr;
        Swizzle<T, 0, 2, 2, 1> rbbg;
        Swizzle<T, 0, 2, 2, 2> rbbb;
        Swizzle<T, 1, 0, 0, 0> grrr;
        Swizzle<T, 1, 0, 0, 1> grrg;
        Swizzle<T, 1, 0, 0, 2> grrb;
        Swizzle<T, 1, 0, 1, 0> grgr;
        Swizzle<T, 1, 0, 1, 1> grgg;
        Swizzle<T, 1, 0, 1, 2> grgb;
        Swizzle<T, 1, 0, 2, 0> grbr;
        Swizzle<T, 1, 0, 2, 1> grbg;
        Swizzle<T, 1, 0, 2, 2> grbb;
        Swizzle<T, 1, 1, 0, 0> ggrr;
        Swizzle<T, 1, 1, 0, 1> ggrg;
        Swizzle<T, 1, 1, 0, 2> ggrb;
        Swizzle<T, 1, 1, 1, 0> gggr;
        Swizzle<T, 1, 1, 1, 1> gggg;
        Swizzle<T, 1, 1, 1, 2> gggb;
        Swizzle<T, 1, 1, 2, 0> ggbr;
        Swizzle<T, 1, 1, 2, 1> ggbg;
        Swizzle<T, 1, 1, 2, 2> ggbb;
        Swizzle<T, 1, 2, 0, 0> gbrr;
        Swizzle<T, 1, 2, 0, 1> gbrg;
        Swizzle<T, 1, 2, 0, 2> gbrb;
        Swizzle<T, 1, 2, 1, 0> gbgr;
        Swizzle<T, 1, 2, 1, 1> gbgg;
        Swizzle<T, 1, 2, 1, 2> gbgb;
        Swizzle<T, 1, 2, 2, 0> gbbr;
        Swizzle<T, 1, 2, 2, 1> gbbg;
        Swizzle<T, 1, 2, 2, 2> gbbb;
        Swizzle<T, 2, 0, 0, 0> brrr;
        Swizzle<T, 2, 0, 0, 1> brrg;
        Swizzle<T, 2, 0, 0, 2> brrb;
        Swizzle<T, 2, 0, 1, 0> brgr;
        Swizzle<T, 2, 0, 1, 1> brgg;
        Swizzle<T, 2, 0, 1, 2> brgb;
        Swizzle<T, 2, 0, 2, 0> brbr;
        Swizzle<T, 2, 0, 2, 1> brbg;
        Swizzle<T, 2, 0, 2, 2> brbb;
        Swizzle<T, 2, 1, 0, 0> bgrr;
        Swizzle<T, 2, 1, 0, 1> bgrg;
        Swizzle<T, 2, 1, 0, 2> bgrb;
        Swizzle<T, 2, 1, 1, 0> bggr;
        Swizzle<T, 2, 1, 1, 1> bggg;
        Swizzle<T, 2, 1, 1, 2> bggb;
        Swizzle<T, 2, 1, 2, 0> bgbr;
        Swizzle<T, 2, 1, 2, 1> bgbg;
        Swizzle<T, 2, 1, 2, 2> bgbb;
        Swizzle<T, 2, 2, 0, 0> bbrr;
        Swizzle<T, 2, 2, 0, 1> bbrg;
        Swizzle<T, 2, 2, 0, 2> bbrb;
        Swizzle<T, 2, 2, 1, 0> bbgr;
        Swizzle<T, 2, 2, 1, 1> bbgg;
        Swizzle<T, 2, 2, 1, 2> bbgb;
        Swizzle<T, 2, 2, 2, 0> bbbr;
        Swizzle<T, 2, 2, 2, 1> bbbg;
        Swizzle<T, 2, 2, 2, 2> bbbb;
#pragma endregion vec3_rgb

      };
    };

#pragma endregion VEC3_INTERNAL

#pragma region VEC4_INTERNAL

    template <typename T>
    class vec_internal_data<T, 4>
    {
    public:
      union
      {
        T store[4];
#pragma region vec4_xyzw
        Swizzle<T, 0> x;
        Swizzle<T, 1> y;
        Swizzle<T, 2> z;
        Swizzle<T, 3> w;
        Swizzle<T, 0, 0> xx;
        Swizzle<T, 0, 1> xy;
        Swizzle<T, 0, 2> xz;
        Swizzle<T, 0, 3> xw;
        Swizzle<T, 1, 0> yx;
        Swizzle<T, 1, 1> yy;
        Swizzle<T, 1, 2> yz;
        Swizzle<T, 1, 3> yw;
        Swizzle<T, 2, 0> zx;
        Swizzle<T, 2, 1> zy;
        Swizzle<T, 2, 2> zz;
        Swizzle<T, 2, 3> zw;
        Swizzle<T, 3, 0> wx;
        Swizzle<T, 3, 1> wy;
        Swizzle<T, 3, 2> wz;
        Swizzle<T, 3, 3> ww;
        Swizzle<T, 0, 0, 0> xxx;
        Swizzle<T, 0, 0, 1> xxy;
        Swizzle<T, 0, 0, 2> xxz;
        Swizzle<T, 0, 0, 3> xxw;
        Swizzle<T, 0, 1, 0> xyx;
        Swizzle<T, 0, 1, 1> xyy;
        Swizzle<T, 0, 1, 2> xyz;
        Swizzle<T, 0, 1, 3> xyw;
        Swizzle<T, 0, 2, 0> xzx;
        Swizzle<T, 0, 2, 1> xzy;
        Swizzle<T, 0, 2, 2> xzz;
        Swizzle<T, 0, 2, 3> xzw;
        Swizzle<T, 0, 3, 0> xwx;
        Swizzle<T, 0, 3, 1> xwy;
        Swizzle<T, 0, 3, 2> xwz;
        Swizzle<T, 0, 3, 3> xww;
        Swizzle<T, 1, 0, 0> yxx;
        Swizzle<T, 1, 0, 1> yxy;
        Swizzle<T, 1, 0, 2> yxz;
        Swizzle<T, 1, 0, 3> yxw;
        Swizzle<T, 1, 1, 0> yyx;
        Swizzle<T, 1, 1, 1> yyy;
        Swizzle<T, 1, 1, 2> yyz;
        Swizzle<T, 1, 1, 3> yyw;
        Swizzle<T, 1, 2, 0> yzx;
        Swizzle<T, 1, 2, 1> yzy;
        Swizzle<T, 1, 2, 2> yzz;
        Swizzle<T, 1, 2, 3> yzw;
        Swizzle<T, 1, 3, 0> ywx;
        Swizzle<T, 1, 3, 1> ywy;
        Swizzle<T, 1, 3, 2> ywz;
        Swizzle<T, 1, 3, 3> yww;
        Swizzle<T, 2, 0, 0> zxx;
        Swizzle<T, 2, 0, 1> zxy;
        Swizzle<T, 2, 0, 2> zxz;
        Swizzle<T, 2, 0, 3> zxw;
        Swizzle<T, 2, 1, 0> zyx;
        Swizzle<T, 2, 1, 1> zyy;
        Swizzle<T, 2, 1, 2> zyz;
        Swizzle<T, 2, 1, 3> zyw;
        Swizzle<T, 2, 2, 0> zzx;
        Swizzle<T, 2, 2, 1> zzy;
        Swizzle<T, 2, 2, 2> zzz;
        Swizzle<T, 2, 2, 3> zzw;
        Swizzle<T, 2, 3, 0> zwx;
        Swizzle<T, 2, 3, 1> zwy;
        Swizzle<T, 2, 3, 2> zwz;
        Swizzle<T, 2, 3, 3> zww;
        Swizzle<T, 3, 0, 0> wxx;
        Swizzle<T, 3, 0, 1> wxy;
        Swizzle<T, 3, 0, 2> wxz;
        Swizzle<T, 3, 0, 3> wxw;
        Swizzle<T, 3, 1, 0> wyx;
        Swizzle<T, 3, 1, 1> wyy;
        Swizzle<T, 3, 1, 2> wyz;
        Swizzle<T, 3, 1, 3> wyw;
        Swizzle<T, 3, 2, 0> wzx;
        Swizzle<T, 3, 2, 1> wzy;
        Swizzle<T, 3, 2, 2> wzz;
        Swizzle<T, 3, 2, 3> wzw;
        Swizzle<T, 3, 3, 0> wwx;
        Swizzle<T, 3, 3, 1> wwy;
        Swizzle<T, 3, 3, 2> wwz;
        Swizzle<T, 3, 3, 3> www;
        Swizzle<T, 0, 0, 0, 0> xxxx;
        Swizzle<T, 0, 0, 0, 1> xxxy;
        Swizzle<T, 0, 0, 0, 2> xxxz;
        Swizzle<T, 0, 0, 0, 3> xxxw;
        Swizzle<T, 0, 0, 1, 0> xxyx;
        Swizzle<T, 0, 0, 1, 1> xxyy;
        Swizzle<T, 0, 0, 1, 2> xxyz;
        Swizzle<T, 0, 0, 1, 3> xxyw;
        Swizzle<T, 0, 0, 2, 0> xxzx;
        Swizzle<T, 0, 0, 2, 1> xxzy;
        Swizzle<T, 0, 0, 2, 2> xxzz;
        Swizzle<T, 0, 0, 2, 3> xxzw;
        Swizzle<T, 0, 0, 3, 0> xxwx;
        Swizzle<T, 0, 0, 3, 1> xxwy;
        Swizzle<T, 0, 0, 3, 2> xxwz;
        Swizzle<T, 0, 0, 3, 3> xxww;
        Swizzle<T, 0, 1, 0, 0> xyxx;
        Swizzle<T, 0, 1, 0, 1> xyxy;
        Swizzle<T, 0, 1, 0, 2> xyxz;
        Swizzle<T, 0, 1, 0, 3> xyxw;
        Swizzle<T, 0, 1, 1, 0> xyyx;
        Swizzle<T, 0, 1, 1, 1> xyyy;
        Swizzle<T, 0, 1, 1, 2> xyyz;
        Swizzle<T, 0, 1, 1, 3> xyyw;
        Swizzle<T, 0, 1, 2, 0> xyzx;
        Swizzle<T, 0, 1, 2, 1> xyzy;
        Swizzle<T, 0, 1, 2, 2> xyzz;
        Swizzle<T, 0, 1, 2, 3> xyzw;
        Swizzle<T, 0, 1, 3, 0> xywx;
        Swizzle<T, 0, 1, 3, 1> xywy;
        Swizzle<T, 0, 1, 3, 2> xywz;
        Swizzle<T, 0, 1, 3, 3> xyww;
        Swizzle<T, 0, 2, 0, 0> xzxx;
        Swizzle<T, 0, 2, 0, 1> xzxy;
        Swizzle<T, 0, 2, 0, 2> xzxz;
        Swizzle<T, 0, 2, 0, 3> xzxw;
        Swizzle<T, 0, 2, 1, 0> xzyx;
        Swizzle<T, 0, 2, 1, 1> xzyy;
        Swizzle<T, 0, 2, 1, 2> xzyz;
        Swizzle<T, 0, 2, 1, 3> xzyw;
        Swizzle<T, 0, 2, 2, 0> xzzx;
        Swizzle<T, 0, 2, 2, 1> xzzy;
        Swizzle<T, 0, 2, 2, 2> xzzz;
        Swizzle<T, 0, 2, 2, 3> xzzw;
        Swizzle<T, 0, 2, 3, 0> xzwx;
        Swizzle<T, 0, 2, 3, 1> xzwy;
        Swizzle<T, 0, 2, 3, 2> xzwz;
        Swizzle<T, 0, 2, 3, 3> xzww;
        Swizzle<T, 0, 3, 0, 0> xwxx;
        Swizzle<T, 0, 3, 0, 1> xwxy;
        Swizzle<T, 0, 3, 0, 2> xwxz;
        Swizzle<T, 0, 3, 0, 3> xwxw;
        Swizzle<T, 0, 3, 1, 0> xwyx;
        Swizzle<T, 0, 3, 1, 1> xwyy;
        Swizzle<T, 0, 3, 1, 2> xwyz;
        Swizzle<T, 0, 3, 1, 3> xwyw;
        Swizzle<T, 0, 3, 2, 0> xwzx;
        Swizzle<T, 0, 3, 2, 1> xwzy;
        Swizzle<T, 0, 3, 2, 2> xwzz;
        Swizzle<T, 0, 3, 2, 3> xwzw;
        Swizzle<T, 0, 3, 3, 0> xwwx;
        Swizzle<T, 0, 3, 3, 1> xwwy;
        Swizzle<T, 0, 3, 3, 2> xwwz;
        Swizzle<T, 0, 3, 3, 3> xwww;
        Swizzle<T, 1, 0, 0, 0> yxxx;
        Swizzle<T, 1, 0, 0, 1> yxxy;
        Swizzle<T, 1, 0, 0, 2> yxxz;
        Swizzle<T, 1, 0, 0, 3> yxxw;
        Swizzle<T, 1, 0, 1, 0> yxyx;
        Swizzle<T, 1, 0, 1, 1> yxyy;
        Swizzle<T, 1, 0, 1, 2> yxyz;
        Swizzle<T, 1, 0, 1, 3> yxyw;
        Swizzle<T, 1, 0, 2, 0> yxzx;
        Swizzle<T, 1, 0, 2, 1> yxzy;
        Swizzle<T, 1, 0, 2, 2> yxzz;
        Swizzle<T, 1, 0, 2, 3> yxzw;
        Swizzle<T, 1, 0, 3, 0> yxwx;
        Swizzle<T, 1, 0, 3, 1> yxwy;
        Swizzle<T, 1, 0, 3, 2> yxwz;
        Swizzle<T, 1, 0, 3, 3> yxww;
        Swizzle<T, 1, 1, 0, 0> yyxx;
        Swizzle<T, 1, 1, 0, 1> yyxy;
        Swizzle<T, 1, 1, 0, 2> yyxz;
        Swizzle<T, 1, 1, 0, 3> yyxw;
        Swizzle<T, 1, 1, 1, 0> yyyx;
        Swizzle<T, 1, 1, 1, 1> yyyy;
        Swizzle<T, 1, 1, 1, 2> yyyz;
        Swizzle<T, 1, 1, 1, 3> yyyw;
        Swizzle<T, 1, 1, 2, 0> yyzx;
        Swizzle<T, 1, 1, 2, 1> yyzy;
        Swizzle<T, 1, 1, 2, 2> yyzz;
        Swizzle<T, 1, 1, 2, 3> yyzw;
        Swizzle<T, 1, 1, 3, 0> yywx;
        Swizzle<T, 1, 1, 3, 1> yywy;
        Swizzle<T, 1, 1, 3, 2> yywz;
        Swizzle<T, 1, 1, 3, 3> yyww;
        Swizzle<T, 1, 2, 0, 0> yzxx;
        Swizzle<T, 1, 2, 0, 1> yzxy;
        Swizzle<T, 1, 2, 0, 2> yzxz;
        Swizzle<T, 1, 2, 0, 3> yzxw;
        Swizzle<T, 1, 2, 1, 0> yzyx;
        Swizzle<T, 1, 2, 1, 1> yzyy;
        Swizzle<T, 1, 2, 1, 2> yzyz;
        Swizzle<T, 1, 2, 1, 3> yzyw;
        Swizzle<T, 1, 2, 2, 0> yzzx;
        Swizzle<T, 1, 2, 2, 1> yzzy;
        Swizzle<T, 1, 2, 2, 2> yzzz;
        Swizzle<T, 1, 2, 2, 3> yzzw;
        Swizzle<T, 1, 2, 3, 0> yzwx;
        Swizzle<T, 1, 2, 3, 1> yzwy;
        Swizzle<T, 1, 2, 3, 2> yzwz;
        Swizzle<T, 1, 2, 3, 3> yzww;
        Swizzle<T, 1, 3, 0, 0> ywxx;
        Swizzle<T, 1, 3, 0, 1> ywxy;
        Swizzle<T, 1, 3, 0, 2> ywxz;
        Swizzle<T, 1, 3, 0, 3> ywxw;
        Swizzle<T, 1, 3, 1, 0> ywyx;
        Swizzle<T, 1, 3, 1, 1> ywyy;
        Swizzle<T, 1, 3, 1, 2> ywyz;
        Swizzle<T, 1, 3, 1, 3> ywyw;
        Swizzle<T, 1, 3, 2, 0> ywzx;
        Swizzle<T, 1, 3, 2, 1> ywzy;
        Swizzle<T, 1, 3, 2, 2> ywzz;
        Swizzle<T, 1, 3, 2, 3> ywzw;
        Swizzle<T, 1, 3, 3, 0> ywwx;
        Swizzle<T, 1, 3, 3, 1> ywwy;
        Swizzle<T, 1, 3, 3, 2> ywwz;
        Swizzle<T, 1, 3, 3, 3> ywww;
        Swizzle<T, 2, 0, 0, 0> zxxx;
        Swizzle<T, 2, 0, 0, 1> zxxy;
        Swizzle<T, 2, 0, 0, 2> zxxz;
        Swizzle<T, 2, 0, 0, 3> zxxw;
        Swizzle<T, 2, 0, 1, 0> zxyx;
        Swizzle<T, 2, 0, 1, 1> zxyy;
        Swizzle<T, 2, 0, 1, 2> zxyz;
        Swizzle<T, 2, 0, 1, 3> zxyw;
        Swizzle<T, 2, 0, 2, 0> zxzx;
        Swizzle<T, 2, 0, 2, 1> zxzy;
        Swizzle<T, 2, 0, 2, 2> zxzz;
        Swizzle<T, 2, 0, 2, 3> zxzw;
        Swizzle<T, 2, 0, 3, 0> zxwx;
        Swizzle<T, 2, 0, 3, 1> zxwy;
        Swizzle<T, 2, 0, 3, 2> zxwz;
        Swizzle<T, 2, 0, 3, 3> zxww;
        Swizzle<T, 2, 1, 0, 0> zyxx;
        Swizzle<T, 2, 1, 0, 1> zyxy;
        Swizzle<T, 2, 1, 0, 2> zyxz;
        Swizzle<T, 2, 1, 0, 3> zyxw;
        Swizzle<T, 2, 1, 1, 0> zyyx;
        Swizzle<T, 2, 1, 1, 1> zyyy;
        Swizzle<T, 2, 1, 1, 2> zyyz;
        Swizzle<T, 2, 1, 1, 3> zyyw;
        Swizzle<T, 2, 1, 2, 0> zyzx;
        Swizzle<T, 2, 1, 2, 1> zyzy;
        Swizzle<T, 2, 1, 2, 2> zyzz;
        Swizzle<T, 2, 1, 2, 3> zyzw;
        Swizzle<T, 2, 1, 3, 0> zywx;
        Swizzle<T, 2, 1, 3, 1> zywy;
        Swizzle<T, 2, 1, 3, 2> zywz;
        Swizzle<T, 2, 1, 3, 3> zyww;
        Swizzle<T, 2, 2, 0, 0> zzxx;
        Swizzle<T, 2, 2, 0, 1> zzxy;
        Swizzle<T, 2, 2, 0, 2> zzxz;
        Swizzle<T, 2, 2, 0, 3> zzxw;
        Swizzle<T, 2, 2, 1, 0> zzyx;
        Swizzle<T, 2, 2, 1, 1> zzyy;
        Swizzle<T, 2, 2, 1, 2> zzyz;
        Swizzle<T, 2, 2, 1, 3> zzyw;
        Swizzle<T, 2, 2, 2, 0> zzzx;
        Swizzle<T, 2, 2, 2, 1> zzzy;
        Swizzle<T, 2, 2, 2, 2> zzzz;
        Swizzle<T, 2, 2, 2, 3> zzzw;
        Swizzle<T, 2, 2, 3, 0> zzwx;
        Swizzle<T, 2, 2, 3, 1> zzwy;
        Swizzle<T, 2, 2, 3, 2> zzwz;
        Swizzle<T, 2, 2, 3, 3> zzww;
        Swizzle<T, 2, 3, 0, 0> zwxx;
        Swizzle<T, 2, 3, 0, 1> zwxy;
        Swizzle<T, 2, 3, 0, 2> zwxz;
        Swizzle<T, 2, 3, 0, 3> zwxw;
        Swizzle<T, 2, 3, 1, 0> zwyx;
        Swizzle<T, 2, 3, 1, 1> zwyy;
        Swizzle<T, 2, 3, 1, 2> zwyz;
        Swizzle<T, 2, 3, 1, 3> zwyw;
        Swizzle<T, 2, 3, 2, 0> zwzx;
        Swizzle<T, 2, 3, 2, 1> zwzy;
        Swizzle<T, 2, 3, 2, 2> zwzz;
        Swizzle<T, 2, 3, 2, 3> zwzw;
        Swizzle<T, 2, 3, 3, 0> zwwx;
        Swizzle<T, 2, 3, 3, 1> zwwy;
        Swizzle<T, 2, 3, 3, 2> zwwz;
        Swizzle<T, 2, 3, 3, 3> zwww;
        Swizzle<T, 3, 0, 0, 0> wxxx;
        Swizzle<T, 3, 0, 0, 1> wxxy;
        Swizzle<T, 3, 0, 0, 2> wxxz;
        Swizzle<T, 3, 0, 0, 3> wxxw;
        Swizzle<T, 3, 0, 1, 0> wxyx;
        Swizzle<T, 3, 0, 1, 1> wxyy;
        Swizzle<T, 3, 0, 1, 2> wxyz;
        Swizzle<T, 3, 0, 1, 3> wxyw;
        Swizzle<T, 3, 0, 2, 0> wxzx;
        Swizzle<T, 3, 0, 2, 1> wxzy;
        Swizzle<T, 3, 0, 2, 2> wxzz;
        Swizzle<T, 3, 0, 2, 3> wxzw;
        Swizzle<T, 3, 0, 3, 0> wxwx;
        Swizzle<T, 3, 0, 3, 1> wxwy;
        Swizzle<T, 3, 0, 3, 2> wxwz;
        Swizzle<T, 3, 0, 3, 3> wxww;
        Swizzle<T, 3, 1, 0, 0> wyxx;
        Swizzle<T, 3, 1, 0, 1> wyxy;
        Swizzle<T, 3, 1, 0, 2> wyxz;
        Swizzle<T, 3, 1, 0, 3> wyxw;
        Swizzle<T, 3, 1, 1, 0> wyyx;
        Swizzle<T, 3, 1, 1, 1> wyyy;
        Swizzle<T, 3, 1, 1, 2> wyyz;
        Swizzle<T, 3, 1, 1, 3> wyyw;
        Swizzle<T, 3, 1, 2, 0> wyzx;
        Swizzle<T, 3, 1, 2, 1> wyzy;
        Swizzle<T, 3, 1, 2, 2> wyzz;
        Swizzle<T, 3, 1, 2, 3> wyzw;
        Swizzle<T, 3, 1, 3, 0> wywx;
        Swizzle<T, 3, 1, 3, 1> wywy;
        Swizzle<T, 3, 1, 3, 2> wywz;
        Swizzle<T, 3, 1, 3, 3> wyww;
        Swizzle<T, 3, 2, 0, 0> wzxx;
        Swizzle<T, 3, 2, 0, 1> wzxy;
        Swizzle<T, 3, 2, 0, 2> wzxz;
        Swizzle<T, 3, 2, 0, 3> wzxw;
        Swizzle<T, 3, 2, 1, 0> wzyx;
        Swizzle<T, 3, 2, 1, 1> wzyy;
        Swizzle<T, 3, 2, 1, 2> wzyz;
        Swizzle<T, 3, 2, 1, 3> wzyw;
        Swizzle<T, 3, 2, 2, 0> wzzx;
        Swizzle<T, 3, 2, 2, 1> wzzy;
        Swizzle<T, 3, 2, 2, 2> wzzz;
        Swizzle<T, 3, 2, 2, 3> wzzw;
        Swizzle<T, 3, 2, 3, 0> wzwx;
        Swizzle<T, 3, 2, 3, 1> wzwy;
        Swizzle<T, 3, 2, 3, 2> wzwz;
        Swizzle<T, 3, 2, 3, 3> wzww;
        Swizzle<T, 3, 3, 0, 0> wwxx;
        Swizzle<T, 3, 3, 0, 1> wwxy;
        Swizzle<T, 3, 3, 0, 2> wwxz;
        Swizzle<T, 3, 3, 0, 3> wwxw;
        Swizzle<T, 3, 3, 1, 0> wwyx;
        Swizzle<T, 3, 3, 1, 1> wwyy;
        Swizzle<T, 3, 3, 1, 2> wwyz;
        Swizzle<T, 3, 3, 1, 3> wwyw;
        Swizzle<T, 3, 3, 2, 0> wwzx;
        Swizzle<T, 3, 3, 2, 1> wwzy;
        Swizzle<T, 3, 3, 2, 2> wwzz;
        Swizzle<T, 3, 3, 2, 3> wwzw;
        Swizzle<T, 3, 3, 3, 0> wwwx;
        Swizzle<T, 3, 3, 3, 1> wwwy;
        Swizzle<T, 3, 3, 3, 2> wwwz;
        Swizzle<T, 3, 3, 3, 3> wwww;
#pragma endregion vec4_xyzw
#pragma region vec4_rgba
        Swizzle<T, 0> r;
        Swizzle<T, 1> g;
        Swizzle<T, 2> b;
        Swizzle<T, 3> a;
        Swizzle<T, 0, 0> rr;
        Swizzle<T, 0, 1> rg;
        Swizzle<T, 0, 2> rb;
        Swizzle<T, 0, 3> ra;
        Swizzle<T, 1, 0> gr;
        Swizzle<T, 1, 1> gg;
        Swizzle<T, 1, 2> gb;
        Swizzle<T, 1, 3> ga;
        Swizzle<T, 2, 0> br;
        Swizzle<T, 2, 1> bg;
        Swizzle<T, 2, 2> bb;
        Swizzle<T, 2, 3> ba;
        Swizzle<T, 3, 0> ar;
        Swizzle<T, 3, 1> ag;
        Swizzle<T, 3, 2> ab;
        Swizzle<T, 3, 3> aa;
        Swizzle<T, 0, 0, 0> rrr;
        Swizzle<T, 0, 0, 1> rrg;
        Swizzle<T, 0, 0, 2> rrb;
        Swizzle<T, 0, 0, 3> rra;
        Swizzle<T, 0, 1, 0> rgr;
        Swizzle<T, 0, 1, 1> rgg;
        Swizzle<T, 0, 1, 2> rgb;
        Swizzle<T, 0, 1, 3> rga;
        Swizzle<T, 0, 2, 0> rbr;
        Swizzle<T, 0, 2, 1> rbg;
        Swizzle<T, 0, 2, 2> rbb;
        Swizzle<T, 0, 2, 3> rba;
        Swizzle<T, 0, 3, 0> rar;
        Swizzle<T, 0, 3, 1> rag;
        Swizzle<T, 0, 3, 2> rab;
        Swizzle<T, 0, 3, 3> raa;
        Swizzle<T, 1, 0, 0> grr;
        Swizzle<T, 1, 0, 1> grg;
        Swizzle<T, 1, 0, 2> grb;
        Swizzle<T, 1, 0, 3> gra;
        Swizzle<T, 1, 1, 0> ggr;
        Swizzle<T, 1, 1, 1> ggg;
        Swizzle<T, 1, 1, 2> ggb;
        Swizzle<T, 1, 1, 3> gga;
        Swizzle<T, 1, 2, 0> gbr;
        Swizzle<T, 1, 2, 1> gbg;
        Swizzle<T, 1, 2, 2> gbb;
        Swizzle<T, 1, 2, 3> gba;
        Swizzle<T, 1, 3, 0> gar;
        Swizzle<T, 1, 3, 1> gag;
        Swizzle<T, 1, 3, 2> gab;
        Swizzle<T, 1, 3, 3> gaa;
        Swizzle<T, 2, 0, 0> brr;
        Swizzle<T, 2, 0, 1> brg;
        Swizzle<T, 2, 0, 2> brb;
        Swizzle<T, 2, 0, 3> bra;
        Swizzle<T, 2, 1, 0> bgr;
        Swizzle<T, 2, 1, 1> bgg;
        Swizzle<T, 2, 1, 2> bgb;
        Swizzle<T, 2, 1, 3> bga;
        Swizzle<T, 2, 2, 0> bbr;
        Swizzle<T, 2, 2, 1> bbg;
        Swizzle<T, 2, 2, 2> bbb;
        Swizzle<T, 2, 2, 3> bba;
        Swizzle<T, 2, 3, 0> bar;
        Swizzle<T, 2, 3, 1> bag;
        Swizzle<T, 2, 3, 2> bab;
        Swizzle<T, 2, 3, 3> baa;
        Swizzle<T, 3, 0, 0> arr;
        Swizzle<T, 3, 0, 1> arg;
        Swizzle<T, 3, 0, 2> arb;
        Swizzle<T, 3, 0, 3> ara;
        Swizzle<T, 3, 1, 0> agr;
        Swizzle<T, 3, 1, 1> agg;
        Swizzle<T, 3, 1, 2> agb;
        Swizzle<T, 3, 1, 3> aga;
        Swizzle<T, 3, 2, 0> abr;
        Swizzle<T, 3, 2, 1> abg;
        Swizzle<T, 3, 2, 2> abb;
        Swizzle<T, 3, 2, 3> aba;
        Swizzle<T, 3, 3, 0> aar;
        Swizzle<T, 3, 3, 1> aag;
        Swizzle<T, 3, 3, 2> aab;
        Swizzle<T, 3, 3, 3> aaa;
        Swizzle<T, 0, 0, 0, 0> rrrr;
        Swizzle<T, 0, 0, 0, 1> rrrg;
        Swizzle<T, 0, 0, 0, 2> rrrb;
        Swizzle<T, 0, 0, 0, 3> rrra;
        Swizzle<T, 0, 0, 1, 0> rrgr;
        Swizzle<T, 0, 0, 1, 1> rrgg;
        Swizzle<T, 0, 0, 1, 2> rrgb;
        Swizzle<T, 0, 0, 1, 3> rrga;
        Swizzle<T, 0, 0, 2, 0> rrbr;
        Swizzle<T, 0, 0, 2, 1> rrbg;
        Swizzle<T, 0, 0, 2, 2> rrbb;
        Swizzle<T, 0, 0, 2, 3> rrba;
        Swizzle<T, 0, 0, 3, 0> rrar;
        Swizzle<T, 0, 0, 3, 1> rrag;
        Swizzle<T, 0, 0, 3, 2> rrab;
        Swizzle<T, 0, 0, 3, 3> rraa;
        Swizzle<T, 0, 1, 0, 0> rgrr;
        Swizzle<T, 0, 1, 0, 1> rgrg;
        Swizzle<T, 0, 1, 0, 2> rgrb;
        Swizzle<T, 0, 1, 0, 3> rgra;
        Swizzle<T, 0, 1, 1, 0> rggr;
        Swizzle<T, 0, 1, 1, 1> rggg;
        Swizzle<T, 0, 1, 1, 2> rggb;
        Swizzle<T, 0, 1, 1, 3> rgga;
        Swizzle<T, 0, 1, 2, 0> rgbr;
        Swizzle<T, 0, 1, 2, 1> rgbg;
        Swizzle<T, 0, 1, 2, 2> rgbb;
        Swizzle<T, 0, 1, 2, 3> rgba;
        Swizzle<T, 0, 1, 3, 0> rgar;
        Swizzle<T, 0, 1, 3, 1> rgag;
        Swizzle<T, 0, 1, 3, 2> rgab;
        Swizzle<T, 0, 1, 3, 3> rgaa;
        Swizzle<T, 0, 2, 0, 0> rbrr;
        Swizzle<T, 0, 2, 0, 1> rbrg;
        Swizzle<T, 0, 2, 0, 2> rbrb;
        Swizzle<T, 0, 2, 0, 3> rbra;
        Swizzle<T, 0, 2, 1, 0> rbgr;
        Swizzle<T, 0, 2, 1, 1> rbgg;
        Swizzle<T, 0, 2, 1, 2> rbgb;
        Swizzle<T, 0, 2, 1, 3> rbga;
        Swizzle<T, 0, 2, 2, 0> rbbr;
        Swizzle<T, 0, 2, 2, 1> rbbg;
        Swizzle<T, 0, 2, 2, 2> rbbb;
        Swizzle<T, 0, 2, 2, 3> rbba;
        Swizzle<T, 0, 2, 3, 0> rbar;
        Swizzle<T, 0, 2, 3, 1> rbag;
        Swizzle<T, 0, 2, 3, 2> rbab;
        Swizzle<T, 0, 2, 3, 3> rbaa;
        Swizzle<T, 0, 3, 0, 0> rarr;
        Swizzle<T, 0, 3, 0, 1> rarg;
        Swizzle<T, 0, 3, 0, 2> rarb;
        Swizzle<T, 0, 3, 0, 3> rara;
        Swizzle<T, 0, 3, 1, 0> ragr;
        Swizzle<T, 0, 3, 1, 1> ragg;
        Swizzle<T, 0, 3, 1, 2> ragb;
        Swizzle<T, 0, 3, 1, 3> raga;
        Swizzle<T, 0, 3, 2, 0> rabr;
        Swizzle<T, 0, 3, 2, 1> rabg;
        Swizzle<T, 0, 3, 2, 2> rabb;
        Swizzle<T, 0, 3, 2, 3> raba;
        Swizzle<T, 0, 3, 3, 0> raar;
        Swizzle<T, 0, 3, 3, 1> raag;
        Swizzle<T, 0, 3, 3, 2> raab;
        Swizzle<T, 0, 3, 3, 3> raaa;
        Swizzle<T, 1, 0, 0, 0> grrr;
        Swizzle<T, 1, 0, 0, 1> grrg;
        Swizzle<T, 1, 0, 0, 2> grrb;
        Swizzle<T, 1, 0, 0, 3> grra;
        Swizzle<T, 1, 0, 1, 0> grgr;
        Swizzle<T, 1, 0, 1, 1> grgg;
        Swizzle<T, 1, 0, 1, 2> grgb;
        Swizzle<T, 1, 0, 1, 3> grga;
        Swizzle<T, 1, 0, 2, 0> grbr;
        Swizzle<T, 1, 0, 2, 1> grbg;
        Swizzle<T, 1, 0, 2, 2> grbb;
        Swizzle<T, 1, 0, 2, 3> grba;
        Swizzle<T, 1, 0, 3, 0> grar;
        Swizzle<T, 1, 0, 3, 1> grag;
        Swizzle<T, 1, 0, 3, 2> grab;
        Swizzle<T, 1, 0, 3, 3> graa;
        Swizzle<T, 1, 1, 0, 0> ggrr;
        Swizzle<T, 1, 1, 0, 1> ggrg;
        Swizzle<T, 1, 1, 0, 2> ggrb;
        Swizzle<T, 1, 1, 0, 3> ggra;
        Swizzle<T, 1, 1, 1, 0> gggr;
        Swizzle<T, 1, 1, 1, 1> gggg;
        Swizzle<T, 1, 1, 1, 2> gggb;
        Swizzle<T, 1, 1, 1, 3> ggga;
        Swizzle<T, 1, 1, 2, 0> ggbr;
        Swizzle<T, 1, 1, 2, 1> ggbg;
        Swizzle<T, 1, 1, 2, 2> ggbb;
        Swizzle<T, 1, 1, 2, 3> ggba;
        Swizzle<T, 1, 1, 3, 0> ggar;
        Swizzle<T, 1, 1, 3, 1> ggag;
        Swizzle<T, 1, 1, 3, 2> ggab;
        Swizzle<T, 1, 1, 3, 3> ggaa;
        Swizzle<T, 1, 2, 0, 0> gbrr;
        Swizzle<T, 1, 2, 0, 1> gbrg;
        Swizzle<T, 1, 2, 0, 2> gbrb;
        Swizzle<T, 1, 2, 0, 3> gbra;
        Swizzle<T, 1, 2, 1, 0> gbgr;
        Swizzle<T, 1, 2, 1, 1> gbgg;
        Swizzle<T, 1, 2, 1, 2> gbgb;
        Swizzle<T, 1, 2, 1, 3> gbga;
        Swizzle<T, 1, 2, 2, 0> gbbr;
        Swizzle<T, 1, 2, 2, 1> gbbg;
        Swizzle<T, 1, 2, 2, 2> gbbb;
        Swizzle<T, 1, 2, 2, 3> gbba;
        Swizzle<T, 1, 2, 3, 0> gbar;
        Swizzle<T, 1, 2, 3, 1> gbag;
        Swizzle<T, 1, 2, 3, 2> gbab;
        Swizzle<T, 1, 2, 3, 3> gbaa;
        Swizzle<T, 1, 3, 0, 0> garr;
        Swizzle<T, 1, 3, 0, 1> garg;
        Swizzle<T, 1, 3, 0, 2> garb;
        Swizzle<T, 1, 3, 0, 3> gara;
        Swizzle<T, 1, 3, 1, 0> gagr;
        Swizzle<T, 1, 3, 1, 1> gagg;
        Swizzle<T, 1, 3, 1, 2> gagb;
        Swizzle<T, 1, 3, 1, 3> gaga;
        Swizzle<T, 1, 3, 2, 0> gabr;
        Swizzle<T, 1, 3, 2, 1> gabg;
        Swizzle<T, 1, 3, 2, 2> gabb;
        Swizzle<T, 1, 3, 2, 3> gaba;
        Swizzle<T, 1, 3, 3, 0> gaar;
        Swizzle<T, 1, 3, 3, 1> gaag;
        Swizzle<T, 1, 3, 3, 2> gaab;
        Swizzle<T, 1, 3, 3, 3> gaaa;
        Swizzle<T, 2, 0, 0, 0> brrr;
        Swizzle<T, 2, 0, 0, 1> brrg;
        Swizzle<T, 2, 0, 0, 2> brrb;
        Swizzle<T, 2, 0, 0, 3> brra;
        Swizzle<T, 2, 0, 1, 0> brgr;
        Swizzle<T, 2, 0, 1, 1> brgg;
        Swizzle<T, 2, 0, 1, 2> brgb;
        Swizzle<T, 2, 0, 1, 3> brga;
        Swizzle<T, 2, 0, 2, 0> brbr;
        Swizzle<T, 2, 0, 2, 1> brbg;
        Swizzle<T, 2, 0, 2, 2> brbb;
        Swizzle<T, 2, 0, 2, 3> brba;
        Swizzle<T, 2, 0, 3, 0> brar;
        Swizzle<T, 2, 0, 3, 1> brag;
        Swizzle<T, 2, 0, 3, 2> brab;
        Swizzle<T, 2, 0, 3, 3> braa;
        Swizzle<T, 2, 1, 0, 0> bgrr;
        Swizzle<T, 2, 1, 0, 1> bgrg;
        Swizzle<T, 2, 1, 0, 2> bgrb;
        Swizzle<T, 2, 1, 0, 3> bgra;
        Swizzle<T, 2, 1, 1, 0> bggr;
        Swizzle<T, 2, 1, 1, 1> bggg;
        Swizzle<T, 2, 1, 1, 2> bggb;
        Swizzle<T, 2, 1, 1, 3> bgga;
        Swizzle<T, 2, 1, 2, 0> bgbr;
        Swizzle<T, 2, 1, 2, 1> bgbg;
        Swizzle<T, 2, 1, 2, 2> bgbb;
        Swizzle<T, 2, 1, 2, 3> bgba;
        Swizzle<T, 2, 1, 3, 0> bgar;
        Swizzle<T, 2, 1, 3, 1> bgag;
        Swizzle<T, 2, 1, 3, 2> bgab;
        Swizzle<T, 2, 1, 3, 3> bgaa;
        Swizzle<T, 2, 2, 0, 0> bbrr;
        Swizzle<T, 2, 2, 0, 1> bbrg;
        Swizzle<T, 2, 2, 0, 2> bbrb;
        Swizzle<T, 2, 2, 0, 3> bbra;
        Swizzle<T, 2, 2, 1, 0> bbgr;
        Swizzle<T, 2, 2, 1, 1> bbgg;
        Swizzle<T, 2, 2, 1, 2> bbgb;
        Swizzle<T, 2, 2, 1, 3> bbga;
        Swizzle<T, 2, 2, 2, 0> bbbr;
        Swizzle<T, 2, 2, 2, 1> bbbg;
        Swizzle<T, 2, 2, 2, 2> bbbb;
        Swizzle<T, 2, 2, 2, 3> bbba;
        Swizzle<T, 2, 2, 3, 0> bbar;
        Swizzle<T, 2, 2, 3, 1> bbag;
        Swizzle<T, 2, 2, 3, 2> bbab;
        Swizzle<T, 2, 2, 3, 3> bbaa;
        Swizzle<T, 2, 3, 0, 0> barr;
        Swizzle<T, 2, 3, 0, 1> barg;
        Swizzle<T, 2, 3, 0, 2> barb;
        Swizzle<T, 2, 3, 0, 3> bara;
        Swizzle<T, 2, 3, 1, 0> bagr;
        Swizzle<T, 2, 3, 1, 1> bagg;
        Swizzle<T, 2, 3, 1, 2> bagb;
        Swizzle<T, 2, 3, 1, 3> baga;
        Swizzle<T, 2, 3, 2, 0> babr;
        Swizzle<T, 2, 3, 2, 1> babg;
        Swizzle<T, 2, 3, 2, 2> babb;
        Swizzle<T, 2, 3, 2, 3> baba;
        Swizzle<T, 2, 3, 3, 0> baar;
        Swizzle<T, 2, 3, 3, 1> baag;
        Swizzle<T, 2, 3, 3, 2> baab;
        Swizzle<T, 2, 3, 3, 3> baaa;
        Swizzle<T, 3, 0, 0, 0> arrr;
        Swizzle<T, 3, 0, 0, 1> arrg;
        Swizzle<T, 3, 0, 0, 2> arrb;
        Swizzle<T, 3, 0, 0, 3> arra;
        Swizzle<T, 3, 0, 1, 0> argr;
        Swizzle<T, 3, 0, 1, 1> argg;
        Swizzle<T, 3, 0, 1, 2> argb;
        Swizzle<T, 3, 0, 1, 3> arga;
        Swizzle<T, 3, 0, 2, 0> arbr;
        Swizzle<T, 3, 0, 2, 1> arbg;
        Swizzle<T, 3, 0, 2, 2> arbb;
        Swizzle<T, 3, 0, 2, 3> arba;
        Swizzle<T, 3, 0, 3, 0> arar;
        Swizzle<T, 3, 0, 3, 1> arag;
        Swizzle<T, 3, 0, 3, 2> arab;
        Swizzle<T, 3, 0, 3, 3> araa;
        Swizzle<T, 3, 1, 0, 0> agrr;
        Swizzle<T, 3, 1, 0, 1> agrg;
        Swizzle<T, 3, 1, 0, 2> agrb;
        Swizzle<T, 3, 1, 0, 3> agra;
        Swizzle<T, 3, 1, 1, 0> aggr;
        Swizzle<T, 3, 1, 1, 1> aggg;
        Swizzle<T, 3, 1, 1, 2> aggb;
        Swizzle<T, 3, 1, 1, 3> agga;
        Swizzle<T, 3, 1, 2, 0> agbr;
        Swizzle<T, 3, 1, 2, 1> agbg;
        Swizzle<T, 3, 1, 2, 2> agbb;
        Swizzle<T, 3, 1, 2, 3> agba;
        Swizzle<T, 3, 1, 3, 0> agar;
        Swizzle<T, 3, 1, 3, 1> agag;
        Swizzle<T, 3, 1, 3, 2> agab;
        Swizzle<T, 3, 1, 3, 3> agaa;
        Swizzle<T, 3, 2, 0, 0> abrr;
        Swizzle<T, 3, 2, 0, 1> abrg;
        Swizzle<T, 3, 2, 0, 2> abrb;
        Swizzle<T, 3, 2, 0, 3> abra;
        Swizzle<T, 3, 2, 1, 0> abgr;
        Swizzle<T, 3, 2, 1, 1> abgg;
        Swizzle<T, 3, 2, 1, 2> abgb;
        Swizzle<T, 3, 2, 1, 3> abga;
        Swizzle<T, 3, 2, 2, 0> abbr;
        Swizzle<T, 3, 2, 2, 1> abbg;
        Swizzle<T, 3, 2, 2, 2> abbb;
        Swizzle<T, 3, 2, 2, 3> abba;
        Swizzle<T, 3, 2, 3, 0> abar;
        Swizzle<T, 3, 2, 3, 1> abag;
        Swizzle<T, 3, 2, 3, 2> abab;
        Swizzle<T, 3, 2, 3, 3> abaa;
        Swizzle<T, 3, 3, 0, 0> aarr;
        Swizzle<T, 3, 3, 0, 1> aarg;
        Swizzle<T, 3, 3, 0, 2> aarb;
        Swizzle<T, 3, 3, 0, 3> aara;
        Swizzle<T, 3, 3, 1, 0> aagr;
        Swizzle<T, 3, 3, 1, 1> aagg;
        Swizzle<T, 3, 3, 1, 2> aagb;
        Swizzle<T, 3, 3, 1, 3> aaga;
        Swizzle<T, 3, 3, 2, 0> aabr;
        Swizzle<T, 3, 3, 2, 1> aabg;
        Swizzle<T, 3, 3, 2, 2> aabb;
        Swizzle<T, 3, 3, 2, 3> aaba;
        Swizzle<T, 3, 3, 3, 0> aaar;
        Swizzle<T, 3, 3, 3, 1> aaag;
        Swizzle<T, 3, 3, 3, 2> aaab;
        Swizzle<T, 3, 3, 3, 3> aaaa;
#pragma endregion vec4_rgba

      };
    };

#pragma endregion VEC4_INTERNAL

  }
}
