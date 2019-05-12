#include <iostream>
#include <algorithm>

//https://brilliant.org/wiki/sorting-algorithms/

void printArray(int arr[], int n)
{
   int i;
   for (i=0; i < n; i++)
       printf("%d ", arr[i]);
   printf("\n");
}

void std_sort(int* array, int array_size)
{
    std::sort(array,array+array_size);
}

void insertionSortAlgorithm(int* array, int array_size)
{
    for(int i=1;i<array_size;i++)
    {
        int key=array[i];
        int j=i-1;
        while(j>=0 &&  key<array[j])
        {
            array[j+1] = array[j];
            j = j-1;
            printArray(array, array_size);
        }
        array[j+1] = key;

    }
}

void bubleSortAlgorithm(int* array, int array_size)
{

}

//https://www.youtube.com/watch?v=SLauY6PpjW4
void quickSortAlgorithm(int* array, int array_size)
{

}

//https://www.youtube.com/watch?v=KF2j-9iSf4Q
void mergeSortAlgorithm(int* array, int array_size)
{

}

void heapSortAlgorithm(int* array, int array_size)
{

}


int main()
{
    int unsorted_array[]={4,3,2,10,12,1,5,6};
    int n = sizeof(unsorted_array)/sizeof(unsorted_array[0]);
    //insertionSortAlgorithm(unsorted_array, n);
    std_sort(unsorted_array, n);

//    printArray(unsorted_array,  n);

    const char * text="Hello world";
    int * x=nullptr;
    std::cout<< sizeof(text)<<std::endl;
    std::cout<< sizeof(x)<<std::endl;
    std::cout<< x<<std::endl;
    std::cout<< *text<<std::endl;
//    double my_array[1000000000000000000]; //my_array[10000000000000000000] -> will give you an error


//    int *y=nullptr;

    return 0;
}
