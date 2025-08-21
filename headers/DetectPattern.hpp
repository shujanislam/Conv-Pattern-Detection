#ifndef DETECTPATTERN_HPP
#define DETECTPATTERN_HPP

#include<vector>

using namespace std;

// Extern declarations (no initialization here)
extern float weights1[2][2];
extern float weights2[2][2];
extern float weights3[2][2];
extern float weights4[2][2];
extern float b;

// Function declaration
float sigmoid(float x);

int DetectPattern(vector<vector<int>> matrix) {
    int rows = matrix.size();
    int cols = matrix[0].size();
    
    float (*weights[4])[2] = {weights1, weights2, weights3, weights4};

    for (int f = 0; f < 4; f++) {
        for (int i = 0; i < 3; i++) {
            for (int j = 0; j < 3; j++) {
                float sum = 0.0;
                for (int p = 0; p < 2; p++) {
                    for (int q = 0; q < 2; q++) {
                        sum += matrix[i+p][j+q] * weights[f][p][q];
                    }
                }
                if (sum >= 4) {
                    return 1;  // pattern found
                }
            }
        }
    }
    return 0;  // no pattern found
}

#endif 
