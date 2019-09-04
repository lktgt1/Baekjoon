// 백준 10775

// 인풋으로 들어오는 수 이하의 자연수 중 가장 높은 숫자의 번호에 도킹시킨다.
// for문으로 인풋 수부터 차례대로 확인하면 O(N^2)로 시간초과
// union-find로 인풋 이하의 자연수 중 가장 높은 번호를 가진 사용하지 않은 게이트를 알 수 있다.
// find(in) = 1 부터 in까지 도킹할 수 있는 가장 높은 번호라고 하면
// find(in) = 0 일 때 도킹할 수 없고, 
// find(in) < 0 일 때 find(in)에 도킹하고 find(in)-1과 union하면
// 다음으로 도킹할 수 있는 가장 높은 번호를 갱신할 수 있다.


#include <cstdio>
#include <cstring>
const int size = 1e5;

int p[size+1];

int find(int a){
	if(p[a] < 0) return a;
	return p[a] = find(p[a]);
}

bool merge(int a,int b){
	a = find(a);
	b = find(b);
	if(a == b) return false;
	p[a] = b;
	return true;
}

int main(){
	memset(p,-1,sizeof(p));
	int G,P,ans = 0;
	scanf("%d%d",&G,&P);
	for(int i=0;i<P;i++){
		int in;
		scanf("%d",&in);
		if(find(in) == 0) break;
		merge(find(in),find(in)-1);
		ans++;
	}
	printf("%d",ans);
}