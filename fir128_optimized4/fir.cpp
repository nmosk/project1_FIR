/*
	Filename: fir.cpp
		FIR lab wirtten for WES/CSE237C class at UCSD.
		Match filter
	INPUT:
		x: signal (chirp)

	OUTPUT:
		y: filtered output

*/

#include "fir.h"

void fir (
  data_t *y,
  data_t x
  )
{

	//#pragma HLS pipeline ii=110


	coef_t c[N] = {10, 11, 11, 8, 3, -3, -8, -11, -11, -10, -10, -10, -10, -10, -10, -10, -10, -10, -10, -10, -10, -10, -10, -10, -10, -10, -10, -10, -10, -10, -10, -10, -10, -11, -11, -8, -3, 3, 8, 11, 11, 10, 10, 10, 10, 10, 10, 10, 10, 11, 11, 8, 3, -3, -8, -11, -11, -10, -10, -10, -10, -10, -10, -10, -10, -11, -11, -8, -3, 3, 8, 11, 11, 10, 10, 10, 10, 10, 10, 10, 10, 11, 11, 8, 3, -3, -8, -11, -11, -10, -10, -10, -10, -10, -10, -10, -10, -11, -11, -8, -3, 3, 8, 11, 11, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10};
	
	// Write your code here
	static data_t my_reg[N];
#pragma HLS ARRAY_PARTITION variable=my_reg type=complete
	acc_t acc;
	int i;
	acc = 0;

	for (i = N-1; i > 0; i--){
#pragma HLS unroll factor=32
			my_reg[i] = my_reg[i - 1];
		}

	for (i = N-1; i > 0; i--){
#pragma HLS unroll factor=32
			acc += my_reg[i] * c[i];
		}
		acc += x * c[0];
		my_reg[0] = x;

	*y = acc;


}


