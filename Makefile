CXX = clang++
CXXFLAGS = -std=c++17 -Wall -Iinclude

SRC = src/main.cpp src/DataLoader.cpp src/DecisionStump.cpp src/GradientBoosting.cpp
OBJ = $(SRC:src/%.cpp=build/%.o)

TARGET = build/main

all: $(TARGET)

$(TARGET): $(OBJ)
	@mkdir -p build
	$(CXX) $(CXXFLAGS) $^ -o $@

build/%.o: src/%.cpp
	@mkdir -p build
	$(CXX) $(CXXFLAGS) -c $< -o $@

clean:
	rm -f build/*.o
	rm -f $(TARGET)
