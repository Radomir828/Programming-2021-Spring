#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include <stdbool.h>

void remove_even_numbers(){
    int m;
    int n = 0;
    int i;
    printf("Enter number of elements in array: ");
    scanf("%d", &m);
    int *nums = (int*) calloc(m, sizeof(int));
    int *no_even_nums = (int *) calloc(m, sizeof(int));

    for (i = 0; i < m; i++) {
        nums[i] = rand() % 9999;
    }
    printf("all elements of array:\n");
    for (i = 0; i < m; i++) {
        printf("%d element of array: %d\n", i + 1, nums[i]);
    }
    for (i = 0; i < m; i++) {
        if (nums[i] % 2 != 0) {
            no_even_nums[n] = nums[i];
            n++;
        }
    }
    printf("\n");
    printf("array without even numbers: \n");
    for (i = 0; i < n; i++) {
        printf("%d element of array: %d\n", i + 1, no_even_nums[i]);
    }

    free(nums);
    free(no_even_nums);
    printf("\n");

}

void biggest_smallest(){
    int m;
    int min, max = 0;
    int i;
    printf("Enter number of elements in array: ");
    scanf("%d", &m);
    int *nums = (int*) calloc(m, sizeof(int));

    for (i = 0; i < m; i++) {
        nums[i] = rand() % 9999;
    }

    printf("all elements of array:\n");
    for (i = 0; i < m; i++) {
        printf("%d element of array: %d\n", i + 1, nums[i]);
    }
    min = nums[0];
    for (i = 0; i < m; i++) {
        if (nums[i] > max) {
            max = nums[i];
        }

        if(nums[i] < min) {
            min = nums[i];
        }
    }

    printf("biggest num: %d\nsmallest num: %d\n", max, min);

    free(nums);

}

char *get_str() {
    char buf[81] = {0};
    char *res = NULL;
    int len = 0;
    int n = 0;
    do {
        n = scanf("%80[^\n]", buf);
        if (n < 0) {
            if (!res) {
                return NULL;
            }
        } else if (n > 0) {
            int chunk_len = strlen(buf);
            int str_len = len + chunk_len;
            res = realloc(res, str_len + 1);
            memcpy(res + len, buf, chunk_len);
            len = str_len;
        } else {
            scanf("%*c");
        }
    } while (n > 0);

    if (len > 0) {
        res[len] = '\0';
    } else {
        res = calloc(1, sizeof(char));
    }

    return res;
}

void do_reverse(char *s){
    int begin = 0;
    char *str = (char*) calloc(strlen(s) + 1, sizeof(char));
    int last;
    for(last= strlen(s)- 1; last >= 0; last--) {
        str[begin] = s[last];
        begin++;
    }
    printf("reversed string: \"%s\n", str);
    free(s);
    free(str);
}
void reverse_string() {
    char *s = NULL;
    char *s2 = NULL;
    getchar();
    printf("enter a string:");
    s = get_str();
    do_reverse(s);
}

void insertionSort(int *nums, int m)
{
    int i, key, j;
    for (i = 1; i < m; i++) {
        key = nums[i];
        j = i - 1;

        while (j >= 0 && nums[j] > key) {
            nums[j + 1] = nums[j];
            j = j - 1;
        }
        nums[j + 1] = key;
    }
}

void binary_search() {
    int i, m, x;
    printf("Enter number of elements in array: ");
    scanf("%d", &m);
    int *nums = (int*) calloc(m, sizeof(int));
    printf("Enter elements into array\n");
    for (i = 0; i < m; i++) {
        printf("%d elemnt of array:", i + 1);
        scanf("%d", &nums[i]);
    }
    printf("\n");
    insertionSort(nums, m);

    printf("sorted elements:\n");
    for (i = 0; i < m; i++) {
        printf("%d\n", nums[i]);
    }

    printf("enter number to find in array: ");
    scanf("%d", &x);
    int start = 0, end = m - 1, mid = (start + end) / 2;

    bool found = false;
    while(start <= end) {
        if(x == nums[mid]) {
            printf("number %d at %d position\n", x, mid + 1);
            found = true;
            break;
        }
        else if( x > nums[mid]) {
            start = mid + 1;
        }
        else {
            end = mid - 1;
        }
        mid = (start + end) / 2;
    }
    if(!found){
        printf("%d is not in this array!\n", x);
    }
    free(nums);

}

int main() {

    srand(time(NULL));
    int k, p;
    do {
        printf("1.Remove even numbers from array\n2.Find biggest and smallest number in array\n3.Reverse a string\n4.Binary search in array\n\n");
        printf("Your choice: ");
        scanf("%d", &k);
        switch (k) {
            case 1:
                remove_even_numbers();
                break;
            case 2:
                biggest_smallest();
                break;
            case 3:
                reverse_string();
                break;
            case 4:
                binary_search();
                break;
            default:
                printf("You have entered a wrong number!\n");
                break;
        }
        printf("If you want to finish, press 0. Else, press any oyher number.\nYour choice: ");
        scanf("%d", &p);

        printf("\n");
    } while(p != 0);

    return 0;
}
