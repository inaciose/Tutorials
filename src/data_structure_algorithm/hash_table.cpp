#include <string>
#include <functional>
#include <iostream>
#include <list>
#include <memory>
#include <vector>

//https://www.youtube.com/watch?v=shs0KM3wKv8
/*
Imaging you need to store some data about employees info, phone, name, address, etc
solution:


1)Array:
    search take linear time
    In sorted array search can be done in O(Log(n)) using binary search tree but insert and delete operations are expensive
    
2)Linked List:
    search take linear time
    
3)Balance BST:
    Insertion: O(Log(n))
    Delete: O(Log(n))
    Search: O(Log(n))
    
    First problem with this solution is extra space required is huge. For example if phone number is n digits, we need O(m * 10n) space for table where m is size of a pointer to record. Another problem is an integer in a programming language may not store n digits.

    
4)Direct Access Table:
    Insertion: O(1)
    Delete: O(1)
    Search: O(1)
    cons: lot of space
5)Hash Table
    Hashing is an improvement over Direct Access Table. The idea is to use hash function that converts a given phone number or any other key to a smaller number and uses the small number as index in a table called hash table.
    
    Insertion: O(1)
    Delete: O(1)
    Search: O(1)

    
A good hash function should have following properties
1) Efficiently computable.
2) Should uniformly distribute the keys (Each table position equally likely for each key)

Collision Handling:
    1)Chaining:
    The idea is to make each cell of hash table point to a linked list of records that have same hash function value. Chaining is simple, but requires additional memory outside the table.
    2)Open Addressing: 
    In open addressing, all elements are stored in the hash table itself. Each table entry contains either a record or NIL. When searching for an element, we one by one examine table slots until the desired element is found or it is clear that the element is not in the table. (linear, quadratic and double probing).
*/

namespace chaining
{

class hash
{
    int bucket;
    std::vector<std::list<int> > table;
public:
    hash(int bucket)
    {
        this->bucket=bucket;
        table.resize(bucket);
    }
    
    int hashfunction(int entry)
    {
        return (entry%bucket);
    }
    
    void insert(int entry)
    {
        int index=hashfunction(entry);
        table[index].push_back(entry);
    }
    
    void remove(int entry)
    {
        int index=hashfunction(entry);
        table[index].remove(entry);

    }
    
    void printTable()
    {
        for(std::size_t i=0;i<table.size();i++)
        {
            std::cout<<"[" <<i<< "]:";
            
            for(std::list<int>::iterator it=table[i].begin();it!=table[i].end() ;it++)
            {
                std::cout<<"->"  <<*it; 
            }
            std::cout<<"\n";
        }
    }
    
};

}


 

namespace openAddressing 
{
    //https://www.geeksforgeeks.org/implementing-hash-table-open-addressing-linear-probing-cpp/
    class linearProbing{};
}

void chainingHashExample()
{
    // array that contains keys to be mapped 
    int a[] = {15, 11, 27, 8, 12}; 
    int n = sizeof(a)/sizeof(a[0]); 

    // insert the keys into the hash table 
    chaining::hash h(7);   // 7 is count of buckets in 
    // hash table 
    for (int i = 0; i < n; i++)  
        h.insert(a[i]);   

    // display the Hash table 
    h.printTable(); 
    
    // delete 12 from hash table 
    std::cout<<"removing 12" <<std::endl;
    h.remove(12); 

    // display the Hash table 
    h.printTable();     
}
int main()
{
    //std::cout<< std::hash<std::string>{}("bamboo")<<std::endl;
    chainingHashExample();

    
    
}
