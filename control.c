#include <stdio.h>
#include <math.h>


double getSemitone(double frequency, int grade);
double nextSemitone(double frequency);
double previousSemitone(double frequency);
int pitch(double frequency);
int scaleOf(double frequency);


// return desired semitone of a frequency in Hz
double getSemitone(double frequency, int grade)
{
	double semitone = frequency * pow(2, (double) grade/12);

	return semitone;
}

// return the next semitone of a frequency in Hz
double nextSemitone(double frequency)
{
	/*	A4  = 440Hz; A5  = 880Hz
			A#4 = A4 * 2^(1/12)
			B4  = A4 * 2^(2/12)

			1/12 = 0.083333 */

	double semitone = pow(2, 0.083333);
	return frequency * semitone;
}

// return the previous semitone of a frequency in Hz
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

// Print a music scale of a input frequency
int scaleOf(double frequency) 
{

	double semitone = pow(2, 0.083333);			// a semiton distance
	int note;												// Musical notes of a scale
	char* grade[12] = {"1ª", "2ªm", "2ª", "3ªm", "3ª", "4ª", "4ª+", "5ª", "5ª+", "6ª", "7ªm", "7ª"};


	// print the music intervals and its frequency value
	printf("Interval\tFrequency\tNote\n");
	for (note=0;note<12;note++)
	{
		printf("%s\t\t%.2lf\t\t", \
						grade[note], getSemitone(frequency, note));
		pitch(getSemitone(frequency, note));

	}
	return 0;
}


