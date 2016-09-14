//This is a sandbox for doing quick tests.
//RUN_ALL_TESTS runs the unit tests defined in GoogleTest.cpp.
//I'm still in the process of writing unit tests.

#include <gtest/gtest.h>
#include <array>

#include "../PHM/phm.hpp"

#include "../PHM/Tensor/Static/tensor.hpp"
#include "../PHM/Tensor/Static/Matrix/matrix.hpp"
#include "../PHM/Tensor/Static/Vector/vector.hpp"
#include "../PHM/Tensor/Static/Scalar/scalar.hpp"
#include <iostream>

int main(int argc, char** argv)
{

  //testing::InitGoogleTest(&argc, argv);

  phm::vec4 aarg(1, 2, 3, 4);
  phm::vec2 uv(1);
  phm::vec3 blaarg(aarg.yxz);
  phm::vec2 glaarg = aarg.wx;

  phm::vec4 wrong_args(glaarg, 3, 4.f); //yay this actually errors with the wrong number of args

  phm::vec3 idiot(wrong_args);
  std::array<float, 3> arrayTest = {1, 2, 3};
  phm::vec3 assign = phm::vec3(arrayTest);
  float boat = blaarg.g - glaarg.r;
  double trouble = aarg.b;
  double bubble = 3.0;
  bool test = bubble == blaarg.b;
  int mint = 3;
  int e_sizevec4 = 4 * sizeof(float);
  int r_sizevec4 = sizeof(phm::vec4);
  bool sizetest = r_sizevec4 == e_sizevec4;
  test = mint == blaarg.b;
  test = blaarg.b == mint;
  phm::dvec4 naarg = aarg.xxyw;
  naarg.yzx = blaarg;

  phm::type_vec<float, 1> real = aarg.y;
  aarg.z = real;
  real = 3.0;
  real.x = 4;
  trouble = real.x;
  bubble = real;

  phm::Reald meal = 1;

  naarg = meal.xxxx;

  //RUN_ALL_TESTS();

  phm::tensor<float, 2, 1> tensorvec2({1, 2});
  std::cout << tensorvec2.x << ", " << tensorvec2.y << std::endl;

  phm::tensor<int, 20, 1> tensorvec20({1, 2, 3, 4, 5});
  for(int i = 0; i < 20; ++i)
    std::cout << tensorvec20.store[i] << ", ";
  std::cout << std::endl;

  phm::tensor<int, 3, 3> mat3x3i{{1, 2, 3}, {4, 5, 6}, {7 , 8, 9}};
  phm::tensor<float, 3, 3>mat3x3f{{9, 8, 7}, {6, 5, 4}, {3, 2, 1}};

  auto result = mat3x3f + mat3x3i;

  for(int i = 0; i < 9; ++i)
    std::cout << result.store[i] << ", ";
  std::cout << std::endl;

  phm::tensor<int, 3, 4> mat3x4i = {{11, 12, 13, 14}, {21, 22, 23, 24}, {31, 32, 33, 34}};

  for(int i = 0; i < 3; ++i)
  {
    for(int j = 0; j < 4; ++j)
      std::cout << mat3x4i[i][j] << "\t";
    std::cout << std::endl;
  }

  phm::tensor<float, 3, 4> mat3x4f = {{1.1, 1.2, 1.3, 1.4}, {2.1, 2.2, 2.3, 2.4}, {3.1, 3.2, 3.3, 3.4}};

  for(int i = 0; i < 3; ++i)
  {
    for(int j = 0; j < 4; ++j)
      std::cout << mat3x4f[i][j] << "\t";
    std::cout << std::endl;
  }

  phm::tensor<int, 2, 2, 2, 2> order4 = {{{{1111, 1112}, {1121, 1122}}, {{1211, 1212}, {1221, 1222}}}, {{{2111, 2112}, {2121, 2122}}, {{2211, 2212}, {2221, 2222}}}};

  for(int i = 0; i < 2; ++i)
    for(int j = 0; j < 2; ++j)
      for(int k = 0; k < 2; ++k)
        for(int l = 0; l < 2; ++l)
          std::cout << order4[i][j][k][l] << ", ";

  std::cout << std::endl;
  // phm::tensor<double> scalar;
  // std::cout << scalar << std::endl;
  // scalar = 5;
  // std::cout << scalar << std::endl;

//  phm::tensor<float, 1, 1> mat1x1(3);//(scalar);

  //getchar();
  return 0;
}
