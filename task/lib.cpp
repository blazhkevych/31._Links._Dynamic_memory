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
int* AddArrToTheEndOfADynamicArr(int*& ptrB, int& sizeB, int*& arrA, int arrA_Size)
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
	return ptrB;
}

//Функция, которая позволяет вставлять блок элементов
//(одномерный массив) в указанную позицию динамического массива.
//Функция возвращает указатель на динамический массив.
int*& InsertArrInArrByIndex(int*& ptrA, int sizeA, int*& ptrB, int& sizeB, int index)
{
	int sizeP = sizeA + sizeB;
	if (index < 0 || index > sizeP - sizeA)
		return ptrB;
	int* p = new int[sizeP];
	int k = index + sizeA;
	int j{ 0 }, q{ 0 };
	for (int i = 0; i < sizeP; i++)
	{
		if (i < index || i >= k)
		{
			p[i] = ptrB[j];
			j++;
		}
		else if (i >= index && i < k)
		{
			p[i] = ptrA[q];
			q++;
		}
	}
	sizeB = sizeP;
	delete[]ptrA;
	delete[]ptrB;
	return p;
}

// Функция, которая позволяет удалять с произвольного
// индекса указанное количество элементов из динамического
// массива.Функция должна возвращать указатель на динамический
// массив.
int*& RemoveByIndexInArr(int*& ptrA, int& sizeA, int index, int amount)
{
	int sizeP = sizeA - amount;
	if (index < 0 || index > sizeA - amount)
		return ptrA;
	int* p = new int[sizeP];
	int j = 0;
	for (int i = 0; i < sizeA; i++)
	{
		if (i < index || i >= index + amount)
		{
			p[j] = ptrA[i];
			j++;
		}
	}
	sizeA = sizeP;
	delete[]ptrA;
	return p;
}

// Функция проверяющая является ли число простым.
bool IsPrime(int& number)
{
	if (number < 2)
		return false;
	for (int i = 2; i * i <= number; i++) // Проверка до квадратного корня из number.
		if (number % i == 0) // Если найден другой делитель числа number.
			return false;
	return true;
}

// Функция возвращающая количество простых чисел в массиве.
int NumberOfPrimesIn1DArr(int*& ptrA, int& size)
{
	int count{ 0 };

	for (int i = 0; i < size; i++)
		if (IsPrime(ptrA[i]))
			count++;

	return count;
}

// Функция, получает указатель на динамический
// массив и его размер. Удаляет из массива все
// простые числа и возвращает указатель на новый динамический массив.
int*& DelPrimeNumInArr(int*& ptrA, int& size)
{
	int n = NumberOfPrimesIn1DArr(ptrA, size);
	int newSize = size - n;
	int* ptrB{ nullptr };
	Allocate(ptrB, newSize);
	int j{ 0 };
	for (int i = 0; i < size; i++) // бежим до размера старого массива
	{
		if (IsPrime(ptrA[i]) == false)
		{
			ptrB[j] = ptrA[i];
			j++;
		}
	}
	size = newSize;
	delete[]ptrA;
	return ptrB;
}