#ifndef PAIR_HPP
#define PAIR_HPP

#include "map.hpp"

// https://www.cplusplus.com/reference/utility/pair/?kw=pair


namespace ft
{
    template< class T1, class T2>
    struct pair
    {
/*---------------------------------MEMBER TYPE-------------------------------------*/
        typedef T1  first_type;
        typedef T2  second_type;

/*--------------------------------MEMBER VARIABLES---------------------------------*/
        first_type  first;
        second_type second;

/*--------------------------------MEMBER FUNCTIONS---------------------------------*/
    //-----Constructors :

        //default :
        pair() : first(), second() {};

        //copy :
        template<class U, class V>
        pair (const pair<U,V>& pr) : first(pr.first), second(pr.second) {};

        //initialization :
        pair (const first_type& a, const second_type& b) : first(a), second (b) {};
    
    //-----Operator= :
        
        pair& operator= (const pair& pr)
        {
            if (this != &pr)
            {
                first = pr.first;
                second = pr.second;
            }
            return (*this);
        };

    };

/*--------------------------------NON-MEMBER FUNCTION--------------------------------*/

    template< class T1, class T2 >
    pair<T1,T2> make_pair( T1 t, T2 u )
    { return ( pair<T1,T2>(t,u) ); };

    template <class T1, class T2>
    bool operator== (const pair<T1,T2>& lhs, const pair<T1,T2>& rhs)
    { return lhs.first==rhs.first && lhs.second==rhs.second; };

    template <class T1, class T2>
    bool operator!= (const pair<T1,T2>& lhs, const pair<T1,T2>& rhs)
    { return !(lhs==rhs); };

    template <class T1, class T2>
    bool operator<  (const pair<T1,T2>& lhs, const pair<T1,T2>& rhs)
    { return lhs.first<rhs.first || (!(rhs.first<lhs.first) && lhs.second<rhs.second); };

    template <class T1, class T2>
    bool operator<= (const pair<T1,T2>& lhs, const pair<T1,T2>& rhs)
    { return !(rhs<lhs); };

    template <class T1, class T2>
    bool operator>  (const pair<T1,T2>& lhs, const pair<T1,T2>& rhs)
    { return rhs<lhs; };

    template <class T1, class T2>
    bool operator>= (const pair<T1,T2>& lhs, const pair<T1,T2>& rhs)
    { return !(lhs<rhs); };
};
#endif