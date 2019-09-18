/**

 * Goes over some basic programming principles, such as Sorting and Recursion

 * Completion time: 0.5 hours

 *

 * @author Gunnar Hoglund

 * @version 1.0

 */
package app;

public class Homework {

    // Puts 0's in the odd positions of the array
    // and 5's in the even positions
    public static void initializeArray(int[] x) {
        for (int i = 0; i < x.length; i++) {
            if (i % 2 != 0)
                x[i] = 0;
            else
                x[i] = 5;
        }
    }

    // prints the array to the terminal
    public static void printArray(int[] x) {
        for (int i = 0; i < x.length; i++) {
            System.out.print(x[i]);
            if (i == x.length - 1)
                System.out.println();
            else
                System.out.print(", ");
        }
    }

    // Sorts an array in descending order
    // Using the insertion sort algorithm
    public static void insertionSort(int[] x) {

        // incrementing through array
        for (int i = 1; i < x.length; ++i) {
            int key = x[i];
            int j = i - 1;

            // move element that is larger than key over by 1 position
            while (j >= 0 && x[j] < key) {
                x[j + 1] = x[j];
                j = j - 1;
            }
            x[j + 1] = key;
        }
    }

    // recursively calculates the factorial
    // of a number passed to the method
    public static int factorial(int x) {
        if (x == 1)
            return 1;

        int fact;

        fact = factorial(x - 1) * x;
        return fact;
    }

    public static void main(String[] args) {
        int[] a = { 2, 5, 7, 9, 12, 13, 15, 17, 19, 20 };
        int[] b = { 18, 16, 19, -5, 3, 14, 6, 0 };
        int[] c = { 4, 2, 5, 3, 1 };

        // testing initializeArray
        printArray(a); // print: 5, 7, 9, 12, 13, 15, 17, 19, 20
        initializeArray(a);
        printArray(a);

        // testing insertionSort
        printArray(b);
        insertionSort(b);
        printArray(b);

        // testing factorial
        System.out.println(factorial(5));

        c[0] = factorial(c[0]);
        c[1] = factorial(c[2]);
        printArray(c); // print: 24, 120, 5, 3, 1

    }

}