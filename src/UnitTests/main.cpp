#include <gtest/gtest.h>
#include <array>

#include "../PHM/phm.hpp"

int main(int argc, char** argv)
{

  testing::InitGoogleTest(&argc, argv);

  phm::vec4 aarg(1, 2, 3, 4);
  phm::vec2 uv(1);
  phm::vec3 blaarg(aarg.yxz);
  phm::vec2 glaarg = aarg.wx;

  phm::vec4 moron(glaarg, 3, 4.f); //yay this actually errors with the wrong number of args
  
  phm::vec3 idiot(moron);
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

  RUN_ALL_TESTS();

  getchar();
  return 0;
}
