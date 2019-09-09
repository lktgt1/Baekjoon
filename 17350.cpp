// 백준 17350

// 인풋으로 들어오는 스트링이 정확히 anj이면 뭐야; 없으면 뭐야?를 출력하면 된다.

#include <string>
#include <iostream>

using namespace std;

int main(){
	string in;
	int n;
	cin >> n;
	while(n--){
		cin >> in;
		if(in=="anj"){
			cout << "뭐야;";
			return 0;
		}
	}
	cout << "뭐야?";
}