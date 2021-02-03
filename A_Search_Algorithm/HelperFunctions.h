#ifndef HELPERFUNCTIONS_H
#define HELPERFUNCTIONS_H

#include<iostream>
#include<vector>
#include<sstream>
#include<fstream>
#include<cmath>
#include<algorithm>


using namespace std;

enum State {kStart, kEmpty, kObstacle, kClosed, kPath, kFinish} state;

//directional deltas
const int delta[4][2]{{-1, 0}, {0, -1}, {1, 0}, {0, 1}};

vector<State> ParseLine(string line) {
    istringstream sline(line);
    int n;
    char c;
    vector<State> row;
    while (sline >> n >> c && c == ',') {
      if (n == 0) {
        row.push_back(State::kEmpty);
      } else {
        row.push_back(State::kObstacle);
      }
    }
    return row;
}
vector<vector<State>> ReadBoardFile(string path) {
  ifstream myfile (path);
  vector<vector<State>> board{};
  if (myfile) {
    string line;
    while (getline(myfile, line)) {
      vector<State> row = ParseLine(line);
      board.push_back(row);
    }
  }
  return board;
}


//Compare the f values of two nodes
bool Compare(const vector<int> node1, const vector<int> node2){
    //f=g1+h1
    int f1 = node1[2]+node1[3];
    //f=g2+h2
    int f2 = node2[2]+node2[3];

    return f1 > f2;
}

void CellSort(vector<vector<int>>*v){
    sort(v->begin(), v->end(), Compare);
}

int heuristic(int x1, int x2, int y1, int y2)
{   
    return abs(x2 - x1) + abs(y2 - y1);
}


bool CheckValidCell(int x, int y, vector<vector<State>> &grid){
    //check if cell is located in the grid
    bool on_grid_x = (x >= 0 && x < grid.size());
    bool on_grid_y = (y >= 0 && y < grid[0].size());

    //if the above values are true (located in the grid)
    //check whether this location is empty or occupiedd 
    if(on_grid_x && on_grid_y){
        return grid[x][y] == State::kEmpty;
    }
    else{
        return false;
    }
}

void AddToOpen(int x, int y, int g, int h, vector<vector<int>> &openodes, vector<vector<State>> &grid){
    //create a node vector
    vector<int> node{x, y, g, h};
    //push the above node to the back of the open vector
    openodes.push_back(node);
    //set the grid value for the x,y coordinates to the enum value kClosed
    grid[x][y]=State::kClosed;

}


void ExpandNeighbors(const vector<int> &current_node, int goal[2], vector<vector<int>> &open, vector<vector<State>> &grid){
    //Get current node's data
    int x = current_node[0];
    int y = current_node[1];
    int g = current_node[2];
    int h = current_node[3];

    //loop through current node's potential neighbors
    for (int i = 0; i < 4; i++)
    {
        /* code */
        int x2 = x + delta[i][0];
        int y2 = y + delta[i][1];

        //increment g value, compute h value, and add neighbor to open list
        if(CheckValidCell(x2, y2, grid)){
            int g2 = g + 1;
            int h2 = heuristic(x2, goal[0], y2, goal[1]); //this is what was causing the bug: heuristic(x2, y2, goal[0], goal[1])
            AddToOpen(x2, y2, g2, h2, open, grid);
        }
    }
    
}

#endif