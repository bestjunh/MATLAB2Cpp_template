//#define _DEBUG_TXT_

#include "STFT.h"
#ifdef _DEBUG_TXT_	
#include <fstream>
#include <stdio.h>
#include <string>
#endif

class processor {
private:
	/* Set Parameter of Input */
	int nch;
	int out_nch;
	int rate;
	int frame;
	int shift;	

public:
	double** data; // Input STFT
	double** output_data; // Output STFT		
	
	
	// Class
	STFT* stft_in;
	STFT* stft_out;	

#ifdef _DEBUG_TXT_	
	std::ofstream **LRT_TXT;
#endif
	// Generator
	processor(int nch_, int out_nch_, int rate_, int frame_, int shift_);
	 ~processor();
	void process(short* buf_in, short* buf_out);
	void output_data_zero();
	void copy_to_output(double** input);


};

