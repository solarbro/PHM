/******************************************************************************/
/*!
\file   tensorOP.hpp
\author Sagnik Chowdhury
\brief  tensor operations common to all tensor types
*/
/******************************************************************************/
#include "tensor.hpp"

#include <iostream>

namespace phm
{
    //cout----------------------------------------------------------------------
    template <typename T, unsigned D0, unsigned ... Drest>
    std::ostream& operator<<(std::ostream& stream, const tensor<T, D0, Drest...> &t)
    {
        stream << "{";
        for(unsigned i = 0; i < D0 - 1; ++i)
            stream << t[i] << ", ";
        stream << t[D0 - 1] << "}";
        return stream;
    }

    //Recursion end
    template <typename T>
    std::ostream& operator<<(std::ostream& stream, const tensor<T> &scalar)
    {
        return stream << scalar.store;
    }
    //--------------------------------------------------------------------------
}
