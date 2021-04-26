#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>


double nextSemitone(double frequency);
double previousSemitone(double frequency);

int main()
{
	double user = 440.00;
	
	printf("Frequency: ");
	scanf("%lf", &user);
	printf("the next semitone of %.2fHz is %.2f\n", user, nextSemitone(user));
	printf("The previous semitone of %.2fHz is %.2f\n", user, previousSemitone(user));
	return 0;
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
double previousSemiton(double frequency)
{
	double semitone = pow(2, 0.083333);
	return frequency / semitone;
}
