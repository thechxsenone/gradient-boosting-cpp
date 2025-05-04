#ifndef DECISIONSTUMP_H
#define DECISIONSTUMP_H

#include <vector>

using namespace std;

class DecisionStump {
public:
    int feature_index;
    double threshold;
    double left_value;
    double right_value;

    void fit(const vector<vector<double>>& X, const vector<double>& y);
    double predict(const vector<double>& x) const;
};

#endif
