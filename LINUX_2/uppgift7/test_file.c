#include <stdio.h>
#include <string.h>
#include "CUnit/Basic.h"
#include "electro.h"

/* Pointer to the file used by the tests */
static FILE* temp_file = NULL;

/*opens the temp file that wants to be used by the test*/
int init_suite1(void)
{
	if (NULL == (temp_file = fopen("electrotest-standalone.c", "r"))) {
		return -1;
	}
	else {
		return 0;
	}
}

/* cleanup crew, closes temporary file*/
int clean_suite1(void)
{
	if (0 != fclose(temp_file)) {
		return -1;
	}
	else {
		temp_file = NULL;
		return 0;
	}
}

void testCalcPowerR(void)
{
	//test korrekt inmatning
	float result = calc_power_r(10.0, 5.0);
	CU_ASSERT_DOUBLE_EQUAL(result, 20.0, 0.001);

	//test noll res (Ska returnera -1)
	result = calc_power_r(10.0, 0.0);
	CU_ASSERT_DOUBLE_EQUAL(result, -1.0, 0.001);
}

void testCalcPowerI(void)
{
	//korrekt inmatning
	float result = calc_power_i(10.0, 2.0);
	CU_ASSERT_DOUBLE_EQUAL(result, 20.0, 0.001);
}

void testCalcResistance(void)
{
	float array1[3] = {10.0, 20.0, 30.0};

	//test serie(S)
	float result = calc_resistance(3, 'S', array1);
	CU_ASSERT_DOUBLE_EQUAL(result, 60.0, 0.001);

	//test parralellkoppling (P)
	float array[2] = {10.0, 20.0};
	result = calc_resistance(2, 'P', array);
	CU_ASSERT_DOUBLE_EQUAL(result, 6.666, 0.01);

	//felaktig koppling
	result = calc_resistance(2, 'X', array);
	CU_ASSERT_DOUBLE_EQUAL(result, -1.0, 0.001);

	//ogilitligt antal (negativt)
	result = calc_resistance(-1, 'S', array);
	CU_ASSERT_DOUBLE_EQUAL(result, -1.0, 0.001);

	//null array
	result = calc_resistance(2, 'S', NULL);
	CU_ASSERT_DOUBLE_EQUAL(result, -1.0, 0.001);
}

void testEResistance(void)
{
	float res_array[3];
	int count = e_resistance(1000.0, res_array);

	//kontrollera att funktinen hittar exakt 3 motstånd
	CU_ASSERT_EQUAL(count, 3);

	//kontrollera att summan är ungefär 1000 ohm
	float sum = res_array[0] + res_array[1] + res_array[2];
	CU_ASSERT_DOUBLE_EQUAL(sum, 1000.0, 20.0); //tolerans mellan +- 20 ohm

	//testa ogiltigt negativt värde
	count = e_resistance(-10.0, res_array);
	CU_ASSERT_TRUE(count >= 0); //crashsafe
}

int main()
{
	CU_pSuite pSuite = NULL;

/*inititalizze the CUnit test registry */
	if (CUE_SUCCESS != CU_initialize_registry())
		return CU_get_error();

/* add the suite to the registry */
	pSuite = CU_add_suite("Suite_1", init_suite1, clean_suite1);
	if (NULL == pSuite){
		CU_cleanup_registry();
		return CU_get_error();
	}

	CU_add_test(pSuite, "test of calc_power_r()", testCalcPowerR);
	CU_add_test(pSuite, "test of calc_power_i()", testCalcPowerI);
	CU_add_test(pSuite, "test of calc_resistance()", testCalcResistance);
	CU_add_test(pSuite, "test of e_resistance()", testEResistance);

/*run all the test using the CUnit Basic interface*/
	CU_basic_set_mode(CU_BRM_VERBOSE);
	CU_basic_run_tests();
	CU_cleanup_registry();
	return CU_get_error();
}
