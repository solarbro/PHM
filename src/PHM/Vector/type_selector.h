/******************************************************************************/
/*!
\filxe  type_selector.h
\author Sagnik Chowdhury
\par    Course: GAM300
\brief  Choose the type of higher precision and promote the other to that.
*/
/******************************************************************************/

#include <limits>

namespace phm
{
  //By default, a type is not promoted
  template <typename T>
  struct promote { typedef T type; };

  /*We then use template specializations 
  for the types that need to be promoted.*/
  template <>
  struct promote<signed short> { typedef int type; };
  template <>
  struct promote<bool> { typedef int type; };

  /*For the rest, we need a sort of if-then-else 
  for choosing a type*/
  template <bool C, typename T, typename F>
  struct choose_type { typedef F type; };
  template <typename T, typename F>
  struct choose_type<true, T, F> { typedef T type; };

  /*So the boolean value of the first argument determines 
  whether to choose the type T (if true) or F (if false).
  We now have*/
  template <>
  struct promote<unsigned short> {
    typedef choose_type<sizeof(short) < sizeof(int), int, unsigned>::type type;
  };
  template <>
  struct promote<signed char> {
    typedef choose_type<sizeof(char) <= sizeof(int), int, unsigned>::type type;
  };
  template <>
  struct promote<unsigned char> {
    typedef choose_type<sizeof(char) < sizeof(int), int, unsigned>::type type;
  };
  /*This last one for plain char is needed because C++ considers char, 
  signed char, and unsigned char to be three distinct types. 
  The standard does not specify whether char is signed or not. 
  (The numeric_limits template is defined in the limits header.)*/
  template <>
  struct promote<char>
    : public promote<choose_type<std::numeric_limits<char>::is_signed,
    signed char, unsigned char>::type>{};

  /*Finally, to promote wchar_t*/
  template <>
  struct promote<wchar_t> {
    typedef choose_type<
      std::numeric_limits<wchar_t>::is_signed,
      choose_type<sizeof(wchar_t) <= sizeof(int), int, long>::type,
      choose_type<sizeof(wchar_t) <= sizeof(int), unsigned, unsigned long>::type
    >::type type;
  };

  /*This ensures that the type arguments for resolve_uac2 are at least ints.
  We then introduce ranks for those types*/
  template <typename T> struct type_rank;
  template <> struct type_rank<int>           { static const int rank = 1; };
  template <> struct type_rank<unsigned>      { static const int rank = 2; };
  template <> struct type_rank<long>          { static const int rank = 3; };
  template <> struct type_rank<unsigned long> { static const int rank = 4; };
  template <> struct type_rank<float>         { static const int rank = 5; };
  template <> struct type_rank<double>        { static const int rank = 6; };
  template <> struct type_rank<long double>   { static const int rank = 7; };

  /*Now we can pick the type with the highest rank*/
  template <typename A, typename B>
  struct resolve_uac2 {
    typedef typename choose_type<
      type_rank<A>::rank >= type_rank<B>::rank, A, B
    >::type return_type;
  };

  /*Finally we need to deal with the special case where
  one type is long int and the other is unsigned int*/
  template <>
  struct resolve_uac2<long, unsigned> {
    typedef choose_type<sizeof(long) == sizeof(unsigned),
      unsigned long, long>::type return_type;
  };
  template <>
  struct resolve_uac2<unsigned, long> : public resolve_uac2<long, unsigned>{};

  /*We can now turn to the usual arithmetic conversions. 
  First, we promote each type, if necessary*/
  template <typename A, typename... args>
  struct resolve_uac { typedef typename resolve_uac<A, resolve_uac<args...>>::type return_type; };
  /*End condition for the recursive evaluation*/
  template <typename A, typename B>
  struct resolve_uac<A, B> : public resolve_uac2<typename promote<A>::type, typename promote<B>::type> {};

  

  /*Choose the type that has higher precision. The typename keyword
  is required to tell the compiler that the following term is a type*/
  template <typename A, typename... args>
  using ptype = typename resolve_uac<A, args...>::return_type;

}