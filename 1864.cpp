// 백준 1864

// 각 문어숫자에 대응하는 숫자를 만들어 놓으면 편하게 구현할 수 있다.

#include <iostream>
#include <string>
using namespace std;

int main(){
	int mapping[127]={};
	mapping['\\']=1,mapping['(']=2,mapping['@']=3,mapping['?']=4,
	mapping['>']=5,mapping['&']=6,mapping['%']=7,mapping['/']=-1;
	string in;
	while(cin >> in){
		if(in == "#") return 0;
		int sum = 0;
		for(char c : in){
			sum *= 8;
			sum += mapping[c];
		}
		cout << sum << "\n";
	}
}