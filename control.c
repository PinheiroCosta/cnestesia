#include <stdio.h>
#include <math.h>


double nextSemitone(double frequency);
double previousSemitone(double frequency);
int pitch(double frequency);


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

