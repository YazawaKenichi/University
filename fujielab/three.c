#include <stdio.h>

void count(char *str)
{
	char *ptr = str;
	int alpha = 0, num = 0, oth = 0;
	while(*ptr != 0x00)
	{
		if(*ptr >= 'A' && *ptr <= 'Z' || *ptr >= 'a' && *ptr <= 'z')
		{
			alpha++;
		}
		else if('0' <= *ptr && *ptr <= '9')
		{
			num++;
		}
		else
		{
			oth++;
		}
		ptr++;
	}
	printf("%d, %d, %d\n", alpha, num, oth);
	return ;
}

void main()
{
	count("Hello, 16th students!");
}
