#ifndef HELPERFUNCTIONS_H
#define HELPERFUNCTIONS_H

#include<iostream>
#include<vector>
#include<sstream>
#include<fstream>
#include<cmath>


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


enum State {kEmpty, kObstacle, kClosed} state;


void AddToOpen(int x, int y, int g, int h, vector<vector<int>>& openodes, vector<vector<State>>& grid){
    //create a node vector
    vector<int> node{x, y, g, h};
    //push the above node to the back of the open vector
    openodes.push_back(node);
    //set the grid value for the x,y coordinates to the enum value kClosed
    grid[x][y]=State::kClosed;

}

#endif