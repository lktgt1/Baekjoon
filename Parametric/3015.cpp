#include <cstdio>

int n,m,marr[10000];

bool f(long long min){
	long long x = m;
	for(int i=0;i<m;i++) x += min/marr[i];
	return n <= x;
}

int main(){
	long long l,r,mid,cur;
	scanf("%d%d",&n,&m);
	for(int i=0;i<m;i++) scanf("%d",&marr[i]);
	if(n <= m){
		printf("%d",n);
		return 0;
	}
	cur = m;
	l = 0, r = 1e12;
	while(l+1 < r){
		mid = (l+r)/2;
		if(f(mid)) r = mid;
		else l = mid;
	}
	for(int i=0;i<m;i++) cur += r/marr[i] - (marr[i] <= r && r%marr[i] == 0);
	for(int i=0;i<m;i++){
		cur += (marr[i] <= r && r%marr[i] == 0);
		if(cur == n){
			printf("%d",i+1);
			return 0;
		}
	}
}