/////
/*
    Part 1:
    We are getting random strings of characters
    We need to split the strings exactly in half
    We need to loop through both strings and look to see which character they share.
    We then need to add a value to our cumulative total based on the following assignments:
        a-z(lower) == 1-26
        A-Z(UPPER) == 27-52

    Part 2:
    We need to group 3 lines at a time and find the common character among all three lines. 
    We no longer care about splitting the lines into 2 bags. 
    COllect the "Score" the same way as before, but the score item being whichever character is in all three lines.
*/
/////
#include <iostream>
#include <fstream>
#include <vector>
#include <map>
using namespace std;

char findSimilar(string x, string y)
{
    for(char a : x)
    {
        for (char b : y)
        {
            if (a == b)
            return a;
        }
    }
}

char findSimilar2(string x, string y, string z)
{
    for(char a : x)
    {
        for (char b : y)
        {
            for (char c : z)
            {
                if (a == b && a == c)
                {
                    return a;
                }
            }
            
        }
    }
}

int assignScore(char x)
{

    std::map<char, int> scoreMap;
    
    scoreMap.insert(make_pair('a', 1));
    scoreMap.insert(make_pair('b', 2));
    scoreMap.insert(make_pair('c', 3));
    scoreMap.insert(make_pair('d', 4));
    scoreMap.insert(make_pair('e', 5));
    scoreMap.insert(make_pair('f', 6));
    scoreMap.insert(make_pair('g', 7));
    scoreMap.insert(make_pair('h', 8));
    scoreMap.insert(make_pair('i', 9));
    scoreMap.insert(make_pair('j', 10));
    scoreMap.insert(make_pair('k', 11));
    scoreMap.insert(make_pair('l', 12));
    scoreMap.insert(make_pair('m', 13));
    scoreMap.insert(make_pair('n', 14));
    scoreMap.insert(make_pair('o', 15));
    scoreMap.insert(make_pair('p', 16));
    scoreMap.insert(make_pair('q', 17));
    scoreMap.insert(make_pair('r', 18));
    scoreMap.insert(make_pair('s', 19));
    scoreMap.insert(make_pair('t', 20));
    scoreMap.insert(make_pair('u', 21));
    scoreMap.insert(make_pair('v', 22));
    scoreMap.insert(make_pair('w',23));
    scoreMap.insert(make_pair('x', 24));
    scoreMap.insert(make_pair('y', 25));
    scoreMap.insert(make_pair('z', 26));
    scoreMap.insert(make_pair('A', 27));
    scoreMap.insert(make_pair('B', 28));
    scoreMap.insert(make_pair('C', 29));
    scoreMap.insert(make_pair('D', 30));
    scoreMap.insert(make_pair('E', 31));
    scoreMap.insert(make_pair('F', 32));
    scoreMap.insert(make_pair('G', 33));
    scoreMap.insert(make_pair('H', 34));
    scoreMap.insert(make_pair('I', 35));
    scoreMap.insert(make_pair('J', 36));
    scoreMap.insert(make_pair('K', 37));
    scoreMap.insert(make_pair('L', 38));
    scoreMap.insert(make_pair('M', 39));
    scoreMap.insert(make_pair('N', 40));
    scoreMap.insert(make_pair('O', 41));
    scoreMap.insert(make_pair('P', 42));
    scoreMap.insert(make_pair('Q', 43));
    scoreMap.insert(make_pair('R', 44));
    scoreMap.insert(make_pair('S', 45));
    scoreMap.insert(make_pair('T', 46));
    scoreMap.insert(make_pair('U', 47));
    scoreMap.insert(make_pair('V', 48));
    scoreMap.insert(make_pair('W',49));
    scoreMap.insert(make_pair('X', 50));
    scoreMap.insert(make_pair('Y', 51));
    scoreMap.insert(make_pair('Z', 52));

   return scoreMap[x];
     
}

int split_string(string oldString)
{
    int mid = (oldString.length() + 1) / 2;
    string firstHalf = oldString.substr(0, mid);
    string secondHalf = oldString.substr(mid);

    return assignScore(findSimilar(firstHalf, secondHalf));

}



int main()
{
    std::ifstream infile("input.txt");
    std::vector<string> data;
    string s;
    string first, second, third;
    int score = 0;
    int score2 = 0;
    int counter = 0;
    while(infile >> s)
    {
        data.push_back(s);
        if (counter == 0)
        {
            first = s;
            counter++;
        }
        else if(counter == 1)
        {
            second = s;
            counter++;
        }
        else if(counter ==2)
        {
            third = s;
            score2 += assignScore(findSimilar2(first, second, third));
            counter = 0;
        }
    }
    for (auto &str : data)
    {
        score += split_string(str);
    }
    printf("%i\n", score);
    printf("%i\n", score2);
    return 0;
}
