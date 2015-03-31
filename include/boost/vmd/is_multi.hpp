#if !defined(BOOST_VMD_IS_MULTI_HPP)
#define BOOST_VMD_IS_MULTI_HPP

#include <boost/vmd/detail/setup.hpp>

#if BOOST_PP_VARIADICS

#include <boost/vmd/detail/sequence_arity.hpp>

/*

  The succeeding comments in this file are in doxygen format.

*/

/** \file
*/

/** \def BOOST_VMD_IS_MULTI(sequence)

    \brief Determines if the sequence has more than one element, referred to as a multi-element sequence.
    
    sequence = a sequence

    returns = 1 if the sequence is a multi-element sequence, else returns 0.
    
    If the size of a sequence is known it is faster comparing that size to be greater
    than one to find out if the sequence is multi-element. But if the size of the
    sequence is not known it is faster calling this macro than getting the size and
    doing the previously mentioned comparison in order to determine if the sequence
    is multi-element or not.
    
*/

#define BOOST_VMD_IS_MULTI(sequence) \
	BOOST_VMD_DETAIL_IS_MULTI(sequence) \
/**/

/** \def BOOST_VMD_IS_MULTI_D(d,sequence)

    \brief Determines if the sequence has more than one element, referred to as a multi-element sequence.
    
	d        = The next available BOOST_PP_WHILE iteration. 
    sequence = a sequence

    returns = 1 if the sequence is a multi-element sequence, else returns 0.
    
    If the size of a sequence is known it is faster comparing that size to be greater
    than one to find out if the sequence is multi-element. But if the size of the
    sequence is not known it is faster calling this macro than getting the size and
    doing the previously mentioned comparison in order to determine if the sequence
    is multi-element or not.
    
*/

#define BOOST_VMD_IS_MULTI_D(d,sequence) \
	BOOST_VMD_DETAIL_IS_MULTI_D(d,sequence) \
/**/

#endif /* BOOST_PP_VARIADICS */
#endif /* BOOST_VMD_IS_MULTI_HPP */