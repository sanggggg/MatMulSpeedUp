#pragma once

void mat_mul_pthread(float *_A, float *_B, float *_C, int _M, int _N, int _K, int _num_threads);