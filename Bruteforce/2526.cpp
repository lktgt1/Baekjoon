#include <cstdio>

int main(){
	int rep[1001]={};
	int n,p,cnt = 1,next,prev;
	scanf("%d%d",&n,&p);
	next = n;
	while(!rep[next]){
		rep[next] = cnt++;
		prev = next;
		next = (next*n)%p;
	}
	printf("%d",rep[prev]-rep[next]+1);
}