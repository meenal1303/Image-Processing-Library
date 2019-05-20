#include <iostream>
#include <cmath>
#include <cstdlib>
#include <vector>
#include <fstream>
using namespace std;

void tanh(int r,float **a)
{
	 for(int i=0;i<r;i++){
         	for(int j=0;j<r;j++){
            		float x=a[j][i];
            		a[j][i]=(float)(exp(2*x)-1)/(exp(2*x)+1);
		}
	}
}
