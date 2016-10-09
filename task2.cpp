#include <iostream>
using namespace std;

void fillArray(char*** base);
void printArray(char*** base, int countTab, int countLine, int size);
void scanArray(char*** base, int countTab, int countLine, int size, int& tab, int& line);
void enterInArray(char*** base, int countTab, int countLine, int size, int tab, int line);
void addLineInArray(char*** base, int countTab, int& countLine, int size, int& tab, int& line);

void main()
{
	int tab, line;
	int size = 50;
	int countTab = 2;
	int countLine = 5;
	char*** base = new char**[countTab];
	for (int i = 0; i < countTab; i++)
	{
		(base[i]) = new char*[countLine];
		for (int j = 0; j < countLine; j++)
		{
			(base[i][j]) = new char[size];
		}
	}
	fillArray(base);
	printArray(base, countTab, countLine, size);
	scanArray(base, countTab, countLine, size, tab, line);
	enterInArray(base, countTab, countLine, size, tab, line);
	addLineInArray(base,countTab, &countLine, size, &tab, &line);
	printArray(base, countTab, countLine, size);

	for (int i = 0; i < countTab; i++)
	{
		for (int j = 0; j < countLine; j++)
		{
			delete[] (base[i][j]) ;
		}
		delete[] (base[i]);
	}
	delete[] base;
}

void fillArray(char *** base)
{
	strcpy(base[0][0], "Eliza");
	strcpy(base[1][0], "+375(29)250 00 00");
	strcpy(base[0][1], "Kity");
	strcpy(base[1][1], "+375(29)250 11 00");
	strcpy(base[0][2], "Jorj");
	strcpy(base[1][2], "+375(29)250 11 22");
	strcpy(base[0][3], "Maxim");
	strcpy(base[1][3], "+375(29)200 11 22");
	strcpy(base[0][4], "Bat");
	strcpy(base[1][4], "+375(29)234 56 78");
}

void printArray(char *** base, int countTab, int countLine, int size)
{
	for (int j = 0; j < countLine; j++)
	{
		for (int i = 0; i < countTab; i++)
		{
			cout << base[i][j] << "\t";
		}
		cout << endl;
	}
}

void scanArray(char*** base, int countTab, int countLine, int size, int& tab, int& line)
{
	int test = 0;
	char* str = new char[size];
	cout << "enter the name or phone number to search";
	cin.getline(str, size);
	for (tab = 0; tab < countTab; tab++)
	{
		for (line = 0; line < countLine; line++)
		{
			int result = strcmp(str, base[tab][line]);
			if (result == 0)
			{
				cout << base[0][line] << "\t" << base[1][line] << endl;
				test++;
				break;
			}
		}
		if (test > 0)
		{
			break;
		}
	}
	if (test == 0)
	{
		cout << "is not found " << endl;
	}
}

void enterInArray(char *** base, int countTab, int countLine, int size, int tab, int line)
{
	cout << "enter name: ";
	cin.getline(base[0][line], size);
	cout << "enter telephone number: ";
	cin.getline(base[1][line], size);
	for (int i = 0; i < countTab; i++)
	{
		cout << base[i][line] << "\t";
	}
	cout << endl;
}

void addLineInArray(char *** base, int countTab, int& countLine, int size, int& tab, int& line)
{
	int tempCountLine = countLine + 1;
	
	for (int i = 0; i < countTab; i++)
	{
		(base[i]) = new char*[tempCountLine];
		for (int stepCountLine = countLine = 0; stepCountLine < countLine; stepCountLine++)
		{
			(base[i][stepCountLine]) = new char[size] {NULL};
		}
	}
	line = countLine;
	tab = 0;
	countLine++;
	enterInArray(base, countTab, countLine, size, tab, line);
}


/*Создайте динамический массив, хранящий в первой строке имя, а во второй - телефон. 
Организуйте поиск по имени и по номеру телефона и возможность ввода и изменения данных. */