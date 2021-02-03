#ifndef HELPERFUNCTIONS_H
#define HELPERFUNCTIONS_H

#include<iostream>
#include<vector>
#include<sstream>
#include<fstream>
#include<cmath>
#include<algorithm>


using namespace std;

int heuristic(int x1, int x2, int y1, int y2)
{   
    //initialize the manhattan distance variable
    int distance;

    int x_diff = x2 - x1;
    int y_diff = y2 - y1;

    if(x_diff < 0){
        x_diff = -x_diff;
    }

    if(y_diff < 0){
        y_diff = -y_diff;
    }

    //calculate manhattan distance
    distance = x_diff + y_diff;
    cout<<"\n Manhattan distance between the points ("<<x1<<','<<y1<<") and ("<<x2<<','<<y2<<") is: "<<distance<<endl;

    return distance;

}


enum State {kEmpty, kObstacle, kClosed, kPath} state;


void AddToOpen(int x, int y, int g, int h, vector<vector<int>> &openodes, vector<vector<State>> &grid){
    //create a node vector
    vector<int> node{x, y, g, h};
    //push the above node to the back of the open vector
    openodes.push_back(node);
    //set the grid value for the x,y coordinates to the enum value kClosed
    grid[x][y]=State::kClosed;

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

bool CheckValidCell(int x, int y, vector<vector<State>> &grid){
    //check if cell is located in the grid
    bool on_grid_x = (x >= 0 && x < grid.size());
    bool on_grid_y = (y >= 0 && y < grid[0].size());

    //if the above values are true (located in the grid)
    //check whether this location is empty or occupied
    if(on_grid_x && on_grid_y){
        return grid[x][y] == State::kEmpty;
    }
    else{
        return false;
    }
}

#endif