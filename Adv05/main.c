#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void print(char stack[][100]) {
	for (int i = 0; i < 9; ++i) {
		printf("%s\n", stack[i]);
	}
	printf("\n");
}

void printTop(char stack[][100]) {
	for (int i = 0; i < 9; ++i) {
		for (int j = 1; j < 98; ++j) {
			if (stack[i][j+1] == ' ') {
				printf("%c", stack[i][j]);
				break;
			}
		}
	}
	printf("\n");
}

void push(char* stack, char x) {
	for (int i = 1; i < 100; ++i) {
		if (stack[i] == ' ') {
			stack[i] = x;
			break;
		}
		else if (i == 99 && stack[i] != ' ') printf("Stack is full\n");
	}
}

char pop(char* stack) {
	char x = ' ';
	if (stack[0] == ' ') {
		printf("Stack is empty\n");
		return x;
	}
	if (stack[99] != '\0') {
		x = stack[99];
		stack[99] = ' ';
		return x;
	}
	for (int i = 0; i < 99; ++i) {
		if (stack[i+1] == ' ') {
			x = stack[i];
			stack[i] = ' ';
			return x;
		}
	}
}

void move(char* from, char* to, int num) {
	char tmp;
	for (int i = 0; i < num; ++i){
		tmp = pop(from);
		push(to, tmp);
	}
}

void moveMultiple(char* from, char* to, int num) {
	char buffer[100];
	for (int i = 0; i < num; ++i) {
		buffer[i] = pop(from);
	}
	for (int i = num-1; i >= 0; --i) {
		push(to, buffer[i]);
	}
}

int main() {
	FILE *file = fopen("input.txt", "r");
	char line[100];
	char buffer[2];
	char stack[9][100];
	char data[6][5];
	for(int i = 0; i < 9; ++i) {
		memset(stack[i],' ',100);
		stack[i][99] = '\0'; 
	}
	int row = 8;
	int col = 0;
	while(fgets(line, 100, file)) {
		if (strlen(line) == 36) {
			for (int i = 0; i < strlen(line); ++i) {
				if (i > 0 && i % 4 == 1) {
					stack[col][row] = line[i];
					col++;
					if (col == 9) col = 0;
				}
			}
			row--;
		}
		else {
			char buffer[5];
			int index = 0;
			int dataIndex = 0;
			for (int i = 0; i < strlen(line); ++i) {
				if (line[i] != ' ' && line[i] != '\n') {
					buffer[index] = line[i];
					index++; 
				}
				else {
					strcpy(data[dataIndex], buffer);
					strcpy(buffer, "   ");
					index = 0;
					dataIndex++;
				}
			}
			//move(stack[atoi(data[3])-1], stack[atoi(data[5])-1], atoi(data[1]));
			moveMultiple(stack[atoi(data[3])-1], stack[atoi(data[5])-1], atoi(data[1]));
		}
	}
	printf("\n");
	print(stack);
	printTop(stack);
	fclose(file);
	return 0;
}