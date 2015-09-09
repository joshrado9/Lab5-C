
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Adds src at the end of dest. Return the value of dest.
char *mystrcat(char * dest, char * src)
{
	char * cpyD = dest;
	char * cpyS = src;
	while (*cpyD != '\0')
	{
		cpyD ++;
	}
	while (*cpyS != '\0')
	{
		*cpyD = *cpyS;
		cpyS ++;
		cpyD ++;
	}
	*cpyD = '\0';
	return dest;
}


// Return a pointer to the first occurrence of the substring needle in
// the string haystack. 
// Return NULL if the string is not found.
char * mystrstr(char * haystack, char * needle)
{
	char * cpyN = needle;
	char * cpyH = haystack;
	while (*cpyH != '\0')
	{
		if (*cpyH == *cpyN)
		{
			char * foundN = cpyN;
			char * foundH = cpyH;
			while (*foundN != '\0' && *foundH != '\0' && *foundH == *foundN)
			{
				foundN ++;
				foundH ++;
			}
			if (*foundN == '\0')
			{
				return cpyH;
			}
		}
		cpyH ++;
	}
	return NULL;
}


// Trims any spaces that are at the beginning or the end of s and returns s.
// Use the same memory passed in s. 
// Example:
// char s1[20];
// strcpy(s1,      hello    );
// strtrim(s1);
// printf(<s1=%s>\n, s1); // it will print <s1=hello>  without the spaces.
char * mystrtrim(char * s)
{
	char * cpy = s;
	while (*cpy == ' ')
	{
		cpy ++;
	}
	char * trans = s;
	while (*cpy != '\0')
	{
		char temp = *cpy;
		*cpy = ' ';
		*trans = temp;
		trans ++;
		cpy ++;
	}
	cpy --;
	while (*cpy == ' ')
	{
		*cpy = '\0';
		cpy --;
	}
}


// Returns a new string that will substitute the first occurrence of the substring from
//  to the substring to in the string src
// This call will allocate memory for the new string and it will return the new string.
// Example:
// char a[6];
// strcpy(a, apple);
// char * b = strreplace(a, pp, orange);
// printf(<b=%s>\n, b); // It will print <b=aorangele>  
char * mystrreplace( char * src, char * from, char * to)
{
	char * index = mystrstr(src, from);
	char * fromcpy = from;
	char * tocpy = to;
	int srclen = strlen(src);
	int fromlen = strlen(from);
	int tolen = strlen(to);
	int newstrlen = srclen + tolen - fromlen;
	char * newstr = (char *) malloc(sizeof(char)*newstrlen);
	char * start = newstr;
	while (src != index)
	{
		*newstr = *src;
		src ++;
		newstr ++;
	}
	while(*to != '\0')
	{
		*newstr = *to;
		newstr ++;
		to ++;
	}
	int count = 0;
	while (count < fromlen)
	{
		src ++;
		count ++;
	}
	while (*src != '\0')
	{
		*newstr = *src;
		src ++;
		newstr ++;
	}
	if (mystrstr(start, from) != NULL)
	{
		start = mystrreplace(start, fromcpy, tocpy);
	}
	return start;
}
