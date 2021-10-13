#include <stdio.h>

void main()
{
    int y;
    while(1)
    {
        printf("???:");
        scanf("%d", &y);
        if(y < 0)
            break;
        if(1989 <= y && y <= 2019)
            printf("%d is H %d\n", y, y - 1988);
        if(y >= 2019)
            printf("%d is R %d\n", y, y - 2019);
    }
}