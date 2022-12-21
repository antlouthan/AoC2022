#pragma once
#include <string>
using namespace std;
class Monkey
{
    public:
        Monkey();
        string name; 
        string equation;
        long long value;
        std::vector<Monkey> * monkeys;

        long long getValue(Monkey monke);
        long long addVal(string eq, std::vector<Monkey> monkeys);
        long long subVal(string eq, std::vector<Monkey> monkeys);
        long long multVal(string eq, std::vector<Monkey> monkeys);
        long long divVal(string eq, std::vector<Monkey> monkeys);

};