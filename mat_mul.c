#include "mat_mul.h"
#include <stdlib.h>
#include <stdio.h>

#define min(a, b) (((a) < (b)) ? (a) : (b))
// 4KB / 4 Byte
// 4 Byte -> size of float
#define BS 1024

void mat_mul_naive(float *A, float *B, float *C, int M, int N, int K) {
  for (int i = 0; i < M; i++) {
    for (int j = 0; j < N; j++) {
      for (int k = 0; k < K; k++) {
        C[i * N + j] += A[i * K + k] * B[k * N + j];
      } 
    }
  }
}

void mat_mul_locality(float *A, float *B, float *C, int M, int N, int K) {
  for (int i = 0; i < M; i++) {
    for (int k = 0; k < K; k++) {
      for (int j = 0; j < N; j++) {
        C[i * N + j] += A[i * K + k] * B[k * N + j];
      }
    }
  }
}

void mat_mul_blocking(float *A, float *B, float *C, int M, int N, int K) {
  for (int ii = 0; ii < M; ii += BS) {
    for (int kk = 0; kk < K; kk += BS) {
      for (int jj = 0; jj < N; jj += BS) {

        for (int i = ii; i < min(ii + BS, M); i++) {
          for (int k = kk; k < min(kk + BS, K); k++) {
            for (int j = jj; j < min(jj + BS, N); j++) {
              C[i * N + j] += A[i * K + k] * B[k * N + j];
            }
          }
        }

      }
    }
  }
}