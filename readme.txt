Type in command "make" to compile in terminal, an executable  file called subtask1.out is made.
Function calling format is given below:
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
