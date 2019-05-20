#include "function.h"
#include <iostream>
#include <cmath>
#include <cstdlib>
#include <vector>
#include <fstream>
using namespace std;

void swap(float *x, float *y){
	float temp;
	temp=*x;
	*x=*y;
	*y=temp;
}

float cal(int i,int j,int c2,float **a,float **b){
    float count = 0.0;
    for(int p=i;p<i+c2;p++){
        for(int t=j;t<j+c2;t++){
            count=count+a[p][t]*b[p-i][t-j];
        } 
    }
    return count;
}

void convolution(float **a,int c1,float **b, int c2, float **c){
    for(int i=0;i<int(c2/2);i++){
		for(int j=0;j<c2;j++){
			swap(&b[i][j],&b[c2-1-i][j]);
		}
	}
	for(int j=0;j<int(c2/2);j++){
		for(int i=0;i<c2;i++){
			swap(&b[i][j],&b[i][c2-1-j]);
		}
	}
    for(int i=0;i<(c1-c2+1);i++){
        for(int j=0;j<(c1-c2+1);j++){
            c[i][j]=cal(i,j,c2,a,b);
        }
    }   
}
