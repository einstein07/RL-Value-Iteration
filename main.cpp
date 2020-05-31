/* 
 * File:            main.cpp
 * Author:          Sindiso Mkhatshwa
 * Student Number:  MKHSIN035
 * Created on 23 May 2020, 22:27
 */

#include <cstdlib>
#include <vector>
#include <string>
#include <fstream>
using namespace std;

/*
 * Assignment 6 driver file for testing Value iteration algorithm implementation
 */
int main(int argc, char** argv) {
    int states [6] = {1,2,3,4,5,6};
    string action [4] = {"left", "right", "up", "down"};
    vector < vector<string> > actions = {{"right","down"},
                                        {"left","right", "down"},
                                        {""},
                                        {"right", "up"},
                                        {"left", "right", "up"},
                                        {"left", "up"}};
    double theta = 0.000001;
    double gamma = 0.8;
    int it = 0;
    double V [6] = {2,5,0,10,1,10};
    double delta;
    while (true){
        it++;
        delta = 0;
        for (int s = 0; s < 6; s++){
            double v = V[s];
            for (int i = 0; i < actions[s].size(); i++){
                if(actions[s][i] == "right"){
                    if(s == 1)
                        V[s] = 50 + (gamma*V[s+1]);
                    else
                        V[s] = gamma * V[s+1];
                }
                else if(actions[s][i] == "left"){
                    V[s] = gamma * V[s-1];
                }
                else if(actions[s][i] == "up"){
                    if(s == 5)
                        V[s] = 100 + (gamma*V[s-3]);
                    else
                        V[s] = gamma * V[s+1];
                }
                else if(actions[s][i] == "down"){
                    V[s] = gamma * V[s+3];
                }
            }
            double d = abs(v-V[s]);
            delta = (delta>d?delta:d);
        }
        
        if(delta < theta)
            break;
    }
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

