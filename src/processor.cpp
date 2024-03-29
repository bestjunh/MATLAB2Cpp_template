#include "processor.h"


processor::processor(int nch_, int out_nch_, int rate_, int frame_, int shift_)
{
	nch = nch_;
	out_nch = out_nch_;
	rate = rate_;
	frame = frame_;
	shift = shift_;


	stft_in = new STFT(nch, frame, shift);
	stft_out = new STFT(out_nch, frame, shift);


	data = new double* [nch];
	for (int i = 0; i < nch; i++) {
		data[i] = new double[frame + 2];
		memset(data[i], 0, sizeof(double) * (frame + 2));
	}


	output_data = new double* [out_nch]; // tmp nch
	for (int i = 0; i < out_nch; i++) {
		output_data[i] = new double[frame + 2];
		memset(output_data[i], 0, sizeof(double) * (frame + 2));
	}


#ifdef _DEBUG_TXT_		
	LRT_TXT = new std::ofstream * [nTarget];
	for (int i = 0; i < nTarget; i++) {
		LRT_TXT[i] = new std::ofstream("../output/LRT_" + std::to_string(i) + ".txt");
	}
#endif

}
processor::~processor() {

	for (int i = 0; i < nch; i++)
		delete[] data[i];
	delete[] data;


	for (int i = 0; i < out_nch; i++)
		delete[] output_data[i];
	delete[] output_data;

	delete stft_in;
	delete stft_out;


#ifdef _DEBUG_TXT_			
	for (int i = 0; i < nTarget; i++) {
		delete[] LRT_TXT[i];
	}
	delete[] LRT_TXT;
#endif
}
void processor::process(short* buf_in, short* buf_out) {

	// STFT
	stft_in->stft(buf_in, shift * nch, data);

	// Process
	copy_to_output(data);

	// ISTFT
	stft_out->istft(output_data, buf_out);


#ifdef _DEBUG_TXT_
	if (LRT_TXT[0]->is_open()) {
		for (int i = 0; i < nTarget; i++) {
			*LRT_TXT[i] << std::to_string(lrt[i]->LRT);
			*LRT_TXT[i] << "\n";
		}

	}

#endif
}

void processor::output_data_zero() {
	for (int ch = 0; ch < nch; ch++) {
		for (int k = 0; k < frame + 2; k++)
			output_data[ch][k] = 0.0;
	}
}

void processor::copy_to_output(double** input) {
	for (int ch = 0; ch < nch; ch++) {
		for (int k = 0; k < frame + 2; k++)
			output_data[ch][k] = input[ch][k];
	}
}