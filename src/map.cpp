#include <iostream>
#include <map>
#include <algorithm>



/*


Both std::set and std::map are associative containers. The difference is that std::sets contain only the key, while in std::map there is an associated value. Choosing one over the other depends mainly on what the task at hand is. If you want to build a dictionary of all the words that appear in a text, you could use a std::set<std::string>, but if you also want to count how many times each word appeared (i.e. associate a value to the key) then you would need an std::map<std::string,int>. If you don't need to associate that count, it does not make sense to have the int that is unnecessary.

*/




int main ()
{
    std::map<std::string, int> items_quantiy;
    std::pair< std::string,int > single_item;
    single_item.first="book";
    single_item.second=45;
    
    items_quantiy.insert(single_item);
    
    
    single_item.first="beer";
    single_item.second=10;
    
    items_quantiy.insert(single_item);
    
    single_item.first="wine";
    single_item.second=14;
    
    items_quantiy.insert(single_item);
    
    items_quantiy["melon"]=3;
    
    items_quantiy["water melon"]=6;
    
    
    if(items_quantiy.find("zzzz")!=items_quantiy.end())
    {
        std::cout<<"item found" <<std::endl;
    }
    else
    {
        std::cout<<"item not found" <<std::endl;
    }

//since C++17
//for (auto&& [first,second] : items_quantiy)
//{
//    std::cout<<first <<std::endl;
//    std::cout<< second<<std::endl;
//}

    
    
//    items_quantiy.size();
    
//    for(std::map<std::string,int>::iterator it=items_quantiy.begin();it!=items_quantiy.end();++it)
//    {
//	std::cout<<it->first<< ":"<<it->second <<std::endl;
//    }
    
    
//    std::map< std::string, int >::iterator it= items_quantiy.find("melon");
    
//    if (it==items_quantiy.end())
//    {
//	std::cout<<"not found" <<std::endl;
//    }
//    else
//    {
//	std::cout<<"item found, "<<it->second <<std::endl;
//    }
    
    
//     

    

    
}
