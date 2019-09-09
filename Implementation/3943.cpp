// 백준 3943

// n을 입력받고 max를 n으로 초기화 시켜준다.
// n이 홀수일 경우 원래 max보다 커질 수 있으므로 max를 갱신해준다.

#include <cstdio>

void solve(){
	int n,max;
	scanf("%d",&n);
	max = n;
	while(n>1){
		if(n&1) {
			n *= 3;
			n += 1;
			if(max < n) max = n;
		}
		else n /= 2;
	}
	printf("%d\n",max);
}

int main(){
	int t;
	scanf("%d",&t);
	while(t--) solve();
}