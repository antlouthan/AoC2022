////
/*
    Part 1
        We have a rope with a Head and a Tail. 
            Whenever the Head moves, the Tail cannot be more than 2 nodes away. 
                After every Head move, we should run a check to see if it is +2 in up, down, left, right 
                    or the diagonals (UL, UR, DL, DR).

    Part 2
        Same as above but with 10 links instead of just Head and Tail. 
            Whenever Head moves, next link moves and calls the check move on the next link. 
*/
///
#include <vector>
#include <fstream>
#include <iostream>
using namespace std;
class RopePart
{
    public: 
        std::vector<std::pair<int, int> > locVisits;
        int currX, currY;
        RopePart * partner;
        RopePart()
        {
            currX = 0;
            currY = 0;
            locVisits.push_back(std::make_pair(currX, currY));
        }
        void moveUp()
        {
            currY +=1;
            if(!std::count(locVisits.begin(), locVisits.end(), std::make_pair(currX, currY)))
            {
                locVisits.push_back(std::make_pair(currX, currY));
            }
            
        }
        void moveDown()
        {
            currY -=1;
            if(!std::count(locVisits.begin(), locVisits.end(), std::make_pair(currX, currY)))
            {
                locVisits.push_back(std::make_pair(currX, currY));
            }        
        }
        void moveRight()
        {
            currX +=1;
            if(!std::count(locVisits.begin(), locVisits.end(), std::make_pair(currX, currY)))
            {
                locVisits.push_back(std::make_pair(currX, currY));
            }
        }
        void moveLeft()
        {
            currX -=1;
            if(!std::count(locVisits.begin(), locVisits.end(), std::make_pair(currX, currY)))
            {
                locVisits.push_back(std::make_pair(currX, currY));
            }
        }
        void moveUpLeft()
        {
            currY +=1;
            currX -=1;
            if(!std::count(locVisits.begin(), locVisits.end(), std::make_pair(currX, currY)))
            {
                locVisits.push_back(std::make_pair(currX, currY));
            }
        }
        void moveUpRight()
        {
            currY +=1;
            currX +=1;
            if(!std::count(locVisits.begin(), locVisits.end(), std::make_pair(currX, currY)))
            {
                locVisits.push_back(std::make_pair(currX, currY));
            }
        }
        void moveDownRight()
        {
            currY -=1;
            currX +=1;
            if(!std::count(locVisits.begin(), locVisits.end(), std::make_pair(currX, currY)))
            {
                locVisits.push_back(std::make_pair(currX, currY));
            }
        }
        void moveDownLeft()
        {
            currY -=1;
            currX -=1;
            if(!std::count(locVisits.begin(), locVisits.end(), std::make_pair(currX, currY)))
            {
                locVisits.push_back(std::make_pair(currX, currY));
            }

        }

        void fixTooFar()
        {
            if(partner == nullptr)
            {
                return;
            }
            //check if both X and Y are different. This indicates a diagnol
            if(currX != partner->currX && currY != partner->currY)
            {
                //if both are pos, then the Head is up and right of the Tail
                if (currX - partner->currX >= 2 && currY - partner->currY >= 1 || currX - partner->currX >= 1 && currY - partner->currY >= 2)
                {
                    partner->moveUpRight();
                    partner->fixTooFar();
                }
                // if x is pos and Y is neg, then it's down right
                else if (currX - partner->currX >= 2 && currY - partner->currY <= -1 ||currX - partner->currX >= 1 && currY - partner->currY <= -2)
                {
                    partner->moveDownRight();
                    partner->fixTooFar();
                }
                // if x is neg and y is neg, then it's down left
                else if (currX - partner->currX <= -2 && currY - partner->currY <= -1 || currX - partner->currX <= -1 && currY - partner->currY <= -2)
                {
                    partner->moveDownLeft();
                    partner->fixTooFar();
                }
                // if x is neg and y is pos, then it's down left
                else if (currX - partner->currX <= -2 && currY - partner->currY >= 1 || currX - partner->currX <= -1 && currY - partner->currY >= 2) 
                {
                    partner->moveUpLeft();
                    partner->fixTooFar();
                }

            }
            else if(currX - partner->currX >= 2)
            {
                partner->moveRight();
                partner->fixTooFar();
            }
            else if(currX - partner->currX <= -2)
            {
                partner->moveLeft();
                partner->fixTooFar();
            }
            else if(currY - partner->currY >= 2)
            {
                partner->moveUp();
                partner->fixTooFar();
            }
            else if(currY - partner->currY <= -2)
            {
                partner->moveDown();
                partner->fixTooFar();
            }
        }
 
        void applyInput(string direction, int amountToMove)
        {
            for(int i = 0; i <= amountToMove-1; i++)
            {
                if(direction =="R")
                {
                    currX += 1;
                    locVisits.push_back(std::make_pair(currX, currY));
                    fixTooFar();
                }
                else if(direction == "L")
                {
                    currX -= 1;
                    locVisits.push_back(std::make_pair(currX, currY));
                    fixTooFar();
                }
                else if(direction == "D")
                {
                    currY -=1;
                    locVisits.push_back(std::make_pair(currX, currY));
                    fixTooFar();
                }
                else if(direction == "U")
                {
                    currY += 1;
                    locVisits.push_back(std::make_pair(currX, currY));
                    fixTooFar();
                }
            }
        }
};

int main()
{
    RopePart Head;
    RopePart Tail;
    RopePart r1, r2, r3, r4, r5, r6, r7, r8;
    Tail.partner=nullptr;
    Head.partner=&r1;
    r1.partner=&r2;
    r2.partner=&r3;
    r3.partner=&r4;
    r4.partner=&r5;
    r5.partner=&r6;
    r6.partner=&r7;
    r7.partner=&r8;
    r8.partner=&Tail;
    fstream infile("input.txt");
    string dir;
    int num;
    while(infile >> dir >> num)
    {
        Head.applyInput(dir, num);
    }


    printf("We visited %lu locations", Tail.locVisits.size());

}