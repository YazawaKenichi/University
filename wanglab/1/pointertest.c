/// pointer test

#include <stdio.h>

#define COUNT 0
#define AMPERSAND4 0
#define AMPERSAND3 0
#define AMPERSAND2 0
#define AMPERSAND1 1

void intput4(int ****result)
{
    ****result++;
    printf("input4 result = %d\n", ****result);
}

void input3(int ***result)
{
    ***result++;
    printf("input3 result = %d\n", ***result);
#if AMPERSAND4
    input4(&&&&result);
#endif
#if AMPERSAND1
    input4(&result);
#endif
}

void input2(int **result)
{
    **result++;
    printf("input2 result = %d\n", **result);
#if AMPERSAND3
    input2(&&&result);
#endif
#if AMPERSAND1
    input2(&result);
#endif
}

void input1(int *result)
{
    *result++;
    printf("input1 result = %d\n", *result);
#if AMPERSAND2
    input2(&&result);
#endif
#if AMPERSAND1
    input2(&result);
#endif
}

void main()
{
    int result;
    input1(&result);
    printf("result = %d\n", result);
}
