#include<iostream>
#include<vector>
#include<string>
#include<fstream>
#include<sstream>

using namespace std;

enum State {kEmpty, kObstacle} state;

void CellString(State state){
    switch (state)
    {
    case kEmpty:
        /* code */
        cout<<"0 ";
        // break;
    case kObstacle:
        /* code */
        cout<<"⛰️ ";
        // break;
    default:
        break;
    }
}

int main(){

    CellString(state);
    return 0;
}