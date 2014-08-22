#include <iostream>
#include <stdio.h>
#include "Bitmap.hpp"



Bitmap::Bitmap(const char* filename) 
{
    FILE* file;
    file = fopen(filename, "rb");

    std::cout << sizeof(BITMAPFILEHEADER) << std::endl;

    if(file != NULL) { // file opened
        BITMAPFILEHEADER h;
        size_t x = fread(&h, sizeof(BITMAPFILEHEADER), 1, file); //reading the FILEHEADER

        std::cout << x;
        fread(&this->ih, sizeof(BITMAPINFOHEADER), 1, file);

        fclose(file);
    }
}


Bitmap::~Bitmap() 
{
	
}
