////
/*
    Part 1:
        We have a bunch of monkeys
            They either have an equation(string with other monkeys as the inputs)
            or
            They have a number to be used for other monkey's equations. 
        We need to get the value of the monkey named "root". 
            This requires tracing the monkeys back from the root call 
                and figuring out what the values are when applying the various equations
*/
////
#include <vector>
#include <fstream>
#include <iostream>
#include "Monkey.cpp"

using namespace std;
int main()
{
    fstream inFile("input.txt");
    string line;
    std::vector<Monkey> monkeys;
    while(!inFile.eof())
    {
        getline(inFile, line);
        Monkey tmpMonke;
        int delim = line.find(":");
        tmpMonke.name = line.substr(0, delim);
        tmpMonke.monkeys = &monkeys;
        string rest = line.substr(delim+2);

        int test1 = rest.find("+");
        int test2 = rest.find("-");
        int test3 = rest.find("*");
        int test4 = rest.find("/");

        if(test1 > 0 || test2 > 0 || test3  > 0|| test4 > 0)
        {
            tmpMonke.equation = rest;
            tmpMonke.value = 0;
        }
        else
        {
            tmpMonke.equation = "";
            tmpMonke.value = stoi(line.substr(delim+1));
        }
        monkeys.push_back(tmpMonke);
    }

    for(Monkey monke : monkeys)
    {
        if (monke.name == "root")
        {
            monke.value = monke.getValue(monke);
            printf("The value of root is: %lli\n", monke.value);
        }
    }
}

