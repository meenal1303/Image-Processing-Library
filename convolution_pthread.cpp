// CPP Program to multiply two matrix using pthreads 
#include "convolution_pthread.h"
#include <iostream>
#include <cmath>
#include <cstdlib>
#include <vector>
#include <fstream>
#include <pthread.h>
using namespace std; 

// maximum size of matrix 
// maximum number of threads 
int MAX;
int MAX2;
float **matA;
float *matB;
float *matC;
int step_i = 0; 

void convert2(float *ans, float **final_ans,int size){
    for(int i=0;i<size*size;i++){
        int l=(i)/size;
        int m=(i)%size;
        final_ans[l][m]=ans[i];
    }
}

void* multi(void* arg) 
{ 
        
	int core = step_i++;
        
	// Each thread computes 1/4th of matrix multiplication 
	for (int i = (core*MAX)/4 ; i < ((core + 1)*MAX)/4; i++) {
                matC[i]=0.0;
                for (int k = 0; k < MAX2; k++){
                        matC[i]+= matA[i][k]*matB[k];
                }
        }
        
} 

// Driver Code 
void convolution_pthread(float** A, float* B,float** final_ans, int n,int m) 
{ 
	// declaring four threads
        MAX=n;
        MAX2=m;
        matA=new float*[n];
        for(int i=0;i<n;i++)
            matA[i]=new float[m];
        matB=new float[m];
        
        for(int i=0;i<n;i++)
            for(int j=0;j<m;j++)
                matA[i][j]=A[i][j];
        for(int i=0;i<m;i++)
            matB[i]=B[i];
        
        matC=new float[n];
        
	pthread_t threads[4];

	// Creating four threads, each evaluating its own part 

		int* p;
		pthread_create(&threads[0], NULL, multi, (void*)(p)); 
                pthread_create(&threads[1], NULL, multi, (void*)(p)); 
                pthread_create(&threads[2], NULL, multi, (void*)(p)); 
                pthread_create(&threads[3], NULL, multi, (void*)(p)); 
	
       
	// joining and waiting for all threads to complete 
		pthread_join(threads[0],NULL);
                pthread_join(threads[1],NULL);
                pthread_join(threads[2],NULL);
                pthread_join(threads[3],NULL);
        
         
        convert2(matC,final_ans,sqrt(n));
	
} 
