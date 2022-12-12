///
/*
    Part 1: 
        We have a grid of numbers representing tree height. 
        We need to check how many trees are visible from Top, Right, Bottom or Left. 
            We would need to traverse all numbers from the current number all the way T,R,B,L 
                to see if ANY number is Greater than the current number

    Part 2: 
        We have the same grid of trees. 
        We want to determine what the Highest "Scenic" score is. 
            Scenic score = the number of trees it can see. 
            A tree can see any trees that are <= it's height. 
*/
///

#include <vector>
#include <fstream>
#include <iostream>
#include <map>
using namespace std;

struct Node
{
    bool seen = true;
    int val;
};


int countTrees(int currCount, int row, int col, Node(&trees)[99][99])
{   
    int upScore=0, downScore=0, leftScore=0, rightScore=0;
    bool UpBlocked = false;
    bool DownBlocked = false;
    bool LeftBlocked = false;
    bool RightBlocked = false;

    //check all trees above this grid. 
    int currRow = row - 1;
    int currCol = col;
    int originalVal = trees[row][col].val;

    while (UpBlocked == false && currRow >= 0)
    {
        int upValue = trees[currRow][currCol].val;
        if(upValue >= originalVal)
        { 
            upScore++;
            UpBlocked = true;
        }
        else if(upValue < originalVal)
        {
            upScore++;
        }
        currRow--;
    }

    //check Down trees. 
    currRow = row+1;
    currCol = col;
    while (DownBlocked == false && currRow <= 98)
    {
        int downValue = trees[currRow][currCol].val;
        if(downValue >= originalVal)
        {
            downScore++;
            DownBlocked = true;
        }
        else if(downValue < originalVal)
        {
            downScore++;
        }
        currRow++;
    }

    //check Left Trees
    currRow = row;
    currCol = col-1;
    while (LeftBlocked == false && currCol >= 0)
    {
        int leftValue = trees[currRow][currCol].val;
        if(leftValue >= originalVal)
        {
            leftScore++;
            LeftBlocked = true;
        }
        else if(leftValue < originalVal)
        {
            leftScore++;
        }
        currCol--;
    }

    //check Right Trees
    currRow = row;
    currCol = col+1;
    while (RightBlocked == false && currCol <= 98)
    {
        int rightValue = trees[currRow][currCol].val;
        if(rightValue >= originalVal)
        {
            RightBlocked = true;
            rightScore++;
        }
        else if(rightValue < originalVal)
        {
            rightScore++;
        }
        currCol++;
    }

    if(upScore * downScore * leftScore * rightScore > currCount)
    {
        return upScore * downScore * leftScore * rightScore;
    }
    else
    {
        return currCount;
    }
}

bool checkUp(int row, int col, Node(&trees)[99][99])
{
    bool blocked = false;
    int currRow = row - 1;
    int currCol = col;
    int originalVal = trees[row][col].val;
    while (blocked == false && currRow >= 0)
    {
        
        int upValue = trees[currRow][currCol].val;
        if(upValue >= originalVal)
        {
            blocked = true;
            break;
        }
        currRow--;
        
    }
    return blocked;
}

bool checkDown(int row, int col, Node(&trees)[99][99])
{
    bool blocked = false;
    int currRow = row + 1;
    int currCol = col;
    int originalVal = trees[row][col].val;
    while (blocked == false && currRow <=  98)
    {
       
        int downValue = trees[currRow][currCol].val;
        if(downValue >= originalVal)
        {
            blocked = true;
            break;
        }
        currRow++;
    }
    return blocked;
}

bool checkRight(int row, int col, Node(&trees)[99][99])
{
    bool blocked = false;
    int currRow = row;
    int currCol = col + 1;
    int originalVal = trees[row][col].val;
    while (blocked == false && currCol <= 98)
    {
        
        int rightVal = trees[currRow][currCol].val;
        if(rightVal >= originalVal)
        {
            blocked = true;
            break;
        }
        currCol++;
        
    }
    return blocked;
}

bool checkLeft(int row, int col, Node(&trees)[99][99])
{
    bool blocked = false;
    int currRow = row;
    int currCol = col - 1;
    int originalVal = trees[row][col].val;
    while (blocked == false && currCol >= 0)
    {
        
        int leftVal = trees[currRow][currCol].val;
        if(leftVal >= originalVal)
        {
            blocked = true;
            break;
        }
        currCol--;
        
    }
    return blocked;
}

template <int rows, int cols>
void setSeenTrees(Node (&trees)[rows][cols])
{
   
    for (int i = 0; i < rows; i++)
    {   
        for (int j = 0; j < cols; j++)
        {
            bool upBlocked = false;
            bool downBlocked = false;
            bool leftBlocked = false;
            bool rightBlocked = false;

            //Check if we are on the 1st or last row or column. These are always visible. 
            if(i == 0)
            {
                trees[i][j].seen = true;
                continue;
            }
            else if(j == 0)
            {
                trees[i][j].seen = true;
                continue;
            }
            else if(i == 98)
            {
                trees[i][j].seen = true;
                continue;
            }
            else if(j == 98)
            {
                trees[i][j].seen = true;
                continue;
            }

            upBlocked = checkUp(i, j, trees);
            downBlocked = checkDown(i, j, trees);
            rightBlocked = checkRight(i,j,trees);
            leftBlocked = checkLeft(i,j,trees);

            if (upBlocked && downBlocked && leftBlocked && rightBlocked)
            {
                trees[i][j].seen = false;
            }
            else{
                trees[i][j].seen = true;
            }
        }
    }
}

template <size_t rows, size_t cols>
int getSeenTrees(Node (&trees)[rows][cols])
{
    int count = 0;
    for (int i = 0; i < rows; i++)
    {   
        for (int j = 0; j < cols; j++)
        {
            if(trees[i][j].seen == true)
            {
                count++; 
            }
        }
    }
    return count;
}



int main()
{
    int maxRow = 99;
    int maxCol = 99;
    Node grid [99][99] = {{}};
    int val = 0;
    int rowCount = 0;
    int colCount = 0;
    fstream infile("input.txt");
    string row;
    //Need to look character by character and adding to the grid. 
    while(infile >> row)
    {
        for (char c : row)
        {
            val = c - '0';
            if (colCount < maxCol)
            {
                Node treeNode;
                treeNode.val = val;
                grid[rowCount][colCount] = treeNode;
                colCount++;
            }
            else
            {
                colCount = 0;
            }
        } 
        rowCount++;
        colCount = 0;   
    }
    //Part 1 solve:
    setSeenTrees(grid);
    printf("The number of trees that can be seen from the outside is: %i\n", getSeenTrees(grid));

    //Part 2 solve:
    int bestScenicScore = 0;
    for (int i = 0; i < 99; i++)
    {
        for (int j = 0; j < 99; j++)
        {
            bestScenicScore = countTrees(bestScenicScore, i, j, grid);
        }
        
    }
    printf("The best Scenic Score is %i", bestScenicScore);
    ofstream myfile ("example.txt");
    if (myfile.is_open())
    {

        for (int i = 0; i < 99; i++)
        {
            for (int j = 0; j <99; j++)
            {
                myfile << grid[i][j].seen;
            }
            if (i < 99)
            {
                myfile << endl;
            }
            
        }
        myfile.close();
    }
}