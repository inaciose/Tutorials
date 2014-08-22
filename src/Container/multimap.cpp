#include <iostream>
#include <string.h>
#include <map>

int main ( int argc, char *argv[] )
{


    typedef std::multimap<std::string, int> item;
    typedef std::pair <std::string, int> single_item;

    item products;

    single_item prodcut1, prodcut2, prodcut3;

    prodcut1.first="a";
    prodcut1.second=12;


    products.insert(prodcut1);


    prodcut2.first="a";
    prodcut2.second=11;


    products.insert(prodcut2);

    
    
    prodcut3.first="b";
    prodcut3.second=1001;


    products.insert(prodcut3);

    

    std::cout<< products.size()  <<std::endl;
    
    for(std::multimap<std::string, int >::iterator it=products.begin();it!=products.end();it++  )
    {
	std::cout<< it->first<<std::endl;
	std::cout<< it->second <<std::endl;
    }
    
    std::cout<<  products.find("a")->second <<std::endl;
    
    std::pair< std::multimap<std::string, int>::iterator, std::multimap<std::string, int>::iterator> ppp;
   // equal_range(b) returns pair<iterator,iterator> representing the range
   // of element with key b
   ppp = products.equal_range("a");

   
    for (std::multimap<std::string, int>::iterator it2 = ppp.first; it2 != ppp.second;  ++it2)
    {
	std::cout << "  [" << it2->first << ", " << it2->second << "]" << std::endl;
    }

   
   
   

    return 0;
    
}












