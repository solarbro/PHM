/******************************************************************************/
/*!
\filxe  type_vec3.hpp
\author Sagnik Chowdhury
\par    Course: GAM300
\brief  Contains the Photon renderer math library
*/
/******************************************************************************/

#pragma once

#include <iomanip>
#include <type_traits>
#include "type_vec.hpp"
#include "type_vec4.hpp"

namespace phm
{

  enum class Major
  {
    ROW,
    COL
  };

#pragma region TEMPLATEHELPERS
  template <Major Ma, Major Mb, typename T = void>
  using MatchType = typename std::enable_if<Ma == Mb, T>::type;

  template <Major Ma, Major Mb, typename T = void>
  using MismatchType = typename std::enable_if<Ma != Mb, T>::type;

  template <unsigned R, unsigned C, Major maj>
  struct MajorDim : std::conditional<maj == Major::ROW, 
    std::integral_constant<unsigned, R>, 
    std::integral_constant<unsigned, C >> ::type{};

  template <unsigned R, unsigned C, Major maj>
  struct MinorDim : std::conditional<maj == Major::ROW,
    std::integral_constant<unsigned, C>,
    std::integral_constant<unsigned, R >> ::type{};
#pragma endregion TEMPLATEHELPERS

  /*************************************      
  *        type_mat
  *        - ctor(float)
  *        - ctor(float*)
  *        - ctor(vec2, vec2)
  *        - operator[]
  *        - operator *(vec2)
  *        - operator *(mat2)
  *        - transpose()
  **************************************/

  //template<typename T>
  //T det(const T> &m);


  template<class T, unsigned R, unsigned C, Major major = Major::COL>
  class type_mat
  {
  public:

    /*************************************
    *               CTORS                *
    *************************************/
#pragma region CTORS

    type_mat()
    {
      //Initialize diagonals to 0
      unsigned diagonal = std::min(C, R);
      for (unsigned i = 0; i < diagonal; ++i)
        col[i][i] = static_cast<T>(1.0);
    }

    template <typename T2>
    type_mat(T2 f)
    {
      unsigned diagonal = std::min(C, R);
      for (unsigned i = 0; i < diagonal; ++i)
        col[i][i] = static_cast<T>(f);
    }

    template<typename T2>
    type_mat(T2 *f)
    {
      for (unsigned i = 0; i < C; ++i)
        col[i] = type_vec<T, R>(f + i * R);
    }

    template<typename T1, typename ... T2>
    type_mat(const type_vec<T1, MinorDim<R, C, major>::value> &init0, 
      const type_vec<T2, MinorDim<R, C, major>::value>& ... init)
    {
      //Initialize diagonals to 0
      unsigned diagonal = std::min(C, R);
      for (unsigned i = 0; i < diagonal; ++i)
        col[i][i] = static_cast<T>(1.0);

      type_vec<T, R> temp[] = { init0, init ... };
      const unsigned paramSize = std::min(static_cast<unsigned>(sizeof...(T2)), 
                                          static_cast<unsigned>(MajorDim<R, C, major>::value));
      for (unsigned i = 0; i < paramSize; ++i)
        col[i] = temp[i];
    }

    template<typename T2, unsigned R2, unsigned C2, Major maj2, 
      typename = typename std::enable_if<major == maj2>::type>  
      /*sfinae this ctor for matching majors*/
    type_mat(const type_mat<T2, R2, C2, maj2> &m)
    {
      unsigned r = std::min(mDimension, m.mDimension);
      unsigned c = std::min(MDimension, m.MDimension);

      //Initialize to identity matrix
      unsigned diagonal = std::min(C, R);
      for (unsigned i = 0; i < diagonal; ++i)
        col[i][i] = static_cast<T>(1.0);

      for (unsigned i = 0; i < c; ++i)
        for (unsigned j = 0; j < r; ++j)
          col[i][j] = static_cast<T>(m[i][j]);
    }

