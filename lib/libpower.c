//libpower.c
#include "../lib/libpower.h"
#include <math.h>
#include <stdio.h>


float calc_power_r(float volt, float resistance) {
	if (resistance == 0 || volt == 0) {
		fprintf(stderr, "Ange korrekt värde som översitger 0\n");
		return NAN;
	}
	return (volt * volt) / resistance;
}


float calc_power_i(float volt, float current) {
	if (current == 0 || volt == 0) {
		fprintf(stderr, "Ange korrekt värde som översitger 0\n");
		return NAN;
	}

	return volt * current;
}
