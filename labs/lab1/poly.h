//
// Created by Korisnik on 3.4.2021..
//

#ifndef LAB1_POLY_H
#define LAB1_POLY_H
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <math.h>
typedef struct poly{
    int coefficient;
    int exponent;

} poly;

void entry(poly **polynome, int degree);
void create_poly1(poly **p1, int *degree1);
void create_poly2(poly **p2, int *degree2);
void create_poly_sum(poly **poly_sum, int degree1, int degree2);
void create_poly_multi(poly **poly_multi, int degree1, int degree2);
void print(poly *polynome, int degree);
void multi_scalar(poly *polynome, int degree);
void find_y(poly *polynome, int degree);
void sort(poly *polynome, int degree);
int polynome_sum(poly* polynome1, poly* polynome2, poly* poly_sum, int degree1, int degree2);
void polynome_multi(poly* polynome1, poly* polynome2, poly* poly_multi, int degree, int degree2);
void clean_memory(poly *polynome1,poly *polynome2,poly *poly_sum,poly *poly_multi);

#endif //LAB1_POLY_H
