#include <iostream>
#include <vector>
#include <cmath>
#include "headers/Dataset.hpp"
#include "headers/Convolution.hpp"
#include "headers/DetectPattern.hpp"

using namespace std;

// Trainable parameters: 4 filters + bias
float weights1[2][2] = {{0.01, -0.01}, {0.02, -0.02}};
float weights2[2][2] = {{0.01, -0.01}, {0.02, -0.02}};
float weights3[2][2] = {{-0.01, 0.01}, {-0.02, 0.02}};
float weights4[2][2] = {{-0.01, 0.01}, {-0.02, 0.02}};
float b = 0.0;

// Sigmoid function
float sigmoid(float x) {
    return 1.0 / (1.0 + exp(-x));
}

int main() {
    TrainModel();

    // Example detection
    vector<vector<int>> test = {
        {1,1,0,0, 0, 0, 1, 1},
        {1,1,0,0, 0, 1, 1, 0},
        {0,0,1,1, 0, 0, 0, 0},
        {0,0,0,1, 0, 0, 0, 0}, 
        {1,0,0,0, 0, 1, 1, 0},
        {0,0,1,1, 0, 0, 0, 0},
        {1,0,0,0, 0, 1, 1, 0},
        {0,0,1,1, 0, 0, 0, 0},
    };

    cout << "Detection result: " << DetectPattern(test) << endl;
    return 0;
}

