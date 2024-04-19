#include <stdio.h>
#include <math.h>
#include "test-functions.h"

double secantMethod(double x0, double x1, double tol, int maxIterations, double (*f)(double)) {
    double x2, fx0, fx1;
    int iteration = 0;
    int flops = 0; 

    fx0 = (*f)(x0);
    fx1 = (*f)(x1);
    flops += 28; // 2x f(x)

    while (iteration < maxIterations) {
        if (fabs(fx1 - fx0) < tol) {
            printf("Warning: Difference between function values is too small.\n");
            printf("Floating-point operations: %d\n", flops);
            return x1;
        }

        x2 = x1 - fx1 * (x1 - x0) / (fx1 - fx0);
        flops += 5; // 2 subtractions, 1 multiplication, and 1 division

        if (fabs(x2 - x1) < tol) {
            printf("The root is approximately %.5f found in %d steps. (flops: %d)\n", x2, iteration, flops);
            return x2;
        }

        x0 = x1;
        fx0 = fx1;
        x1 = x2;
        fx1 = (*f)(x2);
        flops += 14; // f(x)

        iteration++;
    }

    printf("Maximum iterations reached (Last approximation: %f) (flops: %d)\n", x2, flops);
    return x2;
}

int main() {
    double root = secantMethod(1.0, 2.0, 0.0001, 100, f);
    return 0;
}
