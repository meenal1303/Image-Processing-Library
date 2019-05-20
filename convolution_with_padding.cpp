#include "function.h"
#include <iostream>
#include <cmath>
#include <cstdlib>
#include <vector>
#include <fstream>
using namespace std;

void swap1(float *x, float *y){
	float temp;
	temp=*x;
	*x=*y;
	*y=temp;
}
float cal1(int i,int j,int c2,float **a,float **b){
    float count = 0.0;
    for(int p=i;p<i+c2;p++){
        for(int t=j;t<j+c2;t++){
            count=count+a[p][t]*b[p-i][t-j];
        } 
    }
    return count;
}
void convolution_with_padding(float **a,int c1,float **b, int c2,int p, float **d){
    for(int i=0;i<int(c2/2);i++){
		for(int j=0;j<c2;j++){
			swap1(&b[i][j],&b[c2-1-i][j]);
		}
	}
	for(int j=0;j<int(c2/2);j++){
		for(int i=0;i<c2;i++){
			swap1(&b[i][j],&b[i][c2-1-j]);
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
    
    
    for(int i=0;i<(c1+2*p-c2+1);i++){
        for(int j=0;j<(c1+2*p-c2+1);j++){
            d[i][j]=cal1(i,j,c2,k,b);
        }
    }    
}
