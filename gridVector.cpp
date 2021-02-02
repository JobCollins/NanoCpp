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

vector<int> ParseLine(string input){
    istringstream ss(input);

    vector<int> vec;

    string token;

    while (getline(ss, token, ','))
    {
        /* code */
        vec.push_back(stoi(token));
    }

    // DEBUGGING
    //for (int i = 0; i < 6; i++)
    // {
    //     /* code */
    //     cout<<vec[i]<<' ';
    // }
    // cout<<endl;
    
    

    return vec;
}

vector<vector<int>> ReadBoardFile(string path){
    //mother of all vectors
    vector<vector<int>> grandvec;
    //read file in path
    ifstream ReadFile(path);

    //store each read line in a variable
    string line;

    //cout each line
    while (getline(ReadFile, line))
    {
        /* DEBUGGING code */
        // cout<<line<<endl;

        //append the vectors got from running ParseLine on each output
        grandvec.push_back(ParseLine(line));
    }

    //return mother of all vectors
    return grandvec;
    
}

int main()
{
    // vector<vector<int>> board
    // {
    //     {0, 1, 0, 0, 0, 0},
    //     {0, 1, 0, 0, 0, 0},
    //     {0, 1, 0, 0, 0, 0},
    //     {0, 1, 0, 0, 0, 0},
    //     {0, 0, 0, 0, 1, 0}
    // };

    // PrintBoard(board);

    cout<<"Reading from file...\n";

    string filepath = "1.board";

    PrintBoard(ReadBoardFile(filepath));

    return 0;
}
