#ifndef NS_QUATERNION_HPP
#define NS_QUATERNION_HPP

#include <cmath>
#include <type_traits>

namespace phm
{
    template <typename T>
    struct quaternion
    {
        T r, i, j, k;

        // template <typename T2, typename std::enable_if<!std::is_same<T, T2>::value>::type>
        // quaternion(const quaternion<T2> &q2) :
        //     r(static_cast<T>(q2.r)),
        //     i(static_cast<T>(q2.i)),
        //     j(static_cast<T>(q2.j)),
        //     k(static_cast<T>(q2.k)){}
        template <typename T2>
        quaternion<T> operator= (const quaternion<T2> &rhs)
        {
            r = static_cast<T>(rhs.r);
            i = static_cast<T>(rhs.i);
            j = static_cast<T>(rhs.j);
            k = static_cast<T>(rhs.k);
        }
    };
    //define quaternion operations
    //operator +
    template <typename T1, typename T2>
    quaternion<std::common_type_t<T1, T2>> operator+ (const quaternion<T1> &q1, const quaternion<T2> &q2)
    {
        return quaternion<std::common_type_t<T1, T2>>({q1.r+q2.r, q1.i+q2.i, q1.j+q2.j, q1.k+q2.k});
    }

    ////////////////////////////////
    //         operator*          //
    ////////////////////////////////
    //scalar
    template <typename T1, typename T2>
    quaternion<T1> operator*(const quaternion<T1> &q, T2 s)
    {
        return quaternion<T1>({q.r * s, q.c1 * s, q.c2 * s, q.c3 * s});
    }
    template <typename T1, typename T2>
    quaternion<T2> operator*(T1 s, const quaternion<T2> &q)
    {
        return q * s;
    }
    //quat
    template <typename T1, typename T2>
    quaternion<std::common_type_t<T1, T2>> operator*(const quaternion<T1> &q1, const quaternion<T2> &q2)
    {
        return q1 + q2; //TODO: Write actual quat multiplication
    }

    template <typename T>
    quaternion<T> conjugate(const quaternion<T> &q)
    {
        return quaternion<T>({q.r, -q.c1, -q.c2, -q.c3});
    }

    template <typename T>
    T norm(const quaternion<T> &q)
    {
        return std::sqrt(q.r * q.r + q.c1 * q.c1 + q.c2 * q.c2 + q.c3 * q.c3);
    }

    template <typename T>
    quaternion<T> normalize(const quaternion<T> &q)
    {
        return q / norm(q);
    }
    // template <typename T>
    // quaternion<T> inverse(const quaternion<T> &q)
    // {
    //     return conjugate(q) / norm(q);
    // }
}

#endif /* end of include guard: NS_QUATERNION_HPP */
