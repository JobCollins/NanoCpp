#include<iostream>
#include<fstream>
#include<string>
#include<sstream>
#include<vector>

using namespace std;


vector<int> ParseLine(string input){
    istringstream ss(input);

    vector<int> vec;

    string token;

    while (getline(ss, token, ','))
    {
        /* code */
        vec.push_back(stoi(token));
    }

    for (int i = 0; i < 6; i++)
    {
        /* code */
        cout<<vec[i]<<' ';
    }
    
    

    return vec;
}

int main()
{
    string filepath = "0, 1, 0, 0, 0, 0,";
    ParseLine(filepath);

    return 0;
}