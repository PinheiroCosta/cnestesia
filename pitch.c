#include <stdio.h>
#include <math.h>

int pitch(double frequency);

// prints the music notation of a given frequency
int main()
{
		double freq = 7592.13;
		pitch(freq);
		return 0;
}

int pitch(double frequency)
{
	double A4 = 440;
	double C0 = A4 * pow(2, -4.75);
	char* name[12] = {"C", "C#", "D", "D#", "E", "F", "F#", "G", "G#", "A", "A#", "B"};
	
	double hz = round(12*log2(frequency/C0));
	int octave = hz / 12;
	int letter = (int) hz % 12;

	printf("%s%d", name[letter], octave);
	return 0;
}
