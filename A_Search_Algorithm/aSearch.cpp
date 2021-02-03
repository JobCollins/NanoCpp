#include<iostream>
#include<vector>
#include<sstream>
#include<fstream>
#include"HelperFunctions.h"


using namespace std;


vector<vector<State>> Search(vector<vector<int>> grid, int start[2], int goal[2]){
    
    vector<vector<State>> open{};

    //initialize the starting node
    int x = start[0];
    int y = start[1];
    int g = 0;
    int h = heuristic(x, goal[0], y, goal[1]);

    //Add first node to open vector using the AddToOpen function by passing 
    //the node values: x, y, g, and h, along with the open and grid vectors.
    AddToOpen(x, y, g, h, open, grid);
    
    cout<<"No path found!";

    return open;
}

//taken from ../gridVector.cpp
// enum State {kEmpty, kObstacle} state;

void CellString(State state){
    switch (state)
    {
    case kEmpty:
        /* code */
        cout<<"0 ";
        break;
    case kObstacle:
        /* code */
        cout<<"⛰️ ";
        break;
    default:
        break;
    }
}

void PrintBoard(vector<vector<int>> vec){
    for (auto i = 0; i < vec.size(); i++)
    {
        /* code */
        for (auto j = 0; j < vec[i].size(); j++)
        {
            /* code */

            // cout<<vec[i][j]<<' ';
            if (vec[i][j]==0)
            {
                /* code */
                CellString(kEmpty);
            }
            else if(vec[i][j]==1)
            {
                /* code */
                CellString(kObstacle);
            }
            else
            {
                break;
            }
            
        }
        cout<<endl;
        
    }
    
}

int main()
{   
    int start[2] = {0,0};
    int goal[2] = {4,5};


    int solution = Search(board, start, goal);

    PrintBoard(solution);

    return 0;
}