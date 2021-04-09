//
// Created by Korisnik on 3.4.2021..
//

#ifndef LAB1_COMPLEX_H
#define LAB1_COMPLEX_H
typedef struct complex{
    int real;
    int im;
    int exponent;

} complex;

void create_complex_p1(complex **p1, int *degree_complex1);
void create_complex_p2(complex **p2, int *degree_complex2);
void create_complex_sum(complex **complex_sum, int degree_complex1, int degree_complex2);
void create_complex_poly_multi(complex **complex_multi, int degree_complex1, int degree_complex2);
void entry_complex(complex **p1, int degree);
void print_complex(complex *p1, int degree);
void sort_complex( complex *polynome, int degree);
void complex_multi_scalar(complex* complex_p1, int degree_complex1);
void complex_find_y(complex *complex_p1, int degree_complex1);
int complex_sum_func(complex* p1, complex* p2, complex* complex_sum, int degree_complex1, int degree_complex2);
void complex_multi_func(complex* p1, complex* p2, complex* poly_multi, int degree, int degree2);
void clean_memory_complex(complex* p1, complex* p2, complex* complex_sum, complex* complex_multi);
#endif //LAB1_COMPLEX_H
