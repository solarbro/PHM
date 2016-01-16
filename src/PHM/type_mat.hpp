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
#include "type_vec.hpp"
#include "type_vec4.hpp"


namespace phm
{
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


  template<class T, unsigned R, unsigned C>
  class type_mat
  {
  public:
    /*************************************
    *               CTORS                *
    *************************************/
    //type_mat()
    //{
    //  //Initialize to identity matrix
    //  unsigned diagonal = std::min(C, R);
    //  for (unsigned i = 0; i < diagonal; ++i)
    //    col[i][i] = static_cast<T>(1.0);
    //}

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

    template<typename ... T2>
    type_mat(type_vec<T2, R> ... init)
    {
      //Initialize diagonals to 0
      unsigned diagonal = std::min(C, R);
      for (unsigned i = 0; i < diagonal; ++i)
        col[i][i] = static_cast<T>(1.0);

      type_vec<T, R> temp[C] = { init ... };
      unsigned params = sizeof...(T2);
      for (unsigned i = 0; i < params; ++i)
        col[i] = temp[i];
    }

    template<typename T2, unsigned R2, unsigned C2>
    type_mat(const type_mat<T2, R2, C2> &m)
    {
      unsigned r = std::min(R, R2);
      unsigned c = std::min(C, C2);

      //Initialize to identity matrix
      unsigned diagonal = std::min(C, R);
      for (unsigned i = 0; i < diagonal; ++i)
        col[i][i] = static_cast<T>(1.0);

      for (unsigned i = 0; i < c; ++i)
        for (unsigned j = 0; j < r; ++j)
          col[i][j] = static_cast<T>(m[i][j]);
    }
    ~type_mat(){}
    /*************************************
    *             OPERATORS              *
    *************************************/
    template<typename T2>
    bool operator== (const type_mat<T2, R, C> &m) const
    {
      for (unsigned i = 0; i < C; ++i)
      {
        if (col[i] != m[i])
          return false;
      }
      return true;
    }

    template<typename T2>
    bool operator!= (const type_mat<T2, R, C> &m) const
    {
      return !(*this == m);
    }

    type_vec<T, R> operator[] (unsigned i) const
    {
      return col[i];
    }

    type_vec<T, R>& operator[](unsigned i)
    {
      return col[i];
    }

    template<typename T2>
    type_mat<T, R, C>& operator=(const type_mat<T2, R, C> &m)
    {
      for (unsigned i = 0; i < C; ++i)
        col[i] = m[i];

      return *this;
    }

    template<typename T2>
    type_mat<T, R, C> operator*(const T2 &f) const
    {
      type_mat<T, R, C> temp;
      for (unsigned i = 0; i < C; ++i)
        temp[i] = col[i] * f;

      return temp;
    }

    template<typename T2>
    type_mat<T, R, C>& operator*= (const T2 &f)
    {
      for (unsigned i = 0; i < C; ++i)
        col[i] *= f;

      return *this;
    }

    template<typename T2>
    type_mat<T, R, C> operator/ (const T2 &f) const
    {
      T2 invf = static_cast<T2>(1.0) / f;
      return operator*(invf);
    }

    template<typename T2>
    type_mat<T, R, C>& operator/= (const T2 &f)
    {
      T2 invf = static_cast<T2>(1.0) / f;
      return operator*=(invf);
    }

    template<typename T2>
    type_vec<T, R> operator*(const type_vec<T2, C> vec)const
    {
      type_vec<T, R> temp;

      for (unsigned i = 0; i < R; ++i)
      {
        T value = static_cast<T>(0.0);
        for (unsigned j = 0; j < C; ++j)
        {
          value += col[j][i] * vec[j];
        }
        temp[i] = value;
      }

      return temp;
    }

    template<typename T2, unsigned C2>
    type_mat<T, R, C2> operator*(const type_mat<T2, C, C2> m)const
    {
      type_mat<T, R, C2> temp;
      for (unsigned r = 0; r < R; ++r)
      {
        type_vec<T, C> row;
        for (unsigned i = 0; i < C; ++i)
          row[i] = col[i][r];

        for (unsigned c = 0; c < C2; ++c)
        {
          type_vec<T, C> column = m[c];
          temp[c][r] = dot(row, column);
        }
      }
      return temp;
    }
    
