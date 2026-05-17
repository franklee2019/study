#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define COUNT 100
#define MAX_RANDOM 1000

static int compare_ints(const void *a, const void *b)
{
    int x = *(const int *)a;
    int y = *(const int *)b;

    return (x > y) - (x < y);
}

static void print_numbers(const int numbers[], int count)
{
    for (int i = 0; i < count; i++) {
        printf("%4d", numbers[i]);

        if ((i + 1) % 10 == 0) {
            putchar('\n');
        }
    }
}

int main(void)
{
    int numbers[COUNT];

    srand((unsigned int)time(NULL));

    for (int i = 0; i < COUNT; i++) {
        numbers[i] = rand() % MAX_RANDOM;
    }

    printf("Before sorting:\n");
    print_numbers(numbers, COUNT);

    qsort(numbers, COUNT, sizeof(numbers[0]), compare_ints);

    printf("\nAfter sorting in ascending order:\n");
    print_numbers(numbers, COUNT);

    return 0;
}
