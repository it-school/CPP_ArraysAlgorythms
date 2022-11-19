#include <iostream>
#include <iomanip>
using namespace std;


int main()
{
	setlocale(LC_ALL, "ru");
	cout << "Array algorythms: linear search, sorts, i.e." << endl;
	const int N = 20;
	int array[N];

	for (size_t i = 0; i < N; i++)
	{
		array[i] = rand() % 100;
		cout << setw(4) << array[i];
	}

	// линейный поиск (linear search)
	int number = 5, position = -1;
	for (int i = 0; i < N; i++)
	{
		if (array[i] == number)
		{
			position = i;
			break;  // добавляем для поиска только первого вхождения
		}
	}
	cout << endl << "Position of number " << number << " is " << position << endl;

	// Поиск в массиве MIN и MAX значений и их индексов
	int indexMin = 0, indexMax = 0;
	for (int i = 1; i < N; i++)
	{
		if (array[i] < array[indexMin])
			indexMin = i;
		else
			if (array[i] > array[indexMax])
				indexMax = i;
	}
	cout << endl << "Минимальный элемент на ходится на позиции: " << indexMin << ", его значение: " << array[indexMin];
	cout << endl << "Максимальный элемент на ходится на позиции: " << indexMax << ", его значение: " << array[indexMax] << endl;

	// Сортировка поиском (выбором) минимального (selection sort)
	int imin = 0, temp;

	// N-1 * N/2 - количество операций
	for (int j = 0; j < N - 1; j++)
	{
		for (int i = 1 + j; i < N; i++)
		{
			if (array[i] < array[imin])
			{
				imin = i;
			}
		}
		// cout << endl << "Minimum is: array[" << imin << "] = " << array[imin] << endl;
		temp = array[j];
		array[j] = array[imin];
		array[imin] = temp;
		cout << endl;
		for (size_t i = 0; i < N; i++)
		{
			cout << setw(4) << array[i];
		}
	}

	// Пузырьковая сортировка (bubble sort)
	int n = 0;
	bool isOrdered = true;
	for (size_t j = 0; j < N - 1; j++)
	{
		isOrdered = true;
		for (int i = 0; i < N - 1 - j; i++)
		{
			if (array[i + 1] < array[i])
			{
				temp = array[i];
				array[i] = array[i + 1];
				array[i + 1] = temp;
				isOrdered = false;
			}
			n++;
		}

		if (isOrdered)
			break;
	}

	cout << endl;
	for (size_t i = 0; i < N; i++)
	{
		cout << setw(4) << array[i];
	}
	cout << endl << "Total operations: " << n;

	// Двоичный (бинарный) поиск в отсортированном массиве 
	int steps = ceil(log2(n));	// кол-во шагов для поиска
	int middle = n / 2;			// середина для старта поиска
	number = 555;				// искомое значение
	position = -1;				// позиция найденного элемента или -1, если не найден

	cout << endl << steps;
	for (size_t i = 1; i <= n; i++)
	{
		if (array[middle] == number)
		{
			number = middle;
			break;
		}
		else
		{
			if (array[middle] > number)
			{
				middle = middle / 2; // go left
			}
			else
			{
				middle = middle + middle / 2; // go right
			}

			// middle = array[middle] > value ? middle / 2 : middle + middle / 2;
		}
	}
	cout << endl << "Индекс для значения " << number << " => " << position;



	// Практический пример
	n = 0;

	cout << endl << endl << "Известны показания термометра за год. Найти 3 самых теплых и 3 самых холoдных дня в году:" << endl;
	const int DAYS = 365;
	int year[DAYS];

	for (int i = 0; i < DAYS; i++)
	{
		year[i] = -20 + rand() % 61;
		cout << setw(4) << year[i];
	}

	/*
	// С сортировкой, т.е. исходные данные будут изменены
	bool isOrdered = true;
	for (int j = 0; j < DAYS - 1; j++)
	{
		isOrdered = true;
		for (int i = 0; i < DAYS - 1 - j; i++)
		{
			if (year[i + 1] < year[i])
			{
				temp = year[i];
				year[i] = year[i + 1];
				year[i + 1] = temp;
				isOrdered = false;
			}
			n++;
		}

		if (isOrdered)
			break;
	}

	cout << endl;
	for (int i = 0; i < DAYS; i++)
	{
		cout << setw(4) << year[i];
	}

	cout << endl<<year[0] << " " << year[1] << " " << year[2] << endl;
	cout << endl<<year[DAYS-1] << " " << year[DAYS - 2] << " " << year[DAYS - 3] << endl;
	cout << endl << "Total operations: " << n;
	*/

	// Без сортировки - обычный поиск минимума и максимума

	cout << endl << endl << "Пары температур для самых 3 холодных и самых тёплых дней года:" << endl;

	n = 0;
	int iMax = 0, iMin = 0;
	for (int i = 1; i < DAYS; i++)
	{
		if (year[i] < year[iMin])
			iMin = i;
		if (year[i] > year[iMax])
			iMax = i;
		n++;
	}

	cout << endl << "1 минимальная температура года: " << year[iMin];
	cout << endl << "1 максимальная температура года: " << year[iMax];

	int iMax2 = iMax == 0 ? 1 : 0;		// избегаем старта с уже найденного максимума
	int iMin2 = iMin == 0 ? 1 : 0;		// избегаем старта с уже найденного минимума
	for (int i = 1; i < DAYS; i++)
	{
		if (year[i] < year[iMin2] && year[i] > year[iMin])
			iMin2 = i;
		if (year[i] > year[iMax2] && year[i] < year[iMax])
			iMax2 = i;
		n++;
	}
	cout << endl << "2 минимальная температура года: " << year[iMin2];
	cout << endl << "2 максимальная температура года: " << year[iMax2];

	int iMax3 = iMax == 1 || iMax2 == 1 ? 2 : iMax == 0 || iMax2 == 0 ? 1 : 0;  // избегаем старта с уже найденных максимумов
	int iMin3 = iMin == 1 || iMin2 == 1 ? 2 : iMin == 0 || iMin2 == 0 ? 1 : 0;  // избегаем старта с уже найденных минимумов
	for (int i = 1; i < DAYS; i++)
	{
		if (year[i] < year[iMin3] && year[i] > year[iMin2])
			iMin3 = i;
		if (year[i] > year[iMax3] && year[i] < year[iMax2])
			iMax3 = i;
		n++;
	}
	cout << endl << "3 минимальная температура года: " << year[iMin3];
	cout << endl << "3 максимальная температура года: " << year[iMax3];
	cout << endl << endl << "Total operations: " << n << endl;
}