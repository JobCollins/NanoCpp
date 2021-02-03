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

int main()
{
    int x1=2;
    int y1=3;
    int x2 = 7;
    int y2 = 8;

    int manhattan_distance = heuristic(x1,x2,y1,y2);

    return 0;
}