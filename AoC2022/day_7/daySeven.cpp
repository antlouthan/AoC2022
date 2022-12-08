
/* 
    I wasn't able to fully solve this on my own, so I had to look up another solution.
        Reasons why I failed: 
            I didn't have a proper tracking mechanism for the dir I was on/in. 
                The pointer object I had referenced the instance to which it belonged. 
                    This created a memory issue and caused frequent overwrites. 
            I didn't have the external struct and because of that the tree would never have worked. 

            In the end I found a solution on reddit and used this time to learn how Trees work and then used that knowledge to understand the solution. 

        Things I did right before looking up the solution:
            The logic for parsing the strings and performing the actions based on the input/string values. 
                My code worked fine with regards to passing the information along and calling what it needed to call. 
            My original class was fine with regards to tracking individual directories within a root directory and compiling it's size. 
                
*/
////
/*
    Part 1:
        We have an input that provides Directories and Files. 
        The Directories can contain directories or files.
        If the line is a directory, we'll need to look into that directory and count it's files/directories. 
        If the line is a file, we need to add it's file size to a running count. 
        We need to provide the total size of any directories that are <100000 in size. 
            If a directory is within another directory and their values combined do not exceed our limit, they need to be reported together. 
*/
////
////
/*
    Part 1:
        We have an input that provides Directories and Files. 
        The Directories can contain directories or files.
        If the line is a directory, we'll need to look into that directory and count it's files/directories. 
        If the line is a file, we need to add it's file size to a running count. 
        We need to provide the total size of any directories that are <100000 in size. 
            If a directory is within another directory and their values combined do not exceed our limit, they need to be reported together. 
*/
////
#include <vector>
#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
using namespace std;

//The individual directory. It has:
//  A size which is it's total file size
//  A name
//  A pointer to the parent. 
//  A vector of all of the subdirectories. 
int SPACENEEDED = 70000000 - 30000000;
struct Dir
{
    int size;
    string name;
    Dir *parent;
    std::vector<Dir *> children;
    std::vector<string> files;
    
};
//The container class for all of the directories. 
class Directories
{
    public: 
        Dir *rootDir;
        Dir *currentDir;
        

        Directories()
        {
            //initialize the rootDirectory's values. 
            rootDir = new Dir();
            rootDir->size = 0;
            rootDir->name = "/";
            rootDir->parent = NULL;
        }

        //The change directory method. It takes the name of the next directory, then loops through all of the children to see if that name exists. 
        void cd(string dir)
        {
           for (int i = 0; i < currentDir->children.size(); i++)
        {
            if (currentDir->children[i]->name == dir)
            {
                currentDir = currentDir->children[i];
                break;
            }
        }
        }
        //The 'cd ..' method. Takes the current directory and moves to the parent. Check for parent to be null, which prevents the move into undefined. 
        void cdBack()
        {
            if(currentDir->parent != NULL)
            {
                currentDir = currentDir->parent;
            }
        }
        //Add an individual directory. 
        void addDirectory(Dir *newDir)
        {
            if (rootDir == NULL)
            {
                rootDir = newDir;
            }
            else
            {
                currentDir->children.push_back(newDir);
                newDir->parent = currentDir;
            }
        }
        //Increase the total size of the current directory and it's parent(and it's parent's parent....n)
        void addSize(int fSize)
        {
            //add the size of the colletive files of this node. 
            currentDir->size += fSize;
            Dir *temp = currentDir;
            //Keep changing the parent to be the next parent until we hit the end. 
            while (temp->parent != NULL)
            {
                temp->parent->size += fSize;
                temp = temp->parent;
            }
        }

        void addFile(string file)
        {
            currentDir->files.push_back(file);
        }
        //Method to print the tree. Prints files and directories in an easy to read format
        void print(Dir *tree, const int depth = 0) const
        {
            //Ensure the formating matches for directories
            for ( int i = 0 ; i < depth ; ++i )
            {
                if ( i != depth-1 ) std::cout << "    ";
                else std::cout << "|-- ";   
            }
            std::cout << tree->name << "/"<< std::endl;
            //Loop through files before moving on to next thing. 
            for (auto f : tree->files)
                {   
                    for ( int i = 0 ; i < depth ; ++i )
                    {
                        //depth -10 gives us a good buffer. Yay magic numbers. 
                        if ( i != depth-10 ) std::cout << "    ";   
                    }   
                    std::cout << "|-- " << f << std::endl;
                }
            
            
            for ( uint i = 0 ; i < tree->children.size() ; ++i )
            {
                print(tree->children[i], depth+1 );
            }
        }
        //Calling function for the solution. Will call the recursive version of the function. 
        void solve1()
        {
            int sum = 0;
            solve1Rec(rootDir, sum);
            printf("The sum of the files is: %i\n", sum);
        }
        //Where the recursion needs to go. 
        void solve1Rec(Dir *dir, int &sum)
        {

            int maxAllowed = 100000;
            //Ensure the current size is still less than the maxAllowed size. 
            if (dir->size <= maxAllowed)
            {
                sum += dir->size;
            }
            //Loop through the children and attempt to add the sizes. 
            for (int i = 0; i < dir->children.size(); i++)
            {
                solve1Rec(dir->children[i], sum);
            }
        }

        void solve2()
        {
            //The root Directory's size is how much space we've taken up already. 
            int totalSize = rootDir->size;
            //The difference between where we are and what we need. 
            int dirSize = totalSize - SPACENEEDED;
    
            int minSizeNeeded = solve2Rec(rootDir, dirSize);

            printf("The amount to be deleted is: %i", minSizeNeeded);
        }
        int solve2Rec(Dir *dir, int dirSize)
        {
            int minSize = INT_MAX;
            if(dir->size >= dirSize)
            {
                minSize = dir->size;
            }
            //Loop through all of the children and perform the same operation until we are below the minimum size. 
            for (int i = 0; i < dir->children.size(); i++)
            {
                int tmp = solve2Rec(dir->children[i], dirSize);
                if (tmp < minSize)
                {
                    minSize = tmp;
                }
            }
            return minSize;

        }
};


int main()
{
    std::ifstream infile("input.txt");
    string line;
    Directories dirs = Directories();
    dirs.currentDir = dirs.rootDir;
    while(getline(infile, line))
    {
        if (line.substr(0, line.find(" ")) == "dir")
        {
            Dir * newDir = new Dir();
            newDir->name = line.substr(line.find(" ")+1);
            dirs.addDirectory(newDir);
        }
        else if ((line.substr(0, line.find(" ")) == "$"))
        {
            //Offset by 2 because the only commands we care about are ls and cd. May need to revisit if it changes
            int cmdOffset = 2; 
            string cmdName = line.substr(line.find(" ") + 1, cmdOffset);
            if(cmdName == "cd")
            {
                string dirName = line.substr(line.find_last_of(" ") + 1);
                if (dirName == "/")
                {
                    continue;
                }
                else if(dirName == "..")
                {
                    dirs.cdBack();
                }
                else
                {
                    dirs.cd(dirName);
                }     
            }
                
        }
        else if(stoi(line.substr(0, line.find(" "))) > 0)
        {
            dirs.addFile(line);
            int sizeToAdd = stoi(line.substr(0, line.find(" ")));
            dirs.addSize(sizeToAdd);
        }
    }
    dirs.print(dirs.rootDir);
    dirs.solve1();
    dirs.solve2();
    return 0;
}