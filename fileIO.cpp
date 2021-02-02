#include<iostream>
#include<fstream>
#include<string>

using namespace std;

void ReadBoardFile(string path){
    //create a string value that hold each line
    string line;

    //read the file
    ifstream ReadFile(path);

    //print the lines
    while (getline(ReadFile, line))
    {
        /* code */
        cout<<line<<endl;
    }
    
}

int main()
{
    //create a file
    // ofstream MyWriteFile("filename.txt");

    // //write to file
    // MyWriteFile<<"Hello World!"<<endl;
    // MyWriteFile<<"I am learning"<<endl;
    // MyWriteFile<<"To do file IO"<<endl;

    // //close the file
    // MyWriteFile.close();

    //read the file
    // ifstream MyReadFile("filename.txt");

    // //create string to contain output of read file
    // string line;

    // while(getline(MyReadFile, line)){
    //     cout<<line<<endl;
    // }
    ReadBoardFile("filename.txt");

    return 0;

}