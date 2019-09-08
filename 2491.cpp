// 백준 2491

// 수열의 연속한 ascending or descending 부분수열의 최대 길이를 세는 문제
// 원소가 같은 경우에는 ascending 인지 descending인지 상관 없기 때문에 카운트가 겹쳐서 세어 질 수 있다.
// 그렇기때문에 ascending으로 한 번,descending으로 한 번 각각 세줘야 한다.

#include <cstdio>

inline int max(int a,int b){return a > b ? a : b;};

int arr[100000],n;

int f(bool desc){
	int ret = 1,cnt = 1;
	for(int i=1;i<n;i++){
		if(arr[i-1] <= arr[i] && !desc) cnt++;
		else if(arr[i-1] >= arr[i] && desc) cnt++;
		else cnt = 1;
		ret = max(ret,cnt);
	}
	return ret;
}

int main(){
	scanf("%d",&n);
	for(int i=0;i<n;i++) scanf("%d",&arr[i]);
	printf("%d",max(f(0),f(1)));
}