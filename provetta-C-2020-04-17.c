/* ex 1 */

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int work_array[] = {
   7788, -7066, -6641, -2324, 7799, 3530, -8426, 267,
   -569, -4432, -217, 1761, 4885, 274, -6318, 3527,
   4346, 1710, 2562, 7932, -8472, 7351, 354, -7463, 1657,
   -4285, 3926, -7771, -4498, -3430, -5992, 2488, 658, -6352,
   -7909, 188, 3005, -8457, 4242, 1259, 3662, 32, 7910, 1252,
   3067, -5430, 6794, 3550, -3073, 2204, -821, 6769, 390,
   -2097, 1685, -2996, -6410, 3972, -4800, 4674, -2337,
   1897, -1160, -7987, -8890, -2197, 938, -6302, -5909,
   3723, 8615, 7096, 3080, -5511, 6339
};

typedef struct {
   int splitter_value;					// valore "separatore"
   int * less_than_array; 				// array dei valori <= splitter_value
   unsigned int less_than_array_len; 	// lunghezza di less_than_array
   int * larger_than_array; 			// array dei valori > splitter_value
   unsigned int larger_than_array_len; 	// lunghezza di larger_than_array
} split_result;

split_result splitter(int * param_array, unsigned int array_len, int splitter_value) {

	// Count
	unsigned int less_than_count = 0;
	for (unsigned int i = 0; i < array_len; i++) {
		less_than_count += (param_array[i] <= splitter_value) ? 1 : 0;
	}

	// Allocate
	split_result out;
	out.splitter_value = splitter_value;
	out.less_than_array_len = less_than_count;
	out.less_than_array = malloc(sizeof(int) * out.less_than_array_len);
	out.larger_than_array_len = array_len - less_than_count;
	out.larger_than_array = malloc(sizeof(int) * out.larger_than_array_len);

	if (out.less_than_array == NULL || out.larger_than_array == NULL) {
		printf("malloc() failed\n");
		exit(EXIT_FAILURE);
	}

	// Populate
	unsigned int ai = 0, ab = 0;
	for (unsigned int i = 0; i < array_len; i++) {
		if (param_array[i] <= splitter_value) {
			out.less_than_array[ai++] = param_array[i];
		} else {
			out.larger_than_array[ab++] = param_array[i];
		}
	}

	return out;
}

void min_max(int * param_array, unsigned int array_len) {
	if (array_len <= 0) return;

	int min = param_array[0], max = param_array[0];
	for (unsigned int i = 0; i < array_len; i++) {
		min = (min <= param_array[i]) ? min : param_array[i];
		max = (max >= param_array[i]) ? max : param_array[i];
	}

	printf("min = %d, max = %d\n", min, max);
}

int main() {

	// Len
	int work_array_len = (int)sizeof(work_array) / sizeof(int);
	printf("dimensione di work_array: %ld\n", work_array_len);

	// Split
	split_result result = splitter(work_array, work_array_len, 0);
	printf("less_than_array_len=%d larger_than_array_len=%d\n",
			result.less_than_array_len, result.larger_than_array_len);

	// Fork process 1
	switch(fork()) {
		case 0:
			printf("esecuzione primo processo:\n");
			min_max(result.less_than_array, result.less_than_array_len);
			exit(EXIT_SUCCESS);
		case -1:
			exit(EXIT_FAILURE);
		default:
			while(wait(NULL) != -1) ;
	}

	// Fork process 2
	switch(fork()) {
		case 0:
			printf("esecuzione secondo processo:\n");
			min_max(result.larger_than_array, result.larger_than_array_len);
			exit(EXIT_SUCCESS);
		case -1:
			exit(EXIT_FAILURE);
		default:
			while(wait(NULL) != -1) ;
	}

	// Done
	printf("bye!\n");

	return 0;
}
