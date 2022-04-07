#include <Windows.h>
#include <iostream>
using std::cout;
using std::endl;

// Функция распределяет положительные, отрицательные и
// нулевые элементы в отдельные динамические массивы и возвращает
// указатели на эти массивы, используя механизм ссылок.
void Distribute(int* ptrArr, int size, int*& posArr, int& posSize,
	int*& negArr, int& negSize, int*& zeroArr, int& zeroSize)
{
	for (int i = 0; i < size; i++)
	{
		if (ptrArr[i] == 0)
			zeroSize++;
		else if (ptrArr[i] < 0)
			negSize++;
		else if (ptrArr[i] > 0)
			posSize++;
	}

	posArr = new int[posSize] {-111};
	negArr = new int[negSize] {-222};
	zeroArr = new int[zeroSize] {-333};

	int j{ 0 }, q{ 0 }, e{ 0 };
	for (int i = 0; i < size; i++)
	{
		if (ptrArr[i] > 0)
		{
			posArr[j] = ptrArr[i];
			j++;
		}
		else if (ptrArr[i] < 0)
		{
			negArr[q] = ptrArr[i];
			q++;
		}
		else if (ptrArr[i] == 0)
		{
			zeroArr[e] = ptrArr[i];
			e++;
		}
	}

	cout << endl;
	for (int i = 0; i < posSize; i++)
	{
		cout << posArr[i] << "\t";
	}
	cout << endl;
	for (int i = 0; i < negSize; i++)
	{
		cout << negArr[i] << "\t";
	}
	cout << endl;
	for (int i = 0; i < zeroSize; i++)
	{
		cout << zeroArr[i] << "\t";
	}
	cout << endl;
	cout << "\nEnd\n";

	// Уточнить есть ли в функции потеря памяти связанная с int* ptrArr.
}

// Функция получает указатель на массив и его размер, и 
// заполняет массив случайными числами
void Init(int* const& ref, int size, int min, int max)
{
	for (int i = 0; i < size; i++)
	{
		ref[i] = rand() % (max - min + 1) + min;
	}
}

// Функция получает указатель на массив и его размер, и 
// выводит массив на экран
void Print(int* const& ref, int size)
{
	for (int i = 0; i < size; i++)
	{
		cout << ref[i] << '\t';
	}
}

// функция создания динамического массива
void Allocate(int*& ptr, int size)
{
	ptr = new int[size];
}

// функция удаления динамического массива
void Free(int*& ptr)
{
	delete[] ptr;
}

//Возвращает количество отрицательных, положительных и нулевых элементов массива.
void NegPosZeroArrEl(int* const& ref, int const size, int& refNeg, int& ptrPos, int& ptrZero)
{
	for (int i = 0; i < size; i++)
	{
		if (ref[i] < 0)
			refNeg++;
		else if (ref[i] > 0)
			ptrPos++;
		else
			ptrZero++;
	}
}

// Функция удаляет из массива все отрицательные числа и возвращает указатель на новый динамический массив.
void DelNeg(int*& ref, int &size)
{
	int newSize{ 0 };
	for (int i = 0; i < size; i++)
	{
		if (ref[i] >= 0)
			newSize++;
	}
	
	int* p = new int[newSize] {0};
	int k{ 0 };
	for (int i = 0; i < size; i++)
	{
		if (ref[i] > 0)
		{
			p[k++] = ref[i];
		}
	}
	size = newSize;
	delete[] ref;
	ref = p;
}

// функция, добавляет массив в конец динамического массива. Возвращает указатель на динамический массив.
int* AddArrToTheEndOfADynamicArr(int* ptrB, int* sizeB, int arrA[], int arr_Size)
{
	int newSize = arr_Size + *(sizeB);
	ptrB = Allocate(newSize);
	Init(ptrB, (newSize - arr_Size), -1, -1);
	int j{ 0 };
	for (int i = newSize - arr_Size; i < newSize; i++)
	{
		ptrB[i] = arrA[j];
		j++;
	}
	*(sizeB) = newSize;

	return ptrB;
}