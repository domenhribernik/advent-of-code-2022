#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
	FILE *file = fopen("input.txt", "r");
	char buffer;
	int msgSize = 15;
	char word[msgSize];
	memset(word, ' ', msgSize-1);
	int count = 1;
	while (1) {
		buffer = fgetc(file);
		if (feof(file)) break;
		for (int i = 0; i < msgSize-1; ++i) {
			if (word[i] == ' ') {		
				word[i] = buffer;
				break;
			}
			if (word[i] == buffer) {
				for (int j = 0; j < msgSize-1; ++j) {
					if (word[j] == ' ') {
						word[j] = buffer;
						break;
					}
				}
				for (int j = 0; j < msgSize-1; ++j) {
					if (j <= i) {
						word[j] = ' ';
					}
				}
				char tmp[msgSize];
				memset(tmp, ' ', msgSize-1);
				int index = 0;
				for (int j = 0; j < msgSize-1; ++j) {
					if (word[j] != ' ') {
						tmp[index] = word[j];
						index++;
					}
				}
				strcpy(word, tmp);
				for (int j = strlen(word); j < msgSize-2; ++j) {
					word[j] = ' ';
				}
				break;
			}
		}
		if (word[msgSize-2] != ' ') {
			printf("%d: %s\n", count, word);
			break;
		}
		count++;
	}
	return 0;
}