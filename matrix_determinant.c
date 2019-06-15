#include <stdio.h>
#include <stdlib.h>

double **readSqrMatrix(int x){

	double **matrixOne = (double **) malloc(x * sizeof(double *));

	for(int i = 0; i<x; i++){
	
		matrixOne[i] = (double *) calloc(x, sizeof(double));
		for(int j = 0; j<x; j++) {
			scanf("%lf", &(matrixOne[i][j]));
		}
	}

	return matrixOne;
}

double **submatrix(double **origMatrix, int sizeOrg, int row) {
	
	//always first column
	double ** newMatrix = (double **) malloc((sizeOrg-1) * sizeof(double *));
	
	int deviation = 0;
	for(int i = 0; i<sizeOrg; i++){
		if(i != row) {
			newMatrix[i-deviation] = (double *) calloc(sizeOrg-1, sizeof(double));
			for(int j = 0; j<sizeOrg-1; j++) {
				newMatrix[i-deviation][j] = origMatrix[i][j+1];
			}
		} else {
			deviation = 1;
		}
	}

	return newMatrix;
}


int det2x2(double **matrix) {
	//The Leibniz formula
	return (matrix[0][0]*matrix[1][1] - matrix[1][0]*matrix[0][1]);
}


int determinant(double **matrix, int size) {
	// the Laplace expansion
	if(size == 2) return det2x2(matrix);

	//go through the whole first column/row and do
	int det = 0; 
	int sign = 1;
	for(int j = 0; j < size; j++) {

		double ** sub = submatrix(matrix, size, j);

		det += sign * matrix[j][0] * determinant(sub, size-1);
		sign *= -1;
	}
	return det;
}

int main() {
	/**
	* the Laplace expansion  [implemented]
	* matrix decomposition/factorization
	* Gaus -> upper Triangulare matrix -> multiplication of diagonal elements
	*/


	//determinant can be only calculated for SQUARE matrices
	int n; scanf("%d\n", &n);
	double **matrix = readSqrMatrix(n);

	printf("%d\n", determinant(matrix, n));

	return 0;
}







/*double[][] readMatrix(int x, int y){

	double **matrixOne = (double **) malloc(x * sizeof(double *));

	for(int i = 0; i<x; i++){
	
		matrixOne[i] = (double *) calloc(y, sizeof(double));
		for(int j = 0; j<y; j++) {
			scanf("&f", &(matrixOne[i][j]));
		}
	}

	return matrixOne;
}*/