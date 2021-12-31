#include <stdio.h>

typedef struct {
    char c;
    short s;
    int i;
    long l;
    float f;
    double d;
    long double ld;
}struct_t1;

typedef struct {
    char c;
    short s;
    int i;
    long l;
    float f;
    double d;
}struct_t2;

typedef struct {
    char c;
    short s;
    int i;
    double d;
}struct_t3;

typedef struct {
    char c;
    int i;
}struct_t4;

typedef struct {
    long i;
    long d;
    long c;
    long s;
}struct_t5;

int main() {

    struct_t1 str1;
    struct_t2 str2;
    struct_t3 str3;
    struct_t4 str4;
    struct_t5 str5;

    printf("%lu\n", sizeof (str1));
    printf("%lu\n", sizeof (str2));
    printf("%lu\n", sizeof (str3));
    printf("%lu\n", sizeof (str4));
    printf("%lu\n", sizeof (str5));

    return 0;
}
