// 백준 1015

// 입력을 받을 때 입력받은 순서와 원소를 저장한다.
// 이 배열을 sort하면 원소를 기준으로 비내림차순으로 정렬되는데, 
// answer배열을 만들어서
// 정렬된 원소의 입력받았을때의 순서 위치에 정렬된 후의 위치를 저장해주고 출력하면 된다.

#include <cstdio>
#include <algorithm>
using namespace std;
typedef pair<int,int> pii;

int main(){
	int n,ans[50]={};
	pii arr[50];
	scanf("%d",&n);
	for(int i=0;i<n;i++){
		int in;
		scanf("%d",&in);
		arr[i]={in,i};
	}
	sort(arr,arr+n);
	for(int i=0;i<n;i++) ans[arr[i].second] = i;
	for(int i=0;i<n;i++) printf("%d ",ans[i]);
}