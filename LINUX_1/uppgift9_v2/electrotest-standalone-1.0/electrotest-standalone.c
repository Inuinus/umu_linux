#include <math.h>
#include <stdio.h>
#include <stdlib.h>

float calc_power_r(float volt, float resistance) {
    if (resistance == 0) {
        fprintf(stderr, "Error: Resistance cannot be zero.\n");
        return -1.0;
    }
    return (volt * volt) / resistance;
}

float calc_power_i(float volt, float current) {
    return volt * current;
}

float calc_resistance(int count, char conn, float *array);
float parallel_resistance(int count, float *array);
float sequence_resistance(int count, float *array);

float calc_resistance(int count, char conn, float *array) {
    if (count <= 0) {
        fprintf(stderr, "Array size %d is invalid!\n", count);
        return -1;
    }
    if (!array) {
        fprintf(stderr, "%s", "Array is nullptr!\n");
        return -1;
    }

    switch (conn) {
        case 'P':
            return parallel_resistance(count, array);
        case 'S':
            return sequence_resistance(count, array);
        default:
            fprintf(stderr, "Invalid input argument %c, looking for 'P' or 'S'!\n", conn);
            return -1;
    }
    fprintf(stderr, "%s", "Should never get here!\n");
    return -1;
}

float parallel_resistance(int count, float *array) {
    for (int i = 0; i < count; ++i)
        if ((float)array[i] == 0)
            return 0;

    float r = (float)*array;
    for (int i = 1; i < count; ++i)
        r = r*(float)array[i]/(r+(float)array[i]); // Rt = R1*R2/(R1+R2)
    
    return r;
}

float sequence_resistance(int count, float *array) {
    float r = 0;
    for (int i = 0; i < count; ++i)
        r += (float)array[i];
    return r;
}

int e_resistance(float orig_resistance, float *res_array) {
    const int decades = 7;
    float resistor_values[(12 * 7) + 1] = {0};
    // Fill array with resitor values, 7 decades. 12 resistor values in each 
    // decade in E12 serie, the official formula doesn't match with all values
    resistor_values[0] = 1;
    resistor_values[1] = 1.2;
    resistor_values[2] = 1.5;
    resistor_values[3] = 1.8;
    resistor_values[4] = 2.2;
    resistor_values[5] = 2.7;
    resistor_values[6] = 3.3;
    resistor_values[7] = 3.9;
    resistor_values[8] = 4.7;
    resistor_values[9] = 5.6;
    resistor_values[10] = 6.8;
    resistor_values[11] = 8.2;
    // Setting last value to 0
    resistor_values[(decades + 12) + 1] = 0.f;
    int k = 0;
    for (int i = 0; i < decades; i++) {
        for (int j = 0; j < 12; j++) {
            resistor_values[k++] = resistor_values[j] * pow(10, i);
            printf("%f\n", resistor_values[k-1]);
        }
    }

    res_array[0] = resistor_values[0];
    res_array[1] = resistor_values[0];
    res_array[2] = resistor_values[0];
    // find all configurations and find the closest values
    for (int i = 0; i < (12 * decades) + 1; i++) {
        for (int j = 0; j < (12 * decades) + 1; j++) {
            for (int k = 0; k < (12 * decades) + 1; k++) {
                if (fabs(orig_resistance - (res_array[0] + res_array[1] + res_array[2])) > fabs(orig_resistance - (resistor_values[i] + resistor_values[j] + resistor_values[k]))) {
                    res_array[0] = resistor_values[i];
                    res_array[1] = resistor_values[j];
                    res_array[2] = resistor_values[k];

                    printf("%f\n", res_array[0]);
                    printf("%f\n", res_array[1]);
                    printf("%f\n", res_array[2]);
                }
            }
        }
    }
    // count number of resistors
    int count = 0;
    for (int i = 0; i < 3; i++) {
        if (res_array[i] > 0.0001) {
            count++;
        }
    }
    return count;
}

float r_value(int n) {
    return pow(pow(10.f, (float)n), 1.f/12.f);
}

int main() {
    // Test the combined application
    float res_array[3];
    float orig_resistance = 1000.0; // Example input
    int count = e_resistance(orig_resistance, res_array);
    printf("Number of resistors: %d\n", count);

    // Example power calculations
    float volt = 10.0;
    float resistance = 100.0;
    printf("Power using resistance: %f\n", calc_power_r(volt, resistance));

    float current = 0.1;
    printf("Power using current: %f\n", calc_power_i(volt, current));

    return 0;
}
