#include <stdio.h>
#include <math.h>
#include "control.c"


int main()
{
	double frequency;
	printf("Type the frequency to find the scale of the musical notation: ");
	scanf("%lf", &frequency);
	printf("\n");

	printf("Notation: ");
	pitch(frequency);
	printf("\n");

	scaleOf(frequency);
	return 0;
}

