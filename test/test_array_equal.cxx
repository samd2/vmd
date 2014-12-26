#if defined(BOOST_VMD_TEST_GENERAL_HEADER)
#include <boost/vmd/vmd.hpp>
#else
#include <boost/vmd/array/array_equal.hpp>
#include <boost/vmd/array/array_not_equal.hpp>
#endif
#include <boost/detail/lightweight_test.hpp>

int main()
  {
  
#if BOOST_PP_VARIADICS
  
  #define BOOST_VMD_REGISTER_aaa (aaa)
  #define BOOST_VMD_REGISTER_bbb (bbb)
  #define BOOST_VMD_REGISTER_ccc (ccc)
  #define BOOST_VMD_REGISTER_ddd (ddd)
  #define BOOST_VMD_DETECT_aaa_aaa
  #define BOOST_VMD_DETECT_bbb_bbb
  #define BOOST_VMD_DETECT_ccc_ccc
  #define BOOST_VMD_DETECT_ddd_ddd
  
  #define ANARRAY (3,(aaa,bbb,38))
  #define ANARRAY2 (3,(bbb,aaa,38))
  #define ANARRAY3 (3,(bbb,aaa,38))
  #define ANARRAY4 (3,(aaa,(aaa,(bbb,(ccc,BOOST_PP_NIL))),(ccc,ddd,(1)(2))))
  #define ANARRAY5 (3,(aaa,(aaa,(bbb,(ccc,BOOST_PP_NIL))),(ccc,ddd,(1)(2))))
  #define ANARRAY6 (4,(aaa,(aaa,(bbb,(ccc,BOOST_PP_NIL))),(ccc,ddd,(1)(2),37)))
  
  BOOST_TEST(BOOST_VMD_ARRAY_EQUAL(ANARRAY4,ANARRAY5));
  BOOST_TEST(BOOST_VMD_ARRAY_EQUAL(ANARRAY2,ANARRAY3));
  BOOST_TEST(BOOST_VMD_ARRAY_NOT_EQUAL(ANARRAY,ANARRAY2));
  BOOST_TEST(BOOST_VMD_ARRAY_NOT_EQUAL(ANARRAY5,ANARRAY6));

#endif

  return boost::report_errors();
  
  }
