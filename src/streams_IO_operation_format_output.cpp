#include <iostream>
#include <fstream> 
#include <bitset>
#include <complex>
#include <map>
#include <limits>


/*

class hierarchy
                                        ios
                                         |
                               -------------------          
                               |                 |            
                            ostream           istream
                               |                 |
                 ---------------------------------------------------
                 |                       |                         |
             ofstream                    |                     ifstream
                                         |
                                      iostream
                                         |
                                      fstream
ios
    In more recent compilers, ios has been replaced by ios_base. The class ios contains most of the actual I/O code. It is ios that keeps track of the error state of the stream. The ios class converts data for display. It understands the format of the different types of numbers, how to output character strings, and how to convert an ASCII string to and from an integer or a oating{point number.

istream class
    This class is responsible for handling input stream: get, getline, read, ignore, putback
    Standard output, cout, is an ob ject of the class ostream.

ostream class
    This class is responsible for handling output stream write, put
    The ostream class has methods for formatting output, i.e. specifying scientific notation, fixed decimal notation, or a combination thereof, and for specifying the number of decimal digits displayed. 


iostream
    This class is responsible for handling both input and output stream as both istream class and istream class is inherited into it. It provides function of both istream class and istream class.
    Standard input, cin, is an object of the class istream
    
    
    Standard input/ output, cin/cout, are object of the class istream/ostream. cout, cin, and
    cerr are automatically constructed as global ob jects at program start up
  
ofstream, ifstream, fstream
    Objects of ifstream deal with input files and objects of the class ofstream deal with output files. Objects fstream deal with files that can one can write to and read from.
    They are all in fstream.h
    
Overloading << and >>
    The overloaded right shift operator operator>>() is called the extractor.
    istream& operator>>(istream& source, &datatype);

    The overloaded left shift operator operator<<() is called the inserter.
    ostream& operator<<(ostream& dest, &datatype);

    
    
StringStream

    stream is serial IO interface to external devices: file, stdin/stdout,network.
    A stringstream associates a string object with a stream allowing you to read from the string as if it were a stream (like cin).
*/



//ofstream ifstream fstream Example
void readingWrittingFilesExample()
{
/*
Available Modes for Opening a File:

Flag          Application          Meaning
___________________________________________________________________________
ios::app         out               Always append output to the end of the file
___________________________________________________________________________
ios::ate         out               Open and seek to end-of-file ("at end")
___________________________________________________________________________
ios::binary      in, out           Open file in binary mode (as opposed to
text mode)
___________________________________________________________________________
ios::in          in                Open a file for input
___________________________________________________________________________
ios::nocreate    in, out           If file doesn't exist, don't create it
___________________________________________________________________________
ios::noreplace   out               Don't delete the file (open fails if file exists
                                   unless you specify appor ate)
___________________________________________________________________________
ios::out         out               Open file for output
___________________________________________________________________________
ios::trunc       out               Truncate file to zero length if it already exists 
                                   (default if file exists and app or ate is not specified)
___________________________________________________________________________

modes are bitset. For instance, ios::app might equal 00000001, ios::ate might equal 00000010, ios::out might equal 00000100, etc. So each mode corresponds to one bit which can be 0 or 1. This means that more than one mode's value can be set at the same time using the arithmetic OR.

*/
    {
        std::ifstream inputfile("inputfile.txt");
        std::ofstream outputfile("outputfile.txt");
        float f;
        while(inputfile>>f)//detects end-of-file and exits loop
        {
            outputfile << "f = " << f << std::endl;
        }
        inputfile.close();
        outputfile.close();
    }
    //simple writting
    {
        std::ofstream myfile;
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

void flushcin()
{
    //flush cin
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    std::system("read -p 'Press Enter to continue...' var");    
}

/*Member Functions of istream and ostream*/
void istreamostreamMemberFunctions()
{
/*
get()
It has two version:
    1)Can read a single char.
    2)It can input a series of characters terminated either by the appearance of a terminator character in the input stream or by a character count.
*/
    std::cout<<"Insert one character:" <<std::endl;
    char c;
    std::cin>>c;
    std::cout<<"your input was: " <<c <<std::endl;
    
    flushcin();
    std::cout<<"Insert array of characters of size 10:" <<std::endl;
    char buffer[10];
    std::cin.get(buffer, 10);
    std::cout<< "your input was: " << buffer <<std::endl;
    
    flushcin();
    
    /*getline()*/
    std::cout<<"Insert array of characters of arbitrary size in one line:" <<std::endl;
    std::string str;
    std::getline(std::cin,str);
    std::cout<< "your input was: " << str <<std::endl;
    

    flushcin();
    /*read()*/

    
    
    /*put()*/
    std::cout.put(c);
    
    /*putback(Ch c)*/
    
    /*write()*/
    
    /*scanf()*/
    
    /*printf()*/
    
    
    /*getchar()*/
    
    /*putchar()*/
    
    
    
}

int main()
{

}
