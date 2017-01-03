#ifndef NS_BASIC_HPP
#define NS_BASIC_HPP

#include <cstdint>

namespace phm
{
    enum class precision
    {
        Low,     //32 Bit
        Regular, //64 Bit
        High,    //Custom higher precision type
    };
    //TODO: Use precision as template parameter
    
    using natural = std::uint64_t;
    using integer = std::int64_t;
    using real    = double; //option for higher precision?

    struct rational
    {
        integer numerator;
        integer denominator;
    };
    //define rational number operations
}


#endif /* end of include guard: NS_BASIC_HPP */
