//electrotest.c
#include <stdio.h>
#include <stdlib.h>
#include "../lib/libresistance.h"
#include "../lib/libcomponent.h"
#include "../lib/libpower.h"
#include <math.h>

int main(){
	// To be implementedi
	//	 float *res_array = (float*)calloc(3, sizeof(float));
	//	 printf("The nr of resistor used to find best comination to 3 are: %d", e_resistance(3, res_array) ); 
	//
	//    return 0;
	//


	char conn;
	float voltage, resistance, effect;
	
	int componentCount;

	float *res_array = (float*)calloc(3, sizeof(float));
	
	
	printf("Ange spänning (U): ");
	scanf("%f", &voltage);
	
	do {
    	printf("Ange koppling[S | P]: ");
    	scanf(" %c", &conn);
	} while (conn != 'S' && conn != 'P');
	
	printf("Antal komponenter: ");
	scanf(" %d", &componentCount);
	float *components = calloc(componentCount, sizeof(float));

	for (int i = 0; i<componentCount; i++) {
		printf("Komponent %d i ohm: ", i+1);
		scanf("%f", &components[i]);
	}

	resistance = calc_resistance(componentCount, conn, components);
	//printf("Resistance is: %.1f \n", resistance);

	printf("Ersättningsresistans:\n %.1f ohm \n", resistance);
	effect = calc_power_r(voltage, resistance);
	printf("Effekt: %.2f W \n", floor(effect * 100)/100);
	int count = e_resistance(resistance, res_array);
	printf("Ersättningsreistanser i E12-serien kopplade i serie: \n");
	for (int i = 0; i < count; i++){
		printf("  %.0f \n", res_array[i]);
	}


	free(res_array);
	//free(components);
}
