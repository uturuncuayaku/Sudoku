#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct board{

	int s[9][9];
	int difficulty;
};

void initBoard(struct board *sb, int difficulty)
{
	int i, j;
	
	for(i = 0; i < 9; i++)
	{
		for(j = 0; j < 9; j++)
		{
			sb->s[i][j] = 0;
			printf("%d",sb->s[i][j]);
		}
		putchar('\n');
	}
	sb->difficulty = difficulty;
	printf("Difficulty Level: %d\n", difficulty +1);
}
void readBoard(struct board *s)
{
	FILE *f = fopen("puzzle.in", "r");
	char *su = malloc(81*sizeof(char)+1);
	fscanf(f, "%s", su);
	printf("%s\n",su);
	
	int i,j, ct = 0;
	for(i = 0; i < 9; i++)
	{
		for(j = 0; j < 9; j++)
		{
			s->s[i][j] = su[ct++] -'0';
//			printf("%d", s->s[i][j]);
		}
//		putchar('\n');
	}
	fclose(f);
	free(su);
}
void printBoard(struct board *s)
{

	int i,j;
	for(i = 0; i < 9; i++)
	{
		for(j = 0; j < 9; j++)
		{
			printf("%d", s->s[i][j]);
		}
		putchar('\n');
	}
}
int main(void)
{
//	struct sudoku sud;
	
	struct board *s;

	s = malloc(sizeof(struct board));

	initBoard(s,0);

	readBoard(s);
	printBoard(s);
	return (0);
}

