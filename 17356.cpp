// 백준 17356

// 문제에서 요구하는대로 식을 만들면 된다.

#include <cstdio>
#include <cmath>

int main(){
	long double a,b;
	scanf("%Lf%Lf",&a,&b);
	printf("%Lf",1/(1+(long double)pow(10,(b-a)/400)));
}