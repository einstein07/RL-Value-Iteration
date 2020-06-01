/* 
 * File:   value_iteration.h
 * Author: Sindiso Mkhatshwa
 *
 * Created on 31 May 2020, 15:37
 */
#include "value_iteration.h"

int MKHSIN035::value_iteration(int states, double theta, double gamma, const std::vector<std::vector<std::string > > &actions, const std::vector<std::vector<int > > &rewards, double* V){
        
    int it = 0;
    double delta;
    while (true){
        it++;
        delta = 0;
                    
        //Loop through all states
        for (int s = 0; s < states; s++){
            double v = V[s];
            double maxValue = -1.0;
            double nxtValue = 0.0;
            //Iterate through all possible actions for each state
            for (int i = 0; i < actions[s].size(); i++){
                if(actions[s][i] == "right"){
                    nxtValue = rewards[s][i] + gamma * V[s+1];
                }
                else if(actions[s][i] == "left"){
                    nxtValue = rewards[s][i] + gamma * V[s-1];
                }
                else if(actions[s][i] == "up"){
                    nxtValue = rewards[s][i] + gamma * V[s-3];
                }
                else if(actions[s][i] == "down"){
                    nxtValue = rewards[s][i] + gamma * V[s+3];
                }
                //Check for max action
                maxValue = (nxtValue>maxValue?nxtValue:maxValue);

            }
            V[s] = maxValue;
            double d = abs(v-V[s]);
            delta = (delta>d?delta:d);
        }

        //check for convergence
        if(delta < theta)
            break;
    }
    return it;
}
