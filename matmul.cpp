#include <stdio.h>
#include<sys/time.h>

#define NI 1000
#define NJ 1100
#define NK 1200

int CC[NI][NJ];
int AA[NI][NK];
int BB[NK][NJ];

void matmul (int C[NI][NJ], int A[NI][NK], int B[NK][NJ]) {
    for (int i = 0; i < NI; i++) {
        for (int k = 0; k < NK; k++) {
            for (int j = 0; j < NJ; j++) {
                C[i][j] += A[i][k] * B[k][j];
            }
        }
    }
}

int main() {
    int sum = 0;
    for (int i = 0; i < NI; i++) {
        for (int k = 0; k < NK; k++) {
            AA[i][k] = (i + k) / NI * 2;
        }
    }
    for (int k = 0; k < NK; k++) {
        for (int j = 0; j < NJ; j++) {
            BB[k][j] = (k + j) / NI;
        }
    }
    for (int i = 0; i < NI; i++) {
        for (int j = 0; j < NJ; j++) {
            CC[i][j] = 0;
        }
    }
    matmul(CC, AA, BB);
    matmul(CC, AA, BB);
    struct timeval tv1, tv2;
    gettimeofday(&tv1, NULL);
    for (int iter = 0; iter < 10; iter++) 
      matmul(CC, AA, BB);
    gettimeofday(&tv2, NULL);

    for (int i = 0; i < NI; i++) {
        for (int j = 0; j < NJ; j++) {
            sum += CC[i][j];
        }
    }
    printf("%d\n",sum);
    printf ("Total time = %f us\n",
            (double) (tv2.tv_usec - tv1.tv_usec) +
            (double) (tv2.tv_sec - tv1.tv_sec) * 1000000);
    return 0;
}
