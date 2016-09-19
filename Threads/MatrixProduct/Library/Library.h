#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

void ThreadProduct ( void *argument );
void ConstructMatrix ( int answer );
int Menu ( );

typedef struct MatrixParameters {
    int size;
    int **inputMatrix;
} Matrix;

Matrix Parameters;

int **matrixProduct;
