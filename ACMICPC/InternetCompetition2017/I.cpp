// ACMICPC Internet Competition 2017

// row,col 각각 탐색하면서 앞에서 봤을 때 가장 큰 원소, 옆에서 봤을 때 가장 큰 원소만을 남겨주고
// 나머지는 다 더하면 front view와 side view가 바뀌지 않고 피자 박스를 제거할 수 있다.

#include <cstdio>

int main(){
	int y,x,arr[1000][1000];
	long long ans = 0;
	bool alive[1000][1000]={};
	scanf("%d%d",&y,&x);
	for(int i=0;i<y;i++) for(int j=0;j<x;j++)scanf("%d",&arr[i][j]);
	for(int i=0;i<y;i++){
		int maxn = 0,cy,cx;
		for(int j=0;j<x;j++){
			if(maxn < arr[i][j]){
				maxn = arr[i][j];
				cy = i;
				cx = j;
			}
		}
		alive[cy][cx] = true;
	}
	for(int i=0;i<x;i++){
		int maxn = 0,cy,cx;
		for(int j=0;j<y;j++){
			if(maxn < arr[j][i]){
				maxn = arr[j][i];
				cy = j;
				cx = i;
			}
		}
		alive[cy][cx] = true;
	}
	for(int i=0;i<y;i++) for(int j=0;j<x;j++){
		if(!alive[i][j]) ans += arr[i][j];
	}
	printf("%lld",ans);
}