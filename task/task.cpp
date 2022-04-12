#include <iostream>
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

			const int size{ 10 };
			const int& refSize = size;
			int arr[size]{ 0 };

			Init(arr, size, -10, 10);
			Print(arr, size);

			int neg{ 0 };
			int pos{ 0 };
			int zero{ 0 };
			int& refNeg = neg;
			int& refPos = pos;
			int& refZero = zero;

			NegPosZeroArrEl(arr, refSize, refNeg, refPos, refZero);
			cout << "\nneg = " << neg << endl
				<< "zero = " << zero << endl
				<< "pos = " << pos << endl;
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
			int size{ 10 };
			int* ptr{ nullptr };
			Allocate(ptr, size);
			Init(ptr, size, -10, 10);
			Print(ptr, size);
			DelNeg(ptr, size);
			cout << endl;
			Print(ptr, size);

			delete[]ptr;
		}
		break;

		case 3:
		{
			/*
			3. Написать функцию, которая позволяет добавлять массив в конец
			динамического массива. Функция должна возвращать указатель на
			динамический массив, используя механизм ссылок.
			*/
			const int arrA_Size{ 10 };
			int arrA[arrA_Size]{ 0, 1, 2, 3, 4, 5, 6, 7, 8, 9 };
			int* ptrA = arrA;

			int sizeB{ 5 };
			int* ptrB{ nullptr };

			Allocate(ptrB, sizeB);
			Init(ptrB, sizeB, 99, 99);
			Print(ptrB, sizeB);

			ptrB = AddArrToTheEndOfADynamicArr(ptrB, sizeB, ptrA, arrA_Size);
			cout << endl;
			Print(ptrB, sizeB);

			delete[] ptrB;
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
			int sizeA{ 5 };
			int sizeB{ 5 };
			int* ptrSizeA = &sizeA;
			int* ptrSizeB = &sizeB;
			int* ptrA{ nullptr };
			Allocate(ptrA, sizeA);
			int* ptrB{ nullptr };
			Allocate(ptrB, sizeB);
			Init(ptrA, sizeA, 99, 99);
			Init(ptrB, sizeB, 1, 98);
			cout << "ptrA :"
				<< endl;
			Print(ptrA, sizeA);
			cout << "\nptrB :"
				<< endl;
			Print(ptrB, sizeB);
			cout << "\nEnter an index to insert: ";
			int index{ 0 };
			cin >> index;
			ptrB = InsertArrInArrByIndex(ptrA, sizeA, ptrB, sizeB, index);
			cout << "\nptrA in ptrB:"
				<< endl;
			Print(ptrB, sizeB);

			delete[] ptrB;

			/*const int sizeA{ 5 };
			int arrA[sizeA]{ 0, 1, 2, 3, 4 };
			int* ptrA = arrA;

			int sizeB{ 5 };
			int* ptrB{ nullptr };

			Allocate(ptrB, sizeB);
			Init(ptrB, sizeB, 99, 99);

			cout << "ptrA :"
				<< endl;
			Print(ptrA, sizeA);

			cout << "\nptrB :"
				<< endl;
			Print(ptrB, sizeB);

			cout << "\nEnter an index to insert: ";
			int index{ 0 };
			cin >> index;

			int* p{ nullptr };

			p = InsertArrInArrByIndex(ptrA, sizeA, ptrB, sizeB, index);
			cout << "\nptrA in ptrB:"
				<< endl;
			Print(p, sizeB);

			delete[] ptrA;
			delete[] ptrB;*/
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
			int sizeA{ 5 }, index{ 0 }, amount{ 0 };
			int* ptrA{ nullptr };
			Allocate(ptrA, sizeA);
			Init(ptrA, sizeA, 1, 99);
			cout << "ptrA :"
				<< endl;
			Print(ptrA, sizeA);
			cout << "\nEnter index, than amount: \n";
			cin >> index;
			cin >> amount;
			ptrA = RemoveByIndexInArr(ptrA, sizeA, index, amount);
			cout << "\nptrA after removal:"
				<< endl;
			Print(ptrA, sizeA);

			delete[] ptrA;
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
			int size{ 5 };
			int* ptrA{ nullptr };
			Allocate(ptrA, size);
			Init(ptrA, size, 2, 19);
			Print(ptrA, size);
			ptrA = DelPrimeNumInArr(ptrA, size);
			cout << endl;
			Print(ptrA, size);

			delete[]ptrA;
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
			//2.11.30
			srand(time(0));
			int* posArr{ nullptr }, * negArr{ nullptr }, * zeroArr{ nullptr };
			int posSize{ 0 }, negSize{ 0 }, zeroSize{ 0 };
			int array[15]{ 0 };
			Init(array, 15, -10, 10);
			Print(array, 15);
			Distribute(array, 15, posArr, posSize, negArr, negSize, zeroArr, zeroSize);
			Print(posArr, posSize);
			cout << endl;
			Print(negArr, negSize);
			cout << endl;
			Print(zeroArr, zeroSize);
			cout << endl;

			delete[]posArr;
			delete[]negArr;
			delete[]zeroArr;
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