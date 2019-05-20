#include <iostream>
#include <cmath>
#include <cstdlib>
#include <vector>
#include <fstream>
using namespace std;
void average_pooling(int r,float **a, float **b);
void convolution(float **a,int c1,float **b, int c2, float **c);
void convolution_matrix_mult(float **a,int c1,float **b, int c2,float **final_ans);
void convolution_matrix_mult_with_padding(float **a,int c1,float **b, int c2,int p,float **final_ans2);
void convolution_with_padding(float **a,int c1,float **b, int c2,int p, float **d);
void max_pooling(int r,float **a, float **b);
void relu(int r,float **a);
vector<float> sigmoid(vector<float> v);
vector<float> softmax(vector<float> v);
void tanh(int r,float **a);

