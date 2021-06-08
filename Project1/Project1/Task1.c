#include<stdio.h>
#include<stdlib.h>
#include<malloc.h>
#include<locale.h>
#include<Windows.h>
#include<time.h>

#include"Task1.h"

//�������� ������� - ������� ��� �� ��������� ������� � ������ ������

int** new(int string, int columns)//��������� ������ ��� �������
{
	int** matrix = (int**)malloc(string * sizeof(int*));
	for (int i = 0; i < string; i++)
	{
		matrix[i] = (int*)malloc(columns * sizeof(int));
	}

	//������ ������ � ������� ����� ��������� �� �������� ��������
	//����� � �������� ����������� ��� ������ ������� ���������� � ������� 1, � �� 0
	matrix[0][0] = string + 1;
	matrix[0][1] = columns;

	//�������� � ����� �������������� ������, �.�. ������ ������ ��������
	matrix = (int**)realloc(matrix, (string + 1) * sizeof(int*));
	matrix[string] = (int*)malloc(columns * sizeof(int));

	return(matrix);
}

int** new_matrix(int** matrix)//������� ��� ���������� ������� � �����, ������ �������� �����
{
	int string = matrix[0][0];
	int columns = matrix[0][1];

	int** matr = (int**)malloc(string * sizeof(int*));
	for (int i = 0; i < string; i++)
	{
		matr[i] = (int*)malloc(columns * sizeof(int));
	}

	int index = 0;
	for (int i = 1; i < string; i++)
	{
		for (int j = 0; j < columns; j++)
		{
			matr[index][j] = matrix[i][j];
			printf("%d ", matr[index][j]);
			index++;
		}
		printf("\n");
	}

	return matr;
}

int** delete(int** matrix)//������� ������, ���������� ��� �������
{
	int string = matrix[0][0];
	for (int i = 0; i < string; i++)
	{
		free(matrix[i]);
	}
	free(matrix);

	return(matrix);
}

int** cin(int** matrix)//���� �������
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

int cout(int** matrix)//����� �������
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


int** multiplication(int** matrix_1, int** matrix_2)//��������� ������
{
	int string_1, string_2, columns_1, columns_2;

	//���������� �������� ������ ������ � ����������
	string_1 = matrix_1[0][0] - 1;
	columns_1 = matrix_1[0][1];

	string_2 = matrix_2[0][0] - 1;
	columns_2 = matrix_2[0][1];


	//����������� �������� ������� � �����, ��� ������� ������
	int** matr_1 = new_matrix(matrix_1);
	int** matr_2 = new_matrix(matrix_2);
}


void Matrix()
{
	srand(time(NULL));
	system("cls");
	printf("Task 1\n");
	setlocale(0, "ru");

	int size_matrix[4];//������, ���� ������������ ������ ������� ������. ��������������� ��� ������� ����� 2
	for (int i = 0; i < 4; i += 2)
	{
		printf("������� ������ ������� %d\n:", i + 1);
		scanf_s("%d", &size_matrix[i]);
		printf(":");
		scanf_s("%d", &size_matrix[i+1]);
	}

	int** matrix_1 = new(size_matrix[0], size_matrix[1]);
	int** matrix_2 = new(size_matrix[2], size_matrix[3]);

	cin(matrix_1);
	cin(matrix_2);

	cout(matrix_1);
	printf("\n");
	cout(matrix_2);

	multiplication(matrix_1, matrix_2);
}