// 백준 6321

// 대문자 알파벳의 순서를 오른쪽으로 한칸씩 미는 문제
// 나머지 연산을 이용하여 Z 이후 A로 가도록 만든다.

#include <cstdio>

int main(){
	char in[51]={};
	int n;
	scanf("%d",&n);
	for(int i=1;i<=n;i++){
		scanf("%s",in);
		printf("String #%d\n",i);
		for(int j=0;in[j];j++)
			printf("%c",(in[j]-'A'+1)%26+'A');
		puts("\n");
	}
}