  private:

    type_vec<T, R> col[C];

  };

  template<typename T1, typename T2, unsigned R, unsigned C>
  type_mat<T1, R, C> operator+(const T2 f, const type_mat<T1, R, C> &m)
  {
    return m + f;
  }

  template<typename T1, typename T2, unsigned R, unsigned C>
  type_mat<T1, R, C> operator*(const T2 f, const type_mat<T1, R, C> &m)
  {
    return m * f;
  }

  /*******************************
           Common types
  *******************************/
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

  template<typename T, unsigned R, unsigned C>
  type_mat<T, C, R> transpose(const type_mat<T, R, C> &m)
  {
    type_mat<T, C, R> temp;

    for (unsigned i = 0; i < C; ++i)
    {
      for (unsigned j = 0; j < R; ++j)
        temp[j][i] = m[i][j];
    }

    return temp;
  }

  template<typename T, unsigned R, unsigned C>
  type_mat<T, R - 1, C - 1> minor(const type_mat<T, R, C> &m, unsigned column, unsigned row)
  {
    type_mat<T, R - 1, C - 1> temp;

    for (unsigned i = 0; i < R - 1; ++i)
    {
      for (unsigned j = 0; j < C - 1; ++j)
      {
        unsigned temp_c = i >= column ? i + 1 : i;
        unsigned temp_r = j >= row ? j + 1 : j;

        temp[i][j] = m[temp_c][temp_r];
      }
    }

    return temp;
  }

  template<typename T, unsigned D>
  T det(const type_mat<T, D, D> &m)
  {
    T determinant = static_cast<T>(0.0);

    for (unsigned i = 0; i < D; ++i)
    {
      determinant += m[0][i] * static_cast<T>(i % 2 == 0 ? 1.0 : -1.0) * det(minor(m, 0, i));
    }

    return determinant;
  }

  template<typename T>
  T det(const type_mat<T, 1, 1> &m)
  {
    return m[0][0];
  }

  template<typename T>
  T det(const type_mat<T, 2, 2> &m)
  {
    return m[0][0] * m[1][1] - m[0][1] * m[1][0];
  }

  template<typename T>
  T det(const type_mat<T, 3, 3> &m)
  {
    return (m[0][0] * m[1][1] * m[2][2])
         + (m[1][0] * m[2][1] * m[0][2])
         + (m[2][0] * m[0][1] * m[1][2])
         - (m[2][0] * m[1][1] * m[0][2])
         - (m[1][0] * m[0][1] * m[2][2])
         - (m[0][0] * m[2][1] * m[1][2]);
  }

  template<typename T>
  T det(const type_mat<T, 4, 4> &m)
  {
    return m[0][0] * m[1][1] * m[2][2] * m[3][3] +
           m[0][0] * m[1][2] * m[2][3] * m[3][1] +
           m[0][0] * m[1][3] * m[2][1] * m[3][2] +
           
           m[0][1] * m[1][0] * m[2][3] * m[3][2] +
           m[0][1] * m[1][2] * m[2][0] * m[3][3] +
           m[0][1] * m[1][3] * m[2][2] * m[3][0] +
           
           m[0][2] * m[1][0] * m[2][1] * m[3][3] +
           m[0][2] * m[1][1] * m[2][3] * m[3][0] +
           m[0][2] * m[1][3] * m[2][0] * m[3][1] +
          
           m[0][3] * m[1][0] * m[2][2] * m[3][1] +
           m[0][3] * m[1][1] * m[2][0] * m[3][2] +
           m[0][3] * m[1][2] * m[2][1] * m[3][0] -
           
           m[0][0] * m[1][1] * m[2][3] * m[3][2] -
           m[0][0] * m[1][2] * m[2][1] * m[3][3] -
           m[0][0] * m[1][3] * m[2][2] * m[3][1] -
           
           m[0][1] * m[1][0] * m[2][2] * m[3][3] -
           m[0][1] * m[1][2] * m[2][3] * m[3][0] -
           m[0][1] * m[1][3] * m[2][0] * m[3][2] -
           
           m[0][2] * m[1][0] * m[2][3] * m[3][1] -
           m[0][2] * m[1][1] * m[2][0] * m[3][3] -
           m[0][2] * m[1][3] * m[2][1] * m[3][0] -
           
           m[0][3] * m[1][0] * m[2][1] * m[3][2] -
           m[0][3] * m[1][1] * m[2][2] * m[3][0] -
           m[0][3] * m[1][2] * m[2][0] * m[3][1];
  }

