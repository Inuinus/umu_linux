#ifndef ELECTRO_H
#define ELECTRO_H

float calc_power_r(float volt, float resistance);
float calc_power_i(float volt, float current);
float calc_resistance(int count, char conn, float *array);
int e_resistance(float orig_resistance, float *res_array);

#endif
