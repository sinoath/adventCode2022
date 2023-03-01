#include <iostream>
#include <fstream>
#include <string>
#include <list>

using std::cout, std::endl, std::cin, std::string;

struct inFolderFile{
    string Name{};
    long Size{};
    bool isNode{true};
};

struct Directory{
    string Name{};
    std::list<inFolderFile> listOfFiles{};
    std::list<Directory *> listOfChildren{};
    Directory *parentFolder{};
};

Directory* createNode(string N){
    Directory *newDir = new Directory();
    newDir->Name = N;
    std::list<inFolderFile> List = newDir->listOfFiles;
    std::list<Directory *> Children = newDir->listOfChildren;
    newDir->parentFolder = newDir;
    return newDir;
};

void populateTree(const string str){
    if (str.substr(0,7) == "$ cd ..")
        cout << "changing to parent folder" << endl;
    else if (str.substr(2,2) == "cd")
        cout << "changing to directory " << str.substr(4) << endl;
    
    if (str[0] == 'd')
    {
        cout << "directory name " << str.substr(str.rfind(' ')) << endl;
        return;
    }else if ('0' <= str[0] && str[0] <= '9'){
        cout << "file name " << str.substr(str.rfind(' ')) << " and dimension: " << str.substr(0, str.find(' ')) << endl;
    }
}

int main() {
    std::string filePath{"./test.txt"};
    std::string fileLine{"not empty"};
    std::ifstream myFile(filePath);

     while (myFile.good())
     {
        getline(myFile, fileLine);
        if (!fileLine.empty())
        {
            populateTree(fileLine);
        }
    }
}