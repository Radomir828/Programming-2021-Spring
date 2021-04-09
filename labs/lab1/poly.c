//
// Created by Korisnik on 3.4.2021..
//

#include "poly.h"
void create_poly1(poly **p1, int *degree1) {
    printf("enter the highest degree in the first polynome:");
    scanf("%d", degree1);
    *p1 = (poly*)malloc((*degree1 + 1) * sizeof(poly)) ;
}

void create_poly2(poly **p2, int *degree2) {
    printf("enter the highest degree in the second polynome:");
    scanf("%d", degree2);
    *p2 = (poly*)malloc((*degree2 + 1) * sizeof(poly));
}
void create_poly_sum(poly **poly_sum, int degree1, int degree2) {
    *poly_sum = (poly*) malloc((degree1 + degree2 + 2) * sizeof(poly));
}
void create_poly_multi(poly **poly_multi, int degree1, int degree2){
    *poly_multi = (poly*) malloc((degree1 + degree2 + 2) * sizeof(poly));
}

void entry(poly **polynome, int degree) {

    for(int i = 0; i < degree + 1; i++) {
        printf("Enter %d coefficient: ",i + 1);
        scanf("%d", &(*polynome + i)->coefficient);
        (*polynome+ i)->exponent = i;
        //printf("\n");
    }
}

void print(poly *polynome, int degree) {
    printf("\n");
    bool plus = false;

    for(int i = 0; i < degree + 1; i++) {
        if(plus)
            printf("+");

        printf(" %d(x^%d) ", polynome[i].coefficient, polynome[i].exponent);
        plus = true;
    }
    printf("\n");
}



void multi_scalar(poly *polynome, int degree) {
    print(polynome, degree);
    int scalar;
    printf("enter number to multiple your polynome with: ");
    scanf("%d", &scalar);
    for(int i = 0; i < degree + 1; i++) {
        polynome[i].coefficient = polynome[i].coefficient * scalar;
    }
    print(polynome, degree);

}

void find_y(poly *polynome, int degree) {

    print(polynome, degree);
    int y = 0, x;
    printf("\nNow enter the value of x to find y: ");
    scanf("%d", &x);

    for(int i = 0; i < degree + 1; i++) {
        y += polynome[i].coefficient * pow(x, polynome[i].exponent);
    }
    printf("y = %d\n", y);


//  return y;
}

void sort(poly *polynome, int degree) {//sort from biggest exponent to smallest
    int i, j;
    poly temp;

    for (i = 0; i < degree; i++) {
        for (j = 0; j < degree - i; j++) {
            if (polynome[j].exponent < polynome[j + 1].exponent) {
                temp = polynome[j];
                polynome[j] = polynome[j + 1];
                polynome[j + 1] = temp;
            }
        }
    }
}


int polynome_sum(poly* polynome1, poly* polynome2, poly* poly_sum, int degree1, int degree2){
    int i = 0, j = 0, k = 0;
    //polynome1 - i
    //polynome2 - j
    //poly_sum - k

    while(i < degree1 + 1 && j < degree2 + 1) {
        if(polynome1[i].exponent == polynome2[j].exponent) {
            poly_sum[k].coefficient = polynome1[i].coefficient + polynome2[j].coefficient;
            poly_sum[k].exponent = polynome1[i].exponent;
            i++;
            j++;
            k++;
        } else if(polynome1[i].exponent > polynome2[j].exponent) {
            poly_sum[k].coefficient = polynome1[i].coefficient;
            poly_sum[k].exponent = polynome1[i].exponent;
            i++;
            k++;
        } else {
            poly_sum[k].coefficient = polynome2[j].coefficient;
            poly_sum[k].exponent = polynome2[j].exponent;
            j++;
            k++;
        }

    }
    return  k;
}


void polynome_multi(poly* polynome1, poly* polynome2, poly* poly_multi, int degree, int degree2) {
    for (int  i = 0; i < degree + degree2 + 2; i++) {
        poly_multi[i].coefficient = 0;
    }

    for (int i=0; i<degree + 1; i++)
    {
        for (int j=0; j < degree2 + 1; j++) {
            poly_multi[i + j].coefficient += polynome1[i].coefficient * polynome2[j].coefficient;
            poly_multi[i + j].exponent = polynome1[i].exponent + polynome2[j].exponent;
        }
    }
}

void clean_memory(poly *polynome1,poly *polynome2,poly *poly_sum,poly *poly_multi) {

    if(polynome1)
        free(polynome1);

    if(polynome2)
        free(polynome2);

    if(poly_sum)
        free(poly_sum);

    if(poly_multi)
        free(poly_multi);

}