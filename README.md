# MatMulSpeedUp
Matrix multiplication speed up with multithreading

## Single thread approach (branch name: single-thread)
- how to run
```shell
❯ make all
❯ ./main -h
Usage: ./main [-pvh] [-t num_threads] [-n num_iterations] M N K
Options:
  -p : print matrix data. (default: off)
  -v : validate matrix multiplication. (default: off)
  -h : print this page.
  -t : number of threads (default: 1)
  -n : number of iterations (default: 1)
   M : number of rows of matrix A and C. (default: 8)
   N : number of columns of matrix B and C. (default: 8)
   K : number of columns of matrix A and rows of B. (default: 8)
❯ ./main 1024 1024 1024
```

## Multi thread approach - pthread (branch name: pthread)
- how to run
```shell
❯ make all
❯ ./main -h
Usage: ./main [-pvh] [-t num_threads] [-n num_iterations] M N K
Options:
  -p : print matrix data. (default: off)
  -v : validate matrix multiplication. (default: off)
  -h : print this page.
  -t : number of threads (default: 1)
  -n : number of iterations (default: 1)
   M : number of rows of matrix A and C. (default: 8)
   N : number of columns of matrix B and C. (default: 8)
   K : number of columns of matrix A and rows of B. (default: 8)
❯ ./main -t 4 1024 1024 1024
❯ make graph # get performance of cpu threading
```
- 