    template<typename T2, unsigned R2, unsigned C2, Major maj2>
      /*sfinae this ctor for mismatching majors*/
    explicit type_mat(const typename std::enable_if<major != maj2, type_mat<T2, R2, C2, maj2>>::type &m)
    {
      unsigned r = std::min(mDimension, m.MDimension);
      unsigned c = std::min(MDimension, m.mDimension);

      //Initialize to identity matrix
      unsigned diagonal = std::min(C, R);
      for (unsigned i = 0; i < diagonal; ++i)
        col[i][i] = static_cast<T>(1.0);

      for (unsigned i = 0; i < c; ++i)
        for (unsigned j = 0; j < r; ++j)
          col[i][j] = static_cast<T>(m[j][i]);
    }
#pragma endregion CTORS

    ~type_mat(){}

    /*************************************
    *             OPERATORS              *
    *************************************/
#pragma region M_OPERATORS
    type_vec<T, R> operator[] (unsigned i) const
    {
      return col[i];
    }

    type_vec<T, R>& operator[](unsigned i)
    {
      return col[i];
    }

    template<typename T2, Major rhs_major>
    MatchType<major, rhs_major, type_mat<T, R, C>&> operator=(const type_mat<T2, R, C> &m)
    {
      for (unsigned i = 0; i < C; ++i)
        col[i] = m[i];

      return *this;
    }

    template<typename T2, Major rhs_major>
    MismatchType<major, rhs_major, type_mat<T, R, C>&> operator=(const type_mat<T2, R, C> &m)
    {
      for (unsigned i = 0; i < C; ++i)
        for (unsigned j = 0; j < R; ++i)
          col[i][j] = m[j][i];

      return *this;
    }
#pragma endregion M_OPERATORS

#pragma region STATICS
    static const unsigned MDimension = MajorDim<R, C, major>::value;
    static const unsigned mDimension = MinorDim<R, C, major>::value;
#pragma endregion STATICS

  private:

    using base_mat_type = std::conditional_t<major == Major::ROW, type_vec<T, C>[R], type_vec<T, R>[C]>;

    base_mat_type col;
  };

  /*******************************
             Operators
  *******************************/
#pragma region OPERATOR_OVERLOADS

#pragma region OPERATOR==
  template <typename T1, typename T2, unsigned R, unsigned C, Major maj1, Major maj2>
  MismatchType<maj1, maj2, bool> operator==(const type_mat<T1, R, C, maj1> &m1, const type_mat<T2, R, C, maj2 > &m2)
  {
    for (unsigned i = 0; i < C; ++i)
    {
      for (unsigned j = 0; j < R; ++j)
        if (m1[i][j] != m2[j][i])
          return false;
    }
    return true;
  }

  template <typename T1, typename T2, unsigned R, unsigned C, Major maj1, Major maj2>
  MatchType<maj1, maj2, bool> operator==(const type_mat<T1, R, C, maj1> &m1, const type_mat<T2, R, C, maj2 > &m2)
  {
    for (unsigned i = 0; i < C; ++i)
    {
      if (m1[i] != m2[i])
        return false;
    }
    return true;
  }
#pragma endregion OPERATOR==

#pragma region OPERATOR!=
  template<typename T1, typename T2, unsigned R, unsigned C, Major maj1, Major maj2>
  bool operator!= (const type_mat<T1, R, C, maj1> &m1, const type_mat<T2, R, C, maj2> &m)
  {
    return !(*this == m);
  }

#pragma endregion OPERATOR!=
  //===========================
#pragma region OPERATOR*

#pragma region MATRIX*SCALAR
  //Multiply by scalars
  template<typename T1, typename T2, unsigned R, unsigned C, Major maj>
  type_mat<T1, R, C, maj> operator*(const type_mat<T1, R, C, maj> &m, const T2 &f)
  {
    type_mat<T1, R, C, maj> temp;
    for (unsigned i = 0; i < m.MDimension; ++i)
      temp[i] = m[i] * f;

    return temp;
  }
#pragma endregion MATRIX*SCALAR

#pragma region SCALAR*MATRIX
  //Multiply by scalars
  template<typename T1, typename T2, unsigned R, unsigned C, Major maj>
  type_mat<T1, R, C, maj> operator*(const T2 &f, const type_mat<T1, R, C, maj> &m)
  {
    return m * f;
  }
#pragma endregion SCALAR*MATRIX

#pragma region MATRIX*VECTOR
  //Multiply by vector for column major
  template<typename T1, typename T2, unsigned R, unsigned C>
  type_vec<ptype<T1, T2>, R> operator*(const type_mat<T1, R, C, Major::COL> &mat, const type_vec<T2, C> vec)
  {
    type_vec<ptype<T1, T2>, R> temp;

    for (unsigned i = 0; i < R; ++i)
    {
      ptype<T1, T2> value = static_cast<ptype<T1, T2>>(0.0);
      for (unsigned j = 0; j < C; ++j)
      {
        value += mat[j][i] * vec[j];
      }
      temp[i] = value;
    }

    return temp;
  }

