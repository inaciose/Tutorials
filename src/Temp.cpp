/*
 #include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <vector>
#include <string.h>
#include <limits>

struct node
{
    int x;
    struct node* left;
    struct node* right;
    bool visited;

};
 
 
struct node* newNode(int x)
{
  struct node* node = (struct node*)
                       malloc(sizeof(struct node));
  node->x = x;
  node->left = NULL;
  node->right = NULL;
  node->visited=false;
  return(node);
}


std::vector <std::string> traversed_path;
std::vector< std::vector <std::string> >max_pathes;
int max_path;
int path_lengh;
std::string path;


int dfs_traverse2(struct node *node)
{
    node->visited=true;
    if(node!=NULL)
    {
        //std::cout<<"visiting node->x " << node->x <<std::endl;



        //first visit the left child
        if( (node->left!=NULL)  && !node->left->visited)
        {
            traversed_path.push_back("l");
            dfs_traverse2(node->left);
            traversed_path.pop_back();


        }

        // then visit the right child
        if( (node->right!=NULL)  && !node->right->visited)
        {
            traversed_path.push_back("r");
            dfs_traverse2(node->right);
            traversed_path.pop_back();

        }

    }

    if(node->right==NULL && node->left==NULL)
    {
        //now we can check the size of path,



        if( traversed_path.size() >max_path )
        {
//            std::cout<< "-----------------------------------------" <<std::endl;
//            std::cout<< "traversed_path.size() " << traversed_path.size()  <<std::endl;

            max_pathes.clear();
            max_pathes.push_back( traversed_path);
            max_path=traversed_path.size();
        }
        else if( traversed_path.size() ==max_path )
        {

            max_pathes.push_back( traversed_path);
        }


    }

}



void path_amplitude(std::vector <std::string> path, node *tree, int &amplitude )
{
    int max_value_in_path, min_value_in_path;
//    max_value_in_path=std::numeric_limits<int>::min();
//    min_value_in_path=std::numeric_limits<int>::max();


    max_value_in_path=tree->x;
    min_value_in_path=tree->x;

    for(std::size_t i=0;i<path.size();i++)
    {
        if(path.at(i)=="r")
        {
            tree=tree->right;
            max_value_in_path=std::max(tree->x,max_value_in_path);
            min_value_in_path=std::min(tree->x,min_value_in_path);
        }



        if(path.at(i)=="l")
        {
            tree=tree->left;
            max_value_in_path=std::max(tree->x,max_value_in_path);
            min_value_in_path=std::min(tree->x,min_value_in_path);
        }


    }
    amplitude= max_value_in_path-min_value_in_path;

}

int main()
{
 

    struct node *root = newNode(5);
    root->left        = newNode(8);
    root->right       = newNode(9);
    root->left->left  = newNode(12);
    root->left->right = newNode(2);

    root->right->right = newNode(4);
    root->right->left = newNode(7);

    root->right->right->left = newNode(3);
    root->right->left->left = newNode(1);



    max_path=0;
    path_lengh=0;
    dfs_traverse2(root);
    int amplitude;
    int max_min_difference_path;
    std::vector<int> vector_of_max_min_difference_path;
    int max_difrences=0;

    std::cout<<"path with the longest length are:" <<std::endl;
    std::cout<<"--------------------------------------------------------------------" <<std::endl;

    for(std::size_t i=0;i< max_pathes.size();i++)
    {
        std::cout<<"path "<< i<<" is " <<std::endl;

        for(std::size_t j=0;j<max_pathes.at(i).size();j++)
        {
           std::cout<< max_pathes.at(i).at(j)  <<std::endl;
        }

        path_amplitude(max_pathes.at(i), root, max_min_difference_path );
        std::cout<<"max min difference path of this path is: " <<max_min_difference_path<<std::endl;
        if(max_min_difference_path>max_difrences)
        {
            max_difrences=max_min_difference_path;
        }
    }
    std::cout<<"--------------------------------------------------------------------" <<std::endl;


    std::cout<<"the amplitude of three is: " <<max_difrences<<std::endl;

    return 0;

}

*/
// you can use includes, for example:
// #include <algorithm>

// you can write to stdout for debugging purposes, e.g.
// cout << "this is a debug message" << endl;


#include <string>
#include <vector>
#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <vector>
#include <string.h>
#include <limits>
#include <iostream>     // std::cout, std::ios
#include <sstream>  
#include <sys/resource.h>
#include <math.h>
#include <iomanip>

template<typename to, typename from>
to lexical_cast(from const &x)
{
	std::stringstream os;
	to ret;
	os << x;
	os >> ret;
	return ret;
}


std::vector<std::string> split(const std::string& s, char delimiter)
{
   std::vector<std::string> tokens;
   std::string token;
   std::istringstream tokenStream(s);
   while (std::getline(tokenStream, token, delimiter))
   {
      tokens.push_back(token);
   }
   return tokens;
}


int solution(std::string &S, std::string &T,std::string &U)
{

	char delimiter='\n';

	
	std::size_t found = S.find(U);
	if (found!=std::string::npos)
	{
		//std::cout << "found at: " << found << '\n';
	}
		
	else
	{
		//std::cout << "not found"<< '\n';
		return -1;
	}
		

		
	
	std::string str_user_version = T.substr (found+U.size()+1);
	//std::cout << str_version<< '\n';
	int user_version =lexical_cast<int>(str_user_version); 
	//std::cout <<"user_version: "  <<user_version<< std::endl;
	
	
	
	int sum=0;
	
	std::vector<std::string> regions_in_catalog=split(S, delimiter);
	
	
	for(std::size_t i=0;i<regions_in_catalog.size();i++)
	{
		std::size_t found = regions_in_catalog.at(i).find(U);
		
		if (found!=std::string::npos)
		{
			std::string str_catalog_version = regions_in_catalog.at(i).substr (found+U.size()+1);
			
			
			std::size_t location_of_coma=str_catalog_version.find(',');
			str_catalog_version=str_catalog_version.substr(0,location_of_coma);
			//std::cout <<"str_catalog_version: "  <<str_catalog_version<< '\n';
			int catalog_version =lexical_cast<int>(str_catalog_version); 
			
			
			if(catalog_version> user_version)
			{

				std::string temp= regions_in_catalog.at(i);
				
				std::string str_package_size=  temp.substr(temp.find_last_of(',') +1);
				int package_size=lexical_cast<int>(str_package_size);
				//std::cout<<package_size  <<std::endl;
				sum=sum+package_size;
				
			}
		}
		
		//std::cout<<"sum:" <<sum <<std::endl;
		
	}

	return sum;

}

void test_tomtom()
{
    std::string S="Netherlands,1,25000\nNetherlands,2,3000\nNetherlands,3,1000";
    std::string T="Netherlands,1\nBelgium,4";
    std::string U="United Kingdom";
    //std::string U="Netherlands";
    std::cout<<solution(S,T,U)<<std::endl;
}

void temp(int argc, char ** argv)
{
//    std::string inp("AAGTGTTTCCAACGT");
//    const ACGTString myString(inp);
//    std::cout << myString[2] << std::endl;
}

int main(int argc, char ** argv)
{
//    temp(argc,   argv);
    //memory_size();
    //size_of_types();
//    precision();

}
