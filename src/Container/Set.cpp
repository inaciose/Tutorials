#include <iostream>
#include <set>
#include <string>


class student
{
public:
    int id;
    std::string fisrt_name;
    std::string last_name;
};

int main()
{
    std::set<std::string> things_to_buy;
    
    
    std::cout<<things_to_buy.size() <<std::endl;
    
    
    things_to_buy.insert("bread");
    things_to_buy.insert("water");
    things_to_buy.insert("condom");
    things_to_buy.insert("beer");
    
    std::set<std::string>::iterator it=things_to_buy.find("beer");
    if(it==things_to_buy.end() )
    {
	std::cout<<"friday night fails" <<std::endl;
    }
    else
    {
	std::cout<<"friday night wins" <<std::endl;
    }
    
    
    it=things_to_buy.find("wine");
    if(it==things_to_buy.end() )
    {
	std::cout<<"wine is not in the list" <<std::endl;
    }
    else
    {
	std::cout<<"wine is in the list" <<std::endl;
    }
    
    
    things_to_buy.insert("beer");
    
    
    
    
    for(std::set<std::string>::iterator it=things_to_buy.begin(); it!= things_to_buy.end();it++ )
    {
	std::cout<<*it <<std::endl;
    }
    
    
    std::set<student> set_of_students;
   
    
    return 0;
}