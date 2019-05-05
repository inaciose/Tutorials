#include <algorithm>
#include <iostream>
#include <memory>
#include <cassert> // for assert()
#include <iterator>
#include <map>
#include <list>
#include <limits.h> 

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

/*
 
 Graph adjacency list 
floyd's and brent's algorithms
 */

/*
Graph and its representations

▲
▼
►
◄
↘
↖
↙
↗

           2---------►4  
          ↗|          ▲  \
         / |          |   ↘    
        1  |          |    6
         \ |          |   ↗             
          ↘▼          |  /
           3----------►5 


1. Adjacency Matrix
    Pros:
    
    1)Representation is easier to implement and follow. 
    2)Removing an edge takes O(1) time. 
    3)Queries like whether there is an edge from vertex ‘u’ to vertex ‘v’ are efficient and can be done O(1).


    Cons: 
    1)Consumes more space O(V^2). Even if the graph is sparse(contains less number of edges), it consumes the same space. Adding a vertex is O(V^2) time.
    
   | 1  2  3  4  5  6
----------------------     
  1| 0  2  4  0  0  0
  2| 0  0  1  7  0  0    
  3| 0  0  0  0  3  0
  4| 0  0  0  0  0  1
  5| 0  0  0  2  0  5
  6| 0  0  0  0  0  0
    
    
    
2. Adjacency List

1 -► 2 -► 3 -►/
2 -► 4 -► 3-►/
3 -► 5 -►/
4 -► 6 -►/
5 -► 4-► 6 -►/
6 -►/



*/
void adjacencyListGraphRepresentations()
{
//     std::list<int> adjacencyList;
//     adjacencyList.push_back(3);
}


// Number of vertices in the graph 
#define V 9 
  
// A utility function to find the vertex with minimum distance value, from 
// the set of vertices not yet included in shortest path tree 
int minDistance(int dist[], bool sptSet[]) 
{ 
    // Initialize min value 
    int min = INT_MAX, min_index; 
  
    for (int v = 0; v < V; v++) 
        if (sptSet[v] == false && dist[v] <= min) 
            min = dist[v], min_index = v; 
  
    return min_index; 
} 
  
// A utility function to print the constructed distance array 
int printSolution(int dist[], int n) 
{ 
    printf("Vertex   Distance from Source\n"); 
    for (int i = 0; i < V; i++) 
        printf("%d tt %d\n", i, dist[i]); 
} 
  
// Function that implements Dijkstra's single source shortest path algorithm 
// for a graph represented using adjacency matrix representation 
void dijkstra(int graph[V][V], int src) 
{ 
    int dist[V]; // The output array.  dist[i] will hold the shortest 
    // distance from src to i 
  
    bool sptSet[V]; // sptSet[i] will be true if vertex i is included in shortest 
    // path tree or shortest distance from src to i is finalized 
  
    // Initialize all distances as INFINITE and stpSet[] as false 
    for (int i = 0; i < V; i++) 
        dist[i] = INT_MAX, sptSet[i] = false; 
  
    // Distance of source vertex from itself is always 0 
    dist[src] = 0; 
  
    // Find shortest path for all vertices 
    for (int count = 0; count < V - 1; count++) { 
        // Pick the minimum distance vertex from the set of vertices not 
        // yet processed. u is always equal to src in the first iteration. 
        int u = minDistance(dist, sptSet); 
  
        // Mark the picked vertex as processed 
        sptSet[u] = true; 
  
        // Update dist value of the adjacent vertices of the picked vertex. 
        for (int v = 0; v < V; v++) 
  
            // Update dist[v] only if is not in sptSet, there is an edge from 
            // u to v, and total weight of path from src to  v through u is 
            // smaller than current value of dist[v] 
            if (!sptSet[v] && graph[u][v] && dist[u] != INT_MAX 
                && dist[u] + graph[u][v] < dist[v]) 
                dist[v] = dist[u] + graph[u][v]; 
    } 
  
    // print the constructed distance array 
    printSolution(dist, V); 
} 
  
void  dijkstraExample()
{
   /* Let us create the example graph discussed above */
    int graph[V][V] = { { 0, 4, 0, 0, 0, 0, 0, 8, 0 }, 
                        { 4, 0, 8, 0, 0, 0, 0, 11, 0 }, 
                        { 0, 8, 0, 7, 0, 4, 0, 0, 2 }, 
                        { 0, 0, 7, 0, 9, 14, 0, 0, 0 }, 
                        { 0, 0, 0, 9, 0, 10, 0, 0, 0 }, 
                        { 0, 0, 4, 14, 10, 0, 2, 0, 0 }, 
                        { 0, 0, 0, 0, 0, 2, 0, 1, 6 }, 
                        { 8, 11, 0, 0, 0, 0, 1, 0, 7 }, 
                        { 0, 0, 2, 0, 0, 0, 6, 7, 0 } }; 
  
    dijkstra(graph, 0);     
}


void connectedComponentsInMatrix()
{
//https://www.youtube.com/watch?v=ticZclUYy88
//https://www.geeksforgeeks.org/find-number-of-islands/
//https://www.geeksforgeeks.org/strongly-connected-components/
//https://www.youtube.com/watch?v=hMIrQdX4BkE&t=81s
}

void stronglyConnectedComponents()
{
//https://www.geeksforgeeks.org/tarjan-algorithm-find-strongly-connected-components/
}

void connectedComponents()
{
//https://www.geeksforgeeks.org/connected-components-in-an-undirected-graph/
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
