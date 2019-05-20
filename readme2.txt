Before running Makefile type in the terminal following commands - 
export MKLROOT=~/intel/mkl/
and
export LD_LIBRARY_PATH=/opt/openBLAS/lib/
to set up path for libraries "mkl.h" and "cblas.h"

After this type in command "make" to compile in terminal, an executable file called subtask1 is made.

Function calling format is given below:

(for convolution matrix multiplication using mkl)   ./subtask1 convolution_matrix_mult matrix1.txt matrix1_numrows matrix2.txt matrix2_numrows mkl

(for convolution matrix multiplication using openblas)   ./subtask1 convolution_matrix_mult matrix1.txt matrix1_numrows matrix2.txt matrix2_numrows openblas

(for convolution matrix multiplication using pthread)   ./subtask1 convolution_matrix_mult matrix1.txt matrix1_numrows matrix2.txt matrix2_numrows pthread
 
(for Relu)   ./subtask1.out relu matrix1.txt matrix1_numrows (where matrix1.txt is the file name containing matrix values in column major order and matrix1_numrows is dimension of square matrix same follows for below formats)
(for Tanh)  ./subtask1.out tanh matrix1.txt matrix1_numrows
(for Max_pooling)  ./subtask1.out max_pooling matrix1.txt matrix1_numrows
(for Average_pooling)  ./subtask1.out average_pooling matrix1.txt matrix1_numrows
(for Softmax)  ./subtask1.out softmax vector1.txt vector_length
(for Sigmoid)  ./subtask1.out sigmoid vector1.txt vector_length
(for Convolution with padding)  ./subtask1.out convolution_with_padding matrix1.txt matrix1_numrows matrix2.txt matrix2_numrows padding_size
(for Convolution)  ./subtask1.out convolution matrix1.txt matrix1_numrows matrix2.txt matrix2_numrows
(for Convolution as matrix multiplication with padding)  ./subtask1.out convolution_matrix_mult_with_padding matrix1.txt matrix1_numrows matrix2.txt matrix2_numrows padding_size
(for Convolution as matrix multiplication)  ./subtask1.out convolution_matrix_mult matrix1.txt matrix1_numrows matrix2.txt matrix2_numrows

We have here assumed the size of filter in average and max pooling to be 2x2.

Our gnu plots has time taken for convolution(matrix multiplication based) of matrices using all three functions - pthread, mkl and openblas.
We have considered the matrix sizes to be 60x60 , 100x100 , 140x140 , 180x180 and kernel size 5x5 and for boxplots we have taken 6 different random matrices for each different size of matrix. 
Our pthread implementation sometimes might not complete last thread before joining giving 0s at the end, but most times it gives correct output.You can check by running it more than once if at first it is giving zeroes to get desired result.
