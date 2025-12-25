#define _CRT_SECURE_NO_WARNINGS

#include<stdio.h>
#include<string.h>
#include<ctype.h>

#define MAX 50
#define EMPTY 0
#define FULL 1

int Add_two_nums(char num_1[], char num_2[], int result[]);
int main() {
	char num_1[MAX];
	char num_2[MAX];
	int result[MAX + 1];
	int n = 0;
	scanf("%s %s", num_1, num_2);
	n = Add_two_nums(num_1, num_2, result);
	for (int i = n - 1; i >= 0; i--) {
		printf("%d", result[i]);
	}
	return 0;
}

int Add_two_nums(char num_1[], char num_2[], int result[]) {
	int carry_out_bit = 0;
	int i = 0;
	int temp_bit = 0;
	int i1 = strlen(num_1) - 1;
	int i2 = strlen(num_2) - 1;
	int num_1_Flag = EMPTY;
	int num_2_Flag = EMPTY;
	while (1) {

		if (i1 < 0 && num_1_Flag == EMPTY) {
			num_1_Flag = FULL;
		}

		if (i2 < 0 && num_2_Flag == EMPTY) {
			num_2_Flag = FULL;
		}

		if (num_1_Flag == FULL && num_2_Flag == EMPTY) {
			temp_bit = num_2[i2] - '0' + carry_out_bit;
		}
		else if (num_1_Flag == EMPTY && num_2_Flag == FULL) {
			temp_bit = num_1[i1] - '0' + carry_out_bit;
		}
		else if (num_1_Flag == EMPTY && num_2_Flag == EMPTY) {
			temp_bit = num_1[i1] - '0' + num_2[i2] - '0' + carry_out_bit;
		}
		else {
			if (carry_out_bit == 1) {
				result[i] = 1;
				i++;
			}
			break;
		}

		if (temp_bit < 10) {
			carry_out_bit = 0;
			result[i] = temp_bit;
		}
		else {
			carry_out_bit = 1;
			temp_bit = temp_bit % 10;
			result[i] = temp_bit;
		}
		i++;
		i1--;
		i2--;
	}
	return i;
}
