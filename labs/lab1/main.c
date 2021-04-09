#include "poly.h"
#include "complex.h"


int main() {

    int choice, end, poly_choice, poly_end;
    int m, n;

    poly *p1 = NULL; int degree1;
    poly *p2 = NULL; int degree2;
    poly *sum = NULL;
    poly *multi = NULL;
//--------------------------------------------------------------------------

    complex* complex_p1 = NULL; int degree_complex1;
    complex* complex_p2 = NULL; int degree_complex2;
    complex *complex_sum = NULL;
    complex* complex_multi = NULL;

    do {
        printf("Please, choose the data type you would like to work with!\n");
        printf("1. Integers\n2.Complex number\nYour choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                do{
                    printf("\n1.Enter first polynome.\n2.Enter second polynome.\n3.Multiple polynome on scalar.\n4.Find y when given x.\n5.Add two polynomes.\n"
                           "6.Multiple two polynomes.\n\nYour choice:");
                    scanf("%d", &poly_choice);

                    switch (poly_choice) {
                        case 1:
                            create_poly1(&p1, &degree1);
                            entry(&p1, degree1);
                            sort(p1, degree1);
                            print(p1, degree1);
                            break;

                        case 2:
                            create_poly2(&p2, &degree2);
                            entry(&p2, degree2);
                            sort(p2, degree2);
                            print(p2, degree2);
                            break;

                        case 3:
                            multi_scalar(p1,degree1);
                            break;

                        case 4:
                            find_y(p1, degree1);
                            break;

                        case 5:
                            create_poly_sum(&sum, degree1, degree2);
                            m = polynome_sum(p1,p2, sum, degree1, degree2);
                            printf("sum of 2 polynomes: ");
                            print(sum, m - 1);
                            break;

                        case 6:
                            create_poly_multi(&multi, degree1, degree2);
                            polynome_multi(p1, p2, multi, degree1, degree2);
                            printf("multiplication of two polynomes is: ");
                            print(multi, degree1 + degree2);
                            break;
                    }

                    printf("If you want to finish with integers, press 0. If not, press any other number.\nYour choice: ");
                    scanf("%d", &poly_end);
                } while(poly_end != 0);

                clean_memory(p1,p2,sum,multi);
                break;
//--------------------------------------------------------------------------------------------------------------------------------------------
            case 2:
                do{
                    printf("\n1.Enter first complex polynome.\n2.Enter second complex polynome.\n3.Multiple complex polynome on scalar.\n4.Find y when given x.\n5.Add two complex polynomes.\n"
                           "6.Multiple two complex polynomes.\n\nYour choice:");
                    scanf("%d", &poly_choice);

                    switch (poly_choice) {
                        case 1:
                            create_complex_p1(&complex_p1, &degree_complex1);
                            entry_complex(&complex_p1, degree_complex1);
                            sort_complex(complex_p1, degree_complex1);
                            print_complex(complex_p1, degree_complex1);
                            break;

                        case 2:
                            create_complex_p2(&complex_p2, &degree_complex2);
                            entry_complex(&complex_p2, degree_complex2);
                            sort_complex(complex_p2, degree_complex2);
                            print_complex(complex_p2, degree_complex2);
                            break;

                        case 3:
                            complex_multi_scalar(complex_p1, degree_complex1);
                            break;
                        case 4:
                            complex_find_y(complex_p1, degree_complex1);
                            break;

                        case 5:
                            create_complex_sum(&complex_sum, degree_complex1, degree_complex2);
                            n = complex_sum_func(complex_p1, complex_p2,complex_sum, degree_complex1, degree_complex2);
                            printf("Sum of 2 complex polynomes: ");
                            print_complex(complex_sum, n - 1);
                            break;

                        case 6:
                            create_complex_poly_multi(&complex_multi, degree_complex1, degree_complex2);
                            complex_multi_func(complex_p1, complex_p2, complex_multi, degree_complex1, degree_complex2);
                            printf("Multiplication of two complex polynomes is:");
                            print_complex(complex_multi, degree_complex1 + degree_complex2);

                    }
                    printf("If you want to finish with complex numbers, press 0. If not, press any other number.\nYour choice: ");
                    scanf("%d", &poly_end);
                } while(poly_end != 0);

                clean_memory_complex(complex_p1, complex_p2, complex_sum, complex_multi);
                break;

        }

        printf("If you want to finish with the programm, press 0. If not, press any other number.\nYour choice: ");
        scanf("%d", &end);
    }while(end != 0);

    return 0;
}