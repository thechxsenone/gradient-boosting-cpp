#ifndef DATALOADER_H
#define DATALOADER_H

#include <vector>
#include <string>

using namespace std;

class DataLoader {
public:
    static void loadCSV(const string& filename, vector<vector<double>>& X, vector<double>& y);
};

#endif
