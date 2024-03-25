//libcomponent.c
#include "libcomponent.h"
#include <math.h>
#include <stdlib.h>
#include <stdbool.h>
#define TOLERANCE 0.001



static float e12_values[] = {1.0, 1.2, 1.5, 1.8, 2.2, 2.7, 3.3, 3.9, 4.7, 5.6, 6.8, 8.2};

float find_closest_e12(float orig_resistance,  float *res_array, int index){
	
    bool got_better = true;
    float sum = 0;
   // float curent = res_array[0] + res_array[1] + res_array[2];
    int k = 0;
   // int best_e12= 0;
    while (got_better){
        got_better = false; 
        for (int i = 0; i < 12; i++) {
            sum = res_array[0] + res_array[1] + res_array[2];
            int sum1 = sum - res_array[index];
            
            if (fabs((sum1 + (e12_values[i] * pow(10, k))) - orig_resistance) < 
                    fabs(sum - orig_resistance) - TOLERANCE  && (sum1 + (e12_values[i] * pow(10, k))) <= orig_resistance){

                res_array[index] = e12_values[i] * pow(10, k);
                got_better = true;
            }
        }
        k++;
    }
    return res_array[index];
}

int e_resistance(float orig_resistance, float *res_array) {
    int count = 0;
		for (int i = 0; i < 3; i++){
		if (find_closest_e12(orig_resistance, res_array, i)){
			count++;
		}
	}
    return count;
}
