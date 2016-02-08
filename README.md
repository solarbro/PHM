# PHM
Photon Math Library

Currently supports basic vector math with vectors and matrices of arbitrary types and sizes as well as row and column major support for matrices. Vectors have swizzle.
There are some basic math functions (log, exp, cos etc.) which, at some point, will have precision, as well as performance versions.

The library has only been used in my renderer so far, so while there are no issues I'm aware of, I have yet to perform extensive unit tests.

Unit tests are currently in GoogleTest.cpp, which is where more can be added.
