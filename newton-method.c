#include <stdio.h>
#include <math.h>
#include "test-functions.h"

double newtonsMethod(double x0, double tol, double (*f)(double), double (*f_prime)(double));

int main() {
    double root;
    double x0 = 0.4, tol = 0.00005; 

    root = newtonsMethod(x0, tol, f, f_prime);

    return 0;
}

double newtonsMethod(double x0, double tol, double (*f)(double), double (*f_prime)(double)) {
    double x1;
    int steps = 0;
    int flops = 0; 

    while (1) {
        double fx = (*f)(x0);
        double fpx = (*f_prime)(x0);

        flops += 14; //  f(x) 
        flops += 18; // f'(x) 

        if (fabs(fpx) < tol) {
            printf("Warning: Derivative is close to zero. Solution could be inaccurate.\n");
            printf("Floating-point operations: %d\n", flops);
            return x0;
        }

        x1 = x0 - fx / fpx;
        flops += 3; // 1 subtraction and 1 division 

        if (fabs(x1 - x0) < tol) {
            break;
        }

        x0 = x1;
        steps++;
        flops++; // 1 subtraction
    }

    printf("The root is approximately %.5f found in %d steps. (flops: %d)\n", x1, steps, flops);
    return x1;
}
