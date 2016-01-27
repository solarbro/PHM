/******************************************************************************/
/*!
\filxe  type_selector.h
\author Sagnik Chowdhury
\par    Course: GAM300
\brief  Choose the type of higher precision and promote the other to that.
*/
/******************************************************************************/

#include <type_traits>

namespace phm
{

  template <typename... args>
  using ptype = typename std::common_type<args...>::type;

}