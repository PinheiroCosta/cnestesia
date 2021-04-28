#include <stdio.h>
#include <math.h>


double nextSemitone(double frequency);
double previousSemitone(double frequency);
int pitch(double frequency);
int scaleOf(double frequency);

// return the next semiton of a frequency in Hz
double nextSemitone(double frequency)
{
	/*	A4  = 440Hz; A5  = 880Hz
			A#4 = A4 * 2^(1/12)
			B4  = A4 * 2^(2/12)

			1/12 = 0.083333 */

	double semitone = pow(2, 0.083333);
	return frequency * semitone;
}

// return the previous semiton of a frequency in Hz
double previousSemitone(double frequency)
{
	double semitone = pow(2, 0.083333);
	return frequency / semitone;
}

// prints the musical notation of a frequency in Hz
int pitch(double frequency)
{
	double A4 = 440;
	double C0 = A4 * pow(2, -4.75);
	char* name[12] = {"C", "C#", "D", "D#", "E", "F", "F#", "G", "G#", "A", "A#", "B"};

	double hz = round(12*log2(frequency/C0));
	int octave = hz / 12;
	int letter = (int) hz % 12;

	printf("%s%d\n", name[letter], octave);

	return 0;
}

// Print a music scale starting from A's frequency. A = 440.00
int scaleOf(double frequency) 
{

	double semitone = pow(2, 0.083333);			// a semiton distance
	int note;												// Musical notes of a scale


	// print the music intervals and its frequency value
	printf("Interval\tFrequency\tNote\n");
	for (note=1;note<8;note++)
	{
		if (note == 3 | note == 7)
		{
			printf("%dª\t-\t%.2f\t-\t", note, frequency);
			pitch(frequency);
			frequency *= semitone;

		}else 
		{
			printf("%dª\t-\t%.2f\t-\t", note, frequency);
			pitch(frequency);
			frequency *= semitone;
			printf("%dªm\t-\t%.2f\t-\t", note+1, frequency);
			pitch(frequency);
		}
		frequency *= semitone;
	}

	return 0;
}
