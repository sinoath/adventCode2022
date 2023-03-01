#include <iostream>
#include <fstream>
#include <string>
#include <algorithm>
#include <functional>

using std::cout, std::endl, std::cin;

int main() {
    std::string filePath{"./calories.txt"};
    std::string fileLine;
    std::ifstream myFile(filePath);

    int max_calories{0};
    int elf_calories{0};
    int array[270]{0};
    int count{0};
    int top_3_calories{0};

    while (myFile.good())
    {
        getline(myFile, fileLine);
        if (fileLine.empty())
        {
            array[count++] = elf_calories;
            elf_calories = 0;
        }
        else{
            elf_calories = elf_calories + stoi(fileLine);
            if (max_calories < elf_calories) max_calories = elf_calories;
        }
    }
    cout << "max calories: " << max_calories << endl;
    std::sort(&array[0], &array[270]);
    for (int i{0}; i < 3; i++)
    {
        cout << array[269 - i] << endl;
        top_3_calories = top_3_calories + array[269 - i];
    }
    cout << top_3_calories << endl;
}