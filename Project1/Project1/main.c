#include<stdio.h>
#include<locale.h>
#include<Windows.h>

#include"Task1.h"

void choice(int number)
{
	system("cls");

	printf("Aud 15\n");
	printf("Error. ������ ������� �� ����������. \n������� ����� �������: ");
	scanf_s("%d", &number);

	switch (number)
	{
	case 1:
		Matrix();
		break;
	default:
		choice(number);
		break;
	}
}

void main()
{
	system("cls");
	printf("Aud 15\n");
	setlocale(0, "ru");

	printf("������� ����� �������: ");
	int number;
	scanf_s("%d", &number);

	switch (number)
	{
	case 1:
		Matrix();
		break;
	default:
		choice(number);
		break;
	}
}