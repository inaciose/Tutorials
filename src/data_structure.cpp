#include <algorithm>
#include <iostream>
#include <memory>
#include <cassert> // for assert()
#include <iterator>
#include <map>
class node
{
public:
    std::vector<std::shared_ptr<node> > leaves;
    double data;
};
/*
h is the height of the tree.


                       -1
                      /  \
                     3     7
                    / \   / \
                   4  1   5
*/

/*

Binary Tree Properties:

    1)The maximum number of nodes at level ‘l’ = 2^(l-1).
    Maximum number of nodes = 2^(h – 1).
    Here h is height of a tree. Height is considered
    as is maximum number of nodes on root to leaf path

    2)Minimum possible height =  ceil(Log2(n+1))

    3)In Binary tree, number of leaf nodes is always one
    more than nodes with two children.

    4)Time Complexity of Tree Traversal: O(n)



Binary Search Tree
In Binary Search Tree is a Binary Tree with following additional properties:
    1) The left subtree of a node contains only nodes with keys less than the node’s key.
    2) The right subtree of a node contains only nodes with keys greater than the node’s key.
    3) The left and right subtree each must also be a binary search tree.

Time Complexities:

    1)Search :  O(h)
    2)Insertion : O(h)
    3)Deletion : O(h)
    4)Extra Space : O(n) for pointers

    h: Height of BST
    n: Number of nodes in BST

    If Binary Search Tree is Height Balanced,
    then h = O(Log n)

    Self-Balancing BSTs such as AVL Tree, Red-Black
    Tree and Splay Tree make sure that height of BST
    remains O(Log n)


Binary Heap
A Binary Heap is a Binary Tree with following properties.
    1) It’s a complete tree (All levels are completely filled except possibly the last level and the last level has all keys as left as possible). This property of Binary Heap makes them suitable to be stored in an array.
    2) A Binary Heap is either Min Heap or Max Heap. In a Min Binary Heap, the key at root must be minimum among all keys present in Binary Heap. The same property must be recursively true for all nodes in Binary Tree. Max Binary Heap is similar to Min Heap. It is mainly implemented using array.

Get Minimum in Min Heap: O(1) [Or Get Max in Max Heap]
Extract Minimum Min Heap: O(Log n) [Or Extract Max in Max Heap]
Decrease Key in Min Heap: O(Log n)  [Or Extract Max in Max Heap]
Insert: O(Log n)
Delete: O(Log n)
*/


/*
                    9
                  /   \
                8       6
              /  \    /   \
             7    4  5     2
            / \  /
           0   3 1



*/

void binaryHeapExample()
{

//https://www.fluentcpp.com/2018/03/13/heaps-priority-queues-stl-part-1/
    std::vector<int> data={0,1,2,3,4,5,6,7,8,9};

    // min heap
    std::make_heap(data.end(),data.begin());

    //min heap
//    std::make_heap(data.begin(),data.end());
//    for(auto d:data)
//        std::cout<<d <<std::endl;


    int height =  ceil(log2(data.size()+1));
    std::cout<<height <<std::endl;


    for(std::size_t i=0;2*i+1<data.size();i++)
    {
        std::cout<<"Node: " <<data[i] <<std::endl;
        if(2*i+1<data.size())
            std::cout<<"left child:"  << data[2*i+1]<<std::endl;
        if(2*i+2<data.size())
            std::cout<<"right child:"<<data[2*i+2] <<std::endl;

    }




}

void populateTree(std::shared_ptr<node> rootNodePtr)
{

/*
                   -1
                  /   \
                3       7
              /  \    /
             4    1  5


*/


    rootNodePtr->data=-1;
    std::shared_ptr<node>  leftNodePtr,rightNodePtr;
    std::shared_ptr<node>  leftNode1stKidPtr,leftNode2ndtKidPtr, rightNode1stKidPtr;

    leftNodePtr.reset(new node) ;
    rightNodePtr.reset(new node);
    rootNodePtr->leaves.push_back(leftNodePtr);
    rootNodePtr->leaves.push_back(rightNodePtr);

    leftNodePtr->data=3;
    rightNodePtr->data=7;



    leftNode1stKidPtr.reset(new node);
    leftNode2ndtKidPtr.reset(new node);
    rightNode1stKidPtr.reset(new node);

    leftNode1stKidPtr->data=4;
    leftNode2ndtKidPtr->data=1;
    rightNode1stKidPtr->data=5;

    leftNodePtr->leaves.push_back(leftNode1stKidPtr);
    leftNodePtr->leaves.push_back(leftNode2ndtKidPtr);

    rightNodePtr->leaves.push_back(rightNode1stKidPtr);

}

