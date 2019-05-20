#include "function.h"
#include <iostream>
#include <cmath>
#include <cstdlib>
#include <vector>
#include <fstream>
using namespace std;

void convert1(float *ans, float **final_ans,int size){
    for(int i=0;i<size*size;i++){
        int l=(i)/size;
        int m=(i)%size;
        final_ans[l][m]=ans[i];
    }
}

void matrix_mult1(float **a,float *q,float *ans,int c1,int c2)
{
    
    int s=0;
    for(int l=0;l<(c1-c2+1)*(c1-c2+1);l++){
        float count=0.0;
        for(int n=0;n<c2*c2;n++){
            count=count+a[l][n]*q[n];
        }
        ans[l]=count;
    }
}

void convolution_matrix_mult_with_padding(float **a,int c1,float **b, int c2,int p,float **final_ans2){
    float *q;
    int l=0;
    q=new float[c2*c2];
    for(int i=c2-1;i>=0;i--){
        for(int j=c2-1;j>=0;j--){
            q[l]=b[i][j];
            l++;
        }
    }
    float **k;
    k=new float*[c1+2*p];
    for(int i=0;i<c1+2*p;i++)
        k[i]=new float[c1+2*p];
    for(int i=0;i<c1+2*p;i++){
        for(int j=0;j<c1+2*p;j++){
            if(i<p || j<p || i>=c1+p || j>=c1+p){
                k[i][j]=0.0;
            }
            else{
                k[i][j]=a[i-p][j-p];
            }
        }
    }
    float **d;
    d=new float*[(c1+2*p-c2+1)*(c1+2*p-c2+1)];
    for(int i=0;i<(c1+2*p-c2+1)*(c1+2*p-c2+1);i++)
        d[i]=new float[c2*c2];
    
    int z=0;
    int u=0;
    for(int i=0;i<(c1+2*p-c2+1);i++){
        for(int j=0;j<(c1+2*p-c2+1);j++){
            z=0;
            for(int w=i;w<i+c2;w++){
                for(int t=j;t<j+c2;t++){
                  d[u][z]=k[w][t];
                  z++;
                }
            }
        u++;
        }
    }   

    float *ans2;
    ans2=new float[(c1+2*p-c2+1)*(c1+2*p-c2+1)];

    matrix_mult1(d,q,ans2,c1+2*p,c2);
    
    convert1(ans2,final_ans2,c1+2*p-c2+1);
    
}
