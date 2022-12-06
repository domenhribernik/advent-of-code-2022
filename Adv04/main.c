#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
	FILE *file = fopen("input.txt", "r");
	char line[50];
	char buffer[5];
	int x = 0;
	int pairs[4];
	int count[2];
	while(fgets(line, 50, file)) {
		x = 0;
		for (int i = 0; i < strlen(line); ++i) {
			if (line[i] == '-' && x == 0) {
				memset(buffer,0,strlen(buffer));
				strncpy(buffer, &line[x], i-x);
				x += strlen(buffer)+1;
				pairs[0] = atoi(buffer);
			}
			else if (line[i] == ',') {
				memset(buffer,0,strlen(buffer));
				strncpy(buffer, &line[x], i-x);
				x += strlen(buffer)+1;
				pairs[1] = atoi(buffer);
				
			}
			else if (line[i] == '-' && x != 0) {
				memset(buffer,0,strlen(buffer));
				strncpy(buffer, &line[x], i-x);
				x += strlen(buffer)+1;
				pairs[2] = atoi(buffer);
			}
			else if (line[i+1] == '\0') {
				memset(buffer,0,strlen(buffer));
				strncpy(buffer, &line[x], i-x);
				pairs[3] = atoi(buffer);
			}
		}
		if ((pairs[0] <= pairs[2] && pairs[1] >= pairs[3]) || (pairs[2] <= pairs[0] && pairs[3] >= pairs[1])) count[0]++;
		if (!(pairs[0] < pairs[3] && pairs[1] < pairs[2]) && !(pairs[2] < pairs[1] && pairs[3] < pairs[0])) count[1]++;
	}
	fclose(file);
	printf("%d\n", count[0]);
	printf("%d\n", count[1]);
	return 0;
}