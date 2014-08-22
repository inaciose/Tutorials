/*
 * ReadingFile.cpp
 *
 *  Created on: Apr 13, 2012
 *      Author: behnam
 */



#include <iostream>
#include <fstream>
#include <string>
using namespace std;


void reading_file_at_once()
{
    std::string path_to_file;
    std::ifstream in(path_to_file.c_str());
    std::stringstream buffer;
    buffer << in.rdbuf();
    std::string contents(buffer.str());
    std::cout<<contents <<std::endl;
}

int ReadingFilemain(int argc, char* argv[]){
  string line;
  ifstream myfile ("src/ReadWriteFile/example.txt");
  if (myfile.is_open())
  {
    while ( getline (myfile,line) )
    {
      //getline (myfile,line);
      cout <<"..." <<line << "..."<<endl;
    }
    myfile.close();
  }

  else
  {
	  cout << "Unable to open file...";
  }
  return 0;
}
