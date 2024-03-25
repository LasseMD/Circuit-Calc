//libresistance.c
#include <stdlib.h>
#include "libresistance.h"

float calc_resistance(int count, char conn, float *array) {
    if(array == NULL || count <= 0) return -1;
    float total = 0;
    if(conn == 'S') {
        for(int i = 0; i < count; i++) total += array[i];
    } else if(conn == 'P') {
        for(int i = 0; i < count; i++) {
            if(array[i] == 0) return 0;
            total += 1 / array[i];
        }
        total = 1 / total;
    } else {
        return -1;
    }
    return total;
}
