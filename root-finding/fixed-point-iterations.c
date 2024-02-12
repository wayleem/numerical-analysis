#include <stdio.h>
#include <math.h>
#include "test-functions.h"

double fixedPointIteration(double x0, double tol, int maxIterations, double (*f)(double)) {
    double x1;
    int iteration = 0;
    int flops = 0; 

    while (iteration < maxIterations) {
        x1 = (*f)(x0); 
        flops += 18; // 1x g(x)

        if (fabs(x1 - x0) < tol) {
            printf("The root is approximately %.5f found in %d steps. (flops: %d)\n", x1, iteration, flops);
            return x1;
        }

        x0 = x1; 
        iteration++;
    }

    printf("Maximum iterations reached (Last approximation: %f) (flops: %d)\n", x1, flops);
    return x1;
}

int main() {
    double initialGuess = 0.5; 
    double tolerance = 0.0001;
    int maxIterations = 100;
    double root = fixedPointIteration(initialGuess, tolerance, maxIterations, g);

    return 0;
}
