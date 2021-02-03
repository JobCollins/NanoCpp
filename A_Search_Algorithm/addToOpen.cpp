#include<iostream>
#include<vector>
#include<sstream>
#include<fstream>
#include<cmath>

using namespace std;


enum State {kEmpty, kObstacle, kClosed} state;


void AddToOpen(int x, int y, int g, int h, vector<vector<int>>& openodes, vector<vector<State>>& grid){
    //create a node vector
    vector<int> node = {x, y, g, h};
    //push the above node to the back of the open vector
    openodes.push_back(node);
    //set the grid value for the x,y coordinates to the enum value kClosed
    grid[x][y]=State::kClosed;

}


int main()
{
    return 0;
}