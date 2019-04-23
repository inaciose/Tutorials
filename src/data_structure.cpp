#include <algorithm>
#include <iostream>
#include <memory>

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


void BFS(std::shared_ptr<node> rootNode)
{

    for(auto n:rootNode->leaves)
        std::cout<<n->data <<std::endl;

    for(auto n:rootNode->leaves)
        BFS(n);
}

int main()
{

}