  template<typename T, unsigned D>
  type_mat<T, D, D> inverse(const type_mat<T, D, D> &m)
  {
    type_mat<T, D, D> adjugate;

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

  template<typename T>
  type_mat<T, 2, 2> inverse(const type_mat<T, 2, 2> &m)
  {
    type_mat<T,2,2> res;
    res[0][0] = m[1][1];
    res[1][1] = m[0][0];
    res[0][1] = -m[0][1];
    res[1][0] = -m[1][0];
    return res / det(m);
  }

  template<typename T>
  type_mat<T, 3, 3> inverse(const type_mat<T, 3, 3> &m)
  {
    type_mat<T,3,3> res;
    res[0][0] = m[1][1] * m[2][2] - m[1][2] * m[2][1];
    res[0][1] = m[0][2] * m[2][1] - m[0][1] * m[2][2];
    res[0][2] = m[0][1] * m[1][2] - m[0][2] * m[1][1];
    res[1][0] = m[1][2] * m[2][0] - m[1][0] * m[2][2];
    res[1][1] = m[0][0] * m[2][2] - m[0][2] * m[2][0];
    res[1][2] = m[0][2] * m[1][0] - m[0][0] * m[1][2];
    res[2][0] = m[1][0] * m[2][1] - m[1][1] * m[2][0];
    res[2][1] = m[0][1] * m[2][0] - m[0][0] * m[2][1];
    res[2][2] = m[0][0] * m[1][1] - m[0][1] * m[1][0];

    return res / det(m);
  }

  template<typename T>
  type_mat<T, 4, 4> inverse(const type_mat<T, 4, 4> &m)
  {
    type_mat<T,4,4> res;
    res[0][0] = m[1][1] * m[2][2] * m[3][3] +
                m[1][2] * m[2][3] * m[3][1] +
                m[1][3] * m[2][1] * m[3][2] -
                m[1][1] * m[2][3] * m[3][2] -
                m[1][2] * m[2][1] * m[3][3] -
                m[1][3] * m[2][2] * m[3][1];
    res[0][1] = m[0][1] * m[2][3] * m[3][2] +
                m[0][2] * m[2][1] * m[3][3] +
                m[0][3] * m[2][2] * m[3][1] -
                m[0][1] * m[2][2] * m[3][3] -
                m[0][2] * m[2][3] * m[3][1] -
                m[0][3] * m[2][1] * m[3][2];
    res[0][2] = m[0][1] * m[1][2] * m[3][3] +
                m[0][2] * m[1][3] * m[3][1] +
                m[0][3] * m[1][1] * m[3][2] -
                m[0][1] * m[1][3] * m[3][2] -
                m[0][2] * m[1][1] * m[3][3] -
                m[0][3] * m[1][2] * m[3][1];
    res[0][3] = m[0][1] * m[1][3] * m[2][2] +
                m[0][2] * m[1][1] * m[2][3] +
                m[0][3] * m[1][2] * m[2][1] -
                m[0][1] * m[1][2] * m[2][3] -
                m[0][2] * m[1][3] * m[2][1] -
                m[0][3] * m[1][1] * m[2][2];
    res[1][0] = m[1][0] * m[2][3] * m[3][2] +
                m[1][2] * m[2][0] * m[3][3] +
                m[1][3] * m[2][2] * m[3][0] -
                m[1][0] * m[2][2] * m[3][3] -
                m[1][2] * m[2][3] * m[3][0] -
                m[1][3] * m[2][0] * m[3][2];
    res[1][1] = m[0][0] * m[2][2] * m[3][3] +
                m[0][2] * m[2][3] * m[3][0] +
                m[0][3] * m[2][0] * m[3][2] -
                m[0][0] * m[2][3] * m[3][2] -
                m[0][2] * m[2][0] * m[3][3] -
                m[0][3] * m[2][2] * m[3][0];
    res[1][2] = m[0][0] * m[1][3] * m[3][2] +
                m[0][2] * m[1][0] * m[3][3] +
                m[0][3] * m[1][2] * m[3][0] -
                m[0][0] * m[1][2] * m[3][3] -
                m[0][2] * m[1][3] * m[3][0] -
                m[0][3] * m[1][0] * m[3][2];
    res[1][3] = m[0][0] * m[1][2] * m[2][3] +
                m[0][2] * m[1][3] * m[2][0] +
                m[0][3] * m[1][0] * m[2][2] -
                m[0][0] * m[1][3] * m[2][2] -
                m[0][2] * m[1][0] * m[2][3] -
                m[0][3] * m[1][2] * m[2][0];
    res[2][0] = m[1][0] * m[2][1] * m[3][3] +
                m[1][1] * m[2][3] * m[3][0] +
                m[1][3] * m[2][0] * m[3][1] -
                m[1][0] * m[2][3] * m[3][1] -
                m[1][1] * m[2][0] * m[3][3] -
                m[1][3] * m[2][1] * m[3][0];
    res[2][1] = m[0][0] * m[2][3] * m[3][1] +
                m[0][1] * m[2][0] * m[3][3] +
                m[0][3] * m[2][1] * m[3][0] -
                m[0][0] * m[2][1] * m[3][3] -
                m[0][1] * m[2][3] * m[3][0] -
                m[0][3] * m[2][0] * m[3][1];
    res[2][2] = m[0][0] * m[1][1] * m[3][3] +
                m[0][1] * m[1][3] * m[3][0] +
                m[0][3] * m[1][0] * m[3][1] -
                m[0][0] * m[1][3] * m[3][1] -
                m[0][1] * m[1][0] * m[3][3] -
                m[0][3] * m[1][1] * m[3][0];
    res[2][3] = m[0][0] * m[1][3] * m[2][1] +
                m[0][1] * m[1][0] * m[2][3] +
                m[0][3] * m[1][1] * m[2][0] -
                m[0][0] * m[1][1] * m[2][3] -
                m[0][1] * m[1][3] * m[2][0] -
                m[0][3] * m[1][0] * m[2][1];
    res[3][0] = m[1][0] * m[2][2] * m[3][1] +
                m[1][1] * m[2][0] * m[3][2] +
                m[1][2] * m[2][1] * m[3][0] -
                m[1][0] * m[2][1] * m[3][2] -
                m[1][1] * m[2][2] * m[3][0] -
                m[1][2] * m[2][0] * m[3][1];
    res[3][1] = m[0][0] * m[2][1] * m[3][2] +
                m[0][1] * m[2][2] * m[3][0] +
                m[0][2] * m[2][0] * m[3][1] -
                m[0][0] * m[2][2] * m[3][1] -
                m[0][1] * m[2][0] * m[3][2] -
                m[0][2] * m[2][1] * m[3][0];
    res[3][2] = m[0][0] * m[1][2] * m[3][1] +
                m[0][1] * m[1][0] * m[3][2] +
                m[0][2] * m[1][1] * m[3][0] -
                m[0][0] * m[1][1] * m[3][2] -
                m[0][1] * m[1][2] * m[3][0] -
                m[0][2] * m[1][0] * m[3][1];
    res[3][3] = m[0][0] * m[1][1] * m[2][2] +
                m[0][1] * m[1][2] * m[2][0] +
                m[0][2] * m[1][0] * m[2][1] -
                m[0][0] * m[1][2] * m[2][1] -
                m[0][1] * m[1][0] * m[2][2] -
                m[0][2] * m[1][1] * m[2][0];

    return res / det(m);
  }

  template<typename T, unsigned R, unsigned C>
  std::ostream& operator<<(std::ostream &os, const type_mat<T, R, C> &m)
  {
    for (unsigned i = 0; i < R; ++i)
    {
      os << "|";
      for (unsigned j = 0; j < C; ++j)
      {
        os << std::setw(8) << std::right << m[j][i];
      }
      os << "|\n";
    }

    return os;
  }
}