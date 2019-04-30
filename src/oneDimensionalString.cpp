#include "oneDimensionalString.h"
#include <stdio.h>
#include <math.h>

#define WORD u_int16_t 
#define DWORD u_int32_t
 
//sizeof(WORD) = 16 bits = 2 bytes
//sizeof(DWORD) = 32 bits = 4 bytes

//The base of the code have been copied from http://www.cyberforum.ru/cpp-beginners/thread1703666.html#post8983232
 
struct wav_header_t
{
	char rId[4]; //"RIFF" = 0x46464952
	DWORD rLen; //28 [+ sizeof(wExtraFormatBytes) + wExtraFormatBytes] + sum(sizeof(chunk.id) + sizeof(chunk.size) + chunk.size)
	char wId[4]; //"WAVE" = 0x45564157
	char fId[4]; //"fmt " = 0x20746D66
	DWORD fLen; //16 [+ sizeof(wExtraFormatBytes) + wExtraFormatBytes]
	WORD wFormatTag;
	WORD nChannels;
	DWORD nSamplesPerSec;
	DWORD nAvgBytesPerSec;
	WORD nBlockAlign;
	WORD wBitsPerSample;
	//[WORD wExtraFormatBytes;]
	//[Extra format bytes]
};
 
struct chunk_t
{
	char id[4]; //"data" = 0x61746164
	DWORD size;
	//Chunk data bytes
};
 
int oneDimensionalString::playToWav (std::string outputFileName, float soundReceiverCoordinate, float time_s)
{
	WORD nChannels = 1;
	DWORD nSamplesPerSec = 44100;
	WORD wBitsPerSample = 16;
 
	int samples_count = time_s * nSamplesPerSec;
 
	chunk_t chunk;
	*(DWORD *)&chunk.id = 0x61746164;
	chunk.size = samples_count * wBitsPerSample / 8;
 
	wav_header_t header;
	*(DWORD *)&header.rId = 0x46464952;
	header.rLen = 36 + chunk.size;
	*(DWORD *)&header.wId = 0x45564157;
	*(DWORD *)&header.fId = 0x20746D66;
	header.fLen = 16;
	header.wFormatTag = 1;
	header.nChannels = nChannels;
	header.nSamplesPerSec = nSamplesPerSec;
	header.wBitsPerSample = wBitsPerSample;
	header.nBlockAlign = header.nChannels * header.wBitsPerSample / 8;
	header.nAvgBytesPerSec = header.nSamplesPerSec * header.nBlockAlign;
 
	int amplitude = 0x7FFF;
	int frequency = 250; //Hz
	float T = 1.0 / frequency;
 
	FILE *f = fopen(outputFileName.c_str(), "wb");
	fwrite(&header, sizeof(header), 1, f);
	fwrite(&chunk, sizeof(chunk), 1, f);
	for (int i = 0; i < samples_count; i++)
	{
		WORD value = amplitude * calculate( ((float) i) / nSamplesPerSec, soundReceiverCoordinate).real() / 100;
		fwrite(&value, 2, 1, f);
	}
	fclose(f);
}
