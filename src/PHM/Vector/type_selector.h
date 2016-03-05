/******************************************************************************/
/*!
\filxe  type_selector.h
\author Sagnik Chowdhury
\brief  Choose the type of higher precision and promote the other to that.
*/
/******************************************************************************/

#include <type_traits>

namespace phm
{
  //I implemented this manually at some point before finding out about common_type
  template <typename... args>
  using ptype = typename std::common_type<args...>::type;

}