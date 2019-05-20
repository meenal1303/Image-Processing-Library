#include "convolution_openBlas.h"
#include <iostream>
#include <cmath>
#include <cstdlib>
#include <vector>
#include <fstream>
#include <cblas.h>
using namespace std;

 
void convert5(float *ans, float **final_ans,int size){
    for(int i=0;i<size*size;i++){
        int l=(i)/size;
        int m=(i)%size;
        final_ans[l][m]=ans[i];
    }
}

void convolution_openBlas(float *A, int N,int K,float *B, bool tA, bool tB,float **final_ans){

    // Error, width and height should match!
    //iszero(N == B_height);
    float* AB;
    AB=new float [N];
    int lda = K;
    int ldb = tB ? K : 1;

    #define TRANSPOSE(X) ((X) ? CblasTrans : CblasNoTrans)

    // http://www.netlib.org/lapack/explore-html/d7/d2b/dgemm_8f.html
    cblas_sgemm(CblasRowMajor,TRANSPOSE(tA), TRANSPOSE(tB), N, 1, K, 1.0, A, lda, B, ldb, 0, AB, 1);
                
    #undef TRANSPOSE (X)
    
    convert5(AB,final_ans,sqrt(N));
}

    
