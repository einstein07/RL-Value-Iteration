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

using namespace std;

/*
 * Assignment 6 driver file for testing Value iteration algorithm implementation
 */
int main(int argc, char** argv) {

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
    double V [6] = {0,5,0,10,1,10};
    int it = MKHSIN035::value_iteration(theta, gamma, actions, V);
    //--------------------------------------------------------------------------
    //Write data to textfile
    //--------------------------------------------------------------------------
    //Create and open file for writing
    ofstream file;
    file.open("output.txt");
    //Check if file was created
    if(file.is_open()){//If the file is open, then write to file
        file<<"--------------------------------------------------------------------------\n";
        file<<"Question 1:\n";
        file<<"--------------------------------------------------------------------------\n";
        file<<"Number of iterations: "<<it<<"\nOptimal values for each state: \n";
        for(int i = 0; i < 5; i++)
            file<<"S"<<(i+1)<<":"<<V[i]<<" ";
        file<<"S6:"<<V[5]<<endl;
        file<<"--------------------------------------------------------------------------\n";
        file<<"Question 2:\n";
        file<<"--------------------------------------------------------------------------\n";
        file<<"S1->S2->S5->S6->S3\n";
        file<<"--------------------------------------------------------------------------\n";
        file<<"Question 3:\n";
        file<<"--------------------------------------------------------------------------\n";
        
    }
    //If file could not be opened, notify the user
    else{
        
    }
    return 0;
}

