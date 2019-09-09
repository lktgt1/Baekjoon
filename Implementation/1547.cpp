// 백준 1547

// 공은 처음에 1에 있고, 입력으로 공에 해당하는 위치의 숫자가 들어오면
// 같이 들어온 다른 입력의 숫자로 공의 위치를 바꾼다. 

#include <cstdio>

int main(){
	int m,ball = 1;
	scanf("%d",&m);
	for(int i=0;i<m;i++){
		int a,b;
		scanf("%d%d",&a,&b);
		if(ball == a) ball = b;
		else if(ball == b) ball = a;
	}
	printf("%d",ball);
}