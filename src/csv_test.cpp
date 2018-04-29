# include "csv.h"
#include <iostream>


//https://github.com/ben-strasser/fast-cpp-csv-parser

int main(){
  io::CSVReader<7> in("/home/behnam/Desktop/gmm-gmr/build/outdata/data01_rescaled.txt");

  in.read_header(io::ignore_extra_column, "x", "y1", "y2" , "y3","y4" ,"y5" ,"y6");
  std::string vendor; int x; double y1,y2,y3,y4,y5,y6;

  while(in.read_row(x,y1,y2,y3,y4,y5,y6))
  {
    // do stuff with the data
      std::cout<<"x:" <<x <<std::endl;
  }
}
