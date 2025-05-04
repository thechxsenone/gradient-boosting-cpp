#include "DataLoader.h"
#include <fstream>
#include <sstream>
#include <iostream>

void DataLoader::loadCSV(const string& filename, vector<vector<double>>& X, vector<double>& y) {
    ifstream file(filename);
    if (!file.is_open()) {
        cerr << "Error: could not open file " << filename << endl;
        return;
    }

    string line;
    bool headerSkipped = false;

    while (getline(file, line)) {
        if (!headerSkipped) {
            headerSkipped = true;
            continue;
        }

        stringstream ss(line);
        string token;
        vector<double> row;

        // разбиваем строку по запятым
        while (getline(ss, token, ',')) {
            try {
                row.push_back(stod(token));
            } catch (const invalid_argument&) {
                cerr << "Warning: invalid number '" << token << "' in file " << filename << endl;
                row.push_back(0.0);
            }
        }

        if (!row.empty()) {
            y.push_back(row.back());
            row.pop_back();
            X.push_back(row);
        }
    }

    file.close();
}
