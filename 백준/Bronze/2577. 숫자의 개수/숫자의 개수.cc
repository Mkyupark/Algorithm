#include <iostream>

using namespace std;
int main() {
	int a, b, c, multi;
	int arr[10] ={0};
	cin >> a >> b >> c;
	multi = a * b * c;
	while (multi != 0) {
		int remain = multi % 10;
		arr[remain]++;
		multi /= 10;
	}
	for (int i = 0; i < 10; i++) {
		cout << arr[i] << endl;
	}
}