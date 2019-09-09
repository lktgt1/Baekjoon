// 백준 8741

// k = 1 일 때 1,
// k = 2 일 때 110,
// k = 3 일 때 11100,
// ...
// k = n 일 때 1의 개수 = n개, 0의 개수 = n-1개인 것을 알 수 있다.

#include <cstdio>

int main(){
	int k;
	scanf("%d",&k);
	for(int i=0;i<k;i++) putchar('1');
	for(int i=0;i<k-1;i++) putchar('0');
}