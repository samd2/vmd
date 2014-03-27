#if !defined(BOOST_VMD_DETAIL_TUPLE_HPP)
#define BOOST_VMD_DETAIL_TUPLE_HPP

#include <boost/preprocessor/control/iif.hpp>
#include <boost/preprocessor/facilities/expand.hpp>
#include <boost/preprocessor/punctuation/paren.hpp>
#include <boost/vmd/gen_empty.hpp>
#include <boost/vmd/is_begin_tuple.hpp>

#define BOOST_VMD_DETAIL_BEGIN_TUPLE_EXP2(...) ( __VA_ARGS__ ) BOOST_VMD_GEN_EMPTY BOOST_PP_LPAREN()
#define BOOST_VMD_DETAIL_BEGIN_TUPLE_EXP1(param) BOOST_VMD_DETAIL_BEGIN_TUPLE_EXP2 param BOOST_PP_RPAREN()
#define BOOST_VMD_DETAIL_BEGIN_TUPLE(param) BOOST_PP_EXPAND(BOOST_VMD_DETAIL_BEGIN_TUPLE_EXP1(param))

#define BOOST_VMD_DETAIL_AFTER_TUPLE_DATA(tuple) BOOST_VMD_GEN_EMPTY tuple
#define BOOST_VMD_DETAIL_AFTER_TUPLE_NOT_FOUND(tuple) (,)
#define BOOST_VMD_DETAIL_AFTER_TUPLE(tuple) (BOOST_VMD_DETAIL_BEGIN_TUPLE(tuple),BOOST_VMD_DETAIL_AFTER_TUPLE_DATA(tuple))

#define BOOST_VMD_DETAIL_TUPLE(param) \
    BOOST_PP_IIF \
      ( \
      BOOST_VMD_IS_BEGIN_TUPLE(param), \
      BOOST_VMD_DETAIL_AFTER_TUPLE, \
      BOOST_VMD_DETAIL_AFTER_TUPLE_NOT_FOUND \
      ) \
    (param) \
/**/

#endif /* BOOST_VMD_DETAIL_TUPLE_HPP */
