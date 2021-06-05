#include<stdio.h>
#include<stdlib.h>
#include<malloc.h>
#include<locale.h>
#include<Windows.h>

#include"Task1.h"

const int N = 2;//количество матриц для умножения

struct Size_matrix//структура для хранения размеров матриц
{
	int string;
	int columns;
} size;

int** new(int string, int columns)//выделение памяти под матрицу
{
	int** massive = (int**)malloc(string * sizeof(int*));
	for (int i = 0; i < string; i++)
	{
		massive[i] = (int*)malloc(columns * sizeof(int));
	}

	return(massive);
}

int** delete(int** matrix)//очистка памяти, выделенной под матрицу
{
	for (int i = 0; i < size.string; i++)
	{
		free(matrix[i]);
	}
	free(matrix);

	return(matrix);
}

int** cin(int** matrix)//ввод матрицы
{
	for (int i = 0; i < size.string; i++)
	{
		for (int j = 0; j < size.columns; j++)
		{
			scanf_s("%d", &matrix[i][j]);
		}
	}

	return(matrix);
}

int cout(int** matrix)//вывод матрицы
{
	for (int i = 0; i < size.string; i++)
	{
		for (int j = 0; j < size.columns; j++)
		{
			printf("%d ", matrix[i][j]);
		}
		printf("\n");
	}
}


void Matrix()
{
	system("cls");
	printf("Task 1\n");
	setlocale(0, "ru");

	struct Size_matrix* count = (struct Size_matrix*)malloc(2 * sizeof(struct Size_matrix));//массив, который будет хранить матрицы

	for (int i = 0; i < N; i++)
	{
		printf("Введите размер матрицы %d\n:", i + 1);
		scanf_s("%d", &count[i].string);
		printf(":");
		scanf_s("%d", &count[i].columns);
	}

	int** matrix_1 = new(count[0].string, count[0].columns);
	int** matrix_2 = new(count[1].string, count[1].columns);

	cin(matrix_1);
	printf("\n");
	cout(matrix_1);

	printf("\n");
	cin(matrix_2);
	printf("\n");
	cout(matrix_2);
}