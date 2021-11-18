
#include "cuda_runtime.h"
#include "device_launch_parameters.h"
#include <ctime>
#include <stdio.h>
#include<iostream>
using namespace std;

#define N  10000//количество элементов массива
// Ядро

#define M 7  //тво массивов

__global__ void add(int* a, int* b, int* c)
{
	//вычисление индекса элемента
	int tid = threadIdx.x;
	//проверка на выход за пределы массива
	if (tid > N - 1) return;
	//поэлементное сложение массивов
	c[tid] = a[tid] + b[tid];
}
int main() {
	double start_time = clock();
	// выделение памяти под массивы на CPU
	int host_a[M][N];
	int host_b[M][N];
	int host_c[M][N];
	// выделение памяти под массивы для копирования
	// на GPU
	int* dev_a, * dev_b, * dev_c;
	// заполнение массивов
	for (int i = 0; i < M; i++) {
		for (int j = 0; j < N; j++) 
		{
			host_a[i][j] = 23;
			host_b[i][j] = 23;
		}
	}
	// выделение памяти под массивы на GPU
	cudaMalloc((void**)&dev_a, N * M * sizeof(int));
	cudaMalloc((void**)&dev_b, N * M * sizeof(int));
	cudaMalloc((void**)&dev_c, N * M * sizeof(int));
	// копирование данных в память GPU
	cudaMemcpy(dev_a, host_a, N *M*sizeof(int),
		cudaMemcpyHostToDevice);
	cudaMemcpy(dev_b, host_b, N * sizeof(int)*M,
		cudaMemcpyHostToDevice);
	// вызов ядра
	add << <1, N*M>>>(dev_a, dev_b, dev_c);
	// получаем результат расчета
	cudaMemcpy(host_c, dev_c, N * sizeof(int)*M,
		cudaMemcpyDeviceToHost);
	// вывод результатов
	//for (int i = 0; i < N; i++)
	//{
		//printf("%d + %d = %d\n", host_a[i],
			//host_b[i], host_c[i]);
	//}
	// освобождение памяти
	cudaFree(dev_a);
	cudaFree(dev_b);
	cudaFree(dev_c);
	double end_time = clock(); // конечное время
	double search_time = end_time - start_time; // искомое время
	cout << N << endl << M << endl;
	cout << search_time;
	return 0;
}
