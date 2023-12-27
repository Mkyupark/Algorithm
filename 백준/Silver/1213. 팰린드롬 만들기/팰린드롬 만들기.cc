#include <iostream>
#include <algorithm>
#include <string>
using namespace std;
int main() {
	
	string alp;
	
	cin >> alp;

	char a[50] ={};	// 정적배열 선언
	char b[50] = {};
	char c[2] = {0,0};
	int num = 0;
	// 입력받은거 리스트에 저장
	for (int i = 0; i < alp.length(); i++) {
		a[i] = alp[i];
	}

	sort(a, a + alp.length());

	for (int i = 0, j =0; i < alp.length(); i++) {
		// 문자열이 다를 경우 AAABB -> A를 C에 저장.
		if (a[i] != a[i + 1]) {
			c[j] = a[i];
			if (j >= 1) { break; }
			j++;
		}
		else {
			b[num] = a[i];
			b[alp.length() - 1-num] = a[i];
			num++;
			i++;
		}
	}

	if (c[1] != 0) {
		cout << "I'm Sorry Hansoo";
	}
	else {
		if (c[0] != 0) {
			b[num] = c[0];
		}
		for (int i = 0; i < alp.length(); i++) {
			cout << b[i];
		}
	}
}