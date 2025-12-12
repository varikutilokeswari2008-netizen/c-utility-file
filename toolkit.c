#include "toolkit.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

/* ============================================================
   1–25: BASIC MATH FUNCTIONS
   ============================================================ */

// returns a + b
int add(int a, int b) { return a + b; }

// returns a - b
int sub(int a, int b) { return a - b; }

// returns a * b
int mul(int a, int b) { return a * b; }

// safe divide (returns 0 if b = 0 to avoid crash)
int divi(int a, int b) {
    if (b == 0) return 0;
    return a / b;
}

// returns remainder a % b
int mod(int a, int b) {
    if (b == 0) return 0;
    return a % b;
}

// returns bigger of two numbers
int max2(int a, int b) { return (a > b) ? a : b; }

// returns smaller of two numbers
int min2(int a, int b) { return (a < b) ? a : b; }

// max of 3 integers
int max3(int a, int b, int c) {
    int m = a;
    if (b > m) m = b;
    if (c > m) m = c;
    return m;
}

// min of 3 integers
int min3(int a, int b, int c) {
    int m = a;
    if (b < m) m = b;
    if (c < m) m = c;
    return m;
}

// returns absolute value
int absval(int x) { return (x < 0) ? -x : x; }

// simple power function (b^e)
int powi(int b, int e) {
    if (e < 0) return 0;
    int r = 1;
    for (int i = 0; i < e; ++i) r *= b;
    return r;
}

// factorial n! (small n only)
long long fact(int n) {
    if (n < 0) return 0;
    long long r = 1;
    for (int i = 1; i <= n; ++i) r *= i;
    return r;
}

// check even
int even(int x) { return (x % 2 == 0); }

// check odd
int odd(int x)  { return !even(x); }

// check prime number
int prime(int n) {
    if (n <= 1) return 0;
    if (n == 2) return 1;
    if (n % 2 == 0) return 0;
    for (int i = 3; i * i <= n; i += 2)
        if (n % i == 0) return 0;
    return 1;
}

// greatest common divisor
int gcd(int a, int b) {
    if (a < 0) a = -a;
    if (b < 0) b = -b;
    while (b != 0) {
        int t = b;
        b = a % b;
        a = t;
    }
    return a;
}

// least common multiple
int lcm(int a, int b) {
    if (a == 0 || b == 0) return 0;
    return absval(a * b) / gcd(a, b);
}

// sum of digits of n
int sod(int n) {
    n = absval(n);
    int s = 0;
    while (n > 0) {
        s += n % 10;
        n /= 10;
    }
    return s;
}

// reverse digits of number
int revnum(int n) {
    int neg = (n < 0);
    if (neg) n = -n;
    int r = 0;
    while (n > 0) {
        r = r * 10 + (n % 10);
        n /= 10;
    }
    return neg ? -r : r;
}

// force x to stay within [lo, hi]
int clamp(int x, int lo, int hi) {
    if (x < lo) return lo;
    if (x > hi) return hi;
    return x;
}

// average of 3 integers
double avg3(int a, int b, int c) {
    return (a + b + c) / 3.0;
}

// swaps two numbers using pointers
void swap(int *a, int *b) {
    if (!a || !b) return;
    int t = *a;
    *a = *b;
    *b = t;
}

// check if Armstrong number
int armstrong(int n) {
    int orig = n;
    n = absval(n);
    int temp = n, digits = 0;

    // count digits
    while (temp > 0) { digits++; temp /= 10; }

    // calculate sum of digits^digits
    int sum = 0;
    temp = n;
    while (temp > 0) {
        int d = temp % 10;
        sum += powi(d, digits);
        temp /= 10;
    }
    return (sum == absval(orig));
}

// nth fibonacci number
int fib(int n) {
    if (n < 0) return 0;
    if (n == 0) return 0;
    if (n == 1) return 1;

    int a = 0, b = 1, c;
    for (int i = 2; i <= n; ++i) {
        c = a + b;
        a = b;
        b = c;
    }
    return b;
}

// number of divisors
int divisors(int n) {
    if (n == 0) return 0;
    n = absval(n);
    int count = 0;

    for (int i = 1; i * i <= n; ++i) {
        if (n % i == 0) {
            count += 2;
            if (i * i == n) count--; // perfect square
        }
    }
    return count;
}


/* ============================================================
   26–50: ARRAY FUNCTIONS (INT)
   ============================================================ */

// sum of array elements
int sumArr(const int *a, int n) {
    if (!a || n <= 0) return 0;
    int s = 0;
    for (int i = 0; i < n; ++i) s += a[i];
    return s;
}

// largest element
int maxArr(const int *a, int n) {
    if (!a || n <= 0) return 0;
    int m = a[0];
    for (int i = 1; i < n; ++i)
        if (a[i] > m) m = a[i];
    return m;
}

