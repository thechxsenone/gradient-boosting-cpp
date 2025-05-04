#include "DataLoader.h"
#include "DecisionStump.h"
#include "GradientBoosting.h"

#include <iostream>
#include <vector>
using namespace std;

int main() {
    vector<vector<double>> X;
    vector<double> y;

    string filename = "data/sample.csv";
    DataLoader::loadCSV(filename, X, y);

    if (X.empty() || y.empty()) {
        cerr << "Error: data not loaded or empty." << endl;
        return 1;
    }

    cout << "Loaded " << X.size() << " samples with " << X[0].size() << " features." << endl;

    int n_estimators = 10;
    double learning_rate = 0.05;
    GradientBoosting gb(n_estimators, learning_rate);

    cout << "Training Gradient Boosting model..." << endl;
    gb.fit(X, y);
    cout << "Training completed." << endl;

    cout << "\nPredictions on training data:" << endl;
    for (size_t i = 0; i < X.size(); ++i) {
        double pred = gb.predict(X[i]);
        cout << "Sample " << i + 1 << ": actual = " << y[i] << ", predicted = " << pred << endl;
    }

    return 0;
}
