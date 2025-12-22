#define _CRT_SECURE_NO_WARNINGS

#include<stdio.h>

void hanoi(int n, char from, char to, char aux);
int main() {
	int n = 0;
	scanf("%d", &n);
	hanoi(n, 'A', 'C', 'B');
	return 0;
}
void hanoi(int n, char from, char to, char aux) {
	if (n == 1) {
		printf("Move disk from %c to %c\n", from, to);
		return;
	}

	hanoi(n - 1, from, aux, to);

	printf("Move disk from %c to %c\n", from, to);

	hanoi(n - 1, aux, to, from);
}
