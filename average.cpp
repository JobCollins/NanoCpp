#include <iostream>
#include <stdio.h>

using namespace std;

int main()
{
    int userInput = 0;
    int maxNum = 0;
    int minNum = 0;
    int sumTotal = 0;
    float avg = 0;

    for (int i = 0; i < 5; i++)
    {
        /* code */
        cout<<"Input a number: ";
        scanf("%d", &userInput);
        cout<<userInput<<endl;

        if (userInput > maxNum)
        {
            /* code */
            maxNum = userInput;
        }
        if (userInput < minNum)
        {
            /* code */
            minNum = userInput;
        }

        sumTotal = sumTotal + userInput;       
        
    }

    cout<<"Maximun Number: "<<maxNum<<endl;
    cout<<"Minimum Number: "<<minNum<<endl;

    avg = sumTotal/5;

    cout<<"Average is: "<<avg<<endl;
    

}