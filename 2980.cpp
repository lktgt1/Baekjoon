// 백준 2980

// 처음 시작점 0부터 다음 신호등까지 시간을 계산하며 시뮬레이션을 진행한다.
// 신호등에 도착했을 때 아직 신호등의 싸이클 시간이 그 신호등까지 걸린 시간을 넘지 않은 경우와
// 싸이클이 한번이상 돌아간 경우를 생각하여 남은 시간을 더해주며 마지막 신호등까지 반복한다.
// 마지막 신호등에서 도로의 마지막까지 걸린 시간까지 더해주면 답이 된다.

#include <cstdio>

int main(){
	int n,l,cur = 0,ans = 0;
	scanf("%d%d",&n,&l);
	for(int i=0;i<n;i++){
		int d,r,g,remain;
		scanf("%d%d%d",&d,&r,&g);
		ans += d-cur;
		if(r+g >= ans){
			if(r <= ans) remain = 0;
			else remain = r-ans;
		}
		else{
			if(ans%(r+g) > r) remain = 0;
			else remain = r - ans%(r+g);
		}
		ans += remain;
		cur = d;
	}
	printf("%d",ans+(l-cur));
}