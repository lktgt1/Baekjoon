// 백준 7567 그릇

// 그릇이 이전과 같은 상태면 ans += 5, 다른 상태면 ans += 10 해준다.
// 초기상태는 left도 right도 아니므로 -1로 시작한다.

#include <iostream>
using namespace std;

int main(){
	int left = -1,ans = 0;
	string s;
	cin >> s;
	for(int i=0;i<s.size();i++){
		if(s[i] == '('){
			if(left == 1) ans += 5;
			else ans += 10,left = 1;
		}
		else{
			if(left == 0) ans += 5;
			else ans += 10,left = 0;
		}
	}
	cout << ans;
}