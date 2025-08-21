# Minimal Convolutional Network for Binary Pattern Recognition

This project implements a lightweight convolution-based model to detect **2×2 binary block patterns** in a 4×4 matrix.  
It demonstrates how convolutional filters can be trained with gradient descent to recognize structured binary features,  
making it a minimal but research-worthy step toward Convolutional Neural Networks (CNNs).

---

## 🚀 Features
- Custom dataset of binary 4×4 matrices (`Dataset.hpp`)
- Trainable **2×2 convolutional filters**
- Gradient descent weight updates
- Accuracy tracking during training
- Filter visualization after learning
- Extendable to noisy data

---

## 📂 Project Structure

├── headers/
│ ├── Convolution.hpp # Training logic and filters
│ ├── Dataset.hpp # Binary dataset and labels
│ ├── DetectPattern.hpp # Pattern detection function
├── main.cpp # Entry point
└── README.md # Project documentation

---

## ⚙️ Build & Run
```bash
# Clone repo
git clone https://github.com/your-username/minimal-convnet.git
cd minimal-convnet

# Compile
g++ main.cpp -o pattern_detector

# Run
./pattern_detector

```

## Example Output

```bash
Epoch 1 accuracy = 18/30
Epoch 500 accuracy = 27/30
Epoch 1000 accuracy = 29/30
...
Learned filters:
Filter 1:
0.95 -0.02
0.98 -0.01
...
Bias: 0.12

Detection result: 1
```
```
```

## Dataset

Each sample is a flattened 4×4 binary matrix

Positive samples contain at least one 2×2 block of ones

Negative samples contain scattered or structured noise without a valid block

Dataset is defined in Dataset.hpp