  //Multiply by vector for row major
  template<typename T1, typename T2, unsigned R, unsigned C>
  type_vec<ptype<T1, T2>, R> operator*(const type_mat<T1, R, C, Major::ROW> &mat, const type_vec<T2, C> vec)
  {
    type_vec<ptype<T1, T2>, R> temp;

    for (unsigned i = 0; i < C; ++i)
    {
      temp[i] = dot(mat[i], vec);
    }

    return temp;
  }
#pragma endregion MATRIX*VECTOR

#pragma region VECTOR*MATRIX

  //Multiply by vector for column major
  template<typename T1, typename T2, unsigned R, unsigned C>
  type_vec<ptype<T1, T2>, C> operator*(const type_vec<T2, R> vec, const type_mat<T1, R, C, Major::COL> &mat)
  {
    type_vec<ptype<T1, T2>, C> temp;

    for (unsigned i = 0; i < C; ++i)
    {
      temp[i] = dot(mat[i], vec);
    }

    return temp;

    
  }

  //Multiply by vector for row major
  template<typename T1, typename T2, unsigned R, unsigned C>
  type_vec<ptype<T1, T2>, C> operator*(const type_vec<T2, R> vec, const type_mat<T1, R, C, Major::ROW> &mat)
  {
    type_vec<ptype<T1, T2>, C> temp;

    for (unsigned i = 0; i < C; ++i)
    {
      ptype<T1, T2> value = static_cast<ptype<T1, T2>>(0.0);
      for (unsigned j = 0; j < R; ++j)
      {
        value += mat[j][i] * vec[j];
      }
      temp[i] = value;
    }

    return temp;
  }

#pragma endregion VECTOR*MATRIX

#pragma region MATRIX*MATRIX
  //Matrix * Matrix (only same major allowed)
  //Column major
  template<typename T1, typename T2, unsigned R, unsigned C1, unsigned C2>
  type_mat<ptype<T1, T2>, R, C2, Major::COL> operator*(const type_mat<T1, R, C1, Major::COL> &m1, const type_mat<T2, C1, C2, Major::COL> &m2)
  {
    type_mat<ptype<T1, T2>, R, C2, Major::COL> temp;
    for (unsigned r = 0; r < R; ++r)
    {
      type_vec<ptype<T1, T2>, C1> row;
      for (unsigned i = 0; i < C1; ++i)
        row[i] = m1[i][r];

      for (unsigned c = 0; c < C2; ++c)
      {
        type_vec<ptype<T1, T2>, C1> column = m2[c];
        temp[c][r] = dot(row, column);
      }
    }
    return temp;
  }

