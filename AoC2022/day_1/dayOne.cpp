#include <iostream>
#include <vector>
#include <fstream>
#include <map>
#include <list>
using namespace std;


int main()
{
    std::ifstream infile("input.txt");
    int highest_1 = 0;
    int highest_2 = 0;
    int highest_3 = 0;
    int current = 0;
    string a = "";
    while (!infile.eof())
    {
        getline(infile, a);
        if (a == "")
        {
            if (current > highest_1)
            {
                highest_3 = highest_2;
                highest_2 = highest_1;
                highest_1 = current;   
            }
            else if (current > highest_2)
            {
                highest_3 = highest_2;
                highest_2 = current;
            }
            else if(current > highest_3)
            {
                highest_3 = current;
            }

            current = 0;
            
        }
        else
        {
            current += std::stoi(a);
        }
    }
    printf("%i\n", highest_1 + highest_2 + highest_3);


}