#include "function.h"
#include "convolution_mkl.h"
#include "convolution_openBlas.h"
#include "convolution_pthread.h"
#include <iostream>
#include <cmath>
#include <cstdlib>
#include <vector>
#include <fstream>
#include <pthread.h>
#include <cblas.h>
using namespace std;

void display(float **s,int size){
    for (int i=0;i<size;i++){
        for(int j=0;j<size;j++){
            cout<<s[i][j]<<" ";
        }
        cout<<endl;
    }
}

int main(int argc,char* argv[])
{
	if(argc==1){
		cout<<"Please enter appropriate function"<<endl;
		return 0;
	}
	string function_line=argv[1];
	ifstream infile;
	
        if(function_line=="relu"){
		string matrix_file=argv[2];
		infile.open(matrix_file);
                if(argc!=4){
                    cout<< "Wrong format,please check readme !"<< endl;
                    return 0;
                }
		int r=stoi(argv[3]);
		if(!infile.is_open()){
                    cout<< "Error opening file"<< endl;
                    return 0;
                }
		float **a;
    		a=new float*[r];
    		for(int i=0;i<r;i++)
        		a[i]=new float[r];
		for(int i=0;i<r;i++){
         		for(int j=0;j<r;j++){
				string y;
            			infile >> y;
				a[j][i]=stof(y);
			}
		}
		infile.close();
		relu(r,a);
		//answer in a
                display(a,r);
	}
	
	else if(function_line=="tanh"){
		string matrix_file=argv[2];
		infile.open(matrix_file);
                if(argc!=4){
                    cout<< "Wrong format,please check readme !"<< endl;
                    return 0;
                }
		int r=stoi(argv[3]);
		if(!infile.is_open()){
                    cout<< "Error opening file"<< endl;
                    return 0;
                }
		float **a;
    		a=new float*[r];
    		for(int i=0;i<r;i++)
        		a[i]=new float[r];
		for(int i=0;i<r;i++){
         		for(int j=0;j<r;j++){
            			string y;
            			infile >> y;
				a[j][i]=stof(y);
			}
		}
		infile.close();
		tanh(r,a);
		//answer in a
                display(a,r);
	}
	else if(function_line=="max_pooling"){
		string matrix_file=argv[2];
		infile.open(matrix_file);
                if(argc!=4){
                    cout<< "Wrong format,please check readme !"<< endl;
                    return 0;
                }
		int r=stoi(argv[3]);
		if(!infile.is_open()){
                    cout<< "Error opening file"<< endl;
                    return 0;
                }
		float **a;
    		a=new float*[r];
    		for(int i=0;i<r;i++)
        		a[i]=new float[r];
		for(int i=0;i<r;i++){
         		for(int j=0;j<r;j++){
            			string y;
            			infile >> y;
				a[j][i]=stof(y);
			}
		}
		infile.close();
		float **b;
    		if(r%2==0){
        		b=new float*[r/2];
        		for(int i=0;i<r/2;i++)
            			b[i]=new float[r/2];
		}
		else{
			b=new float*[((int)(r/2) + 1)];
        		for(int i=0;i<((int)(r/2) + 1);i++)
            			b[i]=new float[((int)(r/2) + 1)];
		}	
		max_pooling(r,a,b);
		//answer in b
                if(r%2==0)
                    display(b,r/2);
                else
                    display(b,int(r/2)+1);
	}
	else if(function_line=="average_pooling"){
		string matrix_file=argv[2];
                infile.open(matrix_file);
		if(argc!=4){
                    cout<< "Wrong format,please check readme !"<< endl;
                    return 0;
                }
		int r=stoi(argv[3]);
		if(!infile.is_open()){
                    cout<< "Error opening file"<< endl;
                    return 0;
                }
		float **a;
    		a=new float*[r];
    		for(int i=0;i<r;i++)
        		a[i]=new float[r];
		for(int i=0;i<r;i++){
         		for(int j=0;j<r;j++){
            			string y;
            			infile >> y;
				a[j][i]=stof(y);
			}
		}
		infile.close();
		float **b;
    		if(r%2==0){
        		b=new float*[r/2];
        		for(int i=0;i<r/2;i++)
            			b[i]=new float[r/2];
		}
		else{
			b=new float*[((int)(r/2) + 1)];
        		for(int i=0;i<((int)(r/2) + 1);i++)
            			b[i]=new float[((int)(r/2) + 1)];
		}	
		average_pooling(r,a,b);
		//answer in b
                if(r%2==0)
                    display(b,r/2);
                else
                    display(b,int(r/2)+1);
	}
	else if(function_line=="softmax"){
		string vector_file=argv[2];
                infile.open(vector_file);
                if(argc!=4){
                    cout<< "Wrong format,please check readme !"<< endl;
                    return 0;
                }
		int r=stoi(argv[3]);
		if(!infile.is_open()){
                    cout<< "Error opening file"<< endl;
                    return 0;
                }
		vector <float> g;
                float y;
                string k;
		for(int i=0;i<r;i++){
            		infile >> k;
			y=stof(k);
			g.push_back(y);
		}
		infile.close();
		vector<float> k1 = softmax(g);
		//answer in k1
                int e=k1.size();
                for(int p=0;p<e;p++)
                    cout<<k1[p]<<" ";
                cout<<endl;
	}
	else if(function_line=="sigmoid"){
		string vector_file=argv[2];
		infile.open(vector_file);
                if(argc!=4){
                    cout<< "Wrong format,please check readme !"<< endl;
                    return 0;
                }
		int r=stoi(argv[3]);
		if(!infile.is_open()){
                    cout<< "Error opening file"<< endl;
                    return 0;
                }
		vector <float> g;
		for(int i=0;i<r;i++){
			string k;
            		infile >> k;
			float y=stof(k);
			g.push_back(y);
		}
		infile.close();
		vector<float> k1 = sigmoid(g);
		//answer in k1
                int e=k1.size();
                for(int p=0;p<e;p++)
                    cout<<k1[p]<<" ";
                cout<<endl;
	}
	else if(function_line=="convolution_with_padding"){
            string matrix_file=argv[2];
		infile.open(matrix_file);
		if(argc!=7){
                    cout<< "Wrong format,please check readme !"<< endl;
                    return 0;
                }
		int c1=stoi(argv[3]);
		if(!infile.is_open()){
                    cout<< "Error opening file"<< endl;
                    return 0;
                }
		float **a;
    		a=new float*[c1];
    		for(int i=0;i<c1;i++)
        		a[i]=new float[c1];
		for(int i=0;i<c1;i++){
         		for(int j=0;j<c1;j++){
            			string y;
            			infile >> y;
				a[j][i]=stof(y);
			}
		}
		infile.close();
		string matrix_file2=argv[4];
		int c2=stoi(argv[5]);
                ifstream infile2;
		infile2.open(matrix_file2);
                if(!infile2.is_open()){
                    cout<< "Error opening file"<< endl;
                    return 0;
                }
		float **b;
    		b=new float*[c2];
    		for(int i=0;i<c2;i++)
        		b[i]=new float[c2];
		for(int i=0;i<c2;i++){
         		for(int j=0;j<c2;j++){
            			string y;
            			infile2 >> y;
				b[j][i]=stof(y);
			}
		}
		infile2.close();
		int p=stoi(argv[6]);
		float **d;
                d=new float*[c1+2*p-c2+1];
                for(int i=0;i<c1+2*p-c2+1;i++)
                    d[i]=new float[c1+2*p-c2+1];
                convolution_with_padding(a,c1,b,c2,p,d);
                //final answer in d
                display(d,(c1+2*p-c2+1));
	}
	
	else if(function_line=="convolution"){
            string matrix_file=argv[2];
		infile.open(matrix_file);
		if(argc!=6){
                    cout<< "Wrong format,please check readme !"<< endl;
                    return 0;
                }
		int c1=stoi(argv[3]);
		if(!infile.is_open()){
                    cout<< "Error opening file"<< endl;
                    return 0;
                }
		float **a;
    		a=new float*[c1];
    		for(int i=0;i<c1;i++)
        		a[i]=new float[c1];
		for(int i=0;i<c1;i++){
         		for(int j=0;j<c1;j++){
            			string y;
            			infile >> y;
				a[j][i]=stof(y);
			}
		}
		infile.close();
		string matrix_file2=argv[4];
		int c2=stoi(argv[5]);
                ifstream infile2;
		infile2.open(matrix_file2);
                if(!infile2.is_open()){
                    cout<< "Error opening file"<< endl;
                    return 0;
                }
		float **b;
    		b=new float*[c2];
    		for(int i=0;i<c2;i++)
        		b[i]=new float[c2];
		for(int i=0;i<c2;i++){
         		for(int j=0;j<c2;j++){
            			string y;
            			infile2 >> y;
				b[j][i]=stof(y);
			}
		}
		infile2.close();
		float **c;
                c=new float*[c1-c2+1];
                for(int i=0;i<(c1-c2+1);i++)
                    c[i]=new float[c1-c2+1];
                convolution(a,c1,b,c2,c);
                //final answer in c
                display(c,(c1-c2+1));
	}
	
	else if(function_line=="convolution_matrix_mult_with_padding"){
                string matrix_file=argv[2];
                infile.open(matrix_file);
		if(argc!=7){
                    cout<< "Wrong format,please check readme !"<< endl;
                    return 0;
                }
		int c1=stoi(argv[3]);
		if(!infile.is_open()){
                    cout<< "Error opening file"<< endl;
                    return 0;
                }
		float **a;
    		a=new float*[c1];
    		for(int i=0;i<c1;i++)
        		a[i]=new float[c1];
		for(int i=0;i<c1;i++){
         		for(int j=0;j<c1;j++){
            			string y;
            			infile >> y;
				a[j][i]=stof(y);
			}
		}
		infile.close();
		string matrix_file2=argv[4];
		int c2=stoi(argv[5]);
                ifstream infile2;
		infile2.open(matrix_file2);
                if(!infile2.is_open()){
                    cout<< "Error opening file"<< endl;
                    return 0;
                }
		float **b;
    		b=new float*[c2];
    		for(int i=0;i<c2;i++)
        		b[i]=new float[c2];
		for(int i=0;i<c2;i++){
         		for(int j=0;j<c2;j++){
            			string y;
            			infile2 >> y;
				b[j][i]=stof(y);
			}
		}
		infile2.close();
		int p=stoi(argv[6]);
		float **final_ans2;
                final_ans2=new float*[(c1+2*p-c2+1)];
                for(int i=0;i<(c1+2*p-c2+1);i++)
                    final_ans2[i]=new float[c1+2*p-c2+1];
                convolution_matrix_mult_with_padding(a,c1,b,c2,p,final_ans2);
                display (final_ans2,(c1+2*p-c2+1));
	}
        
	else if(function_line=="convolution_matrix_mult"){
               
                string matrix_file=argv[2];
		infile.open(matrix_file);
		if(argc!=6 && argc!=7){
                    cout<< "Wrong format,please check readme !"<< endl;
                    return 0;
                }
		int c1=stoi(argv[3]);
		if(!infile.is_open()){
                    cout<< "Error opening file"<< endl;
                    return 0;
                }
		float **a;
    		a=new float*[c1];
    		for(int i=0;i<c1;i++)
        		a[i]=new float[c1];
		for(int i=0;i<c1;i++){
         		for(int j=0;j<c1;j++){
            			string y;
            			infile >> y;
				a[j][i]=stof(y);
			}
		}
		infile.close();
		string matrix_file2=argv[4];
		int c2=stoi(argv[5]);
                ifstream infile2;
		infile2.open(matrix_file2);
                if(!infile2.is_open()){
                    cout<< "Error opening file"<< endl;
                    return 0;
                }
		float **b;
    		b=new float*[c2];
    		for(int i=0;i<c2;i++)
        		b[i]=new float[c2];
		for(int i=0;i<c2;i++){
         		for(int j=0;j<c2;j++){
            			string y;
            			infile2 >> y;
				b[j][i]=stof(y);
			}
		}
		infile2.close();
                
                if(argc!=7){
                    float **final_ans;
                    final_ans=new float*[(c1-c2+1)];
                    for(int i=0;i<(c1-c2+1);i++)
                        final_ans[i]=new float[c1-c2+1];
                    convolution_matrix_mult(a,c1,b,c2,final_ans);
                    display(final_ans,(c1-c2+1));
                }
                else{               
                
                    float* q;
                    int l=0;
                    q=new float[c2*c2];
                    for(int i=(c2-1);i>=0;i--){
                        for(int j=(c2-1);j>=0;j--){
                            q[l]=b[i][j];
                            l++;
                        }
                    }
                                
                                float** c;
                    c=new float*[(c1-c2+1)*(c1-c2+1)];
                    for(int i=0;i<(c1-c2+1)*(c1-c2+1);i++)
                        c[i]=new float[c2*c2];
                    int g=0;
                    int r=0;
                    for(int i=0;i<(c1-c2+1);i++){
                        for(int j=0;j<(c1-c2+1);j++){
                            r=0;
                            for(int w=i;w<i+c2;w++){
                                for(int t=j;t<j+c2;t++){
                                c[g][r]=a[w][t];
                                r++;
                                }
                            }
                        g++;
                        }
                    }
                    float** final_ans;
                    final_ans=new float*[(c1-c2+1)];
                    for(int i=0;i<(c1-c2+1);i++)
                        final_ans[i]=new float[c1-c2+1];
                    
                    string method=argv[6];
                    if(method=="pthread"){
                    //cout<<"ab"; 
                        convolution_pthread(c,q,final_ans,((c1-c2+1)*(c1-c2+1)),(c2*c2));
                        
                    }
                    
                    
                    else if(method=="mkl"){
                        
                        float* y=new float[(c1-c2+1)*(c1-c2+1)*c2*c2];
                        int k=0;
                        for(int i=0;i<(c1-c2+1)*(c1-c2+1);i++){
                        for(int j=0;j<c2*c2;j++){
                                y[k]=c[i][j];
                                k++;
                            }
                        }
                        convolution_mkl(y,(c1-c2+1)*(c1-c2+1),c2*c2,q,final_ans);
                    }
                    else if(method=="openblas"){
                        float* y=new float[(c1-c2+1)*(c1-c2+1)*c2*c2];
                        int k=0;
                        
                        for(int i=0;i<(c1-c2+1)*(c1-c2+1);i++){
                        for(int j=0;j<c2*c2;j++){
                                y[k]=c[i][j];
                                k++;
                            }
                        }
                        convolution_openBlas(y,(c1-c2+1)*(c1-c2+1),c2*c2,q,false,false,final_ans);
                    }
                    else{
                        cout<<"Please select one of the three ways of matrix multiplication"<<endl;
                        return 0;
                    }
                    display(final_ans,(c1-c2+1));
                    
                }
                
                
	}
	
	else{
		cout<<"Please enter appropriate function name"<<endl;
	}
	return 0;
}
