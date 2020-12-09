#include <stdio.h>
#include <malloc.h>
#include <stdlib.h>
#include <time.h>


int main(void) {
    int** a;
    int* a1;
    int* a2;
    int b, c, x, j, n;
    srand(time(NULL));
    n = 3 + rand() % 10;
    a = (int**)malloc(n * sizeof(int*));
    a1 = (int*)malloc(n * sizeof(int));
    a2 = (int*)malloc(n * sizeof(int));

        for (int i = 0; i < n; i++) {
            a[i] = (int*)malloc(n * sizeof(int));
            a1[i] = 0;
        }

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                a[i][j] = rand() % 2;
            }
         }

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                printf("%d ", a[i][j]);
            }
            printf("\n");
        }

    printf("\n");
    printf("Enter two tops\n");
    scanf("%d%d", &b, &c);
    b--;
    c--;

        for (int i = 0; i < n; i++) {
            a[b][i] = 0;
            a[c][i] = 0;
            a[i][b] = 0;
            a[i][c] = 0;
        }

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (a[i][j] == 1) {
                    if (i == j) {
                        a1[j] = a1[j] + 2;
                    }
                    else {
                    a1[j]++;
                    }
                }
            }
        }

        for (int i = 0; i < n; i++) {
            a2[i] = a1[i];
        }

        for (int i = 0; i < n; i++) {
            x = a1[i];
            j = i;
            while ((j > 0) && (a1[j - 1] < x)) {
                a1[j] = a1[j - 1];
                j = j - 1;
            }
            a1[j] = x;
        }
        for (int j = 0; j < n; j++) {
            for (int i = 0; i < n; i++) {
                if (a1[j] == a2[i]) {
                    printf("%d ", i + 1);
                    a2[i] = -1;
                }
            }
        }

		FILE* s;
		s = fopen("graph12.dot", "w");
		fprintf(s, "digraph G { \n");
			
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				if (a[i][j] != 0){
                                     while(a[i][j]>=1){
					fprintf(s, "%d -> %d; \n", i + 1, j + 1);
                                        a[i][j]--;
                                        }
				}
			}
        }
		fprintf(s, "}");
		fclose(s);
		for (int i = 0; i < n; i++) {
            
			free(a[i]);
		}
		free(a);
        system("dot -Tpng graph12.dot -o graph12.png");
        system("graph12.png");
		return 0;
}        
