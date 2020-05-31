/* 
 * File:   value_iteration.h
 * Author: Sindiso Mkhatshwa
 *
 * Created on 31 May 2020, 15:37
 */
#include "value_iteration.h"

int MKHSIN035::value_iteration(double theta, double gamma, const std::vector<std::vector<std::string > > &actions, double* V){
        
    int it = 0;
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
    return it;
}
