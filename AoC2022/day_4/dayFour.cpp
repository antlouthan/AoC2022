////
/*
    Part 1: 
    (Check)We get sets of number ranges. 
    (Check)We need to save off the start and end of each range. 
    We need to check if 1 range is FULLY contained within the other range
        If so, increase count. 
*/
////

#include <iostream>
#include <fstream>
#include <vector>
using namespace std;

int  containsAll(std::vector<int> elfData)
{
    int eFirstStart = elfData[0];
    int eFirstEnd = elfData[1];
    int eSecondStart = elfData[2]; 
    int eSecondEnd = elfData[3];
    if ((eSecondStart >= eFirstStart && eSecondEnd <= eFirstEnd) || (eFirstStart >= eSecondStart && eFirstEnd <= eSecondEnd))
    {
        return 1;
    }
    else 
        return 0;
}
bool overlaps(std::vector<int> elfData)
{
    int eFirstStart = elfData[0];
    int eFirstEnd = elfData[1];
    int eSecondStart = elfData[2]; 
    int eSecondEnd = elfData[3];
    
    if (((eSecondStart > eFirstEnd && eSecondEnd > eFirstEnd) || (eSecondStart < eFirstStart && eSecondEnd < eFirstStart)) || ((eFirstStart > eSecondEnd && eFirstEnd > eSecondEnd) || (eFirstStart< eSecondStart && eFirstEnd < eSecondStart)))
    {
        return 1;
    }
    return 0;

}

std::vector<int> computeRanges(string oldString)
{
    std::vector<int> data;
    string delim_comma = ",";
    string delim_hyphen = "-";
    int pos = 0;
    string firstElf, secondElf;
    int firstElfStartNum, firstElfEndNum, secondElfStartNum, secondElfEndNum;
    while ((pos = oldString.find(delim_comma)) != std::string::npos) {
        //Split each line into elf 1 and elf 2. 
        firstElf = oldString.substr(0, pos);
        secondElf = oldString.substr(pos + delim_comma.length());
        //Remove the comma so the loop can continue to the next set. Have to do this before reusing the pos var, otherwise bad things. 
        oldString.erase(0, pos + delim_comma.length());
        //Split the new sets into start and end ranges as ints for use in comparison. 
        pos = firstElf.find(delim_hyphen);
        firstElfStartNum = std::stoi(firstElf.substr(0, pos));
        firstElfEndNum = std::stoi(firstElf.substr(pos + delim_comma.length()));
        pos = secondElf.find(delim_hyphen);
        secondElfStartNum = std::stoi(secondElf.substr(0, pos));
        secondElfEndNum = std::stoi(secondElf.substr(pos + delim_comma.length()));
    }
    data.push_back(firstElfStartNum);
    data.push_back(firstElfEndNum);
    data.push_back(secondElfStartNum);
    data.push_back(secondElfEndNum);
    return data;
}


int main()
{
    std::ifstream infile("input.txt");
    string line;
    int count = 0;
    int overlapCount = 0;
    int totalLines = 0;
    while(infile >> line)
    {
        count += containsAll(computeRanges(line));
        overlapCount += overlaps(computeRanges(line));
        totalLines++;
    }
    cout << count << endl;
    cout << totalLines - overlapCount << endl;
}