#include <iostream>
#include <fstream>
using namespace std;

// function to determine if the user won against the elf
// first arg is the elf's move, second arg is the user's proposed move
// Part 1 solution
int checkWin(char a, char b)
{
    //Score for each use case. 
    int rockScore = 1;
    int paperScore = 2;
    int scissorScore=3;

    //score for each round result
    int winScore = 6;
    int lossScore = 0;
    int tieScore = 3;

    if (a == 'A' && b == 'Z' || a == 'B' && b == 'X' || a == 'C' && b == 'Y')
    {
        if (b =='X')
        {
            return lossScore + rockScore ;
        }
        else if (b == 'Y')
        {
            return lossScore + paperScore;
        }
        else
        {
            return lossScore + scissorScore;
        }
        
    }
    else if (b == 'X' && a == 'C' || b == 'Y' && a == 'A' || b == 'Z' && a == 'B')
    {
        if (b =='X')
        {
            return winScore + rockScore ;
        }
        else if (b == 'Y')
        {
            return winScore + paperScore;
        }
        else
        {
            return winScore + scissorScore;
        }
    }
    else
    {
        if (b =='X')
        {
            return tieScore + rockScore ;
        }
        else if (b == 'Y')
        {
            return tieScore + paperScore;
        }
        else
        {
            return tieScore + scissorScore;
        }
    }
}

//A second function that is used to complete part 2. 
// The first character is the Elf's choice
// The second character is the outcome that must happen. 
int checkWin2(char a, char b)
{
    //Score for each use case. 
    int rockScore = 1;
    int paperScore = 2;
    int scissorScore=3;

    //score for each round result
    int winScore = 6;
    int lossScore = 0;
    int tieScore = 3;
    // A == Rock, B == Paper, C == Scissors
    // X == lose Y == Draw, Z == Win
    if (a == 'A')
    {
        if (b =='X')
        {
            return lossScore + scissorScore ;
        }
        else if (b == 'Y')
        {
            return tieScore + rockScore;
        }
        else
        {
            return winScore + paperScore;
        }   
    }
    else if (a == 'B')
    {
        if (b =='X')
        {
            return lossScore + rockScore ;
        }
        else if (b == 'Y')
        {
            return tieScore + paperScore;
        }
        else
        {
            return winScore + scissorScore;
        }  
    }
    else
    {
        if (b =='X')
        {
            return lossScore + paperScore ;
        }
        else if (b == 'Y')
        {
            return tieScore + scissorScore;
        }
        else
        {
            return winScore + rockScore;
        }  
    }
}

int main()
{
    std::ifstream infile("input.txt");
    char elfChoice;
    char playerChoice;
    int playerScore1 = 0;
    int playerScore2 = 0;
    while(infile >> elfChoice >> playerChoice)
    {
        playerScore1 += checkWin(elfChoice, playerChoice);
        playerScore2 += checkWin2(elfChoice, playerChoice);
    }

    printf("FIRST PART: The player scored %i\n", playerScore1);
    printf("SECOND PART: The player scored %i\n", playerScore2);


}