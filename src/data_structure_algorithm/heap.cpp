//https://www.youtube.com/watch?v=t0Cq6tVNRBA
#include <algorithm>
#include <iostream>

void heap()
{
/*

Examples of Min Heap:

            10                      10
         /      \               /       \
       20        100          15         30
      /                      /  \        /  \
    30                     40    50    100   40

Examples of Max Heap:

                                   17
                                /       \
                              15         10
                             /  \        /
                            6    10     7

Below table shows indexes of other nodes for the ith node, i.e., Arr[i]:
Arr[i/2]	Returns the parent node
Arr[(2*i)+1]	Returns the left child node
Arr[(2*i)+2]	Returns the right child node

1) getMini(): It returns the root element of Min Heap. Time Complexity of this operation is O(1).

2) extractMin(): Removes the minimum element from Min Heap. Time Complexity of this Operation is O(Logn) as
this operation needs to maintain the heap property (by calling heapify()) after removing root.

3) decreaseKey(): Decreases value of key. Time complexity of this operation is O(Logn).
If the decreases key value of a node is greater than parent of the node, then we don’t need to do anything.
Otherwise, we need to traverse up to fix the violated heap property.

4) insert(): Inserting a new key takes O(Logn) time.
We add a new key at the end of the tree. IF new key is greater than its parent, then we don’t need to do anything. Otherwise,
we need to traverse up to fix the violated heap property.

5) delete(): Deleting a key also takes O(Logn) time. We replace the key to be deleted with minum infinite by
calling decreaseKey(). After decreaseKey(), the minus infinite value must reach root, so we call extractMin() to remove key.




Applications of Heaps:
1) Heap Sort: Heap Sort uses Binary Heap to sort an array in O(nLogn) time.

2) Priority Queue: Priority queues can be efficiently implemented using Binary Heap because it supports insert(), delete() and extractmax(), decreaseKey() operations in O(logn) time. Binomoial Heap and Fibonacci Heap are variations of Binary Heap. These variations perform union also efficiently.

3) Graph Algorithms: The priority queues are especially used in Graph Algorithms like Dijkstra’s Shortest Path and Prim’s Minimum Spanning Tree.

4) Many problems can be efficiently solved using Heaps. See following for example.
a) K’th Largest Element in an array.
b) Sort an almost sorted array/
c) Merge K Sorted Arrays.

*/


    std::vector<int> v={ 6,10,7,17,10,15 };

    std::cout << "initially, v: ";
    for (auto i : v) std::cout << i << ' ';
    std::cout << '\n';

    if (!std::is_heap(v.begin(), v.end()))
    {
        std::cout << "making heap...\n";
        std::make_heap(v.begin(), v.end());
    }

    std::cout << "after make_heap, v: ";
    for (auto i : v) std::cout << i << ' ';
        std::cout << '\n';

    std::cout << "The maximum element of heap is : ";
    std::cout << v.front() << std::endl;


    //remove the largest element
    std::pop_heap(v.begin(),v.end());
    v.pop_back();


    //Adding a new element
    v.push_back(100);
    std::cout<< (std::is_heap(v.begin(),v.end()) ? "it is a heap" : "it is not a heap" )   <<std::endl;
    std::push_heap(v.begin(),v.end());
    std::cout<< (std::is_heap(v.begin(),v.end()) ? "it is a heap" : "it is not a heap" )   <<std::endl;


    //sorting a heap -> it only works on a heap, so you should first turn your vetor into a heap
    std::sort_heap(v.begin(),v.end());
}



int main()
{

}
