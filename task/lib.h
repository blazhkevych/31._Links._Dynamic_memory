// Функция распределяет положительные, отрицательные и
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
void AddArrToTheEndOfADynamicArr(int*& ptrB, int& sizeB, int*& arrA, int arr_Size);