#include <iostream>
#include <string>
#include <sstream>

using namespace std;

int main()
{
    string roomLength;
    string roomWidth;

    float length;
    float width;
    float area;

    cout<<"Input room length"<<endl;
    getline(cin, roomLength);
    cout<<"Input room width"<<endl;
    getline(cin, roomWidth);

    stringstream(roomLength)>>length;
    stringstream(roomWidth)>>width;

    area = length * width;

    cout<<"Area of room is: "<<area<<endl;

}