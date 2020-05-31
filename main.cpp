/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.cpp
 * Author: root07
 *
 * Created on 23 May 2020, 22:27
 */

#include <cstdlib>
#include <vector>
#include <string>
#include <fstream>
using namespace std;

/*
 * 
 */
int main(int argc, char** argv) {
    int states [6] = {1,2,3,4,5,6};
    string action [4] = {"left", "right", "up", "down"};
    vector < vector<string> > policy = {{"right","down"},
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
            for (int i = 0; i < policy[s].size(); i++){
                if(policy[s][i] == "right"){
                    if(s == 1)
                        V[s] = 50 + (gamma*V[s+1]);
                    else
                        V[s] = gamma * V[s+1];
                }
                else if(policy[s][i] == "left"){
                    V[s] = gamma * V[s-1];
                }
                else if(policy[s][i] == "up"){
                    if(s == 5)
                        V[s] = 100 + (gamma*V[s-3]);
                    else
                        V[s] = gamma * V[s+1];
                }
                else if(policy[s][i] == "down"){
                    V[s] = gamma * V[s+3];
                }
            }
            double d = abs(v-V[s]);
            delta = (delta>d?delta:d);
        }
        
        if(delta < theta)
            break;
    }
    ofstream file;
    file.open("output.txt");
    file<<"Question 1:\nNumber of iterations: "<<it<<"\nOptimal values for each state: \n";
    for(int i = 0; i < 5; i++)
        file<<"S"<<(i+1)<<":"<<V[i]<<" ";
    file<<"S6:"<<V[5]<<endl;
    
    file<<"Question 2: S1->S2->S5->S6->S3\n";
    return 0;
}

