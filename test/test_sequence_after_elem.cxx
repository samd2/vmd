#if defined(BOOST_VMD_TEST_GENERAL_HEADER)
#include <boost/vmd/vmd.hpp>
#else
#include <boost/vmd/is_identifier.hpp>
#include <boost/vmd/is_empty.hpp>
#include <boost/vmd/elem.hpp>
#include <boost/vmd/size.hpp>
#endif
#include <boost/detail/lightweight_test.hpp>
#include <boost/preprocessor/tuple/elem.hpp>

int main()
  {
  
#if BOOST_PP_VARIADICS

  #define BOOST_VMD_REGISTER_ggh (ggh)
  #define BOOST_VMD_DETECT_ggh_ggh
  #define BOOST_VMD_REGISTER_dvd (dvd)
  #define BOOST_VMD_DETECT_dvd_dvd
  
  #define ANIDENTIFIER ggh
  #define ANIDENTIFIER2 dvd
  #define ANUMBER 249
  #define ANUMBER2 17
  #define ASEQ (25)(26)(27)
  #define ATUPLE (0,1,2,3,((a,b))((c,d))((e))((f,g,h)))
  #define ALIST (0,(1,(2,(3,BOOST_PP_NIL))))
  #define ANARRAY (3,(a,b,38))
  #define ATYPE BOOST_VMD_TYPE_EMPTY
  #define ASEQUENCE ANUMBER ALIST ATUPLE ANIDENTIFIER ANARRAY ASEQ
  #define ASEQUENCE2 ANIDENTIFIER2 ASEQ ALIST ANUMBER ATUPLE
  #define ASEQUENCE3 ASEQ ATYPE ANUMBER2 ATUPLE
  #define ASEQUENCE4
  
  /* AFTER ELEM */
  
  BOOST_TEST_EQ(BOOST_PP_TUPLE_ELEM(3,BOOST_VMD_ELEM(2,ASEQUENCE3,BOOST_VMD_RETURN_ONLY_AFTER)),3);
  BOOST_TEST(BOOST_VMD_IS_IDENTIFIER(BOOST_VMD_ELEM(0,BOOST_VMD_ELEM(2,ASEQUENCE,BOOST_VMD_RETURN_ONLY_AFTER),BOOST_VMD_TYPE_IDENTIFIER)));
  BOOST_TEST(BOOST_VMD_IS_EMPTY(BOOST_VMD_ELEM(3,ASEQUENCE4,BOOST_VMD_RETURN_ONLY_AFTER)));
  BOOST_TEST_EQ(BOOST_VMD_SIZE(BOOST_VMD_ELEM(1,ASEQUENCE2,BOOST_VMD_RETURN_ONLY_AFTER)),3);
  
#endif

  return boost::report_errors();
  
  }
