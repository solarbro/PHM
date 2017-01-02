/******************************************************************************/
/*!
\filxe  phm.hpp
\author Sagnik Chowdhury
\brief  Contains the Photon renderer math library
*/
/******************************************************************************/
#pragma once

/******************************************************************************
vector_basics.h contains everything needed for to perform basic vector math.
This includes the vector class (type_vec) and matrix class (type_mat) and all
corresponding overloads and specializations.
*******************************************************************************/
#include "Tensor/tensor.hpp"
#include "Tensor/tensorOp.hpp"
#include "Tensor/Vector/vec3.hpp"
/******************************************************************************
Function.hpp contains template implementations of various mathematical functions.
The current implementations are based on Taylor expansion. I will add fast versions
of them for applications that require high performance and less accuracy.
*******************************************************************************/
#include "Math/Function.hpp"
/******************************************************************************
Constants.hpp is where you can access various math constants.
*******************************************************************************/
#include "Math/Constants.hpp"


/*
 *  TODO: Add documentation
 */
