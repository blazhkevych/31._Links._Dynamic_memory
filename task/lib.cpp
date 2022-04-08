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
void DelNeg(int*& ref, int& size)
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
void AddArrToTheEndOfADynamicArr(int*& ptrB, int& sizeB, int*& arrA, int arrA_Size)
{
	int newSize = arrA_Size + sizeB;
	int* p = new int[newSize];
	int w{ 0 };
	for (int i = 0; i < sizeB; i++)
	{
		p[i] = ptrB[w];
		w++;
	}

	int q{ 0 };
	for (int j = newSize - arrA_Size; j < newSize; j++)
	{
		p[j] = arrA[q];
		q++;
	}
	sizeB = newSize;
	delete[]ptrB;
	ptrB = p;
	p = nullptr;
}

// Функция, которая позволяет вставлять блок элементов
// (одномерный массив) в указанную позицию динамического массива.
// Функция возвращает указатель на динамический массив.
//void InsertArrInArrByIndex(int* ptrA, int* sizeA, int* ptrB, int* sizeB, int index)
//{
//	int sizeP = *sizeA + *sizeB;
//	if (index < 0 || index > sizeP - *sizeA)
//		return ptrB;
//	int* p = new int[sizeP];
//	int k = index + *sizeA;
//	int j{ 0 }, q{ 0 };
//	for (int i = 0; i < sizeP; i++)
//	{
//		if (i < index || i >= k)
//		{
//			p[i] = ptrB[j];
//			j++;
//		}
//		else if (i >= index && i < k)
//		{
//			p[i] = ptrA[q];
//			q++;
//		}
//	}
//	*sizeB = sizeP;
//	delete[]ptrA;
//	return p;
//}