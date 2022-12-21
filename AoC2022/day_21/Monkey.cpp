#pragma once
#include <vector>
#include "Monkey.h"
using namespace std;
Monkey::Monkey()
{
    name = ""; 
    equation = "";
    value = 0;
    std::vector<Monkey> * monkeys;
}
long long Monkey::getValue(Monkey monke)
{
    if (monke.equation.empty())
    {
        return monke.value;
    }
    else
    {
        int test1 = monke.equation.find("+");
        int test2 = monke.equation.find("-");
        int test3 = monke.equation.find("*");
        int test4 = monke.equation.find("/");
        if (test1 > 0)
        {
            return addVal(monke.equation, *monkeys);
        }
        else if(test2 > 0)
        {
            return subVal(monke.equation, *monkeys);
        }
        else if(test3 > 0)
        {
            return multVal(monke.equation, *monkeys);
        }
        else if(test4 > 0)
        {
            return divVal(monke.equation, *monkeys);
        }

    }
}

long long Monkey::addVal(string eq, std::vector<Monkey> monkeys)
{
    int delim = eq.find("+");
    Monkey firstMonke;
    Monkey secondMonke;
    firstMonke.name = eq.substr(0, delim-1);
    secondMonke.name = eq.substr(delim+2);
    long long monke1Val = 0;
    long long monke2Val = 0;
    for (Monkey monkey : monkeys)
    {
        if (monke1Val !=0 && monke2Val !=0)
        {
            break;
        }
        if (firstMonke.name == monkey.name)
        {
            monke1Val = monkey.getValue(monkey);
        }
        else if(secondMonke.name == monkey.name)
        {
            monke2Val = monkey.getValue(monkey);
        }
    }
    return monke1Val + monke2Val;
}

long long Monkey::subVal(string eq, std::vector<Monkey> monkeys)
{
    int delim = eq.find("-");
    Monkey firstMonke;
    Monkey secondMonke;
    firstMonke.name = eq.substr(0, delim-1);
    secondMonke.name = eq.substr(delim+2);
    long long monke1Val = 0;
    long long monke2Val = 0;
    for (Monkey monkey : monkeys)
    {
        if (monke1Val !=0 && monke2Val !=0)
        {
            break;
        }
        if (firstMonke.name == monkey.name)
        {
            monke1Val = monkey.getValue(monkey);
        }
        else if(secondMonke.name == monkey.name)
        {
            monke2Val = monkey.getValue(monkey);
        }
    }
    return monke1Val - monke2Val;
}

long long Monkey::multVal(string eq, std::vector<Monkey> monkeys)
{
    int delim = eq.find("*");
    Monkey firstMonke;
    Monkey secondMonke;
    firstMonke.name = eq.substr(0, delim-1);
    secondMonke.name = eq.substr(delim+2);
    long long monke1Val = 0;
    long long monke2Val = 0;
    for (Monkey monkey : monkeys)
    {
        if (monke1Val !=0 && monke2Val !=0)
        {
            break;
        }
        if (firstMonke.name == monkey.name)
        {
            monke1Val = monkey.getValue(monkey);
        }
        else if(secondMonke.name == monkey.name)
        {
            monke2Val = monkey.getValue(monkey);
        }
    }
    return monke1Val * monke2Val;
}

long long Monkey::divVal(string eq, std::vector<Monkey> monkeys)
{
    int delim = eq.find("/");
    Monkey firstMonke;
    Monkey secondMonke;
    firstMonke.name = eq.substr(0, delim-1);
    secondMonke.name = eq.substr(delim+2);
    long long monke1Val = 0;
    long long monke2Val = 0;
    for (Monkey monkey : monkeys)
    {
        if (monke1Val !=0 && monke2Val !=0)
        {
            break;
        }
        if (firstMonke.name == monkey.name)
        {
            monke1Val = monkey.getValue(monkey);
        }
        else if(secondMonke.name == monkey.name)
        {
            monke2Val = monkey.getValue(monkey);
        }
    }
    return monke1Val / monke2Val;
}


