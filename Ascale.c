#include <stdio.h>
#include <stdlib.h>
#include <string.h>


/* Print a music scale starting from A's frequency. 
														 					A = 440.00 */
int main() 
{

	const float A = 440.00;					// Frequency in Hz
	const float semiton = 1.06;			// a semiton distance
	int note;												// Musical notes of a scale

	float frequency = A;

	// print the music intervals and its frequency value
	printf("Interval\tFrequency\n");
	for (note=1;note<8;note++){
		if (note == 3 | note == 7){
			printf("%dª\t-\t%.2f\n", note, frequency);
			frequency *= semiton;

		}else {
			printf("%dª\t-\t%.2f\n", note, frequency);
			frequency *= semiton;
			printf("%dªm\t-\t%.2f\n", note+1, frequency);
		}
		frequency *= semiton;
			}

	return 0;
}
