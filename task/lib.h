﻿// Функция распределяет положительные, отрицательные и
// нулевые элементы в отдельные динамические массивы и возвращает
// указатели на эти массивы, используя механизм ссылок.
void Distribute(int* ptrArr, int size, int*& posArr, int& posSize,
	int*& negArr, int& negSize, int*& zeroArr, int& zeroSize);

// Функция получает указатель на массив и его размер, и 
// заполняет массив случайными числами
void Init(int* const& ref, int size, int min, int max);

// Функция получает указатель на массив и его размер, и 
// выводит массив на экран
void Print(int* const& ref, int size);

// функция создания динамического массива
void Allocate(int*& ptr, int size);

// функция удаления динамического массива
void Free(int*& ptr);

//Возвращает количество отрицательных, положительных и нулевых элементов массива.
void NegPosZeroArrEl(int* const& ptr, int const size, int& ptrNeg, int& ptrPos, int& ptrZero);

// Функция удаляет из массива все отрицательные числа и возвращает указатель на новый динамический массив.
void DelNeg(int*& ptr, int& size);

// функция, добавляет массив в конец динамического массива. Возвращает указатель на динамический массив.
int* AddArrToTheEndOfADynamicArr(int*& ptrB, int& sizeB, int*& arrA, int arr_Size);

// Функция, которая позволяет вставлять блок элементов
// (одномерный массив) в указанную позицию динамического массива.
// Функция возвращает указатель на динамический массив.
int*& InsertArrInArrByIndex(int*& ptrA, int sizeA, int*& ptrB, int& sizeB, int index);

// Функция, которая позволяет удалять с произвольного
// индекса указанное количество элементов из динамического
// массива.Функция должна возвращать указатель на динамический
// массив.
int*& RemoveByIndexInArr(int*& ptrA, int& sizeA, int index, int amount);

// Функция, получает указатель на динамический
// массив и его размер. Удаляет из массива все
// простые числа и возвращает указатель на новый динамический массив.
int*& DelPrimeNumInArr(int*& ptrA, int& size);