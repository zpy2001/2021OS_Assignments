#include <stdio.h>

typedef struct {
    char c;
    short s;
    double d;
}struct_t;

typedef union {
    char c;
    int i;
}union_t;
int main() {
    char c;
    short s;
    int i;
    long l;
    long long ll;
    float f;
    double d;
    long double ld;
    void * v;
    struct_t str;
    union_t uni;
    printf("%lu\n", sizeof (c));
    printf("%lu\n", sizeof (s));
    printf("%lu\n", sizeof (i));
    printf("%lu\n", sizeof (l));
    printf("%lu\n", sizeof (ll));
    printf("%lu\n", sizeof (f));
    printf("%lu\n", sizeof (d));
    printf("%lu\n", sizeof (ld));
    printf("%lu\n", sizeof (v));
    printf("%lu\n", sizeof (str));
    printf("%lu\n", sizeof (uni));

    return 0;
}
