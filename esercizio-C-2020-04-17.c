/** ex 1 */
#include <stdio.h>
// #include <stdlib.h>
#include <string.h>

char * str_1 = "prima-";
char * str_2 = "seconda-";
char * str_3 = "terza!";

int main(int argc, char **argv) {
	// Preparazione buffer
	int total_len = strlen(str_1) + strlen(str_2) + strlen(str_3) + 1;
	char * str_new[total_len];
	// Concatenazione
	strcat(str_new, str_1);
	strcat(str_new, str_2);
	strcat(str_new, str_3);
	// Output
	printf(str_new);
}

/** ex 10 */
#include <stdio.h>
#include <string.h>

int my_strlen3(char * data1, char * data2, char * data3) {
	return (data1 == NULL ? 0 : strlen(data1))
			+ (data2 == NULL ? 0 : strlen(data2))
			+ (data3 == NULL ? 0 : strlen(data3));
}

int main() {
	// tests
	printf("Len1 : %d\n", my_strlen3("0", "ab", "cde"));
	printf("Len2 : %d\n", my_strlen3("0", NULL, "cde"));
	printf("Len3 : %d\n", my_strlen3("0-----", "ab", NULL));
	return 0;
}
