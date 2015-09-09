
#include <stdio.h>
#include <stdlib.h>

#define MAXSTACK 50

int
main(int argc,  char **argv)
{
	if (argc < 2)
	{
		printf("Usage: isbalanced expression\n");
		exit(1);
	}
	if (isBalanced(argv[1]))
	{
		printf("string is balanced\n");
	}
	else
	{
		printf("string is not balanced\n");
	}
}
int isBalanced(char*str)
{
	char stack[MAXSTACK];
	int i = 0;
	while (*str != '\0')
	{
		if (*str == '(' || *str == '{' || *str == '[')
		{
			stack[i] = *str;
			i ++;
		}
		else if(*str == '}')
		{
			i --;
			if (stack[i] == '{')
			{
				stack[i] = '\0';
			}
			else
			{
				return 0;
			}
		}
		else if (*str == ']')
		{
			i --;
			if (stack[i] == '[')
			{
				stack[i] = '\0';
			}
			else
			{
				return 0;
			}
		}
		else if (*str == ')')
		{
			i --;
			if (stack[i] == '(')
			{
				stack[i] = '\0';
			}
			else
			{
				return 0;
			}
		}
		str ++;
	}
	if (stack[0] == '\0')
	{
		return 1;
	}
	return 0;
}
