#include <stdio.h>

void main()
{
    int values[10];
    int i, j, x, tmp;
    for (i = 0; i < 10; i++)
        scanf("%d", &values[i]);
    for(i = 0; i < 9; i++)
    {
        for(j = 0; j < 9; j++)
        {
            if(values[j] > values[j + 1])
            {
                tmp = values[j + 1];
                values[j + 1] = values[j];
                values[j] = tmp;
            }
        }
    }
    for(i = 0; i < 9; i++)
    {
        printf("%d, ", values[i]);
    }
    printf("%d\n", values[i]);
}