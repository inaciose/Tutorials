#include <iostream>
#include <fstream> //for file IO, both read and write
#include <bitset>
#include <complex>
#include <map>

/*
cout

    cout is an object! from type ostream which is in fact -> typedef basic_ostream<char> ostream;
    
<< operator

    << operator has the following signatur function which has been overloaded for various type string, int, double:
    ostream& ostream::operation<<(string v)
    and returns the refrence to the current stream

What is stream?
    Serial IO interface to external devices: file, stdin/stdout,network

Random access:
    sting my_str;
    my_str[3];

Serial Access:
    cout[3];// error!

    
StringStream
    A stringstream associates a string object with a stream allowing you to read from the string as if it were a stream (like cin).
    
*/

void stringstreamExample()
{
    std::stringstream ss;
    std::string name="behnam";
    int age=33;
    ss<<"name: "<<name;
    ss<<" age: "<<age;
    std::cout<< ss.str() <<std::endl;
    
    std::string word;
    
    //ss.getline();
   
    ss<<"23 4 5.0";
    
    while(ss>>word)
    {
        std::cout<<word <<std::endl;
    }
    
/////////////////////////////count words frquency/////////////////////////////////
    std::stringstream wordsFrquencyStream("a b bb c a dd d");
    wordsFrquencyStream.str("a b bb c a dd d");
    
    std::map<std::string,int> wordsFrquency;
    while(wordsFrquencyStream>>word)
    {
        wordsFrquency[word]++;
    }
    std::cout<<"Frequecy of words in "<<wordsFrquencyStream.str() <<std::endl;

    for(auto i:wordsFrquency)
        std::cout<<i.first<<":" <<i.second <<std::endl;

/////////////////////////////Hex Decimal/////////////////////////////////
    std::stringstream hexDecimalStream;
    hexDecimalStream<<std::hex<<10 <<" "<<std::hex<<12;
    std::cout<<hexDecimalStream.str() <<std::endl;
    
    unsigned int x,y;
    hexDecimalStream>>x>>y;
    std::cout<< x<<" "<<y <<std::endl;

    
}


//ostream, istream, ofstream and ifstream

void ifstreamExample()
{
    
}
/*
The ostream class has methods for formatting output, i.e. specifying scientific notation, fixed decimal notation, or a combination thereof, and for specifying the number of decimal digits displayed. 
*/

/*
https://ps.uci.edu/~cyu/p231C/LectureNotes/lecture14:iostreams/lecture14.pdf
http://www.cplusplus.com/reference/ostream/ostream/write/
http://www.physics.utah.edu/~detar/lessons/c++/canned_classes/node3.html
http://www.physics.utah.edu/~detar/lessons/c++/canned_classes/node6.html
http://www.physics.utah.edu/~detar/lessons/c++/canned_classes/node4.html

*/
void ostreamExample()
{
    
}

void ofstreamExample()
{
    
}
void readingWrittingFiles()
{
    //simple writting
    {
        std::ofstream myfile;
        //	myfile.open ("WritingIntoFile.txt"); //simply open the file(will clear its content)  for more option use below

        //std::ofstream::app -> append
        //std::ofstream::ate -> at the end
        //std::ofstream::in
        myfile.open ("ReadingWritingIntoFile.txt",std::ofstream::ate | std::ofstream::app);
        myfile << "Writing this to a file.\n";
        myfile<<std::bitset<8>(14); // it will write 00001110
        myfile<<std::complex<double>(2,3);
        myfile.close();
    }

    //advance writing
    {
        std::ofstream myfile("ReadingWritingIntoFile.txt",std::ofstream::in | std::ofstream::out);
        myfile.seekp( 10,std::ios::beg);// Move the output pointer 10 char from begining
        myfile<<"something at the begining";

        myfile.seekp( -5,std::ios::end);// Move the output pointer 5 char before end
        myfile<<"something at the end";
    }

    //reading chars
    {
        std::ifstream myfile("ReadingWritingIntoFile.txt");
        int i;
        myfile>>i;
        if(myfile.good())
        {
            std::cout<<"Reading successd "<<std::endl;
        }else
        {
            std::cout<<"Reading failed "<<std::endl;
        }
    }

    //reading file at once
    {
        std::string path_to_file;
        std::ifstream in(path_to_file.c_str());
        std::stringstream buffer;
        buffer << in.rdbuf();
        std::string contents(buffer.str());
        std::cout<<contents <<std::endl;
    }

    //reading line by line
    {
        std::string line;
        std::ifstream myfile ("src/ReadWriteFile/example.txt");
        if (myfile.is_open())
        {
            while ( getline (myfile,line) )
            {
            //getline (myfile,line);
            std::cout <<"..." <<line << "..."<<std::endl;
            }
            myfile.close();
        }
        else
        {
            std::cout << "Unable to open file...";
        }
    }



}


void formatingStream()
{
    std::cout.setf(std::ios::oct,std::ios::basefield);
    std::cout<<34<<std::endl; //will show 42
    std::cout.setf(std::ios::dec,std::ios::basefield);
    std::cout<<34<<std::endl; //will show 42
    std::cout.width(10);


    std::cout.setf(std::ios::scientific,std::ios::floatfield);
    std::cout<<3.14<<std::endl;//3.140000e+00
    std::cout.setf(std::ios::fixed,std::ios::floatfield);
    std::cout<<3.14<<std::endl;//3.140000
    std::cout.precision(1);
    std::cout<<3.14<<std::endl;//3.1



    std::cout<<std::cout.flags() <<std::endl;//3.1

}



int main()
{
//     readingWrittingFiles();
//    formatingStream();
   stringstreamExample();
}
