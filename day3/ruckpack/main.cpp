#include <iostream>
#include <fstream>
#include <string>
#include <algorithm>
#include <functional>

using std::cout, std::endl, std::cin;

int main() {
    std::string filePath{"./ruckpacks.txt"};
    std::string fileLine;
    std::ifstream myFile(filePath);
    std::string first_half{}, second_half{}, str_priority{};
    std::string badges{};
    char target{};

    while (myFile.good()){
        getline(myFile, fileLine);
        //cout << fileLine << endl;

        auto half{fileLine.size() / 2};

        first_half.append(fileLine.begin(), fileLine.begin() + half);
        second_half.append(fileLine.begin() + half, fileLine.end());
        //cout << first_half << endl;
        //cout << second_half << endl;

        int i{};
        bool found{false};
        while (i < first_half.size())
        {
            if (found)
                break;
            target = first_half[i];
            int k{};
            while (k < half)
            {
                if (second_half[k] == target){
                    str_priority.append(1, target);
                    found = true;
                    break;
                }
                k++;
            }
            i++;
        }
        first_half.clear();
        second_half.clear();
    }

    bool found = false;
    const size_t s_size{3};
    std::string strCatch{};

    myFile.close();
    myFile.open(filePath);
    std::string str1{}, str2{}, str3{};
    int indexBadges{};
    while (myFile.good())
    {
        getline(myFile, str1);
        getline(myFile, str2);
        getline(myFile, str3);
        strCatch.clear();
        found = false;
        for (auto j{0}; j < str1.size(); j++)
        {
            char character{str1[j]};
            for (auto i{0}; i < str2.size(); i++)
            {
                if (character == str2[i])
                    strCatch.append(1, character);
            }
        }
        for (auto j{0}; j < strCatch.size(); j++)
        {
            if (found)
                break;
            char character{strCatch[j]};
            for (auto i{0}; i < str3.size(); i++)
            {
                if (found)
                    break;
                if (character == str3[i])
                {
                    badges.append(1, character);
                    found = true;
                }
            }
        }
        cout << "---------------------" << endl;
        cout << str1 << endl;
        cout << str2 << endl;
        cout << str3 << endl;
        cout << "badges[" << indexBadges << "]: " << badges[indexBadges] << endl;
        cout << "strCatch: " << strCatch << endl;
        cout << "badges :" << badges << endl;
        cout << "size of badges" << badges.size() << endl;
        //if (badges.size() >= 100)
         //   break;
        indexBadges++;
    }

    cout << "----------------------------------------------" << endl;
    size_t count{str_priority.size()};
    long ruckpack{};
    int temp{};
    for (size_t i{}; i < count; i++)
    {
        if ('a' <= str_priority[i] )
        {
            temp = int(str_priority[i]) - int('a') + 1;
        }
        else {
            temp = int(str_priority[i]) - int('A') + 27;
        }
        ruckpack = temp + ruckpack;
        //cout << ruckpack << '\t' << str_priority[i] << '\t' <<temp << endl;
    }
    temp = 0;
    int intBadges{};
    count = badges.size();
    for (size_t i{}; i < 100; i++)
    {
        if ('a' <= badges[i] )
        {
            temp = int(badges[i]) - int('a') + 1;
        }
        else {
            temp = int(badges[i]) - int('A') + 27;
        }
        intBadges = temp + intBadges;
        //cout << ruckpack << '\t' << str_priority[i] << '\t' <<temp << endl;
    }
    //cout <<str_priority[0] << '\t'<< str_priority[0] - 'a' + 1 << endl;
    //cout <<str_priority[326] << '\t'<< str_priority[326] - 'A' + 27 << endl;

//    cout << "str_priority: " << str_priority << endl;
    cout << "badges: " << badges << endl;
    cout << endl;
    cout << "-------------" << endl;
    cout << "Ruckpack: " << ruckpack << endl;
    cout << "intBadges: " << intBadges << endl;
}