#include <algorithm>
#include <iostream>
#include <vector>
/*
syntax:

[ capture clause ] (parameters) -> return-type  
{   
   definition of method   
}  




*/

template <typename T>
void printVec(std::vector<T> values )
{
     for (auto value:values)
        std::cout<<value <<std::endl;
}

void increaser (int &i) 
{  // function:
  i=i+1;
}

void transformExample()
{
    std::vector<int> x={1,2,3};
    std::vector<int> y(x.size(),0);
    std::vector<int> z(x);
    std::transform(x.begin(),x.end(),y.begin(),[](int a){return a+=1;});
    
    std::for_each(z.begin(), z.end(), [&](int a){return a=a+1;});
    
    //std::for_each(z.begin(), z.end(), increaser);
    
    
    printVec(y);
    printVec(z);
     
}

void count_ifExample()
{
    std::vector<int> x={1,2,1,4,5,1,3};
    int ones;
    
    ones=std::count_if(x.begin(),x.end(), [](int &a){ return a==1;} );
    std::cout<<"Total number of ones in the vector is: " <<ones<<std::endl;
    
    
    auto f=[](int &a){ return a==1;};
    std::count_if(x.begin(),x.end(), f );
    ones=std::count_if(x.begin(),x.end(), [](int &a){ return a==1;} );
    std::cout<<"Total number of ones in the vector is: " <<ones<<std::endl;
    
    
    
}

bool sortFunc(int x, int y)
{
    return (x<y);
}

void labmdaExample()
{
    std::vector<int> v1;
    for(int n : {1,8,5,6,3,4,0,9,7,2})
        v1.push_back(n);

    //inline
    std::sort(v1.begin(),v1.end(),[](int x,int y){ return (x<y); }  );


    //outside
    v1.clear();
    for(int n : {1,8,5,6,3,4,0,9,7,2})
        v1.push_back(n);
    auto cmp = [](int x, int y) { return (x<y);};
    std::sort(v1.begin(),v1.end(),cmp  );

    //otside as a function
    v1.clear();
    for(int n : {1,8,5,6,3,4,0,9,7,2})
        v1.push_back(n);
    std::sort(v1.begin(),v1.end(),sortFunc  );
}

int main()
{
//     transformExample();
    count_ifExample();
}
