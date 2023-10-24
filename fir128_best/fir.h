/*
	Filename: fir.h
		Header file
		FIR lab wirtten for WES/CSE237C class at UCSD.

*/
#ifndef FIR_H_
#define FIR_H_

const int N=128;

typedef short coef_t;
typedef short data_t;
typedef short acc_t;

void fir (
  data_t *y,
  data_t x
  );

#endif
