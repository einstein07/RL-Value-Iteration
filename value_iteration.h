/* 
 * File:   value_iteration.h
 * Author: Sindiso Mkhatshwa
 *
 * Created on 31 May 2020, 15:37
 */

#ifndef VALUE_ITERATION_H
#define VALUE_ITERATION_H
#include <string>
#include <vector>
namespace MKHSIN035{
    int value_iteration(int states, double theta, double gamma, const std::vector<std::vector<std::string > > &actions, const std::vector<std::vector<int > > &rewards, double* V);
};
#endif /* VALUE_ITERATION_H */