  //Matrix * Matrix (only same major allowed)
  //Row major
  template<typename T1, typename T2, unsigned R, unsigned C1, unsigned C2>
  type_mat<ptype<T1, T2>, R, C2, Major::ROW> operator*(const type_mat<T1, R, C1, Major::ROW> &m1, const type_mat<T2, C1, C2, Major::ROW> &m2)
  {
    type_mat<ptype<T1, T2>, R, C2, Major::ROW> temp;
    for (unsigned c = 0; c < C2; ++c)
    {
      type_vec<ptype<T1, T2>, C1> column;
      for (unsigned i = 0; i < C1; ++i)
        column[i] = m2[i][c];

      for (unsigned r = 0; r < R; ++r)
      {
        type_vec<ptype<T1, T2>, C> row = m1[r];
        temp[r][c] = dot(row, column);
      }
    }
    return temp;
  }
#pragma endregion MATRIX*MATRIX

#pragma endregion OPERATOR*
  //==========================
#pragma region OPERATOR*=

#pragma region MATRIX*=SCALAR
  template<typename T1, typename T2, unsigned R, unsigned C, Major maj>
  type_mat<T1, R, C, maj>& operator*= (type_mat<T1, R, C, maj> &m, const T2 &f)
  {
    for (unsigned i = 0; i < m.MDimension; ++i)
      m[i] *= f;

    return m;
  }
#pragma endregion MATRIX*=SCALAR

#pragma region MATRIX*=MATRIX
  template<typename T1, typename T2, unsigned R, unsigned C1, unsigned C2, Major maj>
  type_mat<ptype<T1, T2>, R, C2, maj> operator*=(type_mat<T1, R, C1, maj> &m1, const type_mat<T2, C1, C2, maj> &m2)
  {
    //This requires a temporary
    m1 = m1 * m2;
    return m1;
  }
#pragma endregion MATRIX*=MATRIX

#pragma endregion OPERATOR*=
  //==========================
#pragma region OPERATOR+

#pragma region MATRIX+SCALAR
  template<typename T1, typename T2, unsigned R, unsigned C, Major maj>
  type_mat<T1, R, C, maj> operator+(const type_mat<T1, R, C, maj> &m, const T2 &s)
  {
    type_mat<T1, R, C, maj> temp;
    for (unsigned i = 0; i < m.MDimension; ++i)
      temp[i] = m[i] + s;

    return temp;
  }
#pragma endregion MATRIX+SCALAR

#pragma region MATRIX+MATRIX
  template<typename T1, typename T2, unsigned R, unsigned C, Major maj>
  type_mat<ptype<T1, T2>, R, C, maj> operator+(const type_mat<T1, R, C, maj> &m1, const type_mat<T2, R, C, maj> &m2)
  {
    type_mat<ptype<T1, T2>, R, C, maj> temp;
    for (unsigned i = 0; i < m1.MDimension; ++i)
      temp[i] = m1[i] + m2[i];

    return temp;
  }
#pragma endregion MATRIX+MATRIX

#pragma endregion OPERATOR+
  //============================
#pragma region OPERATOR+=

#pragma region MATRIX+=SCALAR
  template<typename T1, typename T2, unsigned R, unsigned C, Major maj>
  type_mat<T1, R, C, maj>& operator+=(type_mat<T1, R, C, maj> &m, const T2 &s)
  {
    for (unsigned i = 0; i < m.MDimension; ++i)
      m[i] += s;

    return m;
  }
#pragma endregion MATRIX+=SCALAR

#pragma region MATRIX+=MATRIX
  template<typename T1, typename T2, unsigned R, unsigned C, Major maj>
  type_mat<ptype<T1, T2>, R, C, maj>& operator+=(type_mat<T1, R, C, maj> &m1, const type_mat<T2, R, C, maj> &m2)
  {
    for (unsigned i = 0; i < m1.MDimension; ++i)
      m1[i] += m2[i];

    return m1;
  }
#pragma endregion MATRIX+=MATRIX

#pragma endregion OPERATOR+=
  //===========================
#pragma region OPERATOR-

#pragma region MATRIX-SCALAR
  template<typename T1, typename T2, unsigned R, unsigned C, Major maj>
  type_mat<T1, R, C, maj> operator-(const type_mat<T1, R, C, maj> &m, const T2 &s)
  {
    return m + (-s);
  }
#pragma endregion MATRIX-SCALAR

#pragma region -MATRIX
  template<typename T1, unsigned R, unsigned C, Major maj>
  type_mat<T1, R, C, maj> operator-(const type_mat<T1, R, C, maj> &m)
  {
    type_mat<T1, R, C, maj> temp;
    for (unsigned i = 0; i < m.MDimension; ++i)
      temp[i] = -m[i];

    return temp;
  }
#pragma endregion -MATRIX

#pragma region MATRIX-MATRIX
  template<typename T1, typename T2, unsigned R, unsigned C, Major maj>
  type_mat<ptype<T1, T2>, R, C, maj> operator-(const type_mat<T1, R, C, maj> &m1, const type_mat<T2, R, C, maj> &m2)
  {
    return m1 + (-m2);
  }
#pragma endregion MATRIX-MATRIX

#pragma endregion OPERATOR-
  //===========================
#pragma region OPERATOR-=

#pragma region MATRIX-=SCALAR
  template<typename T1, typename T2, unsigned R, unsigned C, Major maj>
  type_mat<T1, R, C, maj>& operator-=(type_mat<T1, R, C, maj> &m, const T2 &s)
  {
    m += (-s);
    return m;
  }
#pragma endregion MATRIX-=SCALAR

#pragma region MATRIX-=MATRIX
  template<typename T1, typename T2, unsigned R, unsigned C, Major maj>
  type_mat<ptype<T1, T2>, R, C, maj>& operator-=(type_mat<T1, R, C, maj> &m1, const type_mat<T2, R, C, maj> &m2)
  {
    m1 += (-m2);
    return m1;
  }
#pragma endregion MATRIX-=MATRIX

#pragma endregion OPERATOR-=
  //===========================
#pragma endregion OPERATOR_OVERLOADS

