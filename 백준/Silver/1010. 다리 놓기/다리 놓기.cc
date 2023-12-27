#include <iostream>

using namespace std;

int Combination(int n1, int n2)
{
	int river = 1;
	for (int i = 0; i < n1; i++)
	{
		river *= (n2 - i);
		river /= (1 + i);
	}
	return river;
}

int main()
{
	int key, n1, n2,idx=0;
	cin >> key;
	int* arr = new int[key];
	while (key--)
	{
		cin >> n1 >> n2;
		arr[idx] = Combination(n1, n2);
		idx++;
	}
	for (int i = 0; i < idx; i++)
	{
		cout << *(arr +i)<<endl;
	}

}