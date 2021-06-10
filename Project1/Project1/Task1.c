#include<stdio.h>
#include<stdlib.h>
#include<malloc.h>
#include<locale.h>
#include<Windows.h>
#include<time.h>

#include"Task1.h"

//полезная матрица - матрица без ее полезного размера в первой строке

int** new(int string, int columns)//выделение памяти под матрицу
{
	int** matrix = (int**)malloc(string * sizeof(int*));
	for (int i = 0; i < string; i++)
	{
		matrix[i] = (int*)malloc(columns * sizeof(int));
	}

	//первая строка в матрице будет заполнена ее полезным размером
	//далее в функциях учитывается что строки матрицы начинаются с индекса 1, а не 0
	matrix[0][0] = string + 1;
	matrix[0][1] = columns;

	//выделяем в конце дополнительную строку, т.к. первая занята размером
	matrix = (int**)realloc(matrix, (string + 1) * sizeof(int*));
	matrix[string] = (int*)malloc(columns * sizeof(int));

	return(matrix);
}

//функция записывает в новую матрицу исходую, только с полезными данными
int** new_matrix(int** matrix)
{
	int** matr = (int**)malloc((matrix[0][0] - 1) * sizeof(int*));
	for (int i = 0; i < matrix[0][0] - 1; i++)
	{
		matr[i] = (int*)malloc(matrix[0][1] * sizeof(int));
	}

	int index = 0;
	for (int i = 1; i < matrix[0][0]; i++)
	{
		for (int j = 0; j < matrix[0][1]; j++)
		{
			matr[index][j] = matrix[i][j];
		}
		index++;
	}

	return matr;
}

int** delete(int** matrix)//очистка памяти, выделенной под матрицу
{
	int string = matrix[0][0];
	for (int i = 0; i < string; i++)
	{
		free(matrix[i]);
	}
	free(matrix);

	return(matrix);
}

int** cin(int** matrix)//ввод матрицы
{
	for (int i = 1; i < matrix[0][0]; i++)
	{
		for (int j = 0; j < matrix[0][1]; j++)
		{
			matrix[i][j] = rand() % 100;
		}
	}

	return(matrix);
}

int cout(int** matrix)//вывод матрицы
{
	for (int i = 1; i < matrix[0][0]; i++)
	{
		for (int j = 0; j < matrix[0][1]; j++)
		{
			printf("%d ", matrix[i][j]);
		}
		printf("\n");
	}
}

int error_multiplication(int columns, int string)
{
	if (columns == string)
		return 1;
	else
		return 0;
}


int** multiplication(int** matrix_1, int** matrix_2)//умножение матриц
{
	int string_1, string_2, columns_1, columns_2;

	//записываем полезный размер матриц в переменные
	string_1 = matrix_1[0][0] - 1;
	columns_1 = matrix_1[0][1];

	string_2 = matrix_2[0][0] - 1;
	columns_2 = matrix_2[0][1];

	//перезапишем полезные матрицы в новые, для удоства работы
	int** matr_1 = new_matrix(matrix_1);
	int** matr_2 = new_matrix(matrix_2);

	int** rezult = new(string_1, columns_2);

	for (int i = 0; i < string_1; i++)
	{
		for (int j = 0; j < columns_2; j++)
		{
			rezult[i][j] = 0;
			for (int k = 0; k < columns_1; k++)
			{
				rezult[i][j] += matr_1[i][k] * matr_2[k][j];
			}
		}
	}

	return(rezult);
}


void Matrix()
{
	srand(time(NULL));
	system("cls");
	printf("Task 1\n");
	setlocale(0, "ru");

	int size_matrix[4];//массив, куда пользователь вводит размеры матриц. подразумевается что матрицы будет 2
	for (int i = 0; i < 4; i += 2)
	{
		printf("Введите размер матрицы %d\n:", i + 1);
		scanf_s("%d", &size_matrix[i]);
		printf(":");
		scanf_s("%d", &size_matrix[i+1]);
	}

	int error = error_multiplication(size_matrix[1], size_matrix[2]);
	if (error == 0)
	{
		system("cls");
		printf("Error.Матрицы перемножить невозможно!");
		exit(error);
	}

	int** matrix_1 = new(size_matrix[0], size_matrix[1]);
	int** matrix_2 = new(size_matrix[2], size_matrix[3]);

	cin(matrix_1);
	cin(matrix_2);

	printf("Исходные матрицы: \n");
	cout(matrix_1);
	printf("\n");
	cout(matrix_2);


	int**rezult = multiplication(matrix_1, matrix_2);


	delete(matrix_1);
	delete(matrix_2);
}