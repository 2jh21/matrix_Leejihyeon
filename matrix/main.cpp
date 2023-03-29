#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>
#include <time.h>

#define SIZE 100

typedef struct {
    int row;
    int col;
    int value;
} element;

typedef struct SparseMatrix {
    element* data;
    int rows;
    int cols;
    int terms;
} matrix;

matrix* matrix_transpose2(matrix* a) {
    matrix* b = (matrix*)malloc(sizeof(matrix));
    b->rows = a->cols;
    b->cols = a->rows;
    b->terms = a->terms;
    if (a->terms > 0) {
        b->data = (element*)malloc(sizeof(element) * a->terms);
        int bindex = 0;
        for (int c = 0; c < a->cols; c++) {
            for (int i = 0; i < a->terms; i++) {
                if (a->data[i].col == c) {
                    b->data[bindex].row = a->data[i].col;
                    b->data[bindex].col = a->data[i].row;
                    b->data[bindex].value = a->data[i].value;
                    bindex++;
                }
            }
        }
    }
    return b;
}

void matrix_print(matrix* a) {
    for (int i = 0; i < a->terms; i++)
        printf("%d %d %d \n", a->data[i].row, a->data[i].col, a->data[i].value);
}

int main(void) {
    matrix m;
    printf("Enter the number of rows and columns,the number of non-zero terms:  ");
    scanf_s("%d %d %d", &m.rows, &m.cols, &m.terms);
    m.data = (element*)malloc(m.terms * sizeof(element));
    printf("\nEnter row, column, and value pairs in order: \n");
    for (int i = 0; i < m.terms; i++) {
        scanf_s("%d %d %d", &m.data[i].row, &m.data[i].col, &m.data[i].value);
    }
    printf("\n");
    matrix* result = matrix_transpose2(&m);
    printf("The transposed matrix is: \n");
    matrix_print(result);
    free(m.data);
    free(result->data);
    free(result);

    system("pause");

    return 0;
}
