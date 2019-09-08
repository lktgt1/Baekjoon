// 백준 2999

// 문제에서 요구하는 R과 C를 구한다.
// R은 s의 약수 중 R <= C 를 만족하는 최대 수이므로 loop를 sqrt(n)까지만 돌려도 된다.

// 배열을 직접 돌려서 만드는 방법 : R=2,C=4일 때 s는 순서대로 배열에 arr[0][0] = s[0], arr[1][0] = s[1],arr[0][1] = s[3]...
// 으로 만들 수 있다.

// 그냥 출력 : 배열을 돌린 결과는 s의 0부터 R만큼 계속 건너뛴 결과다. R=2, C=4일 때 s[0],s[2],s[4],s[6] 후에 s[1],s[3],s[5],s[7]
// 이런식으로 출력하면 돌린 결과와 같아진다.

#include <iostream>
#include <cstdio>
#include <string>
using namespace std;

int main(){
	string s;
	char arr[100][100]={};
	cin >> s;
	int n = s.size();
	int R,C;
	for(int i=1;i*i<=n;i++) {
		if(n%i == 0) {
			R = i;
			C = n/i;
		}
	}
	for(int i=0;i<R;i++) for(int j=i;j<n;j+=R) putchar(s[j]);
	// for(int i=0;i<C;i++) for(int j=0;j<R;j++) arr[j][i] = s[i*R+j];
	// for(int i=0;i<R;i++) for(int j=0;j<C;j++) putchar(arr[i][j]);
}