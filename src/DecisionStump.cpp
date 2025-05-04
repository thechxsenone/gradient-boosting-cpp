#include "DecisionStump.h"
#include <limits>
#include <cmath>
#include <vector>

void DecisionStump::fit(const vector<vector<double>>& X, const vector<double>& y){
    double best_error = numeric_limits<double>::max();

    int n_samples = X.size();
    int n_features = X[0].size();

    for (int feature = 0; feature < n_features; feature++) {
        vector<double> thresholds;
        
        for (int i = 0; i < n_samples; ++i) {
            thresholds.push_back(X[i][feature]);
        }

        for (double t: thresholds) {
            vector<double> left_targets, right_targets;

            for (int i = 0; i < n_samples; ++i) {
                if (X[i][feature] <= t) {
                    left_targets.push_back(X[i][feature]);
                } else {
                    right_targets.push_back(X[i][feature]);
                }
            }
            
            if (left_targets.empty() || right_targets.empty()) {
                continue;
            }

            double left_mean = 0.0, right_mean = 0.0;
            for (double val: left_targets){
                left_mean += val;
            }
            for (double val: right_targets){
                right_mean += val; 
            }

            left_mean /= left_targets.size();
            right_mean /= right_targets.size();

            double error = 0.0;
            for (double val: left_targets){
                error += pow(val - left_mean, 2);
            }
            for (double val: right_targets){
                error += pow(val - right_mean, 2);
            }

            if (error < best_error) {
                best_error = error;
                feature_index = feature;
                threshold = t;
                left_value = left_mean;
                right_value = right_mean;
            }
        }
    }
};

double DecisionStump::predict(const vector<double>& x) const {
    if (x[feature_index] <= threshold) {
        return left_value;
    } else {
        return right_value;
    }
};