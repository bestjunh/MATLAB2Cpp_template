#ifdef _WIN32
#define _CRTDBG_MAP_ALLOC
#include <crtdbg.h>
#endif


#include "WAV.h"
#include <string>
#include <filesystem>
/* Inlcude Algorithm source here */
#include "processor.h"


int main() {

	int n_channel = 6;
	int out_n_channel = 6;
	int sr = 16000;
	int n_fft = 1024;
	int n_hop = 256;	

	/* Define Algorithm Class here */
	processor proc(n_channel, out_n_channel, sr, n_fft, n_hop);	

#ifdef _WIN32
	_CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);
	//_crtBreakAlloc = 1286;
#endif

	int length;
	WAV input(n_channel, sr);
	WAV output(out_n_channel, sr);

	short* buf_in = new short[n_channel * n_hop];
	short* buf_out = new short[out_n_channel * n_hop];

	std::string InputFileName = "F01_22GC010A_BUS";
	input.OpenFile("../input/" + InputFileName + ".wav");
	output.NewFile("../output/" + InputFileName + "_output.wav");	

	while (!input.IsEOF()) {
		length = input.ReadUnit(buf_in, n_hop * n_channel);
		/* Run Process here */
		proc.process(buf_in, buf_out);
		output.Append(buf_out, n_hop * out_n_channel);

	}
	
	output.Finish();
	input.Finish();

	delete[] buf_in;
	delete[] buf_out;
	
	return 0;
}