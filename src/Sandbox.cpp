#include <iostream>
#include <vector>
#include "Sandbox.hpp"
#include <ctime>

#include <iostream>
#include <string.h>
#include <map>


#include <istream>
#include <ostream>
#include <sstream>


using namespace std;





//void write(std::ostream &buf)
//{
//    buf << "Fooo data" << std::endl;
//}

//void read(std::istream &buf)
//{
//    std::cout << buf.rdbuf() << std::endl;
//}

//int main(int argc, char** argv)
//{
//    std::stringstream stringBuf;
//    write(stringBuf);
//    std::cout << stringBuf.rdbuf();
//    std::string str(stringBuf.str());
//    std::istringstream inBuf(str);
//    read(inBuf);
//    return 0;
//}


#include <stdlib.h>

int int_sorter( const void *first_arg, const void *second_arg )
{
    int first = *(int*)first_arg;
    int second = *(int*)second_arg;
    if ( first < second )
    {
        return -1;
    }
    else if ( first == second )
    {
        return 0;
    }
    else
    {
        return 1;
    }
}

//int main()
//{
//    int array[10];
//    int i;
//    /* fill array */
//    for ( i = 0; i < 10; ++i )
//    {
//        array[ i ] = 10 - i;
//    }
//    qsort( array, 10 , sizeof( int ), int_sorter );
//    for ( i = 0; i < 10; ++i )
//    {
//        std::cout<< ( "%d\n" ,array[ i ] );
//    }

//}





//int solution(vector<int> &A) {
//    // write your code in C++11

//    if(A.size()<2 )
//    {
//        return 0;
//    }

//    qsort( &A[0], A.size() , sizeof( int ), int_sorter );

//    for(std::size_t i=0;i<A.size()-1;i++)
//    {
//        //std::cout<<A.at(i) <<std::endl;
//        if( (A.at(i+1)-A.at(i))   ==2 )
//        {
//            return A.at(i)+1;
//        }
//    }
//}

int solution1(vector<int> &A) {
    // write your code in C++11

    int count=0;

    if(A.size()<2 )
    {
        return 0;
    }

   for(std::size_t i=0;i<A.size();i++)
   {

       for(std::size_t j=i+1;j<A.size();j++)
       {
           if(A.at(i)==A.at(j) )
           {
                count++;

           }

       }
   }
   return count;
}


int solution2(vector<int> &A) {
    // write your code in C++11

    int count=0;

    if(A.size()<2 )
    {
        return 0;
    }

    int index=0;

    int value=A.at(index);
    count++;



    while(value>-1)
    {
        std::cout<< "index: " <<index << " value is:" << value ;
        count++;

        if(index>A.size())
        {
            //list is wrong. returning the  correct available linked list size
            return count;

        }

        index=A.at(index) ;

        if(index>A.size())
        {
            //list is wrong. returning the  correct available linked list size
            return count;

        }


        value=A.at(index) ;
        std::cout<<" sucessor is " << index<<std::endl;
    }

   return count;
}



struct  tree
{

    int x;
    tree *l;
    tree *r;
};


int main1()
{

/////////////////q1
//    vector<int> A;
//    A.push_back(3);
//    A.push_back(5);
//    A.push_back(6);
//    A.push_back(3);
//    A.push_back(3);
//    A.push_back(5);

//std::cout<<  solution1(A)<<std::endl;
/////////////////q2
    vector<int> A;
    A.push_back(1);
    A.push_back(4);
    A.push_back(-1);
    A.push_back(3);
    A.push_back(211);

    //std::cout<<  solution2(A)<<std::endl;


    std::cout<<"A.at(0): "  <<A.at(0)  <<std::endl;
    std::cout<<"A.size(): "  <<A.size()  <<std::endl;

    A.erase(A.begin());

    std::cout<<"A.at(0): "  <<A.at(0)  <<std::endl;



///////////////////////////q3




}


// Program to count islands in boolean 2D matrix
#include <stdio.h>
#include <string.h>
#include <stdbool.h>
 
#define ROW 4
#define COL 4
 
