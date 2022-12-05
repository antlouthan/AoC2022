////
/*
    Part 1:
        We have a series of locations with crates already in them. 
        We have a list of instructions to move X crates from Location A to Location B.
*/
////

#include <vector>
#include <iostream>
#include <fstream>
#include <string>
using namespace std;

std::vector<std::vector<char> > setUpCrates()
{
    std::vector<std::vector<char> > c(9);
    c[0].push_back('S');
    c[0].push_back('C');
    c[0].push_back('V');
    c[0].push_back('N');

    c[1].push_back('Z');
    c[1].push_back('M');
    c[1].push_back('J');
    c[1].push_back('H');
    c[1].push_back('N');
    c[1].push_back('S');

    c[2].push_back('M');
    c[2].push_back('C');
    c[2].push_back('T');
    c[2].push_back('G');
    c[2].push_back('J');
    c[2].push_back('N');
    c[2].push_back('D');

    c[3].push_back('T');
    c[3].push_back('D');
    c[3].push_back('F');
    c[3].push_back('J');
    c[3].push_back('W');
    c[3].push_back('R');
    c[3].push_back('N');

    c[4].push_back('P');
    c[4].push_back('F');
    c[4].push_back('H');

    c[5].push_back('C');
    c[5].push_back('T');
    c[5].push_back('Z');
    c[5].push_back('H');
    c[5].push_back('J');

    c[6].push_back('D');
    c[6].push_back('P');
    c[6].push_back('R');
    c[6].push_back('Q');
    c[6].push_back('F');
    c[6].push_back('S');
    c[6].push_back('L');
    c[6].push_back('Z');

    c[7].push_back('C');
    c[7].push_back('S');
    c[7].push_back('L');
    c[7].push_back('H');
    c[7].push_back('D');
    c[7].push_back('F');
    c[7].push_back('P');
    c[7].push_back('W');

    c[8].push_back('D');
    c[8].push_back('S');
    c[8].push_back('M');
    c[8].push_back('P');
    c[8].push_back('F');
    c[8].push_back('N');
    c[8].push_back('G');
    c[8].push_back('Z');

    return c;
}

void performMoves(std::vector<std::vector<char> > &c, int move, int start, int end)
{
    if (move > c[start].size())
    {
        move = c[start].size();
    }
    for (int i = 0; i < move; i++)
    {
        
        c[end].push_back(c[start].back());
        c[start].pop_back();
    }
}

void performMoves2(std::vector<std::vector<char> > &c, int move, int start, int end)
{
    std::vector<char> temp;
    if (move > c[start].size())
    {
        move = c[start].size();
    }
    for (int i = 0; i < move; i++)
    {
        temp.push_back(c[start].back());
        c[start].pop_back();
    }
    for (auto it: temp)
    {
        c[end].push_back(temp.back());
        temp.pop_back();
    }
}

int main()
{
    std::vector<std::vector<char> > crates = setUpCrates();
    std::vector<std::vector<char> > crates2 = setUpCrates();
    int numToMove, startCrate, endCrate;
    string line;
    std::ifstream infile("input.txt");
    int count = 0;
    while(infile >> line)
    {
        for(int i = 0; i < strlen(line.c_str()); i++)
        {
            if (isdigit(line[i]))
            {
                if (count == 0)
                {
                    numToMove = stoi(line);
                    count++;
                    i++;
                }
                else if (count == 1)
                {
                    //Take the number provided and subtract 1 cuz off by one funtimes. 
                    startCrate = stoi(line) - 1;
                    count++;
                }
                else if (count == 2)
                {
                    //Take the number provided and subtract 1 cuz off by one funtimes. 
                    endCrate = stoi(line) - 1;
                    performMoves(crates, numToMove, startCrate, endCrate);
                    performMoves2(crates2,numToMove, startCrate, endCrate);
                    count = 0;
                }
            }
        }
    }
    for (auto it: crates)
    {
        printf("%c", it.back());
    }
    printf("\n");
    for (auto it: crates2)
    {
        printf("%c", it.back());
    }

}

