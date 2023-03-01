#include <iostream>
#include <fstream>
#include <string>
#include <stack>
#include <queue>

using std::cout, std::endl, std::cin;

// Extract numbers from the source file: how many, from wich stack and where to move elements
int * gettingNumbers(std::string fileLine){

    int firstPos{}, secondPos{};
    int static arr[3]{};
    std::string temp{};

    firstPos = fileLine.find(' ');
    secondPos = fileLine.find(' ', firstPos + 1);
    temp.append(fileLine.begin() + firstPos + 1, fileLine.begin() + secondPos);
    arr[0] = std::stoi(temp);
    
    temp.clear();
    firstPos = secondPos;
    secondPos = fileLine.find(' ', firstPos + 1);
    firstPos = secondPos;
    secondPos = fileLine.find(' ', firstPos + 1);
    temp.append(fileLine.begin() + firstPos + 1, fileLine.begin() + secondPos);
    arr[1] = std::stoi(temp);
    
    temp.clear();
    firstPos = secondPos;
    secondPos = fileLine.find(' ', firstPos + 1);
    firstPos = secondPos;
    secondPos = fileLine.find(' ', firstPos + 1);
    temp.append(fileLine.begin() + firstPos, fileLine.end());
    arr[2] = std::stoi(temp);

    return arr;
}

// Insert data inside the 9 stacks, extracting them from the source string
void populateStack(std::stack<char> * S, std::string str){
    int i = str.size();
    int pos{1}, temp{};
    if (str[0] == '[')
        S[0].push(str[1]);
    while (pos < i){
        temp = str.find('[', pos);
        if (temp <= 0)
            break;
        S[temp / 4].push(str[temp+1]);
        pos = temp + 1;
    }
}

void invertStack(std::stack<char> &S){
    std::queue<char> Q{};
    while (!S.empty())
    {
        Q.push(S.top());
        S.pop();
    }
    while (!Q.empty()){
        S.push(Q.front());
        Q.pop();
    }
}

void moveStack(std::stack<char> *S, int q, int f, int t){
    for (int i{}; i < q; i++)
    {
        S[t-1].push(S[f-1].top());
        S[f-1].pop();
    }
}

void altMoveStack(std::stack<char> *S, int q, int f, int t){
    std::stack<char> tempStack{};
    for (int i{}; i < q; i++)
    {
        tempStack.push(S[f - 1].top());
        S[f - 1].pop();
    }
    while (!tempStack.empty()){
        S[t - 1].push(tempStack.top());
        tempStack.pop();
    }
}

// Main Start
int main() {
    std::string filePath{"./stacks.txt"};
    std::ifstream myFile(filePath);
    std::string fileLine{};
    std::stack<char> stack[9]{};

    int from{}, whereTo{}, quantity{};
    int *numbers{};

    // Filling stacks
    while (myFile.good())
    {
        getline(myFile, fileLine);
        populateStack(stack, fileLine);
    }

    for (int i{}; i < 9; i++){
        invertStack(stack[i]);
    }

    myFile.close();
    myFile.open("./stacks.txt");

    while (myFile.good()){

        getline(myFile, fileLine);
        if (!fileLine.empty() && fileLine[0] == 'm'){
            numbers = gettingNumbers(fileLine);
            quantity = numbers[0];
            from = numbers[1];
            whereTo = numbers[2];
            moveStack(stack, quantity, from, whereTo);
        }
    }
    for (int i{}; i < 9; i++)
    {
        if (!stack[i].empty())
            cout << stack[i].top();
    }
    cout << endl;

    // Reset the stacks
    for (int i{}; i < 9; i++){
        while (!stack[i].empty()){
            stack[i].pop();
        }
    }

    // Refilling the stack
    myFile.close();
    myFile.open("./stacks.txt");
    while (myFile.good())
    {
        getline(myFile, fileLine);
        populateStack(stack, fileLine);
    }

    for (int i{}; i < 9; i++){
        invertStack(stack[i]);
    }

    myFile.close();
    myFile.open("./stacks.txt");

    while (myFile.good()){

        getline(myFile, fileLine);
        if (!fileLine.empty()&& fileLine[0] == 'm'){
            numbers = gettingNumbers(fileLine);
            quantity = numbers[0];
            from = numbers[1];
            whereTo = numbers[2];
            altMoveStack(stack, quantity, from, whereTo);
        }
    }
    for (int i{}; i < 9; i++)
    {
        if (!stack[i].empty())
            cout << stack[i].top();
    }

    cout << endl;
}