#include <iostream>
#include <fstream>
#include <string>
#include <algorithm>
#include <functional>

using std::cout, std::endl, std::cin;

int main() {
    std::string filePath{"./rock.txt"};
    std::string fileLine;
    std::ifstream myFile(filePath);
    char firstChar{}, secondChar{};
    unsigned score{};
    while (myFile.good())
    {
        getline(myFile, fileLine);
        if (!fileLine.empty())
        {
            firstChar = fileLine[0];
            secondChar = fileLine[2];
            switch (secondChar)
            {
                case 'X':{
                    score += 1;
                    if (firstChar == 'A')
                        score += 3;
                    if (firstChar == 'C')
                        score += 6;
                    break;
                }
                case 'Y':{
                    score += 2;
                    if (firstChar == 'B')
                        score += 3;
                    if (firstChar == 'A')
                        score += 6;
                    break;
                }
                case 'Z':{
                    score += 3;
                    if (firstChar == 'C')
                        score += 3;
                    if (firstChar == 'B')
                        score += 6;
                    break;
                }
                default:
                    break;
            }
        }
        //cout << "Temp score: " << score << endl;
    }
    
    cout << "Score: " << score << endl;
    unsigned altScore{};
    myFile.close();
    myFile.open(filePath);
    while (myFile.good())
    {
        getline(myFile, fileLine);
        if (!fileLine.empty())
        {
            firstChar = fileLine[0];
            secondChar = fileLine[2];
            switch (secondChar)
            {
                case 'X':{
                    if (firstChar == 'A')
                        altScore += 3;
                    if (firstChar == 'B')
                        altScore += 1;
                    if (firstChar == 'C')
                        altScore += 2;
                    break;
                }
                case 'Y':{
                    altScore += 3;
                    if (firstChar == 'A')
                        altScore += 1;
                    if (firstChar == 'B')
                        altScore += 2;
                    if (firstChar == 'C')
                        altScore += 3;
                    break;
                }
                case 'Z':{
                    altScore += 6;
                    if (firstChar == 'A')
                        altScore += 2;
                    if (firstChar == 'B')
                        altScore += 3;
                    if (firstChar == 'C')
                        altScore += 1;
                    break;
                }
                default:
                    break;
            }
        }
        //cout << "Temp altScore: " << altScore << endl;
    }
    cout << "Alternative score: "<< altScore << endl;
}