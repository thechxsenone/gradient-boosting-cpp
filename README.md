# Gradient Boosting from Scratch (C++)

This project is a simple, educational implementation of **Gradient Boosting Regressor** in C++ from scratch.

It uses **decision stumps (1-level decision trees)** as weak learners to fit a regression model by minimizing mean squared error.
---
## 🚀 Features
- Gradient Boosting for regression
- Decision Stump weak learners
- CSV data loader
- Simple console predictions
---
## 📁 Project Structure
- `src/` — source files (.cpp)
- `include/` — header files (.h)
- `data/` — input CSV file
- `build/` — compiled binaries
---
## ⚙️ Build Instructions

Make sure you have `clang++` or `g++` installed.

To build the project:

```bash
make
```

To run:
```bash
./build/main
```

To clean:
```bash
make clean
```
---
## 📊 Input Data Format

CSV file with numeric features and target:
```csv
x1,x2,...,xn,y
1.0,2.0,...,4.5
...
```
The last column is the target y.
