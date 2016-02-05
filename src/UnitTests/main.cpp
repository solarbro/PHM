#include <gtest/gtest.h>

#include "../PHM/phm.hpp"

int main(int argc, char** argv)
{

  testing::InitGoogleTest(&argc, argv);

  phm::vec4 aarg(1, 2, 3, 4);
  phm::vec3 blaarg(aarg.yxz);
  phm::vec2 glaarg = aarg.wx;
  float boat = blaarg.g - glaarg.r;
  double trouble = aarg.b;
  phm::vec4 naarg = aarg.xxyw;
  naarg.yzx = blaarg;

  RUN_ALL_TESTS();

  getchar();
  return 0;
}
