/*
* This program covers primitive data types, recursion and
* other basic programming concepts
*
* Completion time: 2 hours
*
* @author Gunnar Hoglund
* @version 1.0
*/
#include <stdio.h>

// loops through the array and puts 0s in the odd positions
// and 5s in the even positions
void initialize_array(int *array, int length)
{
    for (int i = 0; i < length; i++)
    {

        // if the position is even, change the value to 5
        if (i % 2 == 0)
        {
            *array = 0;
        }
        else
        {
            *array = 5;
        }

        //incrementing the address in memory
        array++;
    }
}

// prints an array
void print_array(int *array, int length)
{
    for (int i = 0; i < length - 1; i++)
    {
        printf("%d", *array);
        printf(", ");

        array++;
    }
    printf("%d\n", *array);
}

// sorts an array using the insertion sort method
void insertion_sort(int *array, int length)
{
    // variables
    int i, j, k;

    for (i = 1; i < length; ++i)
    {
        k = array[i];
        j = i - 1;

        while ((j >= 0) && (k > array[j]))
        {
            array[j + 1] = array[j];
            --j;
        }
        array[j + 1] = k;
    }
}

// function calculates the factorial
// of the number passed to it recursively
int factorial(int num)
{
    // if the number is 1 then return
    if (num == 1)
    {
        return 1;
    }

    int fact;

    fact = factorial(num - 1) * num;
    return fact;
}

int main()
{
    int a[] = {2, 5, 7, 9, 12, 13, 15, 17, 19, 20};
    int b[] = {18, 16, 19, -5, 3, 14, 6, 0};
    int c[] = {4, 2, 5, 3, 1};

    /* testing initialize_array */
    print_array(a, sizeof(a) / sizeof(a[0])); /* print: 2, 5, 7, 9, 12, 13, 15, 17, 19, 20 */
    initialize_array(a, sizeof(a) / sizeof(a[0]));
    print_array(a, sizeof(a) / sizeof(a[0])); /* print: 5, 0, 5, 0, 5, 0, 5, 0, 5, 0 */

    /* testing insertionSort */
    print_array(b, sizeof(b) / sizeof(b[0])); /* print: 18, 16, 19, -5, 3, 14, 6, 0 */
    insertion_sort(b, sizeof(b) / sizeof(b[0]));
    print_array(b, sizeof(b) / sizeof(b[0])); /* print: 19, 18, 16, 14, 6, 3, 0, -5 */

    // /* testing factorial */
    printf("%d\n", factorial(5)); /* print: 120 */

    c[0] = factorial(c[0]);
    c[1] = factorial(c[2]);
    print_array(c, sizeof(c) / sizeof(c[0])); /* print: 24, 120, 5, 3, 1 */

    return 0;
}
