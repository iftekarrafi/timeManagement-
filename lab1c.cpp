/*
 Author: Iftekar Rafi
 Course: {135,136}
 Instructor: Ali ElSayed
 Assignment: Lab 1 Problem C
 
 This program prints out a greeting to the professor depending on whether the
 current time is midnight-noon, noon-sunset, or sunset-midnight and checks how
 long you have till it becomes dark outside.
 */

#include <iostream>
#include <string>
#include <ctime>
using namespace std;


int main()
{
    int cur_hour, cur_min, numHours, numMins, expect_time, minNew, totalMins;
    cout << "Enter the hours part of today's sunset time (1-12)" << endl;
    cin >> cur_hour;
    cout << "Enter the minutes part of today's sunset time (0-59)" << endl;
    cin >> cur_min;
    
    time_t t;
    struct tm * now;
    t = time(0);
    now = localtime(&t);
    int hour = now->tm_hour - 17;
    int min = now->tm_min;
    
    cout << "The current time is: " << hour << ":" << min << endl;
    
    if(cur_hour > 12 && cur_hour < 23){
        cout << "Good Morning Ali" << endl;
    }
    else if(cur_hour > 5 && cur_hour < 12){
        cout << "Good Evening Ali" << endl;
    }
    else{
        cout << "Good Afternoon Ali" << endl;
    }
    
    numHours = (cur_hour-hour);
    numMins = (cur_min-min);
    
    cout << "It will be dark in " << numHours - 1 << " hours and " << numMins + 60 << " minutes." << endl;
    
    cout << "How many minutes from now do you expect to be home?" << endl;
    cin >> expect_time;
    
    totalMins = 60 * numHours + numMins;
    
    if(expect_time < totalMins){
        cout << "When you get home it will be light" << endl;
    }
    else{
        cout << "When you get home it will be dark" << endl;
    }
    
    return 0;
}
