// 백준 10819

// n이 매우 작기 때문에 모든 경우를 계산해 볼 수 있다.
// mask를 인자로 넘겨서 원소를 넣었었는지 확인한다.

#include <cstdio>
#include <algorithm>
#include <cmath>
using namespace std;
int n,arr[8],narr[8];

int solve(int idx,int mask){
	int ans = 0;
	if((1<<n)-1 == mask){
		for(int i=0;i+1<n;i++) ans += abs(narr[i+1]-narr[i]);
		return ans;
	}
	for(int i=0;i<n;i++){
		if(!((1<<i)&mask)){
			narr[idx] = arr[i];
			ans = max(solve(idx+1,mask|1<<i),ans);
		}
	}
	return ans;
}

int main(){
	scanf("%d",&n);
	for(int i=0;i<n;i++) scanf("%d",&arr[i]);
	printf("%d",solve(0,0));
}