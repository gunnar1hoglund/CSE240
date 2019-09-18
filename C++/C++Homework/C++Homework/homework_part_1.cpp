/*
 * this program goes over some basic programming principles
 * such as arrays, sorting algorithms and recursion
 *
 * Completion time: 2 hours
 *
 * @author Gunnar Hoglund
 * @version 1.0
 */

#include <iostream>

using namespace std;

// puts 0s in the odd positions of the array
// and 5s in the even positions
void initializeArray(int *array, int length)
{
    for (int i = 0; i < length; i++)
    {
        // if even insert 0
        if (i % 2 == 0)
        {
            array[i] = 0;
        }
        else
        {
            // otherwise insert 5s
            array[i] = 5;
        }
    }
}

void printArray(int *array, int length)
{
    for (int i = 0; i < length; i++)
    {
        cout << *array++ << " ";
    }
    cout << endl;
}

// sorts an array of ints in descending order
// using the insertion sort algorithm
void insertionSort(int *array, int length)
{
    int i, j, key;
    for (i = 1; i < length; i++)
    {
        key = array[i];
        j = i - 1;

        while (j >= 0 && array[j] < key)
        {
            array[j + 1] = array[j];
            j = j - 1;
        }
        array[j + 1] = key;
    }
}

// function calculates the factorial
// of the number passed to it recursively
int factorial(int num)
{
    // base case
    if (num == 1)
    {
        return 1;
    }

    return factorial(num - 1) * num;
}

int main()
{
    int a[] = {2, 5, 7, 9, 12, 13, 15, 17, 19, 20};
    int b[] = {18, 16, 19, -5, 3, 14, 6, 0};
    int c[] = {4, 2, 5, 3, 1};

    /* testing initialize_array */
    printArray(a, sizeof(a) / sizeof(a[0])); /* print: 2, 5, 7, 9, 12, 13, 15, 17, 19, 20 */
    initializeArray(a, sizeof(a) / sizeof(a[0]));
    printArray(a, sizeof(a) / sizeof(a[0])); /* print: 5, 0, 5, 0, 5, 0, 5, 0, 5, 0 */

    //    /* testing insertionSort */
    printArray(b, sizeof(b) / sizeof(b[0])); /* print: 18, 16, 19, -5, 3, 14, 6, 0 */
    insertionSort(b, sizeof(b) / sizeof(b[0]));
    printArray(b, sizeof(b) / sizeof(b[0])); /* print: 19, 18, 16, 14, 6, 3, 0, -5 */
                                             //
                                             //    /* testing factorial */
    cout << factorial(5) << endl;            /* print: 120 */
                                             //
    c[0] = factorial(c[0]);
    c[1] = factorial(c[2]);
    printArray(c, sizeof(c) / sizeof(c[0])); /* print: 24, 120, 5, 3, 1 */

    return 0;
}
