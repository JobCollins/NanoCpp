#include<iostream>
#include<vector>

using namespace std;

int main(){
    vector<string> languages;
    languages.push_back("Python ");
    languages.push_back("C++ ");
    languages.push_back("JS");

    for(auto i=languages.begin();i!=languages.end(); ++i)
    cout<<*i;
    cout<<endl;


    vector<int> nums;
    for(auto i=0; i<6; ++i){
        nums.push_back(i);
    }

    for(auto itr=nums.begin();itr!=nums.end();++itr){
        cout<<*itr<<' ';
    }
    
    cout<<"\nSize of languages vector: "<<languages.size()<<endl;
    cout<<"Size of nums vector: "<<nums.size()<<endl;
    

    // 2D vector
    vector<vector<int>> vect
    {
        {1,2,3},
        {4,5,6},
        {7,8,9}
    };

    for(int i=0; i<vect.size();i++){
        for (int j = 0; j < vect[i].size(); j++)
        {
            /* code */
            cout<<vect[i][j]<<" ";
        }
        cout<<endl;
    }



    return 0;
}