#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int
main(){
		// analize the sound frequency in Hz
		float tonic = 440.00;
		float semiton = 1.06;
		char music_scale[8] = "ABCDEFG";
    
    // Print the musical notes followed by their respective frequency values in a music scale based on the given tonic value
		int cont;
		for (cont=0; cont < 7; cont++){
			float previous_frequency;
			
			// Print the tonic and 2th minor frequency values based on the first music scale element. 
			if (cont == 0){
				printf("%-c : %.2f\n", music_scale[cont], tonic);
				previous_frequency = tonic;
				printf("%-c#: %.2f\n", music_scale[cont], tonic*semiton);
				previous_frequency *= semiton;

			// print the next music note based on its previous value
			}else {
				float frequency;
				frequency = previous_frequency * semiton;

				// Se a nota for Mi ou Si, então não haverá sustenidos.
				if (music_scale[cont] == 69 | music_scale[cont] == 66){
					printf("%-c : %.2f\n", music_scale[cont], frequency);
					previous_frequency = frequency;
				}else {
					printf("%-c : %.2f\n", music_scale[cont], frequency);
					printf("%-c#: %.2f\n", music_scale[cont], frequency*semiton);
					previous_frequency = frequency * semiton;
				}
			}
		}
		return 0;
}
