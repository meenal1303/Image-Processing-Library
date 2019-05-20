#include "convolution_mkl.h"
#include <iostream>
#include <cmath>
#include <cstdlib>
#include <vector>
#include <fstream>
#include "mkl.h"
using namespace std;

 
void convert3(float *ans, float **final_ans,int size){
    for(int i=0;i<size*size;i++){
        int l=(i)/size;
        int m=(i)%size;
        final_ans[l][m]=ans[i];
    }
}

void convolution_mkl(float *A, int N,int K,float *B,float **final_ans){
    
    // Error, width and height should match!
    //iszero(N == B_height);
    float* AB;
    AB = (float *)mkl_malloc( N*sizeof( float ), 64 );
    
    int lda = K;
    int ldb = 1;
       
    
    
    #define TRANSPOSE(X) ((X) ? CblasTrans : CblasNoTrans)
   
    // http://www.netlib.org/lapack/explore-html/d7/d2b/dgemm_8f.html
    cblas_sgemm(CblasRowMajor,CblasNoTrans,CblasNoTrans, N, 1, K, 1.0, A, lda, B, ldb, 0, AB, 1);
   
    #undef TRANSPOSE (X)
    
    convert3(AB,final_ans,sqrt(N));
}


