#include "mat_mul.h"
#include <stdlib.h>
#include <pthread.h>
#include <stdio.h>

#define min(a, b) (((a) < (b)) ? (a) : (b))
#define BLOCKSIZE 1024

static float *A, *B, *C;
static int M, N, K;
static int num_threads;

static void* worker(void *data) {
  int pid = * (int *) data;

  int slice = M / num_threads;
  int start = pid * slice;
  int end = pid == num_threads - 1 ? M : (pid + 1) * slice;
  
  float Aik;
  int bs = BLOCKSIZE;
  for (int kk = 0; kk < K; kk += bs) {
    for (int jj = 0; jj < N; jj += bs) {


      for (int i = start; i < end; ++i) {
        for (int k = kk; k < min(kk + bs, K); ++k) {
          Aik = A[i * K + k];
          for (int j = jj; j < min(jj + bs, N); ++j) {
            C[i * N + j] += Aik * B[k * N + j];
          }
        }
      }

    }
  }

  return NULL;
}

void mat_mul_pthread(float *_A, float *_B, float *_C, int _M, int _N, int _K, int _num_threads) {
  A = _A, B = _B, C = _C;
  M = _M, N = _N, K = _K;
  num_threads = _num_threads;

  pthread_t * threads;
  threads = (pthread_t *) malloc(sizeof(pthread_t) * num_threads);

  for (int i = 0; i < num_threads; i++) {
    int * pid = (int *) malloc(sizeof(int));
    *pid = i;
    pthread_create(&threads[i], NULL, worker, pid);
  }

  for (int i = 0; i < num_threads; i++) {
    pthread_join(threads[i], NULL);
  }
}
