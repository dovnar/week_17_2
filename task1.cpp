#include <iostream>
using namespace std;
int** transposingsMatrix(int**arr, int const count);
void printArray(int**arr, int const count);

void main()
{
	int number = 1;
	int count = 5;
	int** arr = new int*[count];
	for (int i = 0; i < count; i++)
	{
		*(arr + i) = new int[count] {number++, number++, number++, number++, number++};
	}
	printArray(arr, count);
	arr = transposingsMatrix(arr, count);
	cout << "transposings of a matrix:" << endl;
	printArray(arr, count);
	for (int i = 0; i < count; i++)
	{
		delete[] arr[i];
	}
	delete[] arr;
}

int** transposingsMatrix(int** arr, int const count)
{
	for (int i = 0; i < count; i++)
	{
		for (int j = 0; j+i < count; j++)
		{
			int temp = arr[i][j+i];
			arr[i][j+i] = arr[j+i][i];
			arr[j+i][i] = temp;
		}
	}
	return arr;
}

void printArray(int** arr, int const count)
{
	for (int i = 0; i < count; i++)
	{
		for (int j = 0; j < count; j++)
		{
			cout << arr[i][j] << "\t";
		}
		cout << endl;
	}
}
