#include <iostream>
#include <fstream>
#include <string>
#include <algorithm>
#include <functional>

using std::cout, std::endl, std::cin;

int main() {
    std::string filePath{"./pairs.txt"};
    std::ifstream myFile(filePath);
    std::string fileLine;
    std::string first_half{}, second_half{};
    std::string pair1{}, pair2{};

    int i{}, countPairs{}, partialPairs{};
    //while (i < 100)
    while (myFile.good())
    {
        getline(myFile, fileLine);
        if (!fileLine.empty())
        {
            //cout << fileLine << endl;
            auto a{fileLine.find(',')};
            first_half.append(fileLine.begin(), fileLine.begin() + a);
            second_half.append(fileLine.begin() + a + 1, fileLine.end());
            //cout << first_half << '\t' << second_half << endl;
            a = first_half.find('-');
            int a1{std::stoi(pair1.append(first_half.begin(), first_half.begin() + a))};
            int a2{std::stoi(pair2.append(first_half.begin() + a + 1, first_half.end()))};
            pair1.clear();
            pair2.clear();
            a = second_half.find('-');
            int b1{std::stoi(pair1.append(second_half.begin(), second_half.begin() + a))};
            int b2{std::stoi(pair2.append(second_half.begin() + a + 1, second_half.end()))};
            cout << a1 << " " << a2 << endl;
            cout << b1 << " " << b2 << " " << endl;
            if ((a1 <= b1) && (a2 >= b2))
            {
                countPairs++;
                cout << "paired" << endl;
            }
            else
            if ((b1 <= a1) && (b2 >= a2))
            {
                countPairs++;
                cout << "paired" << endl;
            }
            if ((a2 < b1) || (b2 < a1)){}
            else {
                partialPairs++;
            }
            //cout << countPairs << endl;
            //cout << "-----------------" << endl;
            pair1.clear();
            pair2.clear();
            first_half.clear();
            second_half.clear();
            // i++;
        }
    }
    cout << "Number of pairs fully contained :" << countPairs << endl;
    cout << "Number of partial overlap pairs: " << partialPairs << endl;
}