// 백준 4796

// 캠핑장을 사용할 수 있는 일수: 일단 V를 P로 나눈 몫 만큼은 L일 전체를 사용할 수 있다.
// 						 마지막 남은 휴가일수 중에 L일 전체를 사용하지 못할 수 있는데, 
// 						 이 경우 min(남은 휴가일 수 = V%P,L일)로 계산할 수 있다.

#include <cstdio>

inline int min(int a,int b){return a>b ? b : a;};

int main(){
	int L,P,V,t_case = 1;
	while(scanf("%d%d%d",&L,&P,&V)){
		if(L==0 && P==0 && V==0) return 0;
		printf("Case %d: %d\n",t_case++,(V/P)*L+min(L,V%P));
	}
}