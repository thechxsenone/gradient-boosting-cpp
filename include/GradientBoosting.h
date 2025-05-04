#ifndef GRADIENTBOOSTING_H
#define GRADIENTBOOSTING_H

#include "DecisionStump.h"
#include <vector>

using namespace std;

class GradientBoosting {
public:
    int n_estimators;
    double learning_rate;
    vector<DecisionStump> stumps;
    double initial_prediction;

    GradientBoosting(int n_estimators = 100, double learning_rate = 0.1);

    void fit(const vector<vector<double>>& X, const vector<double>& y);
    double predict(const vector<double>& x) const;
};

#endif
