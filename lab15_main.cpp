//Name: Christine Deidrich 
//Lab 15 - Semester Review (Super Secret Encoder)


#include <iostream>
#include <fstream>
#include <string>

//Function Prototypes
std::string getFilename();

int readFile(std::string filename, std::string& file_contents);

int main() {
    std::string file_contents;

    std::string filename = getFilename();
 
    readFile(filename, file_contents);

    int offset = file_contents[1];
    for (int i = 2; i < file_contents.length(); i++) {
       

        file_contents[i] -= offset;

        //handles the out of range
        if (file_contents[i] < 0) {
            file_contents[i] += 127;
        }
    }
    
    //removes the first two bytes (start from pos, how many char)
    file_contents.erase(0, 2);
    std::cout << "The super secret contents is: " << file_contents;

    return 0;
}

std::string getFilename()
{
    std::string filename = "";
    std::string filepath = "C:\\Users\\Christine Deidrich\\Downloads\\";

    std::cout << "Enter the filename (assumes in C:\\Users\\Christine Deidrich\\Downloads\\): ";
    std::getline(std::cin, filename);
    filename = filepath + filename;
    return filename;
}

int readFile(std::string filename, std::string& file_contents)
{
    std::ifstream in_file(filename);
    if (!in_file) {
        std::cerr << "Error opening file." << std::endl;
        return 1;
    }

    char c;
    while (in_file.get(c)) {
        file_contents += c;
    }
    in_file.close();

    return 0;
}