  /*******************************
           Common types
  *******************************/
#pragma region TYPEDEFS
#pragma region COLUMNTYPES
  //float
  typedef type_mat<float, 2, 2> mat2;
  typedef type_mat<float, 2, 3> mat23;
  typedef type_mat<float, 2, 4> mat24;
  typedef type_mat<float, 3, 2> mat32;
  typedef type_mat<float, 3, 3> mat3;
  typedef type_mat<float, 3, 4> mat34;
  typedef type_mat<float, 4, 2> mat42;
  typedef type_mat<float, 4, 3> mat43;
  typedef type_mat<float, 4, 4> mat4;
  //double
  typedef type_mat<double, 2, 2> dmat2;
  typedef type_mat<double, 2, 3> dmat23;
  typedef type_mat<double, 2, 4> dmat24;
  typedef type_mat<double, 3, 2> dmat32;
  typedef type_mat<double, 3, 3> dmat3;
  typedef type_mat<double, 3, 4> dmat34;
  typedef type_mat<double, 4, 2> dmat42;
  typedef type_mat<double, 4, 3> dmat43;
  typedef type_mat<double, 4, 4> dmat4;
#pragma endregion COLUMNTYPES
#pragma region ROWTYPES
  //float
  typedef type_mat<float, 2, 2, Major::ROW> Rmat2;
  typedef type_mat<float, 2, 3, Major::ROW> Rmat23;
  typedef type_mat<float, 2, 4, Major::ROW> Rmat24;
  typedef type_mat<float, 3, 2, Major::ROW> Rmat32;
  typedef type_mat<float, 3, 3, Major::ROW> Rmat3;
  typedef type_mat<float, 3, 4, Major::ROW> Rmat34;
  typedef type_mat<float, 4, 2, Major::ROW> Rmat42;
  typedef type_mat<float, 4, 3, Major::ROW> Rmat43;
  typedef type_mat<float, 4, 4, Major::ROW> Rmat4;
  //double
  typedef type_mat<double, 2, 2, Major::ROW> Rdmat2;
  typedef type_mat<double, 2, 3, Major::ROW> Rdmat23;
  typedef type_mat<double, 2, 4, Major::ROW> Rdmat24;
  typedef type_mat<double, 3, 2, Major::ROW> Rdmat32;
  typedef type_mat<double, 3, 3, Major::ROW> Rdmat3;
  typedef type_mat<double, 3, 4, Major::ROW> Rdmat34;
  typedef type_mat<double, 4, 2, Major::ROW> Rdmat42;
  typedef type_mat<double, 4, 3, Major::ROW> Rdmat43;
  typedef type_mat<double, 4, 4, Major::ROW> Rdmat4;
#pragma endregion ROWTYPES
#pragma endregion TYPEDEFS
  /*      =============================================
  *                       Functions
  *       =============================================
  *
  *       transpose(m)
  *       minor(m, col, row)
  *       det(m)
  *       inverse
  *       operator<<
  */

