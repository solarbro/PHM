/******************************************************************************/
/*!
\file   vec3.hpp
\author Sagnik Chowdhury
\brief  vec3 special operations
*/
/******************************************************************************/
#include "vector.hpp"

namespace phm
{
    template <typename T>
    using vec3 = tensor<T, 3, 1>;

    template <typename T1, typename T2>
    vec3<common<T1, T2>> cross(const vec3<T1> &v1, const vec3<T2> &v2)
    {
        vec3<common<T1, T2>> result;
        result[0] = v1[1] * v2[2] - v1[2] * v2[1];
        result[1] = v1[2] * v2[0] - v1[0] * v2[2];
        result[2] = v1[0] * v2[1] - v1[1] * v2[0];
        return result;
    }

}
