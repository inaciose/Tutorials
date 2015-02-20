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

struct X{};

struct Y{};

istream& operator>>(istream&, X&) {}

istream& operator>>(istream&, Y&)
{
    stringstream ss("foo");

    X x;
    ss >> x;
}

int main1()
{
    Y y;
    cin >> y;
}



void write(std::ostream &buf)
{
    buf << "Fooo data" << std::endl;
}

void read(std::istream &buf)
{
    std::cout << buf.rdbuf() << std::endl;
}

int main(int argc, char** argv)
{
    std::stringstream stringBuf;
    write(stringBuf);
    std::cout << stringBuf.rdbuf();
    std::string str(stringBuf.str());
    std::istringstream inBuf(str);
    read(inBuf);
    return 0;
}











