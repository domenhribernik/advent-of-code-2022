#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

int convert(char x) {
	int num = x;
	if (num > 96) num -= 96;
	else if (num > 64) num -= 38;
	return num;
}

int main() {
	FILE *file = fopen("input.txt", "r");
	char line[100];
	int sum = 0;
	int size = 0;
	char *first;
	char *second;
	while(fgets(line, 100, file)) {
		size = strlen(line)-1;
		first = (char*)malloc((size/2+1) * sizeof(char));
		second = (char*)malloc((size/2+1) * sizeof(char));
		for (int i = 0; line[i] != '\0'; i++) {
			if (i < size / 2) first[i] = line[i];
        	else if (line[i] != '\n') second[i-size/2] = line[i]; 
        }
        for (int i = 0; i < size / 2; ++i) {
        	char x[2] = {first[i], '\0'};
			if (strstr(second, x)) {
		    	sum += convert(first[i]);
		    	break;
			}
        }
	}
	fclose(file);
	printf("%d\n", sum);
	FILE *file2 = fopen("input.txt", "r");
	char line2[100];
	char line3[100];
	sum = 0;
	while(fgets(line, 100, file2)) {
		fgets(line2, 100, file2);
		fgets(line3, 100, file2);
		//printf("%s%s%s\n", line, line2, line3);
		for (int i = 0; i < strlen(line2); ++i) {
			char x[2] = {line2[i], '\0'};
			if (strstr(line, x)) {
				if (strstr(line3, x)) {
					sum += convert(line2[i]);
					break;
				}
			}
		}
	}
	fclose(file2);
	printf("%d\n", sum);
	return 0;
}