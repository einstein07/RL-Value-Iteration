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
#include <iostream>
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
    double theta = 0.09;
    double gamma = 0.8;
    int it = 0;
    double V [6] = {0,0,0,0,0,0};
    double delta = 1;
    
    cout<<"Number of iterations: "<<it<<endl;
    for(int i = 0; i < 5; i++)
        cout<<V[i]<<" ";
    cout<<V[5]<<endl;
    return 0;
}

