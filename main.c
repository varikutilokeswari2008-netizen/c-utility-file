
// main.c
// Demo program for custom header file: toolkit.h
// Shows 12 functions from math, array, string and misc utilities.

#include <stdio.h>
#include "toolkit.h"

int main(void) {
    printf("======= CUSTOM TOOLKIT DEMO =======\n\n");

    /* ============================
       1. MATH FUNCTIONS
       ============================ */
    int a = 20, b = 8;

    printf("--- MATH FUNCTIONS ---\n");
    printf("add(%d, %d) = %d\n", a, b, add(a, b));            // 20 + 8
    printf("gcd(%d, %d) = %d\n", a, b, gcd(a, b));            // gcd(20, 8)
    printf("fib(10) = %d\n\n", fib(10));                      // 10th Fibonacci



    /* ============================
       2. ARRAY FUNCTIONS
       ============================ */
    int arr[7] = {5, 2, 9, 1, 7, 3, 4};
    int n = 7;

    printf("--- ARRAY FUNCTIONS ---\n");
    printf("Array elements: ");
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    printf("sumArr(arr, %d) = %d\n", n, sumArr(arr, n));      // sum of array
    printf("maxArr(arr, %d) = %d\n", n, maxArr(arr, n));      // max element

    int key = 7;
    int pos = searchArr(arr, n, key);                         // search key
    if (pos != -1)
        printf("searchArr(arr, %d) found at index %d\n", key, pos);
    else
        printf("searchArr(arr, %d) not found\n", key);

    // sort array
    sortArr(arr, n);
    printf("sorted array: ");
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n\n");



    /* ============================
       3. STRING FUNCTIONS
       ============================ */
    char s1[50] = "hello world";
    char s2[50];

    printf("--- STRING FUNCTIONS ---\n");
    printf("original s1: \"%s\"\n", s1);

    // lenStr
    printf("lenStr(s1) = %zu\n", lenStr(s1));

    // upStr
    copyStr(s2, s1);              // copy "hello world" to s2
    upStr(s2);                    // convert to upper case
    printf("upStr(s1) -> \"%s\"\n", s2);

    // revStr
    revStr(s2);                   // reverse the string
    printf("revStr(UPPER) -> \"%s\"\n\n", s2);



    /* ============================
       4. MISC FUNCTIONS
       ============================ */
    printf("--- MISC FUNCTIONS ---\n");

    // c2f : Celsius to Fahrenheit
    double c = 37.0;
    double f = c2f(c);
    printf("c2f(%.2f) = %.2f F\n", c, f);

    // bitcount : count 1 bits in binary
    unsigned int x = 29;          // 29 = 11101 in binary
    printf("bitcount(%u) = %d\n", x, bitcount(x));

    printf("\n======= END OF DEMO =======\n");

    return 0;
}