#include <iostream>
#include <string>
#include <fstream>

using std::cout, std::endl, std::cin;

int findPattern(std::string str){
    std::string pattern{};
    int pos{};
    bool found{false};
    int howMany{14};
    while (!found)
    {
        pattern = str.substr(pos, howMany);
        std::string::iterator it{pattern.begin()};
        int i{};
        while (i < howMany)
        {
            cout << pattern << "\t" << pattern[i] << "\t" << i << "\t" << pos << endl;
            if (pattern.rfind(pattern[i]) > i)
            {
                pos++;
                i++;
                break;
            }
            else
            {
                i++;
            }
            if (++it == pattern.end())
                return pos + howMany;
        }
    }
    return 0;
}

int main() {
    std::string fileLine;
    std::ifstream myFile("./signals.txt");
    int result{};
    //if (!myFile.eof())
    {
        getline(myFile, fileLine);
    }
    cout << fileLine << endl;
    if (!fileLine.empty())
    {
        result = findPattern(fileLine);
    }
    /*std::string test{"Dio porco"};
    cout << test << endl;
    test.erase(0, 1);
    cout << test << endl;
    auto num = test.find('a');
    if (num <= test.size())
        cout << "found" << endl;
    else
        cout << "not found" << endl;
    cout << "num: " << num << endl;
    cout << test.size() << endl;*/
    cout << result << endl;
}
