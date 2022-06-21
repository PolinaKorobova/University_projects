#include <iostream>

void sliv(int* mass1,int m1,int* mass2,int n2,int* mass3) {
	int a = 0;
	int b = 0;
	int r = 0;
	while (a < m1 && b < n2) {
		if (mass1[a] < mass2[b]) {
			mass3[r] = mass1[a];
			a++;
		}
		else {
			mass3[r] = mass2[b];
			b++;
		}
		r++;
	}

	if (a < m1) {
		while (a < m1) {
			mass3[r] = mass1[a];
			a++;
			r++;
		}
	}
	if (b < n2) {
		while (b < n2) {
			mass3[r] = mass2[b];
			b++;
			r++;
		}
	}

}

int main()
{
	int m1;
	int n2;
	int* mass1;
	int* mass2;
	printf("Size of 1:");
	scanf_s("%d", &m1);
	mass1 = (int*)malloc((m1) * sizeof(int));
	for (int i = 0; i < m1; i++) {
		scanf_s("%d", &mass1[i]);
	}
	printf("Size of 2:");
	scanf_s("%d", &n2);
	mass2 = (int*)malloc((n2) * sizeof(int));
	for (int i = 0; i < n2; i++) {
		scanf_s("%d", &mass2[i]);
	}
	int t = m1 + n2;
	int* mass3;
	mass3 = (int*)malloc((t) * sizeof(int));
	sliv(mass1, m1, mass2, n2, mass3);
	for (int f = 0; f < t; f++) {
		printf("%d ", mass3[f]);
	}

}
