#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main () {
	FILE *file = fopen("input.txt", "r");
	char game[9][4] = {"A X", "A Y", "A Z", "B X", "B Y", "B Z", "C X", "C Y", "C Z", };
	//int score[9] = {4, 8, 3, 1, 5, 9, 7, 2, 6};   // XYZ - rock, paper, scirsors
	int score[9] = {3, 4, 8, 1, 5, 9, 2, 6, 7}; // XYZ - lose, draw, win
	int max = 0;
	char line[4];
	while (fgets(line, 4, file)) if (line[0] != '\n') for (int i = 0; i < 9; ++i) if (strcmp(line, game[i]) == 0) max += score[i];	
	fclose(file);
	printf("%d\n", max);
	return 0;
}