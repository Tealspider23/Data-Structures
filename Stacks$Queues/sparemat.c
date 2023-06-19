
#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int row;
    int col;
    int value;
} Element;

typedef struct {
    int rows;
    int cols;
    int numElements;
    Element* elements;
} SparseMatrix;

SparseMatrix createSparseMatrix(int rows, int cols, int numElements) {
    SparseMatrix matrix;
    matrix.rows = rows;
    matrix.cols = cols;
    matrix.numElements = numElements;
    matrix.elements = (Element*) malloc(numElements * sizeof(Element));
    return matrix;
}

void insertElement(SparseMatrix* matrix, int row, int col, int value) {
    if (matrix->numElements >= matrix->rows * matrix->cols) {
        printf("Matrix overflow\n");
        return;
    }
    
    Element newElement;
    newElement.row = row;
    newElement.col = col;
    newElement.value = value;
    matrix->elements[matrix->numElements] = newElement;
    matrix->numElements++;
}

void displaySparseMatrix(SparseMatrix matrix) {
    int i;
    printf("Sparse Matrix: \n");
    for (i = 0; i < matrix.numElements; i++) {
        printf("(%d, %d, %d)\n", matrix.elements[i].row, matrix.elements[i].col, matrix.elements[i].value);
    }
}

int main() {
    int rows = 3;
    int cols = 3;
    int numElements = 4;
    
    SparseMatrix matrix = createSparseMatrix(rows, cols, numElements);
    
    insertElement(&matrix, 0, 0, 1);
    insertElement(&matrix, 1, 1, 2);
    insertElement(&matrix, 2, 2, 3);
    insertElement(&matrix, 0, 2, 4);
    
    displaySparseMatrix(matrix);
    
    free(matrix.elements);
    
    return 0;
}