// A function to check if a given cell (row, col) can be included in DFS
int isSafe(int M[][COL], int row, int col, bool visited[][COL])
{
    // row number is in range, column number is in range and value is 1 
    // and not yet visited
    return (row >= 0) && (row < ROW) &&     
           (col >= 0) && (col < COL) &&      
           (M[row][col] && !visited[row][col]); 
}
 
// A utility function to do DFS for a 2D boolean matrix. It only considers
// the 8 neighbours as adjacent vertices
void DFS(int M[][COL], int row, int col, bool visited[][COL])
{
    // These arrays are used to get row and column numbers of 8 neighbours 
    // of a given cell
    static int rowNbr[] = {-1, -1, -1,  0, 0,  1, 1, 1};
    static int colNbr[] = {-1,  0,  1, -1, 1, -1, 0, 1};
 
    // Mark this cell as visited
    visited[row][col] = true;
 
    // Recur for all connected neighbours
    for (int k = 0; k < 8; ++k)
        if (isSafe(M, row + rowNbr[k], col + colNbr[k], visited) )
            DFS(M, row + rowNbr[k], col + colNbr[k], visited);
}
 
// The main function that returns count of islands in a given boolean
// 2D matrix
int countIslands(int M[][COL])
{
    // Make a bool array to mark visited cells.
    // Initially all cells are unvisited
    bool visited[ROW][COL];
    memset(visited, 0, sizeof(visited));
 
    // Initialize count as 0 and travese through the all cells of
    // given matrix
    int count = 0;
    for (int i = 0; i < ROW; ++i)
        for (int j = 0; j < COL; ++j)
            if (M[i][j] && !visited[i][j]) // If a cell with value 1 is not
            {                         // visited yet, then new island found
                DFS(M, i, j, visited);     // Visit all cells in this island.
                ++count;                   // and increment island count
            }
 
    return count;
}



template<typename to, typename from>
to lexical_cast(from const &x)
{
	std::stringstream os;
	to ret;
	os << x;
	os >> ret;
	return ret;
}

int ** twoDimentialVectortoArray(vector<vector<int> > &vals, int N, int M)
{
   int** temp;
   temp = new int*[N];
   for(unsigned i=0; (i < N); i++)
   { 
      temp[i] = new int[M];
      for(unsigned j=0; (j < M); j++)
      {
          temp[i][j] = vals[i][j];
      } 
   }
 }

 using namespace std;
int main()
{
	 std::vector<std::vector<int> > mat;
	 std::vector<int> row;
	 
	vector <string> zombies;
	
	std::string temp;
	temp="1100";
	zombies.push_back(temp);
	temp="1110";
	zombies.push_back(temp);
	temp="0110";
	zombies.push_back(temp);
	temp="0001";
	zombies.push_back(temp);
	for(std::size_t i=0;i<zombies.size();i++)
	{	row.clear();
		for(std::size_t j=0;j<zombies.at(i).size();j++)
		{
			//cout<< zombies.at(i).size()<<endl;
			cout<<zombies.at(i).at(j);
			row.push_back( lexical_cast<int>(zombies.at(i).at(j)) );
			
		}
		mat.push_back(row);
		cout<<endl;
	}
	
	
	int N=mat.size(); 
	int M=mat.at(0).size();
	
	int ** myarray=twoDimentialVectortoArray(mat,  N,  M);
	
	//int my_array[][COL]=my_array;
	
//     int M[][COL]= {  {1, 1, 0, 0, 0},
//         {0, 1, 0, 0, 1},
//         {1, 0, 0, 1, 1},
//         {0, 0, 0, 0, 0},
//         {1, 0, 1, 0, 1}
//     };
 
    printf("Number of islands is: %d\n", countIslands(myarray,4));
	
	
// 		for (std::size_t k=1;k<1000;k++)
// 		{
// 			
// 			int n, i;
// 			n=k;
// 			bool isPrime = true;
// 
// 
// 			for(i = 2; i <= n / 2; ++i)
// 			{
// 			if(n % i == 0)
// 			{
// 			isPrime = false;
// 			break;
// 			}
// 			}
// 			if (isPrime)
// 			cout << n<<endl;
// 
// 		} 

	
 
    return 0;
}



