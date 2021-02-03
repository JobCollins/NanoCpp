#include<iostream>
#include<vector>
#include<sstream>
#include<fstream>
#include"HelperFunctions.h"


using namespace std;


vector<vector<State>> Search(vector<vector<State>> grid, int start[2], int goal[2]){
    
    vector<vector<int>> open {};

    //initialize the starting node
    int x = start[0];
    int y = start[1];
    int g = 0;
    int h = heuristic(x, goal[0], y, goal[1]);

    //Add first node to open vector using the AddToOpen function by passing 
    //the node values: x, y, g, and h, along with the open and grid vectors.
    AddToOpen(x, y, g, h, open, grid);
    
    // cout<<"No path found!";
    int i = 0;

    while (!open.empty())
    {
        /* code */
        //sort the open list using CellSort
        CellSort(&open);
        //get the current node
        auto current_node = open.back();
        open.pop_back();
        i++;

        // Get the x and y values from the current node,
        // and set grid[x][y] to kPath.
        grid[current_node[0]][current_node[1]] = State::kPath;

        // Check if goal is reached. If so, return grid.
        // If we're not done, expand search to current node's neighbors.
        // ExpandNeighbors. This step will be completed later.
        if((current_node[0] == goal[0]) && (current_node[1] == goal[1])){
            //set grid cell to kStart for initial coords and kFinish for the goal coords
            grid[start[0]][start[1]] = State::kStart;
            grid[goal[0]][goal[1]] = State::kFinish;
            return grid;
        }
        else{
            ExpandNeighbors(current_node, goal, open, grid);
        }


    }
    

    return vector<vector<State>>{};
}

//taken from ../gridVector.cpp
// enum State {kEmpty, kObstacle} state;

string CellString(State state){
    switch (state)
    {
    case State::kStart:
        /* code */
        return "🚦 ";
    case State::kObstacle:
        /* code */
        return "⛰️ ";
    case State::kPath:
        /* code */
        return "🚗   ";
    case State::kFinish:
        /* code */
        return "🏁 ";
    default:
        return "0  ";
    }
}

void PrintBoard(vector<vector<State>> board){
    for (auto i = 0; i < board.size(); i++)
    {
        /* code */
        for (auto j = 0; j < board[i].size(); j++)
        {
            /* code */

            cout<<CellString(board[i][j]);
           
            
        }
        cout<<endl;
        
    }
    
}

int main()
{   
    int start[2] {0,0};
    int goal[2] {4,5};


    auto board = ReadBoardFile("1.board");

    auto solution = Search(board, start, goal);

    PrintBoard(solution);

    return 0;
}