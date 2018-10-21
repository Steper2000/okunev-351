// lab7.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include "pch.h"
#include <iostream>
using namespace std;
//указатель_на_тип_переменной имя_переменной = new тип;
//или тип * имя_переменной = new типж
// пример: int * ptr_int=new int; для удаления delete имя_указателя
//для одномерного массива:
// тип * имя_указателя = new тип[длина]; для удаления delete[] имя_указателя
class matrix
{
private:
	int * matr = new int[rows*columns];
	int rows, columns;
	int *res = new int[rows*columns];
public:
	matrix();
	~matrix();

	bool summMatrix(matrix matr2);
	bool multMatrix(matrix matr2);

	int getElem(int row, int col);
	int getRows() { return rows; }
	int getColumns() { return columns; }

	bool input();
	void transp();

	void printM()
	{
		for (int i = 0; i <rows; i++)
		{
			for (int j = 0; j < columns; j++)
			{
				cout << matr[i*columns + j] << "\t";
			}
			cout << endl;
		}
	};

};




int main()
{
	matrix matrA, matrB;
	matrA.input();
	matrB.input();
	//matrA.printM();
	//matrA.transp();
	//matrA.summMatrix(matrB);
	matrA.multMatrix(matrB);
}

matrix::matrix() {}
matrix::~matrix() {}

bool matrix::summMatrix(matrix matr2)
{
	if (rows == matr2.getRows() && columns == matr2.getColumns())
	{
		for (int i = 0; i < rows; i++)
		{
			for (int j = 0; j < columns; j++)
			{
				matr[i*columns+j] += matr2.getElem(i, j);
			}
		}
		printM();
		return true;
	}
	else { return false; }
}

void matrix::transp()
{
	int t;
	for (int i = 0; i < columns; i++)
	{
		for (int j = 0; j < rows; j++)
		{
			cout << matr[j * columns + i] <<" ";
		}
		cout << endl;
	}
	
}

bool matrix::multMatrix(matrix matr2)
{
	if (columns == matr2.getRows())
	{
		for (int i = 0; i < rows; i++)
		{
			for (int j = 0; j < matr2.getColumns(); j++)
			{
				int sum = 0;
				for (int k = 0; k < columns; k++) {
					sum += matr[i*columns+k] * matr2.getElem(k, j);
				}
				res[i*columns+j] = sum;
			}
		}
		for (int i = 0; i < rows; i++)
		{
			for (int j = 0; j < matr2.getColumns(); j++)
			{
				cout << res[i*columns + j];
			}
			cout << endl;
		}
       
		return true;
	}
	else 
	{
		cout << "col1 != row2";
		return false;
	}
}

int matrix::getElem(int row, int col)
{
	if (row<rows && col<columns && row>-1 && col>-1)
	{
		return matr[row*columns+col];
	}
	else
	{
		cout << "error";
		return -1;
	}
}

bool matrix::input()
{
	cout << "rows=";
	cin >> rows;
	cout << "columns=";
	cin >> columns;
    for (int i = 0; i <rows; i++)
	{
		for (int j = 0; j < columns; j++)
		{
			cin >> matr[i*columns+j];
		}
		cout << endl;
	}
	return true;
}
