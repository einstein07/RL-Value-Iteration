/* 
 * File:            main.cpp
 * Author:          Sindiso Mkhatshwa
 * Student Number:  MKHSIN035
 * Created on 23 May 2020, 22:27
 */
#include "value_iteration.h"
#include <cstdlib>
#include <vector>
#include <string>
#include <fstream>
#include <iostream>

using namespace std;

/*
 * Assignment 6 driver file for testing Value iteration algorithm implementation
 */
int main(int argc, char** argv) {

    int states = 6;
    vector < vector<string> > actions = {{"right","down"},
                                        {"left","right", "down"},
                                        {""},
                                        {"right", "up"},
                                        {"left", "right", "up"},
                                        {"left", "up"}};
    vector < vector<int> > rewards = {{0,0},
                                        {0,50, 0},
                                        {0},
                                        {0, 0},
                                        {0, 0, 0},
                                        {0, 100}};
    double theta = 0.000001;
    double gamma = 0.8;
    double V [6] = {0,0,0,0,0,0};
    int it = MKHSIN035::value_iteration( states, theta, gamma, actions, rewards, V);
    
    //--------------------------------------------------------------------------
    //Write data to textfile
    //--------------------------------------------------------------------------
    //Create and open file for writing
    ofstream file;
    file.open("output_MKHSIN035.txt");
    //Check if file was created
    if(file.is_open()){//If the file is open, then write to file
        file<<"--------------------------------------------------------------------------\n";
        file<<"Question 1:\n";
        file<<"--------------------------------------------------------------------------\n";
        file<<"Number of iterations: "<<it<<"\nOptimal values for each state: \n";
        for(int i = 0; i < states; i++)
            file<<"S"<<(i+1)<<":"<<V[i]<<"\n";
        //file<<"S6:"<<V[5]<<endl;
        file<<"--------------------------------------------------------------------------\n";
        file<<"Question 2:\n";
        file<<"--------------------------------------------------------------------------\n";
        //By observation:
        file<<"States forming the optimal policy, starting from S1, to reach the"
                " terminal state S3:\nS1->S2->S5->S6->S3\n";
        file<<"--------------------------------------------------------------------------\n";
        //For Question 3, the reward function is changed by doubling the rewards to test this fact
        vector < vector<int> > doubled_rewards = {{0,0},
                                        {0,100, 0},
                                        {0},
                                        {0, 0},
                                        {0, 0, 0},
                                        {0, 200}};
            
        double doubled_V [6] = {0,0,0,0,0,0};

        it = MKHSIN035::value_iteration( states, theta, gamma, actions, doubled_rewards, doubled_V);

        file<<"Question 3:\n";
        file<<"--------------------------------------------------------------------------\n";
        file<<"Yes, it is possible. This is demonstrated by doubling the immediate "
                "reward, which in turn doubles the optimal values, but the optimal"
                " policy remains the same.\nNumber of iterations: "<<it<<endl;
        for(int i = 0; i < states; i++)
            file<<"S"<<(i+1)<<":"<<doubled_V[i]<<"\n";
        //file<<"S6:"<<doubled_V[5]<<endl;
    }
    //If file could not be opened, notify the user
    else{
        cout<<"Could not open file"<<endl;
    }
    return 0;
}

