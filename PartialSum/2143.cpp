#include <cstdio>

const long long MOD = 1e9+7;

int main(){
	int h,w,r[1001],c[1001],map[1001][1001]={};
	long long ans = 1;
	scanf("%d%d",&h,&w);
	for(int i=0;i<h;i++) {
		scanf("%d",&r[i]);
		for(int j=0;j<=r[i];j++) map[i][j] = 1;
	}
	for(int i=0;i<w;i++) {
		scanf("%d",&c[i]);
		for(int j=0;j<=c[i];j++) map[j][i] = 1;
	}
	for(int i=0;i<h;i++){
		for(int j=0;j<w;j++){
			if(map[i][j] == 0){
				ans *= 2;
				ans %= MOD;
			}
		}
	}
	printf("%lld\n",ans == 1 ? 0LL : ans);
}