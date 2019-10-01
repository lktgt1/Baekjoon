#include <cstdio>
#include <algorithm>
#include <cmath>

using namespace std;

int main(){
	int n,m,c1,c2,init,narr[500000],in,cnt;
	long long dist = 1e18;
	scanf("%d%d%d%d",&n,&m,&c1,&c2);
	init = abs(c1-c2);
	for(int i=0;i<n;i++) scanf("%d",&narr[i]);
	sort(narr,narr+n);
	for(int i=0;i<m;i++){
		scanf("%d",&in);
		auto right = lower_bound(narr,narr+n,in);
		int rdist = right - narr == n ? 1e18 : *right-in,ldist = --right - narr == -1 ? 1e18 : in - *right;

		if(rdist < dist){
			dist = rdist;
			cnt = 1;
		}
		else if(rdist == dist) cnt++;

		if(ldist < dist){
			dist = ldist;
			cnt = 1;
		}
		else if(ldist == dist) cnt++;
	}
	printf("%lld %d",dist+init,cnt);
}