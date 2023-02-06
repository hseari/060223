#include <iostream>

using namespace std;

void zapolnenie(int n, int** matrix) {
	srand((unsigned)time(NULL));
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			matrix[i][j] = 1 + rand() % 100;
		}
	}

}

void print(int n, int** matrix) {
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			std::cout << matrix[i][j] << " ";
		}
		std::cout << std::endl;
	}

}

void summa(int n, int** matrix) {
	int sum = 0;
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
			if (i == j) { //так как на главной диагонали номер столбца и строки одинаковый 
				sum += matrix[i][j];
			}

	std::cout << sum;
}

int add(int a, int b) {
	cout << a + b;
	return 0;
}
int min(int a, int b) {
	cout << a - b;
	return 0;
}
int umn(int a, int b) {
	cout << a * b;
	return 0;
}
int del(int a, int b) {
	cout << a / b;
	return 0;
}

void zapolnenie(int n, int* arr) {
	for (int i = 0; i < n; i++) {
		std::cout << "Введите элемент массива: " << std::endl;
		std::cin >> arr[i];
	}

}

double srednee(int* arr, int i, int j, int k) {
	double sum = 0;
	for (int c = i; c < j; ++c) {   //суммируем подмассив
		sum += arr[c];
	}
	return sum / k;   //находим среднее этой суммы
}

int main() {
	setlocale(LC_ALL, "Russian");
	
/*	//тертья задача
	int n;
	int sum = 0;
	cin >> n;
	int** matrix = new int* [n];

	for (int k = 0; k < n; ++k) 
		matrix[k] = new int[n];

	zapolnenie(n, matrix);
	print(n, matrix);
	summa(n, matrix);
	cout << " ";
	
	for (int i = 0; i < n; i++) 
		delete[] matrix[i];
	delete[] matrix;*/

	//пятая задача

	/*int a, b;    //два целых параметра 
	char h = '0';    //символьный знак
	do
	{
		cin >> a >> b;
		cin >> h;

		if (h == '+') add(a, b);
		else if (h == '-') min(a, b);
		else if (h == '*') umn(a, b);
		else if (h == '/') del(a, b);
		else std::cout << "Ошибка";
	} while (h != ' ');*/

	//четвертая задача

	int n, k;
	cin >> n >> k;  //n - длина массива, к - подмассива 
	int* arr = new int[n];
	zapolnenie(n, arr);

	//Найдите непрерывный подмассив, длиной k, который имеет минимальное среднее значение, и верните это значение.
	
	double min = INT_MAX;
	for (int i = 0; i < n; ++i) {
		int j = i + k;  //конец подмассива
		if (j > n) {    //выходим как конец подмассива доходит до конца массива
			break;
		}
		double res = srednee(arr, i, j, k);
		if (res < min) {      //ищем минимум среди всех средних
			min = res;   
		}
	}
	std::cout << min;
	delete[] arr;

	return 0;
}


