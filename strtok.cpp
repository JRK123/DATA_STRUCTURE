#include <iostream>
#include <cstring>
#include <cstdio>
#include <ctime>
#include <cstdlib>
using namespace std;
int N;
// print function to write on stdout. used for debugging.
/*void print_mat(int *mat) {
	int i, j; 
	for (i = 0; i < N; i++) {
		for (j = 0; j < N; j++) {
			printf("%d\t", *(mat + i * N + j));
//			printf("hi\t");
		}
		printf("\n");
	}
}*/

int *Multiply(int *mat1, int *mat2, int count) {
	int *sol; int i, j, k;
	sol = (int *)malloc(N * N * sizeof(int));
	if (sol == NULL) {
		fprintf(stderr, "space not allocated");
		exit(0);
	}
	for (i = 0; i < N; i++) {
		for(j = 0; j < N; j++) {
			*(sol + (i * N) + j) = 0;
		}
	}
	switch(count) {
		case 1 :
			for (i = 0; i < N; i++) {
				for (j = 0; j < N; j++) {
					for (k = 0; k < N; k++) {
						*(sol + i * N + j) += *(mat1 + i * N + k) * *(mat2 + k * N + j); 				
					}
				}
			}
			return sol;
		case 2 :
			for (i = 0; i < N; i++) {
				for (k = 0; k < N; k++) {
					for (j = 0; j < N; j++) {
						*(sol + i * N + j) += *(mat1 + i * N + k) * *(mat2 + k * N + j); 				
					}
				}
			}
			return sol;
		case 3 :
			for (j= 0; j < N; j++) {
				for (i = 0; i < N; i++) {
					for (k = 0; k < N; k++) {
						*(sol + i * N + j) += *(mat1 + i * N + k) * *(mat2 + k * N + j); 				
					}
				}
			}
			return sol;
		case 4 :
			for (j = 0; j < N; j++) {
				for (k = 0; k < N; k++) {
					for (i = 0; i < N; i++) {
						*(sol + i * N + j) += *(mat1 + i * N + k) * *(mat2 + k * N + j); 				
					}
				}
			}
			return sol;
		case 5 :
			for (k = 0; k < N; k++) {
				for (i = 0; i < N; i++) {
					for (j = 0; j < N; j++) {
						*(sol + i * N + j) += *(mat1 + i * N + k) * *(mat2 + k * N + j); 				
					}
				}
			}
			return sol;
		case 6 :
			for (k = 0; k < N; k++) {
				for (j = 0; j < N; j++) {
					for (i = 0; i < N; i++) {
						*(sol + i * N + j) += *(mat1 + i * N + k) * *(mat2 + k * N + j); 				
					}
				}
			}
			return sol;
	}
} 
int main(int argc, char *argv[]) {
	if (argc != 5) {
		fprintf(stdout, "USAGE : MATRIX_ORDER MATRIX1 MATRIX2 ANSWER\n");
		return 0;
	}
	FILE *fp;
	fp = fopen(argv[1], "r");
	fscanf(fp, "%d", &N);
	fclose(fp);
	fp = fopen(argv[2], "r");
	int *mat1;
	mat1 = (int *)malloc(N * N * sizeof(int));
	int i, j , k;	
	for (i = 0; i < N; i++) {
		for ( j = 0; j < N; j++) {
			fscanf(fp, "%d", (mat1 + i * N + j));
		}
	}
	fclose(fp);
	fp = fopen (argv[3], "r");
	int *mat2;
	mat2 = (int *) malloc(sizeof(int) * N * N);
	for (i = 0; i < N; i++) {
		for ( j = 0; j < N; j++) {
			fscanf(fp, "%d", (mat2 + i * N + j));
		}
	}
	fclose(fp);
	int *ans_mat;
	int count;
	for (count = 1; count < 7; count++) {
		clock_t begin = clock();
		ans_mat = Multiply( mat1, mat2, count);
		clock_t end = clock();
		double time_spent = (double) (end - begin)/CLOCKS_PER_SEC;
		printf("WAY_NO : %d TIME = %lf\n",count, time_spent);
		free(ans_mat);
	}

//if you want to get outputed answer on argument 5 provided in command line.
/*	fp = fopen(argv[4], "w+");
	for (i = 0; i < N; i++) {
		for (j = 0; j < N; j++) {
			fprintf(fp, "%d\t\t ", *(ans_mat + i * N + j));
		}
		fprintf(fp, "\n");
	}
	fclose(fp);*/

	return 0;
}
