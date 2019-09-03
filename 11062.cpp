// 백준 11062

// 할 수 있는 행동:카드 뭉치에서 left와 right중 하나를 고른다.

// m[l][r] = 카드에서 선택해야 하는게 l,r중 하나일 때 근우가 얻을 수 있는 최고 점수
// 근우 턴: l 또는 r을 선택해야 하는 경우 중에 ret값이 가장 큰 경우가 최선
// 명우 턴: 근우와 반대되는 조건을 최선의 전략으로 삼는다.
// 		l 또는 r을 선택해야 하는 경우 중에 ret값이 가장 작은 경우가 최선

#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

int m[1000][1000],arr[1000],n;

int f(int l,int r,bool geunwoo){
	int &ret = m[l][r];
	if(~ret) return ret;
	ret = 0;
	if(l>r) return ret;
	if(geunwoo) ret = max(f(l+1,r,0)+arr[l],f(l,r-1,0)+arr[r]);
	else ret = min(f(l+1,r,1),f(l,r-1,1));
	return ret;
}

void solve(){
	memset(m,-1,sizeof(m));
	scanf("%d",&n);
	for(int i=0;i<n;i++) scanf("%d",&arr[i]);
	printf("%d\n",f(0,n-1,1));
}

int main(){
	int t;
	scanf("%d",&t);
	while(t--) solve();
}