// 백준 17352

// 입력으로 들어오는 두 섬을 계속 union해준다.
// 모두 union하고도 parent가 다른 두 섬을 출력해주면 된다.

#include <cstdio>

int p[300001];

int find(int a){
	if(p[a] <= 0) return a;
	return p[a] = find(p[a]);
}

bool merge(int a,int b){
	a = find(a);
	b = find(b);
	if(a == b) return false;
	p[b] = a;
	return true;
}

int main(){
	int n;
	scanf("%d",&n);
	for(int i=0;i<n-2;i++){
		int a,b;
		scanf("%d%d",&a,&b);
		merge(a,b);
	}
	for(int i=1;i<=n;i++){
		if(merge(1,i)){
			printf("1 %d",i);
			return 0;
		}
	}
}