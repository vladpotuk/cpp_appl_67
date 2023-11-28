#ifndef FILE_UTILS_H
#define FILE_UTILS_H

struct MyFile; 

MyFile* myFopen(const char* filename, const char* mode);
int myFclose(MyFile* file);
char* myFgets(char* str, int num, MyFile* file);

void compareAndPrintLines(MyFile* file1, MyFile* file2);

#endif 
