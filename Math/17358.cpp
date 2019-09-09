/*
백준 17358

총 n/2번의 반복문을 돌리면서, 컵의 위치가 바뀌는 경우를 생각해 본다
모든 컵의 위치가 정확히 한번씩 바뀌어야 하므로, 
가장 처음에 어떤 컵 두개를 선택하여 바꾸는 경우,
그 다음으로 위치가 바뀌지 않은 컵 두개를 선택하는 경우... 를 생각하면 
(n-1)*(n-3)*(n-5)*...(n-(n-1))이 답이 된다
*/

#include <cstdio>

const int MOD = 1e9+7;

int main(){
	long long n,sum = 1;
	scanf("%lld",&n);
	int k = n/2;
	n--;
	for(int i=0;i<k;i++){
		sum *= n;
		sum %= MOD;
		n -= 2;
	}
	printf("%lld",sum);
}