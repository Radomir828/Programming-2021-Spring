//
// Created by Korisnik on 3.4.2021..
//

#include "complex.h"
#include "poly.h"
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
//#include <math.h>

void create_complex_p1(complex **p1, int *degree_complex1) {
    printf("enter the highest degree in the first complex polynome:");
    scanf("%d", degree_complex1);
    *p1 = (complex*)malloc((*degree_complex1 + 1) * sizeof(complex));
}

void create_complex_p2(complex **p2, int *degree_complex2) {
    printf("enter the highest degree in the second complex polynome:");
    scanf("%d", degree_complex2);
    *p2 = ( complex*)malloc((*degree_complex2 + 1) * sizeof(complex)) ;
}
/*
void create_complex_poly_sum( complex **poly_sum, int degree1, int degree2) {
    *poly_sum = (poly*) malloc((degree1 + degree2 + 2) * sizeof(poly));
}
*/
void create_complex_sum(complex **complex_sum, int degree_complex1, int degree_complex2){
    *complex_sum = (complex*) malloc((degree_complex1 + degree_complex2 + 2) * sizeof(poly));

}

void create_complex_poly_multi(complex **complex_multi, int degree_complex1, int degree_complex2) {
    *complex_multi = (complex*) malloc((degree_complex1 + degree_complex2 + 2) * sizeof(poly));
}


void entry_complex(complex **p1, int degree) {

    for(int i = 0; i < degree + 1; i++) {
        printf("Enter the real part(%d): ",i + 1);
        scanf("%d", &(*p1 + i)->real);

        printf("Enter the imaginary part(%d): ",i + 1);
        scanf("%d", &(*p1 + i)->im);

        (*p1+ i)->exponent = i;
        printf("\n");
    }

}
void print_complex(complex *p1, int degree) {
    bool plus = false;

    for(int i = 0; i < degree + 1; i++) {
        if(plus)
            printf("+");

        if(p1[i].im < 0) {
            printf("(%d + (%di))x^%d ", p1[i].real, p1[i].im, p1[i].exponent);
        } else {
            printf("(%d + %di)x^%d ", p1[i].real, p1[i].im, p1[i].exponent);

        }

        plus = true;
    }
    printf("\n");

}

void sort_complex( complex *polynome, int degree) {//sort from biggest exponent to smallest

    int i,j;
    complex temp;

    for(i = 0; i < degree; i++) {
        for(j = 0; j < degree - i; j++) {
            if(polynome[j].exponent < polynome[j + 1].exponent) {
                temp = polynome[j];
                polynome[j] = polynome[j + 1];
                polynome[j + 1] = temp;
            }
        }
    }

}

void complex_multi_scalar(complex* complex_p1, int degree_complex1) {
    int scalar;
    printf("Enter number you wold like to multiple your complex polynome with: ");
    scanf("%d", &scalar);

    for(int i = 0; i < degree_complex1 + 1; i++){
        complex_p1[i].real = complex_p1[i].real * scalar;
        complex_p1[i].im = complex_p1[i].im * scalar;
    }
    print_complex(complex_p1, degree_complex1);
}


void complex_find_y(complex *complex_p1, int degree_complex1) {

    print_complex(complex_p1, degree_complex1);
    int x;
    printf("\nNow enter the value of x to find y: ");
    scanf("%d", &x);
    int result_real = 0, result_im = 0;

    for(int i = 0; i < degree_complex1 + 1; i++) {
        result_real += complex_p1[i].real * pow(x, complex_p1[i].exponent);
        result_im += complex_p1[i].im * pow(x, complex_p1[i].exponent);
        //y += (complex_p1[i].real + complex_p1[i].im) * pow(x, complex_p1[i].exponent);
    }

    printf("y = %d + %di\n", result_real, result_im );


//  return y;
}



int complex_sum_func(complex* p1, complex* p2, complex* complex_sum, int degree_complex1, int degree_complex2){
    int i = 0, j = 0, k = 0;
    //polynome1 - i
    //polynome2 - j
    //poly_sum - k

    while(i < degree_complex1 + 1 && j < degree_complex2 + 1) {
        if(p1[i].exponent == p2[j].exponent) {
            complex_sum[k].real= p1[i].real + p2[j].real;
            complex_sum[k].im= p1[i].im + p2[j].im;

            complex_sum[k].exponent = p1[i].exponent;
            i++;
            j++;
            k++;
        } else if(p1[i].exponent > p2[j].exponent) {
            complex_sum[k].real = p1[i].real;
            complex_sum[k].im = p1[i].im;

            complex_sum[k].exponent = p1[i].exponent;
            i++;
            k++;
        } else {
            complex_sum[k].real = p2[j].real;
            complex_sum[k].im = p2[j].im;

            complex_sum[k].exponent = p2[j].exponent;
            j++;
            k++;
        }

    }
    return  k;
}

void complex_multi_func(complex* p1,complex* p2, complex* poly_multi, int degree, int degree2) {
    for (int  i = 0; i < degree + degree2 + 2; i++) {
        poly_multi[i].real = 0;
        poly_multi[i].im = 0;

    }

    for (int i=0; i<degree + 1; i++)
    {
        for (int j=0; j < degree2 + 1; j++) {
            poly_multi[i + j].real += p1[i].real * p2[j].real - p2[i].im * p2[j].im;
            poly_multi[i + j].im += p1[i].real * p2[j].im + p2[j].real * p2[i].im;
            poly_multi[i + j].exponent = p1[i].exponent + p2[j].exponent;
        }
    }
}

void clean_memory_complex(complex* p1, complex* p2, complex* complex_sum, complex* complex_multi) {
    if(p1)
        free(p1);

    if(p2)
        free(p2);

    if(complex_sum)
        free(complex_sum);

    if(complex_multi)
        free(complex_multi);
}
