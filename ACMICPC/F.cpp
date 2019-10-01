// ACMICPC Internet Competition 2018

// 5000개의 원소중 4개를 뽑는다 생각할 수도 있지만, 5000C4는 시간이 매우 오래 걸린다.
// 원소들 중 어떤 지점을 기준으로 앞쪽 두 원소들의 합을 안다고 하면, 그 뒤쪽 원소들의 합을 계산한 후에
// 각각의 합을 합해서 원소 4개의 합을 만들 수 있다.
// 이렇게 하면 2중for문 안에서 모두 해결되므로 시간복잡도 O(N^2)안에 답을 찾아낼 수 있다.

#include <cstdio>

using namespace std;

int main(){
	bool preSum[800000]={};
	int w,n,arr[5000];
	scanf("%d%d",&w,&n);
	for(int i=0;i<n;i++) scanf("%d",&arr[i]);
	for(int i=2;i<n-1;i++){
		for(int j=0;j<i-1;j++)
			preSum[arr[j]+arr[i-1]] = true;
		for(int j=i+1;j<n;j++){
			if(w-arr[i]-arr[j] < 800000 && w-arr[i]-arr[j] >= 0  && preSum[w-arr[i]-arr[j]]) {
				printf("YES");
				return 0;
			}
		}
	}
	printf("NO");
}