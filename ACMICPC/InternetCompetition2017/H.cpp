// ACMICPC Internet Competition 2017

// 배열에서 3개 또는 2개의 원소를 뽑아 가장 큰 곱을 만드는 것이 목표이다.
// 1.3개를 뽑을 때 곱이 가장 크려면
//   가장 작은 원소, 그다음 가장 작은 원소,가장 큰 원소를 곱한것과
//   가장 큰 원소 3개를 골라서 곱한것 중에서 큰 것을 선택하면 되고,
// 2.2개를 뽑을 때 곱이 가장 크려면
//   가장 작은 원소, 그다음 가장 작은 원소를 곱한것과
//   가장 큰 원소, 그다음 가장 큰 원소를 곱한것 중에서 큰 것을 선택하면 된다.

// 원소 값에 따라서 2개를 선택한 경우가 3개를 선택한 경우보다 더 클 수도 있으므로 4가지 경우 모두 탐색해준다.


#include <cstdio>
#include <algorithm>

using namespace std;

int main(){
	int n,arr[10000];
	scanf("%d",&n);
	for(int i=0;i<n;i++) scanf("%d",&arr[i]);
	sort(arr,arr+n);
	printf("%d",max({arr[0]*arr[1]*arr[n-1],arr[n-1]*arr[n-2]*arr[n-3],arr[0]*arr[1],arr[n-1]*arr[n-2]}));
}