// smallest element
int minArr(const int *a, int n) {
    if (!a || n <= 0) return 0;
    int m = a[0];
    for (int i = 1; i < n; ++i)
        if (a[i] < m) m = a[i];
    return m;
}

// linear search
int searchArr(const int *a, int n, int key) {
    if (!a || n <= 0) return -1;
    for (int i = 0; i < n; ++i)
        if (a[i] == key) return i;
    return -1;
}

// count even numbers
int countEven(const int *a, int n) {
    if (!a || n <= 0) return 0;
    int c = 0;
    for (int i = 0; i < n; ++i)
        if (a[i] % 2 == 0) c++;
    return c;
}

// count odd numbers
int countOdd(const int *a, int n) {
    if (!a || n <= 0) return 0;
    int c = 0;
    for (int i = 0; i < n; ++i)
        if (a[i] % 2 != 0) c++;
    return c;
}

// reverse entire array
void revArr(int *a, int n) {
    if (!a || n <= 0) return;
    int i = 0, j = n - 1;
    while (i < j) swap(&a[i++], &a[j--]);
}

// check if sorted (ascending)
int sortedArr(const int *a, int n) {
    if (!a || n <= 1) return 1;
    for (int i = 1; i < n; ++i)
        if (a[i] < a[i - 1]) return 0;
    return 1;
}

// copy array
void copyArr(const int *src, int *dst, int n) {
    if (!src || !dst || n <= 0) return;
    for (int i = 0; i < n; ++i)
        dst[i] = src[i];
}

// check if two arrays equal
int equalArr(const int *a, const int *b, int n) {
    if (!a || !b || n <= 0) return 0;
    for (int i = 0; i < n; ++i)
        if (a[i] != b[i]) return 0;
    return 1;
}

// bubble sort ascending
void sortArr(int *a, int n) {
    if (!a || n <= 1) return;
    for (int i = 0; i < n - 1; ++i)
        for (int j = 0; j < n - 1 - i; ++j)
            if (a[j] > a[j + 1])
                swap(&a[j], &a[j + 1]);
}

// second largest number
int secondMax(const int *a, int n) {
    if (!a || n < 2) return 0;
    int max1 = a[0], max2v = a[0];
    for (int i = 1; i < n; ++i) {
        if (a[i] > max1) {
            max2v = max1;
            max1 = a[i];
        } else if (a[i] > max2v && a[i] != max1) {
            max2v = a[i];
        }
    }
    return max2v;
}

// rotate array left by k elements
void rotLeft(int *a, int n, int k) {
    if (!a || n <= 0) return;
    k %= n;
    int *tmp = malloc(n * sizeof(int));
    for (int i = 0; i < n; ++i)
        tmp[i] = a[(i + k) % n];
    for (int i = 0; i < n; ++i)
        a[i] = tmp[i];
    free(tmp);
}

// rotate array right by k elements
void rotRight(int *a, int n, int k) {
    k %= n;
    rotLeft(a, n, n - k);
}

// prefix sum array
int prefixSumArr(const int *a, int n, int *out) {
    if (!a || !out || n <= 0) return -1;
    int sum = 0;
    for (int i = 0; i < n; ++i) {
        sum += a[i];
        out[i] = sum;
    }
    return 0;
}

// find first element satisfying a condition
int findFirstPred(const int *a, int n, int (*pred)(int)) {
    if (!a || !pred || n <= 0) return -1;
    for (int i = 0; i < n; ++i)
        if (pred(a[i])) return i;
    return -1;
}

// count how many times value appears
int countVal(const int *a, int n, int v) {
    if (!a || n <= 0) return 0;
    int c = 0;
    for (int i = 0; i < n; ++i)
        if (a[i] == v) c++;
    return c;
}

// index of max element
int indexMax(const int *a, int n) {
    if (!a || n <= 0) return -1;
    int idx = 0;
    for (int i = 1; i < n; ++i)
        if (a[i] > a[idx]) idx = i;
    return idx;
}

// index of minimum element
int indexMin(const int *a, int n) {
    if (!a || n <= 0) return -1;
    int idx = 0;
    for (int i = 1; i < n; ++i)
        if (a[i] < a[idx]) idx = i;
    return idx;
}

// fill array with value
void fillArr(int *a, int n, int v) {
    if (!a || n <= 0) return;
    for (int i = 0; i < n; ++i)
        a[i] = v;
}

// swap elements using indexes
void swapArr(int *a, int i, int j) {
    if (!a) return;
    swap(&a[i], &a[j]);
}

// average of array
double avgArr(const int *a, int n) {
    if (!a || n <= 0) return 0.0;
    return (double)sumArr(a, n) / n;
}

