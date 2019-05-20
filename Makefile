CC=g++
CFLAGS=-g -Wall
RM=/bin/rm -f

all:	subtask1
average_pooling.o:  average_pooling.cpp
	${CC} ${CFLAGS} -c average_pooling.cpp
convolution.o:  convolution.cpp
	${CC} ${CFLAGS} -c convolution.cpp
max_pooling.o:  max_pooling.cpp
	${CC} ${CFLAGS} -c max_pooling.cpp
convolution_matrix_mult.o:  convolution_matrix_mult.cpp
	${CC} ${CFLAGS} -c convolution_matrix_mult.cpp
convolution_matrix_mult_with_padding.o:  convolution_matrix_mult_with_padding.cpp
	${CC} ${CFLAGS} -c convolution_matrix_mult_with_padding.cpp
convolution_with_padding.o:  convolution_with_padding.cpp
	${CC} ${CFLAGS} -c convolution_with_padding.cpp
relu.o:  relu.cpp
	${CC} ${CFLAGS} -c relu.cpp
tanh.o:  tanh.cpp
	${CC} ${CFLAGS} -c tanh.cpp
sigmoid.o:  sigmoid.cpp
	${CC} ${CFLAGS} -c sigmoid.cpp
softmax.o:  softmax.cpp
	${CC} ${CFLAGS} -c softmax.cpp
subtask1.o:  subtask1.cpp
	${CC} ${CFLAGS} -c subtask1.cpp
subtask1:subtask1.o average_pooling.o convolution.o convolution_matrix_mult.o convolution_matrix_mult_with_padding.o convolution_with_padding.o max_pooling.o relu.o sigmoid.o softmax.o tanh.o
	${CC} ${CFLAGS} -o subtask1 subtask1.o average_pooling.o convolution.o convolution_matrix_mult.o convolution_matrix_mult_with_padding.o convolution_with_padding.o max_pooling.o relu.o sigmoid.o softmax.o tanh.o
clean:
	${RM} *.o subtask1
