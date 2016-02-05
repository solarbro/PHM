#include <gtest/gtest.h>
#include "mathTesting.h"
#include "../PHM/phm.hpp"

using namespace phm;

#pragma region MATH_TESTS
TEST(test_math, powi)     { EXPECT_FLOAT_EQ(std::pow(3.f, 2), phm::pow(3.f, 2)); }
TEST(test_math, powf)     { EXPECT_FLOAT_EQ(std::pow(2.5, 3.2), phm::pow(2.5, 3.2)); }
TEST(test_math, factorial){ EXPECT_EQ(3628800, phm::factorial(unsigned(10))); }
TEST(test_math, exp)      { EXPECT_FLOAT_EQ(268337.2865f, phm::exp(12.5f)); }
TEST(test_math, ln)       { EXPECT_FLOAT_EQ(1.f, std::log(75.21234f) / phm::ln(75.21234f)); }
TEST(test_math, log)      { EXPECT_FLOAT_EQ(std::log10(12.64f), phm::log(10.f, 12.64)); }
TEST(test_math, cos)      { EXPECT_FLOAT_EQ(cos(0.f), phm::cos(0.f)); }
TEST(test_math, sin)      { EXPECT_FLOAT_EQ(sin(phm::Constant<double>::half_pi), phm::sin(phm::Constant<double>::half_pi)); }
#pragma endregion MATH_TESTS
/**********************************************************
*                   VECTOR TESTS                          *
**********************************************************/

#pragma region VECTOR_LIB_TESTS

#pragma region TYPE_SELECTION_TESTS

TEST(type_selection,   short_short) { EXPECT_EQ(typeid(short).name() , typeid(ptype<short , short>).name() ); }
TEST(type_selection,     short_int) { EXPECT_EQ(typeid(int).name()   , typeid(ptype<short , int>).name()); }
TEST(type_selection,   short_float) { EXPECT_EQ(typeid(float).name() , typeid(ptype<short , float>).name()); }
TEST(type_selection,  short_double) { EXPECT_EQ(typeid(double).name(), typeid(ptype<short , double>).name()); }
TEST(type_selection,     int_short) { EXPECT_EQ(typeid(int).name()   , typeid(ptype<int   , short>).name()); }
TEST(type_selection,       int_int) { EXPECT_EQ(typeid(int).name()   , typeid(ptype<int   , int>).name()); }
TEST(type_selection,     int_float) { EXPECT_EQ(typeid(float).name() , typeid(ptype<int   , float>).name()); }
TEST(type_selection,    int_double) { EXPECT_EQ(typeid(double).name(), typeid(ptype<int   , double>).name()); }
TEST(type_selection,   float_short) { EXPECT_EQ(typeid(float).name() , typeid(ptype<float , short>).name()); }
TEST(type_selection,     float_int) { EXPECT_EQ(typeid(float).name() , typeid(ptype<float , int>).name()); }
TEST(type_selection,   float_float) { EXPECT_EQ(typeid(float).name() , typeid(ptype<float , float>).name()); }
TEST(type_selection,  float_double) { EXPECT_EQ(typeid(double).name(), typeid(ptype<float , double>).name()); }
TEST(type_selection,  double_short) { EXPECT_EQ(typeid(double).name(), typeid(ptype<double, short>).name()); }
TEST(type_selection,    double_int) { EXPECT_EQ(typeid(double).name(), typeid(ptype<double, int>).name()); }
TEST(type_selection,  double_float) { EXPECT_EQ(typeid(double).name(), typeid(ptype<double, float>).name()); }
TEST(type_selection, double_double) { EXPECT_EQ(typeid(double).name(), typeid(ptype<double, double>).name()); }

#pragma endregion TYPE_SELECTION_TESTS

#pragma region TYPE_VEC_TESTS

#pragma region TYPE_VEC_CTORS

TEST(type_vec_ctor, default_ctor1){ type_vec<short, 1> v1s; EXPECT_EQ(0, v1s[0]); }
TEST(type_vec_ctor, default_ctor2){ type_vec<int, 2> v2i; EXPECT_EQ(0, v2i.y); }
TEST(type_vec_ctor, default_ctor3){ type_vec<float, 3> v3f; EXPECT_EQ(0, v3f.z); }
TEST(type_vec_ctor, default_ctor4){ type_vec<double, 4> v4d; EXPECT_EQ(0, v4d[3]); }
TEST(type_vec_ctor, default_ctor150){ type_vec<unsigned, 150> v150u; EXPECT_EQ(0, v150u[67]); }

TEST(type_vec_ctor, one_arg_ctor1){ type_vec<short, 1> v1s(1.0); type_vec<short, 1> test; for (unsigned i = 0; i < 1; ++i) test[i] = (short)1.0; EXPECT_EQ(test, v1s); }
TEST(type_vec_ctor, one_arg_ctor2){ type_vec<short, 2> v1s(2.0); type_vec<int, 2> test; for (unsigned i = 0; i < 2; ++i) test[i] = (int)2.0; EXPECT_EQ(test, v1s); }
TEST(type_vec_ctor, one_arg_ctor3){ type_vec<short, 3> v1s(3.0); type_vec<float, 3> test; for (unsigned i = 0; i < 3; ++i) test[i] = (float)3.0; EXPECT_EQ(test, v1s); }
TEST(type_vec_ctor, one_arg_ctor4){ type_vec<short, 4> v1s(4.0); type_vec<double, 4> test; for (unsigned i = 0; i < 4; ++i) test[i] = (double)4.0; EXPECT_EQ(test, v1s); }
TEST(type_vec_ctor, one_arg_ctor150){ type_vec<short, 150> v1s(150.0); type_vec<unsigned, 150> test; for (unsigned i = 0; i < 150; ++i) test[i] = (unsigned)150.0; EXPECT_EQ(test, v1s); }


#pragma endregion TYPE_VEC_CTORS

#pragma region TYPE_VEC_OPERATORS





#pragma endregion TYPE_VEC_OPERATORS

#pragma region TYPE_VEC_FUNCTIONS





#pragma endregion TYPE_VEC_FUNCTIONS

#pragma endregion TYPE_VEC_TESTS

#pragma region TYPE_MAT_TESTS

#pragma region TYPE_MAT_CTORS




#pragma endregion TYPE_MAT_CTORS

#pragma region TYPE_MAT_OPERATORS




#pragma endregion TYPE_MAT_OPERATORS

#pragma region TYPE_MAT_FUNCTIONS




#pragma endregion TYPE_MAT_FUNCTIONS

#pragma endregion TYPE_MAT_TESTS

#pragma endregion VECTOR_LIB_TESTS


