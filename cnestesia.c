#include <stdio.h>
#include <math.h>
#include "control.c"


int main()
{
	double frequency;
	printf("Type the frequency to find the notation: ");
	scanf("%lf", &frequency);

	printf("Notation: ");
	pitch(frequency);
	printf("Next semitone: ");
	pitch(nextSemitone(frequency));
	printf("Previous semitone: ");
	pitch(previousSemitone(frequency));

	scaleOf(frequency);
	return 0;
}

