#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define NumberCount 10
#pragma region Types
typedef struct {
	int array[NumberCount];
	size_t Used;
} Array;

typedef enum {
	ODD,
	EVEN
}OE;
#pragma endregion
#pragma region Headers
void AddArray(Array*, int);
int GetElementByIndex(Array*, int);
void PrintArray(Array*);

int RandomNumber(int, int);
void NumberFill(Array*);

OE ODDorEVEN(int);

void PrintResult(Array*, Array*, Array*);
void DistributingNumbers(Array*, Array*, Array*);

#pragma endregion
void main()
{
	srand(time(NULL));
	Array Numbers, OddNumbers, EvenNumbers;
	Numbers.Used = OddNumbers.Used = EvenNumbers.Used = 0;
	Array* ptrNumbers = &Numbers,
		* ptrOddNumbers = &OddNumbers,
		* ptrEvenNumbers = &EvenNumbers;
	NumberFill(ptrNumbers);
	DistributingNumbers(ptrNumbers, ptrOddNumbers, ptrEvenNumbers);
	PrintResult(ptrNumbers, ptrOddNumbers, ptrEvenNumbers);
	system("PAUSE");
}
#pragma region Methods
void PrintResult(Array* numbers, Array* odd, Array* even) {
	printf("Tum Sayilar\n_____________\n");
	PrintArray(numbers);
	printf("\nTek Sayilar\n_____________\n");
	PrintArray(odd);
	printf("\nCift Sayilar\n_____________\n");
	PrintArray(even);
}

void DistributingNumbers(Array* numbers, Array* odd, Array* even) {
	for (unsigned short i = 0; i < NumberCount; i++) {
		int item = GetElementByIndex(numbers, i);
		if (ODDorEVEN(item) == ODD)
			AddArray(odd, item);
		else
			AddArray(even, item);
	}
}

void AddArray(Array* array, int num) {
	array->array[array->Used++] = num;
}

int GetElementByIndex(Array* array, int index) {
	return *(array->array + index % NumberCount);
}

OE ODDorEVEN(int num) {
	return num % 2 == 0 ? EVEN : ODD;
}

void PrintArray(Array* array) {
	for (unsigned short i = 0; i < array->Used; i++)
		printf("%d\n", *(array->array + i));

}

void NumberFill(Array* array) {
	for (unsigned short i = 0; i < NumberCount; i++)
		AddArray(array, RandomNumber(1, 101));

}

int RandomNumber(int min, int max) {
	max -= min;
	return (rand() % max) + min;
}
#pragma endregion
