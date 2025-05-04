#include "DecisionStump/DecisionStump.h"
#include <iostream>

int main() {
    vector<vector<double>> X = { {2.0}, {4.0}, {6.0}, {8.0} };
    vector<double> y = { 1.0, 1.5, 3.0, 3.5 };

    DecisionStump stump;
    stump.fit(X, y);

    cout << "Best feature: " << stump.feature_index << endl;
    cout << "Threshold: " << stump.threshold << endl;
    cout << "Left value: " << stump.left_value << endl;
    cout << "Right value: " << stump.right_value << endl;

    vector<double> x_test = {5.0};
    cout << "Prediction for x=5: " << stump.predict(x_test) << endl;

    return 0;
}
