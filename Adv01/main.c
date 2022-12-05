#include <stdio.h>
#include <stdlib.h>

void swap (int *x, int *y) {
	int tmp = *x;
	*x = *y;
	*y = tmp;
}

int main () {
    FILE *f = fopen("input.txt", "r");
    char line[10];
    int max[3] = {1, 1, 1};
    int temp = 0;
    while (fgets(line, 10, f)) {
		if (line[0] == '\n') {
			if (temp > max[2]) max[2] = temp;
			if (max[2] > max[1]) swap(max+2, max+1);
			if (max[1] > max[0]) {
				swap(max+1, max);
				if (max[2] > max[1]) swap(max+2, max+1);
			}
    		temp = 0;
    	} 
    	else temp += atoi(line);
    }
    fclose(f);
    printf("%i %i %i\n", max[2], max[1], max[0]);
    printf("%i\n", max[2] + max[1] + max[0]);
   	return 0;
}