  template<typename T, unsigned R, unsigned C, Major maj>
  type_mat<T, C, R, maj> transpose(const type_mat<T, R, C, maj> &m)
  {
    type_mat<T, C, R, maj> temp;

    for (unsigned i = 0; i < m.mDimension; ++i)
    {
      for (unsigned j = 0; j < m.MDimension; ++j)
        temp[j][i] = m[i][j];
    }

    return temp;
  }

  template<typename T, unsigned R, unsigned C, Major maj>
  type_mat<T, R - 1, C - 1, maj> minor(const type_mat<T, R, C, maj> &m, unsigned column, unsigned row)
  {
    type_mat<T, R - 1, C - 1, maj> temp;

    for (unsigned i = 0; i < m.MDimension - 1; ++i)
    {
      for (unsigned j = 0; j < m.mDimension - 1; ++j)
      {
        unsigned temp_c = i >= column ? i + 1 : i;
        unsigned temp_r = j >= row ? j + 1 : j;

        temp[i][j] = m[temp_c][temp_r];
      }
    }

    return temp;
  }

  template<typename T, unsigned D, Major maj>
  T det(const type_mat<T, D, D, maj> &m)
  {
    T determinant = static_cast<T>(0.0);

    for (unsigned i = 0; i < D; ++i)
    {
      determinant += m[0][i] * static_cast<T>(i % 2 == 0 ? 1.0 : -1.0) * det(minor(m, 0, i));
    }

    return determinant;
  }

  template<typename T, Major maj>
  T det(const type_mat<T, 1, 1, maj> &m)
  {
    return m[0][0];
  }

  template<typename T, Major maj>
  T det(const type_mat<T, 2, 2, maj> &m)
  {
    return m[0][0] * m[1][1] - m[0][1] * m[1][0];
  }

  template<typename T, unsigned D, Major maj>
  type_mat<T, D, D, maj> inverse(const type_mat<T, D, D, maj> &m)
  {
    type_mat<T, D, D, maj> adjugate;

    for (unsigned i = 0; i < D; ++i)
    {
      for (unsigned j = 0; j < D; ++j)
      {
        adjugate[j][i] = static_cast<T>((i + j) % 2 == 0 ? 1.0 : -1.0) * det(minor(m, i, j));
      }
    }
    T determinant = det(m);
    
    return adjugate / determinant;
  }

  template<typename T, Major maj>
  type_mat<T, 2, 2, maj> inverse(const type_mat<T, 2, 2, maj> &m)
  {
    type_mat<T, 2, 2, maj> res;
    res[0][0] = m[1][1];
    res[1][1] = m[0][0];
    res[0][1] = -m[0][1];
    res[1][0] = -m[1][0];
    return res / det(m);
  }

  template<typename T, unsigned R, unsigned C>
  std::ostream& operator<<(std::ostream &os, const type_mat<T, R, C, Major::ROW> &m)
  {
    for (unsigned i = 0; i < R; ++i)
    {
      os << "|";
      for (unsigned j = 0; j < C; ++j)
      {
        os << std::setw(8) << std::right << m[i][j];
      }
      os << "|\n";
    }

    return os;
  }

  template<typename T, unsigned R, unsigned C>
  std::ostream& operator<<(std::ostream &os, const type_mat<T, R, C, Major::COL> &m)
  {
    for (unsigned i = 0; i < C; ++i)
    {
      os << "|";
      for (unsigned j = 0; j < R; ++j)
      {
        os << std::setw(8) << std::right << m[j][i];
      }
      os << "|\n";
    }

    return os;
  }
}