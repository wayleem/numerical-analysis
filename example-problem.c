#include <stdio.h>
#include <math.h>
#include <stdlib.h>

#define N 5 

int steps = 0;
int flops = 0;

void solveSystem(double matrix[N][N + 1], double* coeffs);

int main() {
	double t[N] = {1, 2, 3, 4, 5};
	double y[N] = {15360, 15425, 15483, 15513, 15455};

	double matrix[N][N + 1];
	for (int i = 0; i < N; ++i) {
		for (int j = 0; j < N; ++j) {
			matrix[i][j] = pow(t[i], N-j-1);
		}
		matrix[i][N] = y[i];
	}

	double coeffs[N];

	solveSystem(matrix, coeffs);

	double t6 = 6;
	double p_t6 = 0;
	for (int i = 0; i < N; ++i) {
		p_t6 += coeffs[i] * pow(t6, N-i-1);
	}

	printf("P_4(6) is approximately %.2f in %d steps (flops: %d)\n", p_t6, steps, flops);

	return 0;
}


void solveSystem(double matrix[N][N + 1], double* coeffs) {
    for (int i = 0; i < N; ++i) {
        for (int j = N; j >= i; --j) {
            matrix[i][j] /= matrix[i][i]; // Division
            flops++;
        }
        steps++; 
        
        for (int k = i + 1; k < N; ++k) {
            for (int j = N; j >= i; --j) {
                matrix[k][j] -= matrix[i][j] * matrix[k][i]; // Multiplication and subtraction
                flops += 2;
            }
            steps++; 
        }
    }

    for (int i = N - 1; i >= 0; --i) {
        coeffs[i] = matrix[i][N];
        for (int j = i + 1; j < N; ++j) {
            coeffs[i] -= matrix[i][j] * coeffs[j]; // Multiplication and subtraction
            flops += 2;
        }
        steps++; 
    }
}
