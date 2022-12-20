////
/*
    Part 1: 
        We have a list of commands
            The commands have a certain amount of time they take to execute
                noop = 1 "tick" but does nothing. 
                addx <value> = 2 ticks and applies a x += <value>
            The commands have to be queued, but their counts happen simultaneously. 
                We have 3 cmds: noop addx add x.
                    First tick, noop is called and finishes that tick. 
                    Second tick addx is called and is on it's first tick. 
                    Third tick, add x is called. Second tick's add x finishes and third tick's add has it's first tick. 
                    4th tick, third tick's add x is called. 
            We need to track 20th tick and then every 40 tickets from then on. 
                Take the tick count and multiple it by current X value. 
                    If a addx is in flight but hasn't been applied then we need to not add it to the gathered value. 
                We care about the following tick counts: 
                    20th, 60th, 100th, 140th, 180th, and 220th
                We then need to add up those ticks to get the final number. 
*/
////
#include <vector>
#include <fstream>
#include <iostream>
using namespace std;

int getCount(string command)
{
    //break command into it's first and second parts
    //if noop, return 0
    //if addx <value> return value. 
    int delim = command.find(" ");
    string cmd = command.substr(0, delim);
    if(cmd == "noop")
    {
        return 0;
    }
    else if(cmd == "addx")
    {
        return stoi(command.substr(delim));
    }
}
string getCmd(string command)
{
    int delim = command.find(" ");
    return command.substr(0, delim);
}

std::vector<int> initVec()
{
    std::vector<int> vec;
    vec.push_back(19);
    vec.push_back(59);
    vec.push_back(99);
    vec.push_back(139);
    vec.push_back(179);
    vec.push_back(219);
    return vec;
}

int main()
{
    int x = 1;
    int cycleCount = 0;
    int writeCount = 0;
    std::vector<int> values;
    std::vector<int> times = initVec();
    std::vector<string> lines;
    string line;
    int amountToAdd;
    string currCmd;
    string lastCmd;
    ifstream inFile("input.txt");
    while(!inFile.eof())
    {   
        getline(inFile, line);
        lines.push_back(line);
    }
    for (int i = 0; i<240; i++)
    {

        if(cycleCount % 40 == 0)
        {
            printf("\n");
        }
        if (cycleCount == times.front())
        {
            values.push_back(x * (times.front() + 1));
            times.erase(times.begin());
        }
        currCmd = getCmd(lines[i]);
        if(currCmd == "addx")
        {
            lines.insert(lines.begin() + i + 1, "noop");
        }
        
        if(cycleCount%40 == x || cycleCount%40 == x-1 || cycleCount%40 == x-2)
        {
            printf("#");
        }
        else
        {
            printf(".");
        }
        x += getCount(lines[i]);
        cycleCount++;
    }
    int total = 0;
    printf("\n");
    for (int i = 0; i < values.size(); i++)
    {
        printf("The value we are adding is %i\n", values[i]);
        total += values[i];
    }
    printf("The grand total was %i \n", total);
}



