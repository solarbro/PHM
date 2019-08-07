# PHM
### Photon Tensor Library 

PHM is a templated tensor library.
It supports tensors of arbitrary order and size, including row/column vectors, and matrices.

### Features 
* Arbitrary size tensors
* GLSL style swizzle for 1 to 4 component vectors
* Nested brace-enclosed initializer lists for matrices and higher order tensors (e.g. myMatrix2x2 = {{a, b}, {c, d}})
* Multi-dimensional subscripting (e.g. myMatrix[a][b], myTensorND[a][b][c]...[n])
* Arithmetic operations for vectors and matrices
* Affine transformation functions for 3D graphics applications

TODO:
* Add expression templates
* Add SSE for supported types (e.g. float4, double2, float4xn etc.)
