#include <iostream>
#include <cmath>
#include <cstdlib>
#include <vector>
#include <fstream>
using namespace std;

vector<float> sigmoid(vector<float> v){
    int i=0;
    vector<float> v1;
    while(i<v.size()){
        v1.push_back((float)(1/(1+exp(-v[i]))));
        i++;
    }
    
    return v1;
}

