#include <iostream>
#include <iomanip>
using namespace std;


int main()
{
	cout << "Array algorythms: linear search" << endl;
	const int N = 20;
	int array[N];

	for (size_t i = 0; i < N; i++)
	{
		array[i] = rand() % 100;
		cout << setw(4) << array[i];
	}

	int number = 5, position = -1;

	for (int i = 0; i < N; i++)
	{
		if (array[i] == number)
		{
			position = i;
			break;  // добавляем для поиска первого вхождения
		}
	}
	cout << endl << "Position of number " << number << " is " << position;


	// Сортировка поиском минимального 
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

	// Пузырьковая сортировка 
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


	// Практический пример
	n = 0;
	setlocale(LC_ALL, "ru");
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
	n = 0;
	int iMax = 0, iMin = 0;
	for (int i = 0; i < DAYS; i++)
	{
		if (year[i] < year[iMin])
			iMin = i;
		if (year[i] > year[iMax])
			iMax = i;
		n++;
	}
	cout << endl << year[iMin] << endl;
	cout << endl << year[iMax] << endl;

	int iMax2 = 0, iMin2 = 0;
	for (int i = 0; i < DAYS; i++)
	{
		if (year[i] < year[iMin2] && year[i] > year[iMin])
			iMin2 = i;
		if (year[i] > year[iMax2] && year[i] < year[iMax])
			iMax2 = i;
		n++;
	}
	cout << endl << year[iMin2] << endl;
	cout << endl << year[iMax2] << endl;

	int iMax3 = 0, iMin3 = 0;
	for (int i = 0; i < DAYS; i++)
	{
		if (year[i] < year[iMin3] && year[i] > year[iMin2])
			iMin3 = i;
		if (year[i] > year[iMax3] && year[i] < year[iMax2])
			iMax3 = i;
		n++;
	}
	cout << endl << year[iMin3] << endl;
	cout << endl << year[iMax3] << endl;
	cout << endl << "Total operations: " << n;
}