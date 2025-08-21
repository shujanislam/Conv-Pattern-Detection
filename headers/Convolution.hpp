#ifndef CONVOLUTION_HPP
#define CONVOLUTION_HPP

#include <iostream>
#include <vector>
#include <cmath>
#include "Dataset.hpp"

using namespace std;

extern float weights1[2][2];
extern float weights2[2][2];
extern float weights3[2][2];
extern float weights4[2][2];
extern float b;

float sigmoid(float x);

void TrainModel() {
    float learning_rate = 0.01;
    int epochs = 5000;

    for (int epoch = 0; epoch < epochs; epoch++) {
        int correct = 0;

        for (size_t k = 0; k < X.size(); k++) {
            float best_score[4] = {-1e9, -1e9, -1e9, -1e9};
            int best_i[4] = {0, 0, 0, 0};
            int best_j[4] = {0, 0, 0, 0};

            float (*weights[4])[2] = {weights1, weights2, weights3, weights4};

            for (int f = 0; f < 4; f++) {
                for (int i = 0; i < 3; i++) {
                    for (int j = 0; j < 3; j++) {
                        float sum = 0.0;
                        for (int p = 0; p < 2; p++) {
                            for (int q = 0; q < 2; q++) {
                                sum += X[k][(i+p)*4 + (j+q)] * weights[f][p][q];
                            }
                        }
                        if (sum > best_score[f]) {
                            best_score[f] = sum;
                            best_i[f] = i;
                            best_j[f] = j;
                        }
                    }
                }
            }

            float logit = best_score[0] + best_score[1] + best_score[2] + best_score[3] + b;
            float prob = sigmoid(logit);
            int pred = (prob >= 0.5) ? 1 : 0;

            if (pred == label[k]) correct++;

            float err = label[k] - prob;

            for (int f = 0; f < 4; f++) {
                for (int p = 0; p < 2; p++) {
                    for (int q = 0; q < 2; q++) {
                        weights[f][p][q] += learning_rate * err * X[k][(best_i[f]+p)*4 + (best_j[f]+q)];
                        weights[f][p][q] += 0.001 * (1.0 - weights[f][p][q]);
                    }
                }
            }

            b += learning_rate * err;
        }

        if ((epoch+1) % 500 == 0 || epoch == 0)
            cout << "Epoch " << epoch+1 << " accuracy = " << correct << "/" << X.size() << endl;
    }

    cout << "\nLearned filters:\n";

    cout << "Filter 1:\n";
    for (int p = 0; p < 2; p++) {
        for (int q = 0; q < 2; q++) {
            cout << weights1[p][q] << " ";
        }
        cout << endl;
    }

    cout << "Filter 2:\n";
    for (int p = 0; p < 2; p++) {
        for (int q = 0; q < 2; q++) {
            cout << weights2[p][q] << " ";
        }
        cout << endl;
    }

    cout << "Filter 3:\n";
    for (int p = 0; p < 2; p++) {
        for (int q = 0; q < 2; q++) {
            cout << weights3[p][q] << " ";
        }
        cout << endl;
    }

    cout << "Filter 4:\n";
    for (int p = 0; p < 2; p++) {
        for (int q = 0; q < 2; q++) {
            cout << weights4[p][q] << " ";
        }
        cout << endl;
    }

    cout << "Bias: " << b << endl;
}

#endif
