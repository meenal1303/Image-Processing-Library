# Image-Processing-Library

Implement the following functions using 32 bit float as datatype.

    1.convolution of a square input matrix and a square kernel, both matrices of any size and the kernel smaller than the input
        a.)with and without input padding to maintain or reduce the size of the input matrix
        b.)implement the function both as convolution and as matrix multiplication
    2.non-linear activations of an input matrix of any size with relu and tanh functions on individual matrix elements.
    3.subsampling of square input matrices of any size with max pooling and average pooling functions
    4.converting a vector of random floats to a vector of probabilities with softmax and sigmoid functions
    
    
Accelerate matrix multiplication speed for convolution in your previous implementation with

    a.)linear algebra libraries mkl and openblas. Are these libraries faster than your own C++ matrix multiplication?
    b.)pthreads. Check for correct computation of the matrix multiplication results and synchronization issues with multiple threads if any. 
    
Implement LeNet (paper, software architecture) inference for MNIST digit recognition stitching together the functions you have written so far.