// sum of only positive values
int sumPos(const int *a, int n) {
    if (!a || n <= 0) return 0;
    int s = 0;
    for (int i = 0; i < n; ++i)
        if (a[i] > 0) s += a[i];
    return s;
}

// sum of only negative values
int sumNeg(const int *a, int n) {
    if (!a || n <= 0) return 0;
    int s = 0;
    for (int i = 0; i < n; ++i)
        if (a[i] < 0) s += a[i];
    return s;
}


/* ============================================================
   51–75: STRING FUNCTIONS (char*)
   ============================================================ */

// returns length of string
size_t lenStr(const char *s) {
    size_t len = 0;
    while (s && s[len] != '\0') len++;
    return len;
}

// copies string s into d
void copyStr(char *d, const char *s) {
    if (!d || !s) return;
    while (*s) *d++ = *s++;
    *d = '\0';
}

// appends s to end of d
void catStr(char *d, const char *s) {
    if (!d || !s) return;
    while (*d) d++;   // go to end
    while (*s) *d++ = *s++;
    *d = '\0';
}

// compare strings
int cmpStr(const char *a, const char *b) {
    while (*a && *b && *a == *b) { a++; b++; }
    return (unsigned char)*a - (unsigned char)*b;
}

// convert to uppercase
void upStr(char *s) {
    while (s && *s) {
        *s = toupper(*s);
        s++;
    }
}

// convert to lowercase
void lowStr(char *s) {
    while (s && *s) {
        *s = tolower(*s);
        s++;
    }
}

// check palindrome string
int palStr(const char *s) {
    size_t i = 0, j = lenStr(s);
    if (j == 0) return 1;
    j--;
    while (i < j) {
        if (s[i] != s[j]) return 0;
        i++;
        j--;
    }
    return 1;
}

// count vowels
int countVow(const char *s) {
    int c = 0;
    while (s && *s) {
        char ch = tolower(*s);
        if (ch=='a'||ch=='e'||ch=='i'||ch=='o'||ch=='u') c++;
        s++;
    }
    return c;
}

// count consonants
int countCon(const char *s) {
    int c = 0;
    while (s && *s) {
        char ch = tolower(*s);
        if (isalpha(ch) && !(ch=='a'||ch=='e'||ch=='i'||ch=='o'||ch=='u')) c++;
        s++;
    }
    return c;
}

// reverse string
void revStr(char *s) {
    size_t i = 0, j = lenStr(s) - 1;
    while (i < j) {
        char t = s[i]; s[i] = s[j]; s[j] = t;
        i++; j--;
    }
}

// remove all spaces
void trimSpace(char *s) {
    char *d = s;
    while (*s) {
        if (*s != ' ') *d++ = *s;
        s++;
    }
    *d = '\0';
}

// count occurrences of character
int countChar(const char *s, char c) {
    int cnt = 0;
    while (s && *s) if (*s++ == c) cnt++;
    return cnt;
}

// find index of character
int findChar(const char *s, char c) {
    for (int i = 0; s && s[i]; i++)
        if (s[i] == c) return i;
    return -1;
}

// check prefix
int starts(const char *s, const char *p) {
    while (*p) {
        if (*s++ != *p++) return 0;
    }
    return 1;
}

// check suffix
int ends(const char *s, const char *p) {
    size_t ls = lenStr(s), lp = lenStr(p);
    if (lp > ls) return 0;
    return (cmpStr(s + (ls - lp), p) == 0);
}

// remove newline at end
void trimNL(char *s) {
    size_t len = lenStr(s);
    if (len > 0 && s[len-1] == '\n') s[len-1] = '\0';
}

// safe input from keyboard
void readStr(char *buf, int size) {
    if (fgets(buf, size, stdin)) trimNL(buf);
    else buf[0] = '\0';
}

// print string
void printStr(const char *s) {
    printf("%s", s);
}

// convert to title Case
void titleStr(char *s) {
    int nw = 1;
    while (*s) {
        if (isspace(*s)) nw = 1;
        else {
            *s = nw ? toupper(*s) : tolower(*s);
            nw = 0;
        }
        s++;
    }
}

// check alphabetic-only
int alphaStr(const char *s) {
    while (*s) {
        if (!isalpha(*s)) return 0;
        s++;
    }
    return 1;
}

// check digit-only
int digitStr(const char *s) {
    while (*s) {
        if (!isdigit(*s)) return 0;
        s++;
    }
    return 1;
}

// check alphanumeric-only
int alnumStr(const char *s) {
    while (*s) {
        if (!isalnum(*s)) return 0;
        s++;
    }
    return 1;
}

// remove all occurrences of char c
void removeChar(char *s, char c) {
    char *d = s;
    while (*s) {
        if (*s != c) *d++ = *s;
        s++;
    }
    *d = '\0';
}

