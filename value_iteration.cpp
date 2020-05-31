/* 
 * File:   value_iteration.h
 * Author: Sindiso Mkhatshwa
 *
 * Created on 31 May 2020, 15:37
 */
#include "value_iteration.h"

int MKHSIN035::value_iteration(double theta, double gamma, const std::vector<std::vector<std::string > > &actions, const std::vector<std::vector<int > > &rewards, double* V){
        
    int it = 0;
    double delta;
    while (true){
        it++;
        delta = 0;
                    
        for (int s = 0; s < 6; s++){
            double v = V[s];
            double maxValue = -1.0;
            double nxtValue = 0.0;
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
                maxValue = (nxtValue>maxValue?nxtValue:maxValue);

            }
            V[s] = maxValue;
            //std::cout<<"State: "<<(s+1)<<"iteration "<<it<<" Value: "<<V[s]<<endl;
            double d = abs(v-V[s]);
            delta = (delta>d?delta:d);
        }

        
        if(delta < theta)
            break;
    }
    return it;
}
