IF(MSVC12)
  SET(GTEST_ROOT "${CMAKE_SOURCE_DIR}/../cmake/Libraries/msvc12/x64/gtest-1.7")
ELSEIF(MSVC14)
  SET(GTEST_ROOT "${CMAKE_SOURCE_DIR}/../cmake/Libraries/msvc14/x64/gtest-1.7")
ENDIF(MSVC12)