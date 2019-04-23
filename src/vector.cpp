
#include <string>
#include <vector>
#include <iostream>
#include <iterator>
#include <cstring>



template <typename T>
void printVector(std::vector<T> v)
{
    for(T entity:v)
        std::cout<< entity<<std::endl;
}


template <typename T>
void printArray(T  array, std::size_t arraySize)
{
    for(std::size_t i=0;i<arraySize;i++)
        std::cout<< array[i]<<std::endl;
}


// vector to c style array
void cStyleArrayToVecExample()
{
    int numbers[4]={3,1,-1,5};
    //first way
     std::cout<< "c style array to vector first way"<<std::endl;
    std::vector<int> vec1FromArray(std::begin(numbers),std::end(numbers) );
    printVector(vec1FromArray);

    //second way
    std::cout<< "c style array to vector second way"<<std::endl;
    std::vector<int> vec2FromArray(numbers, numbers+ sizeof(numbers)/sizeof(numbers[0]));
    printVector(vec2FromArray);
}

void vecTocStyleArrayExample()
{
    std::cout<< "Vector to c style array first way (no copying)"<<std::endl;
    std::vector<int> vec={3,1,-1,5};
    printArray(&vec[0], vec.size());

    //second way
    std::cout<< "Vector to c style array second way (memory copying)"<<std::endl;

    int array[4];
    std::memcpy(array,&vec[0],vec.size()*sizeof(vec[0]));
    printArray(array, vec.size());

     //third way
    std::cout<< "Vector to c style array second way (std::copy)"<<std::endl;
    std::copy(vec.begin(),vec.end(),array);
    printArray(array, vec.size());
}

void stringToCharVec()
{
    std::string str("ali baba");
    str.begin();
    std::vector<char> charVec(str.begin(),str.end() );

    printVector(charVec);

}

void  reinterpretVector()
{
    //https://stackoverflow.com/questions/1953621/reinterpret-float-vector-as-unsigned-char-array-and-back
    std::vector<double> p_vector;
    const unsigned char*  sourceArray = reinterpret_cast<const unsigned char *>(&(p_vector[0]));


    typedef unsigned char byte;
    std::vector<float> original_data;

    if (!original_data.empty())
    {
      const float *p_floats = &(original_data[0]);
      const byte *p_bytes = reinterpret_cast<const byte *>(p_floats);
    }
}

void  vectorExample()
{

    //testvector has a 3 element, all of them are 100
    std::vector<int> testvector (3,100);

    std::vector<int> vec={3,4,1,5,2,7,8,0};
    std::cout<<"vec.size()="<<vec.size()<<std::endl;
    std::cout<<"vec.capacity()="<<vec.capacity()<<std::endl;

    std::cout<<"Iterating over a vector with subscripts is more efficient because at(i) is a function call"<<std::endl;
    for(unsigned int i=0;i<vec.size();i++)
        std::cout<<vec[i]<<std::endl;

    std::cout<<"Iterating over a vector with an iterator"<<std::endl;
    for (std::vector<int>::iterator it = vec.begin(); it!=vec.end(); ++it)
        std::cout << *it << std::endl;



    std::cout<<"front() Returns a reference to the first element in the vector container."<<std::endl;
    std::cout<<vec.front()<< std::endl;
    std::cout<<"Returns a reference to the last element in the vector container."<<std::endl;
    std::cout<<vec.back()<< std::endl;


    std::cout<<"pop_back"<<std::endl;
    while(!vec.empty())
    {
        std::cout<<vec.back()<<std::endl;
        vec.pop_back();
    }


    vec={3,4,1,5,2,7,8,0};
    // erase the 3th element
    vec.erase (vec.begin()+1);

    // erase the first 2 elements:
    vec.erase (vec.begin(),vec.begin()+2);

    //the 0th element would be 200
    testvector.insert ( testvector.begin() , 200 );

    //it will add two element
    testvector.insert (testvector.begin(),2,300);

    //or we can add an other vector to testvector
    testvector.insert (testvector.begin(),vec.begin(),vec.end());



    //assignment (equal sign operator) in vectors is a deep copy
    std::vector<int> vec1,vec2;
    vec1={3,4,5,5};
    vec2=vec1;
    vec1.clear();
    std::cout<<"vec1:"<<std::endl;
    printVector(vec1);
    std::cout<<"vec2:"<<std::endl;
    printVector(vec2);

}

int main()
{
    //cStyleArrayToVecExample();
    //vecTocStyleArrayExample();
    //stringToCharVec();
    vectorExample();
}
