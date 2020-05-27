#pragma once

void mat_mul_naive(float *_A, float *_B, float *_C, int _M, int _N, int _K);
void mat_mul_locality(float *_A, float *_B, float *_C, int _M, int _N, int _K);
void mat_mul_blocking(float *_A, float *_B, float *_C, int _M, int _N, int _K);