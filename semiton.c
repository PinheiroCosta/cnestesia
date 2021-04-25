#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>


double nextSemiton(double frequency);
double previousSemiton(double frequency);

int main()
{
	double user = 440.00;
	
	printf("Frequency: ");
	scanf("%lf", &user);
	printf("the next semiton of %.2fHz is %.2f\n", user, nextSemiton(user));
	printf("The previous semiton of %.2fHz is %.2f\n", user, previousSemiton(user));
	return 0;
}


// return the next semiton of a frequency in Hz
double nextSemiton(double frequency) 
{
	/*	A4  = 440Hz; A5  = 880Hz
			A#4 = A4 * 2^(1/12)
			B4  = A4 * 2^(2/12)

			1/12 = 0.083333 */
	
	double semiton = pow(2, 0.083333);
	return frequency * semiton;
}

// return the previous semiton of a frequency in Hz
double previousSemiton(double frequency)
{
	double semiton = pow(2, 0.083333);
	return frequency / semiton;
}