void DFS(std::shared_ptr<node> rootNode)
{
    std::cout<<rootNode->data <<std::endl;
    for(auto n:rootNode->leaves)
        DFS(n);
}

//Level Order Tree Traversal, Breadth first traversal
void BFS(std::shared_ptr<node> rootNode)
{

    for(auto n:rootNode->leaves)
        std::cout<<n->data <<std::endl;

    for(auto n:rootNode->leaves)
        BFS(n);
}

template <typename T>
void permutation(std::vector<T> v)
{
    std::sort(v.begin(), v.end());
    do {
        std::copy(v.begin(), v.end(), std::ostream_iterator<T>(std::cout, " "));
        std::cout << std::endl;
    } while (std::next_permutation(v.begin(), v.end()));
}


bool increase(std::vector<bool>& bs)
{
    for (std::size_t i = 0; i != bs.size(); ++i) {
        bs[i] = !bs[i];
        if (bs[i] == true) {
            return true;
        }
    }
    return false; // overflow
}

template <typename T>
void powerSet(const std::vector<T>& v)
{
    std::vector<bool> bitset(v.size());

    do {
        for (std::size_t i = 0; i != v.size(); ++i) {
            if (bitset[i]) {
                std::cout << v[i] << " ";
            }
        }
        std::cout << std::endl;
    } while (increase(bitset));
}



template <typename T>
void combination(const std::vector<T>& v, std::size_t count)
{
    assert(count <= v.size());
    std::vector<bool> bitset(v.size() - count, 0);
    bitset.resize(v.size(), 1);

    do {
        for (std::size_t i = 0; i != v.size(); ++i) {
            if (bitset[i]) {
                std::cout << v[i] << " ";
            }
        }
        std::cout << std::endl;
    } while (std::next_permutation(bitset.begin(), bitset.end()));
}

namespace huffman
{
    class node
    {
    public:
        std::shared_ptr<node> left,right;
        std::map<std::string, int> data;
        
    };
    
}


template <typename T>
typename T::iterator min_map_element(T& m)
{
    return min_element(m.begin(), m.end(), [](typename T::value_type& l, typename T::value_type& r) -> bool { return l.second < r.second; });
}

void huffmanCoding()
{
    std::map<std::string, int> inputList;

    
    auto cmp=[](std::pair<std::string,int> &left,std::pair<std::string,int> &right){ return (left.second>right.second) ;};
    
    
    //auto inputList=std::map<std::string, int, decltype(cmp)  >(cmp);
    
    inputList.insert(std::make_pair("E",2));
    inputList.insert(std::make_pair("A",3));
    inputList.insert(std::make_pair("D",4));
    inputList.insert(std::make_pair("B",5));
    inputList.insert(std::make_pair("C",6));

    std::map<std::string, int>::iterator first_min=min_map_element(inputList);
    
    
    inputList.erase(first_min);

    
    std::map<std::string, int>::iterator second_min=min_map_element(inputList);
    inputList.erase(second_min);

    std::cout<<first_min->first <<std::endl;
    std::cout<<second_min->first <<std::endl;
    
    huffman::node nodeEA;
    
//     nodeEA.left.reset(new huffman::node());
//     nodeEA.right.reset(new huffman::node());
//     nodeEA.data.insert(std::make_pair(first_min->first+second_min->first,first_min->second+second_min->second));
    
    
    inputList.insert(std::make_pair(first_min->first+second_min->first,first_min->second+second_min->second));
    
        std::cout<<inputList[first_min->first+second_min->first] <<std::endl;

    
    

    
}

int main()
{
//    std::shared_ptr<node> tree(new node);
//    populateTree(tree);
//    DFS(tree);

//     std::vector<char> vc{ 'A', 'B', 'C', 'D' };
//     std::vector<char> path;
//     std::vector<bool> visited(4, false);
//     std::cout << "\n------PERMUTATION----------\n";
//     permutation(vc);
//     std::cout << "\n------COMBINATION----------\n";
//     combination(vc, 3);
//     std::cout << "\n------POWERSET-------------\n";
//     powerSet(vc);
//     return 0;
    
    
    huffmanCoding();
}
