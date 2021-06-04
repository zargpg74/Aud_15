#include<stdio.h>
#include<stdlib.h>
#include<malloc.h>
#include<locale.h>
#include<Windows.h>

#include"Task1.h"

int** new(int size_x, int size_y)
{
	int** massive = (int**)malloc(size_x * sizeof(int*));
	for (int i = 0; i < size_x; i++)
	{
		massive[i] = (int*)malloc(size_y * sizeof(int));
	}

	return(massive);
}

int** delete(int** matrix)
{
	int size_x = sizeof(matrix) / sizeof(matrix[0]);
	printf("%d", size_x);
	for (int i = 0; i < size_x; i++)
	{
		free(matrix[i]);
	}
	free(matrix);

	return(matrix);
}


void Matrix()
{
	system("cls");
	printf("Task 1\n");
	setlocale(0, "ru");

	int** matrix = new(10, 10);
	matrix[0][0] = 10;
	printf("%d", matrix[0][0]);
	matrix = delete(matrix);
	printf("%d", matrix[0][0]);
}