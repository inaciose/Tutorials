#include <iostream>
#include <map>
#include <string>

struct A
{
    int a;
    std::string b;

    // Simple but wrong as it does not provide the strict weak ordering.
    // As A(5,"a") and A(5,"b") would be considered equal using this function.
    bool operator<(const A& l ) const
    {
//        return (a< l.a) ;
//        return (a>l.a) ;
        return false;
    }


    /*
    // Better brute force.
    bool operator<(const A& l, const A& r )
    {
      if (l.a < r.a)  return true;
      if (l.a > r.a)  return false;
      // Otherwise a are equal
      if (l.b < r.b)  return true;
      if (l.b > r.b)  return false;
      // Otherwise both are equal
      return false;
    }

    // This can often be seen written as
    bool operator<(const A& l, const A& r )
    {
     // This is fine for a small number of members.
     // But I prefer the brute force approach when you start to get lots of members.
     return ( l.a < r.a ) ||
            (( l.a == r.a) && ( l.b < r.b ));
    }
    */
};


int main ()
{
    std::map<A, std::string> A_map;

    A a_1, a_2;
    a_1.a=10;
    a_2.a=2;

    a_1.b="1";
    a_2.b="2";

    std::string a_1_string, a_2_string;

    a_1_string="a_1_string";
    a_2_string="a_2_string";

    A_map[a_1]=a_1_string;
    A_map[a_2]=a_2_string;
    std::cout<<A_map[a_1] <<std::endl;
    std::cout<<A_map[a_2]<<std::endl;
  return 0;
}