// replace all old char with new char
void replaceChar(char *s, char o, char n) {
    while (*s) {
        if (*s == o) *s = n;
        s++;
    }
}

// count words in string
int wordCount(const char *s) {
    int wc = 0, inWord = 0;
    while (*s) {
        if (isspace(*s)) inWord = 0;
        else if (!inWord) { wc++; inWord = 1; }
        s++;
    }
    return wc;
}


/* ============================================================
   76–83: 3x3 MATRIX FUNCTIONS
   ============================================================ */

// matrix addition
void add3(int a[3][3], int b[3][3], int r[3][3]) {
    for (int i = 0; i < 3; i++)
        for (int j = 0; j < 3; j++)
            r[i][j] = a[i][j] + b[i][j];
}

// matrix subtraction
void sub3(int a[3][3], int b[3][3], int r[3][3]) {
    for (int i = 0; i < 3; i++)
        for (int j = 0; j < 3; j++)
            r[i][j] = a[i][j] - b[i][j];
}

// transpose matrix
void trans3(int a[3][3], int r[3][3]) {
    for (int i = 0; i < 3; i++)
        for (int j = 0; j < 3; j++)
            r[j][i] = a[i][j];
}

// trace of matrix (sum of diagonal)
int trace3(int a[3][3]) {
    return a[0][0] + a[1][1] + a[2][2];
}

// multiply matrix by scalar k
void smul3(int a[3][3], int k) {
    for (int i = 0; i < 3; i++)
        for (int j = 0; j < 3; j++)
            a[i][j] *= k;
}

// print matrix
void print3(int a[3][3]) {
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++)
            printf("%d ", a[i][j]);
        printf("\n");
    }
}

// check if matrix is diagonal
int diag3(int a[3][3]) {
    for (int i = 0; i < 3; i++)
        for (int j = 0; j < 3; j++)
            if (i != j && a[i][j] != 0) return 0;
    return 1;
}

// check if identity matrix
int ident3(int a[3][3]) {
    for (int i = 0; i < 3; i++)
        for (int j = 0; j < 3; j++)
            if ((i == j && a[i][j] != 1) ||
                (i != j && a[i][j] != 0))
                return 0;
    return 1;
}


/* ============================================================
   84–100: MISC, BITWISE, CONVERSIONS
   ============================================================ */

// Celsius → Fahrenheit
double c2f(double c) { return c * 9.0 / 5.0 + 32.0; }

// Fahrenheit → Celsius
double f2c(double f) { return (f - 32.0) * 5.0 / 9.0; }

// check leap year
int leap(int y) {
    if (y % 400 == 0) return 1;
    if (y % 100 == 0) return 0;
    if (y % 4 == 0)   return 1;
    return 0;
}

// days in month (1–12)
int dim(int m, int y) {
    if (m < 1 || m > 12) return -1;
    int days[] = {31,28,31,30,31,30,31,31,30,31,30,31};
    if (m == 2 && leap(y)) return 29;
    return days[m - 1];
}

// sum 1 to n
int sumN(int n) {
    if (n < 1) return 0;
    return n * (n + 1) / 2;
}

// random integer in [lo, hi]
int randInt(int lo, int hi) {
    if (lo > hi) { int t = lo; lo = hi; hi = t; }
    return lo + rand() % (hi - lo + 1);
}

// fill array with random numbers
void fillRand(int *a, int n, int lo, int hi) {
    for (int i = 0; i < n; i++)
        a[i] = randInt(lo, hi);
}

// delay loop (busy wait)
void delay(long long c) {
    volatile long long x;
    for (x = 0; x < c; x++) { }
}

// check if n is power of two
int pow2(int n) {
    if (n <= 0) return 0;
    return (n & (n - 1)) == 0;
}

// count 1 bits in binary
int bitcount(unsigned int x) {
    int c = 0;
    while (x) { c += x & 1; x >>= 1; }
    return c;
}

// set bit b
unsigned int setbit(unsigned int x, int b) {
    return x | (1u << b);
}

// clear bit b
unsigned int clrbit(unsigned int x, int b) {
    return x & ~(1u << b);
}

// toggle bit b
unsigned int togbit(unsigned int x, int b) {
    return x ^ (1u << b);
}

// check bit b
int chkbit(unsigned int x, int b) {
    return (x & (1u << b)) ? 1 : 0;
}

// print number in binary
void binprint(unsigned int x) {
    for (int i = 31; i >= 0; i--)
        printf("%d", (x & (1u << i)) ? 1 : 0);
    printf("\n");
}

// sum array elements using long long
long long sumArrLL(const int *a, int n) {
    long long s = 0;
    for (int i = 0; i < n; i++) s += a[i];
    return s;
}

// check sign of number
int sign(int x) {
    if (x > 0) return 1;
    if (x < 0) return -1;
    return 0;
}


