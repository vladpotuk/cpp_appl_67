#include <iostream>
#include "file_utils.h"

int main() {
    const char* filePath1 = "file1.txt";
    const char* filePath2 = "file2.txt";

    MyFile* file1 = myFopen(filePath1, "r");
    MyFile* file2 = myFopen(filePath2, "r");

    if (file1 == nullptr || file2 == nullptr) {
        std::cerr << "Unable to open one or both files." << std::endl;
        return 1;
    }

    compareAndPrintLines(file1, file2);

    myFclose(file1);
    myFclose(file2);

    return 0;
}
