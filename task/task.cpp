﻿#include <iostream>
#include "lib.h"
using std::endl;
using std::cin;
using std::cout;

int main()
{
	char answer{ 0 };
	int choice{ 0 };

	do
	{
		cout << "Enter task number:: "
			<< "\nTask 1."
			<< "\nTask 2."
			<< "\nTask 3."
			<< "\nTask 4."
			<< "\nTask 5."
			<< "\nTask 6."
			<< "\nTask 7."
			<< endl;
		cin >> choice;

		switch (choice)
		{
		case 1:
		{
			/*
			1. Написать функцию, которая получает указатель на массив и его
			размер, и возвращает количество отрицательных, положительных и
			нулевых элементов массива, используя механизм ссылок.
			*/

		}
		break;

		case 2:
		{
			/*
			2. Написать функцию, которая получает указатель на динамический
			массив и его размер. Функция должна удалить из массива все
			отрицательные числа и вернуть указатель на новый динамический
			массив, используя механизм ссылок.
			*/

		}
		break;

		case 3:
		{
			/*
			3. Написать функцию, которая позволяет добавлять массив в конец
			динамического массива. Функция должна возвращать указатель на
			динамический массив, используя механизм ссылок.
			*/

		}
		break;

		case 4:
		{
			/*
			4. Написать функцию, которая позволяет вставлять блок элементов
			(одномерный массив) в указанную позицию динамического массива.
			Функция должна возвращать указатель на динамический массив,
			используя механизм ссылок.
			*/

		}
		break;

		case 5:
		{
			/*
			5. Написать функцию, которая позволяет удалять с произвольного
			индекса указанное количество элементов из динамического массива.
			Функция должна возвращать указатель на динамический массив,
			используя механизм ссылок.
			*/

		}
		break;

		case 6:
		{
			/*
			6. Написать функцию, которая получает указатель на динамический
			массив и его размер. Функция должна удалить из массива все
			простые числа и вернуть указатель на новый динамический массив,
			используя механизм ссылок.
			*/

		}
		break;

		case 7:
		{
			/*
			7. Написать функцию, которая получает указатель на массив и его
			размер. Функция распределяет положительные, отрицательные и
			нулевые элементы в отдельные динамические массивы и возвращает
			указатели на эти массивы, используя механизм ссылок.
			*/

		}
		break;
		}

		cout << endl;
		cout << "Do you want to continue? ( y (yes) / n (no) )\n";
		cin >> answer;
		cout << endl;

	} while (answer == 'y');

	return 0;
}