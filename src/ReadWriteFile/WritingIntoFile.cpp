// basic file operations
#include <iostream>
#include <fstream>
using namespace std;

int WritingIntoFilemain ()
//int main ()
{
	ofstream myfile;
	myfile.open ("../src/ReadWriteFile/WritingIntoFile.txt");
//	myfile.open ("WritingIntoFile.txt");
	myfile << "Writing this to a file.\n";
	myfile.close();
	return 0;
}
