/*
 * Xenomai Lab
 * Copyright (C) 2013 Jorge Azevedo
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */

#ifndef MTRX_H
#define	MTRX_H

#include <stdlib.h>
#include <stdio.h>

#define CHAR_BUFFER_SIZE 4096

//size of matrix i sizeof(double)*RMAX*CMAX + sizeof(short)*2
//On x86: 8 bytes and 2 bytes, respectively
#define RMAX 8
#define CMAX 8

#define ESYNTAX 1      /* Matrix string has a syntax error */ 
#define ELARGE 2       /* Matrix exceeds maximum dimensions */
#define EMISMATCH 3    /* Dimensions mismatch */
#define EEMPTY 4       /* Matrix string is empty */
#define ENOOPENER 5    /* Matrix string has no opening '[' */
#define ENOCLOSER 6    /* Matrix string has no closing ']' */
#define EINVALIDCHAR 7 /* Matrix string has an invalid char */
#define ENOTSQUARE 8   /* Matrix should be square but isn't */
#define EZERODET 9     /* Matrix determinant is zero */

#define MTXERROR(...) fprintf(stderr, "E: %17s: ", __PRETTY_FUNCTION__),fprintf(stderr,__VA_ARGS__),fflush(stderr),exit(1)
#define PRINTOFFSET(...) printf("%20s: \t", __PRETTY_FUNCTION__),printf(__VA_ARGS__)

#ifdef	__cplusplus
extern "C" {
#endif

typedef struct {
    unsigned short rows;
    unsigned short columns;
    double matrix[RMAX][CMAX];
}Matrix;

//Matrix type operations
int new_matrix_safe(Matrix*, char *str);
Matrix new_matrix(char *str);
int matrix_is_invalid(char *str);
Matrix empty_matrix(int rows,int col);
Matrix matrix_eye(unsigned char dim, double value);
void matrix_string(Matrix *M1, char* str);
void matrix_print(Matrix * M1);
void matrix_print_pretty(Matrix * M1, char* name, char* format);

//Math operations
int matrix_mul_safe(Matrix *M1, Matrix *M2, Matrix *Mdest);
Matrix matrix_mul(Matrix *M1, Matrix *M2);
Matrix matrix_mul_double(Matrix *M1, double num);
Matrix matrix_tran(Matrix *Msrc);
Matrix matrix_minor(Matrix* M1, int row, int col);
int matrix_det_safe(Matrix* Msrc,double* result);
double matrix_det(Matrix *Msrc);
int matrix_inv_safe(Matrix* Msrc, Matrix* Mdest);
Matrix matrix_inv(Matrix *Msrc);
Matrix matrix_sum(Matrix *M1, Matrix *M2);
Matrix matrix_sub(Matrix *M1, Matrix *M2);



#ifdef	__cplusplus
}
#endif

#endif	/* MTRX_H */

