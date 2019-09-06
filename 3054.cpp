// 백준 3054

// 모든 글자를 피터팬 프레임으로 장식한 뒤, 3의 배수에 있는 글자를 웬디 프레임으로 장식하면 조건을 만족시킬 수 있다.


#include <iostream>
#include <cstdio>
#include <string>

using namespace std;

int main(){
	char out[5][15*5]={};
	string s;
	cin >> s;
	for(int i=0;i<s.size();i++){
		for(int j=0;j<5;j++){
			for(int k=0;k<5;k++){
				if(j == 0 || j == 4) out[j][i*4+k] = (k == 2 ? '#' : '.');
				if(j == 1 || j == 3) out[j][i*4+k] = ((k == 1 || k == 3) ? '#' : '.');
				if(j == 2) out[j][i*4+k] = (k == 0 || k == 4) ? '#' : (k == 2 ? s[i] : '.');
			} 
		}
	}
	for(int i=0;i<s.size();i++){
		if(i%3 == 2){
			for(int j=0;j<5;j++){
				for(int k=0;k<5;k++){
					if(j == 0 || j == 4) out[j][i*4+k] = (k == 2 ? '*' : '.');
					if(j == 1 || j == 3) out[j][i*4+k] = ((k == 1 || k == 3) ? '*' : '.');
					if(j == 2) out[j][i*4+k] = (k == 0 || k == 4) ? '*' : (k == 2 ? s[i] : '.');
				} 
			}
		}
	}
	for(int i=0;i<5;i++) printf("%s\n",out[i]);
}