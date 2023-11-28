#include "file_utils.h"
#include <iostream>
#include <cstring>

struct MyFile {
    FILE* file; 
};

MyFile* myFopen(const char* filename, const char* mode) {
    MyFile* myFile = new MyFile;

    if (fopen_s(&(myFile->file), filename, mode) != 0) {
        delete myFile;
        return nullptr;
    }

    return myFile;
}

int myFclose(MyFile* myFile) {

    int result = fclose(myFile->file);
    delete myFile;
    return result;
}

char* myFgets(char* str, int num, MyFile* myFile) {
    return fgets(str, num, myFile->file);
}

void compareAndPrintLines(MyFile* file1, MyFile* file2) {

    const int MAX_LINE_LENGTH = 1000;
    char line1[MAX_LINE_LENGTH], line2[MAX_LINE_LENGTH];
    int lineNumber = 0;

    while (myFgets(line1, MAX_LINE_LENGTH, file1) && myFgets(line2, MAX_LINE_LENGTH, file2)) {
        lineNumber++;


        if (std::strcmp(line1, line2) != 0) {
            std::cout << "Line " << lineNumber << ":" << std::endl;
            std::cout << "File 1: " << line1;
            std::cout << "File 2: " << line2;
            std::cout << std::endl;  
        }
    }

    
    while (myFgets(line1, MAX_LINE_LENGTH, file1)) {
        lineNumber++;
        std::cout << "Line " << lineNumber << ":" << std::endl;
        std::cout << "File 1: " << line1;
        std::cout << "File 2: [end of file]" << std::endl;
        std::cout << std::endl;
    }

    while (myFgets(line2, MAX_LINE_LENGTH, file2)) {
        lineNumber++;
        std::cout << "Line " << lineNumber << ":" << std::endl;
        std::cout << "File 1: [end of file]" << std::endl;
        std::cout << "File 2: " << line2;
        std::cout << std::endl;
    }
}
