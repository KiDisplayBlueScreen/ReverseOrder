#include <Windows.h>
#include <iostream>
#include <random>
using namespace std;

VOID Swap(PINT A, PINT B)
{
	*A = *A ^ *B;
	*B= *A ^ *B;
	*A = *A ^ *B;
}



int main()
{
	ULONG N= 0;
	cout << "输入数组的大小:  ";
	cin >> N;

	PINT Array = (PINT)malloc(sizeof(INT) * N);
	memset(Array, 0, sizeof(INT) * N);

	default_random_engine RandomNumbers(GetTickCount());

	for (int i = 0; i <= N - 1; i++)
	{
		Array[i] = RandomNumbers() % 10;
		if (Array[i] == 0)
		{
			Array[i]++;
		}

	}
	cout << "The Numbers in Array are: " << endl;
	for (int i = 0; i <= N - 1; i++)
	{
		cout <<Array[i];
		cout << " ";
	}
	cout << endl;

	for (int i = N - 1; i > N / 2; i--)
	{
		Swap(&Array[i], &Array[N - i - 1]);
	}

	cout << "The Numbers in Array are: " << endl;
	for (int i = 0; i <= N - 1; i++)
	{
		cout << Array[i];
		cout << " ";
	}



	cout << endl;
	system("pause");

}