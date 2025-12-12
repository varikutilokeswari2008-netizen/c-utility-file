#ifndef TOOLKIT_H
#define TOOLKIT_H

#include <stddef.h>

/* ---------- 1–25 MATH ---------- */

int add(int a, int b);
int sub(int a, int b);
int mul(int a, int b);
int divi(int a, int b);
int mod(int a, int b);
int max2(int a, int b);
int min2(int a, int b);
int max3(int a, int b, int c);
int min3(int a, int b, int c);
int absval(int x);
int powi(int b, int e);
long long fact(int n);
int even(int x);
int odd(int x);
int prime(int n);
int gcd(int a, int b);
int lcm(int a, int b);
int sod(int n);            // sum of digits
int revnum(int n);
int clamp(int x, int lo, int hi);
double avg3(int a, int b, int c);
void swap(int *a, int *b);
int armstrong(int n);
int fib(int n);
int divisors(int n);

/* ---------- 26–50 ARRAY INT ---------- */

int sumArr(const int *a, int n);
int maxArr(const int *a, int n);
int minArr(const int *a, int n);
int searchArr(const int *a, int n, int key);
int countEven(const int *a, int n);
int countOdd(const int *a, int n);
void revArr(int *a, int n);
int sortedArr(const int *a, int n);
void copyArr(const int *src, int *dst, int n);
int equalArr(const int *a, const int *b, int n);
void sortArr(int *a, int n);
int secondMax(const int *a, int n);
void rotLeft(int *a, int n, int k);
void rotRight(int *a, int n, int k);
int prefixSumArr(const int *a, int n, int *out);
int findFirstPred(const int *a, int n, int (*pred)(int));
int countVal(const int *a, int n, int v);
int indexMax(const int *a, int n);
int indexMin(const int *a, int n);
void fillArr(int *a, int n, int v);
void swapArr(int *a, int i, int j);
double avgArr(const int *a, int n);
int sumPos(const int *a, int n);
int sumNeg(const int *a, int n);

/* ---------- 51–75 STRINGS ---------- */

size_t lenStr(const char *s);
void copyStr(char *d, const char *s);
void catStr(char *d, const char *s);
int cmpStr(const char *a, const char *b);
void upStr(char *s);
void lowStr(char *s);
int palStr(const char *s);
int countVow(const char *s);
int countCon(const char *s);
void revStr(char *s);
void trimSpace(char *s);
int countChar(const char *s, char c);
int findChar(const char *s, char c);
int starts(const char *s, const char *p);
int ends(const char *s, const char *p);
void trimNL(char *s);
void readStr(char *buf, int size);
void printStr(const char *s);
void titleStr(char *s);
int alphaStr(const char *s);
int digitStr(const char *s);
int alnumStr(const char *s);
void removeChar(char *s, char c);
void replaceChar(char *s, char o, char n);
int wordCount(const char *s);

/* ---------- 76–83 MATRIX 3x3 ---------- */

void add3(int a[3][3], int b[3][3], int r[3][3]);
void sub3(int a[3][3], int b[3][3], int r[3][3]);
void trans3(int a[3][3], int r[3][3]);
int trace3(int a[3][3]);
void smul3(int a[3][3], int k);
void print3(int a[3][3]);
int diag3(int a[3][3]);
int ident3(int a[3][3]);

/* ---------- 84–100 MISC ---------- */

double c2f(double c);
double f2c(double f);
int leap(int y);
int dim(int m, int y);      // days in month
int sumN(int n);
int randInt(int lo, int hi);
void fillRand(int *a, int n, int lo, int hi);
void delay(long long c);
int pow2(int n);
int bitcount(unsigned int x);
unsigned int setbit(unsigned int x, int b);
unsigned int clrbit(unsigned int x, int b);
unsigned int togbit(unsigned int x, int b);
int chkbit(unsigned int x, int b);
void binprint(unsigned int x);
long long sumArrLL(const int *a, int n);
int sign(int x);

#endif
