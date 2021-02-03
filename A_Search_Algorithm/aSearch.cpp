#include<iostream>
#include<vector>
#include<sstream>
#include<fstream>
#include"HelperFunctions.h"


using namespace std;


vector<vector<State>> Search(vector<vector<int>> grid, int start[2], int goal[2]){
    
    vector<vector<State>> board;
    
    cout<<"No path found!";

    return board;
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