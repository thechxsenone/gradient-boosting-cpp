#include "GradientBoosting.h"
#include <numeric>  // для accumulate
#include <iostream>


GradientBoosting::GradientBoosting(int n_estimators, double learning_rate) {
    this->n_estimators = n_estimators;
    this->learning_rate = learning_rate; 
}

void GradientBoosting::fit(const vector<vector<double>>& X, const vector<double>& y){
    int n_samples = X.size();

    initial_prediction = std::accumulate(y.begin(), y.end(), 0.0) / y.size();

    vector <double> y_pred(n_samples, initial_prediction); 

    for (int m = 0; m < n_estimators; ++m) {
        vector <double> residuals(n_samples);
        for (int i = 0; i < n_samples; ++i) {
            residuals[i] = y[i] - y_pred[i];
        }

        DecisionStump stump;
        stump.fit(X, residuals);

        for (int i = 0; i < n_samples; ++i) {
            y_pred[i] += learning_rate * stump.predict(X[i]);
        }

        stumps.push_back(stump);

        cout << "Iteration " << m + 1 << "/" << n_estimators << endl;
    }
}

double GradientBoosting::predict(const vector<double>& x) const {
    double pred = initial_prediction;
    for (const auto& stump : stumps) {
        pred += learning_rate * stump.predict(x);
    }
    return pred;
}