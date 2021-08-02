#include <stdio.h>
#include <math.h>


const double TUNE = 440;


//----------------- List of functions -------------------

int pitch(double frequency);
int scaleOf(double frequency);
double colorFrequencyOf(double soundFrequency);
double getSemitone(double frequency, int grade);
double nextSemitone(double frequency);
double previousSemitone(double frequency);

// ------------------------------------------------------


double getSemitone(double frequency, int grade)
// return desired semitone of a frequency in Hz
{
		double semitone = frequency * pow(2, (double) grade/12);
		return semitone;
}		// ------------- End of getSemitone() --------------------

double semitoneInterval()
// return one semitone interval of a given frequency
{
		return pow(2, 0.083333);
}		// -------- End of semitoneInterval() ----------

double nextSemitone(double frequency)
// return the next semitone of a frequency in Hz
{
		/*	A4  = 440Hz; A5  = 880Hz
			A#4 = A4 * 2^(1/12)
			B4  = A4 * 2^(2/12)

			1/12 = 0.083333 */

		return frequency * semitoneInterval();
}		// -------------- End of nextSemitone() -----------------

double previousSemitone(double frequency)
// return the previous semiton of a frequency in Hz
{
		return frequency / semitoneInterval();
}		// ------------- End of previousSemitone() --------------

int pitch(double frequency)
// prints the musical notation of a frequency in Hz
{
		double C0 = TUNE * pow(2, -4.75);
		char* name[12] = {
			"C", "C#", "D", "D#", 
			"E", "F", "F#", "G", 
			"G#", "A", "A#", "B"
		};

		double hz = round(12*log2(frequency/C0));
		int octave = hz / 12;
		int letter = (int) hz % 12;

		printf("%s%d\n", name[letter], octave);

		return 0;
}		// ------------------ End of pitch() --------------------

int scaleOf(double frequency) 
// Print a music scale of a input frequency
{
		int note;		// Musical notes of a scale
		char* grade[12] = {
			"1ª", "2ªm", "2ª", "3ªm", 
			"3ª", "4ª", "4ª+", "5ª", 
			"5ª+", "6ª", "7ªm", "7ª"
		};

		// print the music intervals and its frequency value
		printf("Interval\tFrequency\tNote\n");
		for (note=0;note<12;note++)
		{
			printf("%s\t\t%.2lf\t\t", grade[note], 
					getSemitone(frequency, note));
			pitch(getSemitone(frequency, note));

		}
		return 0;
}		// ------------------- End of scaleOf() ----------------------


