
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct WordInfo {
	char * word;
	int count;
};

typedef struct WordInfo WordInfo;

int maxWords;
int nWords;
WordInfo*  wordArray;

#define MAXWORD 100
int wordLength;
char word[MAXWORD];
FILE * fd;
int charCount;
int wordPos;

void toLower(char * s)
{
	while (*s != '\0')
	{
		if(*s >= 'A' && *s <= 'Z')
		{
			*s = *s - 'A' + 'a';
		}
		s ++;
	}
}

// It returns the next word from stdin.
// If there are no more more words it returns NULL. 
static char * nextword()
{
	char * car = malloc(sizeof(char)*100);
	char * returnCar = car;
	*car = fgetc(fd);
	if (*car == EOF)
	{
		return NULL;
	}
	while (1)
	{
		if (!((*car <= 'z' && *car >= 'a')||(*car <= 'Z' && *car >= 'A')))	
		{
			*car = '\0';
			toLower(returnCar);
			return returnCar;
		}
		car ++;
		*car = fgetc(fd);
	}
	return NULL;
}

int
main(int argc, char **argv)
{
	if (argc < 2) {
		printf("Usage: countwords filename\n");
		exit(1);
	}

	char * filename = argv[1];

	fd = fopen(filename, "r");
	
	WordInfo * wordArray;
	int nWords = 0;
	int maxWords = 10;
	wordArray = (WordInfo *)malloc(maxWords * sizeof(WordInfo));
	
	char * s;
	s = nextword();
	if (s != NULL)
	{
		while (strcmp(s, "") == 0)
		{
			s = nextword();
		}
	}
	while (s != NULL)
	{
		int h = 0;
		int added = 0;
		while (h < nWords)
		{
			if (strcmp(wordArray[h].word, s) == 0)
			{
				wordArray[h].count ++;
				added = 1;
				break;
			}
			h ++;
		}
		if (nWords == maxWords)
		{
			wordArray = (WordInfo *)realloc(wordArray, maxWords*2*sizeof(WordInfo));
			maxWords *= 2;
		}
		if (added != 1)
		{
			wordArray[nWords].word = strdup(s);
			wordArray[nWords].count = 1;
			nWords ++;
		}
		s = nextword();
		if (s != NULL)
		{
			while (s != NULL && strcmp(s, "") == 0)
			{
				s = nextword();
			}
		}
	}
	//sort
	int i = 0;
	while(i < nWords - 1)
	{
		int j = i +1;
		while (j < nWords)
		{
			if (strcmp(wordArray[i].word, wordArray[j].word) >= 1)
			{
				char * tempword = wordArray[i].word;
				int tempcount = wordArray[i].count;
				wordArray[i].word = wordArray[j].word;
				wordArray[i].count = wordArray[j].count;
				wordArray[j].word = tempword;
				wordArray[j].count = tempcount;
			}
			j ++;
		}
		i ++;
	}
	//print
	int k = 0;
	while (k < nWords)
	{
		printf("%s %d\n", wordArray[k].word, wordArray[k].count);
		k ++;
	}
}

